#ifndef QTPVDBCONCEPTMAPRATEWIDGET_H
#define QTPVDBCONCEPTMAPRATEWIDGET_H

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#include "qtpvdbconceptmapwidget.h"

#ifdef PVDB_USE_FORWARD_DECLARATIONS_248738
#include "pvdbfwd.h"
#else
#include "qtpvdbrateconcept.h"
#endif

///QtPvdbConceptMapWidget for creation and editing of a ConceptMap
struct QtPvdbConceptMapRateWidget : public QtPvdbConceptMapWidget
{
  typedef QtPvdbConceptMapRateWidget This_t;

  QtPvdbConceptMapRateWidget(
    const boost::shared_ptr<pvdb::ConceptMap> concept_map,
    QWidget* parent = 0);
  ~QtPvdbConceptMapRateWidget() {}
  QtPvdbConceptMapRateWidget(const QtPvdbConceptMapRateWidget& other) = delete;
  QtPvdbConceptMapRateWidget& operator=(const QtPvdbConceptMapRateWidget& other) = delete;

  #ifndef NDEBUG
  ///Creates a new derived class
  ///A simpler alternative to Clone (see above)
  std::unique_ptr<QtPvdbConceptMapWidget> CreateNewDerived() const;

  ///Do something random
  void DoRandomStuff();
  #endif

  ///If the user wants to rate the focal concept of the already generated sub concept map
  ///the dialog using this widget must display the tally dialog
  boost::signals2::signal<void (boost::shared_ptr<pvdb::ConceptMap>)> m_signal_request_rate_concept_dialog;

private:

  ///Adds an Edge and connects (some of) its signals to slots present in the derived classes
  void AddEdge(
    const boost::shared_ptr<pvdb::Edge> edge);

  ///Adds a node and connects (some of) its signals to slots present in the derived classes
  ///For rating and editing, the node must be non-cost
  ///For display, the node should best be const
  QtPvdbNodeItem * AddNode(const boost::shared_ptr<pvdb::Node> node);

  ///Remove all Qt and non-Qt items and add new ones
  void CleanMe();

  ///Create a subsection of the concept map, with item at the center
  ///Item is non-const, as all items can be edited in other contexts
  const boost::shared_ptr<pvdb::ConceptMap> CreateSubConceptMap(QtPvdbNodeItem * const item);

  ///Called whenever a concept is clicked or moved
  ///If item is nullptr, the last item might be deleted
  ///Use QGraphicsItem* due to QtKeyboardFriendlyGraphicsView working on QGraphicsItems
  ///Is implemented by OnItemUpdateRequestImpl
  void OnItemRequestUpdateImpl(const QGraphicsItem* const item);

  ///Called when a QtConceptItem requests to have its concept rated
  ///Note that this might be a ConceptItem on an Edge, but those signals are not connected
  ///item must be a Node, becaus only Nodes can be rated and because the Node is
  ///used for contruction of a sub concept map
  void OnNodeRequestsRateConcept(QtPvdbNodeItem * const item);

  ///Called when a QtConceptItem requests to have its concept rated
  ///Note that this might be a ConceptItem on an Edge, but those signals are not connected
  ///item must be a Node, becaus only Nodes can be rated and because the Node is
  ///used for contruction of a sub concept map
  void OnNodeRequestsRateConceptWithSuggestion(QtPvdbNodeItem * const item);

  ///Called when a QtConceptItem requests to have its examples rated
  ///Note that this might be a ConceptItem on an Edge, but those signals are not connected
  void OnNodeRequestsRateExamples(QtPvdbNodeItem * const item);

  #ifndef NDEBUG
  ///Test this class
  static void Test();
  #endif
};

#endif // QTPVDBCONCEPTMAPRATEWIDGET_H

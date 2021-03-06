#ifndef PVDBFWD_H
#define PVDBFWD_H

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#ifdef PVDB_USE_FORWARD_DECLARATIONS_248738
///Forward declarations
namespace pvdb
{
  struct CenterNode;
  struct Cluster;
  struct Concept;
  struct ConceptFactory;
  struct ConceptMap;
  struct Edge;
  struct Example;
  struct Examples;
  struct File;
  struct Node;
};

struct QRegExp;
struct QtArrowItem;
struct QTimer;
struct QtPvdbArrow;
struct QtPvdbClusterDialog;
struct QtPvdbClusterWidget;
struct QtPvdbConceptEditDialog;
struct QtPvdbConceptItem;
struct QtPvdbConceptMapDialog;
struct QtPvdbConceptMapItem;
struct QtPvdbConceptMapDisplayWidget;
struct QtPvdbConceptMapEditWidget;
struct QtPvdbConceptMapRateWidget;
struct QtPvdbConceptMapWidget;
struct QtPvdbRateConceptDialog;
struct QtPvdbRateExamplesDialog;
struct QtPvdbDisplayConceptItem;
struct QtPvdbEdgeItem;
struct QtPvdbEditConceptItem;
struct QtPvdbExamplesItem;
struct QtPvdbItemHighlighter;
struct QtPvdbNewArrow;
struct QtPvdbNodeItem;
struct QtPvdbPathArrow;
struct QtPvdbRateConceptItem;
struct QtPvdbStudentMenuDialog;
struct QtPvdbTestConceptItemDialog;
struct QtPvdbTestConceptMapEditWidgetDialog;
struct QtPvdbTestConceptMapRateWidgetDialog;
struct QtPvdbTestEdgeItemDialog;
struct QtPvdbTestNodeItemDialog;
struct QtPvdbToolsItem;
struct QtQuadBezierArrowItem;

#endif

#endif // PVDBFWD_H

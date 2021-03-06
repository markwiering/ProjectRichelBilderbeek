#ifndef QTPVDBRATECONCEPTTALLYDIALOG_H
#define QTPVDBRATECONCEPTTALLYDIALOG_H

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#include <boost/shared_ptr.hpp>
#include "qthideandshowdialog.h"
#include "pvdbfwd.h"

namespace Ui {
  class QtPvdbRateConceptTallyDialog;
}

class QtPvdbRateConceptTallyDialog : public QtHideAndShowDialog
{
  Q_OBJECT
  
public:
  ///Sub concept map is modified by this dialog
  explicit QtPvdbRateConceptTallyDialog(
    const boost::shared_ptr</* const */ pvdb::ConceptMap> sub_concept_map,
    QWidget *parent = 0);

  ~QtPvdbRateConceptTallyDialog();

  static const boost::shared_ptr<pvdb::ConceptMap> CreateTestConceptMap();

  ///Obtain the suggested complexity, calculated from this dialog
  int GetSuggestedComplexity() const;

  ///Obtain the suggested concreteness, calculated from this dialog
  int GetSuggestedConcreteness() const;

  ///Obtain the suggested specificity, calculated from this dialog
  int GetSuggestedSpecificity() const;

protected:
  void keyPressEvent(QKeyEvent *);
  void resizeEvent(QResizeEvent *);
private slots:
  void on_button_ok_clicked();
  void OnCellChanged(int row, int col);

private:
  Ui::QtPvdbRateConceptTallyDialog *ui;
  //const boost::shared_ptr</* const */ pvdb::ConceptMap> m_map;

  ///The concept map is converted to this data type
  ///The std::vector index equals the row
  ///Every row is a pair of a boost::shared_ptr<pvdb::Concept> and an integer
  ///The boost::shared_ptr<pvdb::Concept> is the concept being judged,
  ///  which might be the concept on the focal node and the concept on the egdes connected to the focal node
  ///The index is the index of the example being judged, or -1, denoting it is the concept name being judged
  typedef std::pair<boost::shared_ptr<pvdb::Concept>,int> Row;
  const std::vector<Row> m_data;

  static const std::vector<Row>
    CreateData(const boost::shared_ptr</* const */ pvdb::ConceptMap> map);

  #ifndef NDEBUG
  static void Test();
  #endif

};

#endif // QTPVDBRATECONCEPTTALLYDIALOG_H

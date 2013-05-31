#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtpvdbrateconceptdialog.h"

#ifdef COMPILER_SUPPORTS_THREADS_20130507
#include <thread>
#endif

#include <boost/lexical_cast.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include <QDesktopWidget>
#include <QFileDialog>
#include <QKeyEvent>

#include "qtpvdbconceptmapratewidget.h"
#include "pvdbfile.h"
#include "pvdbedge.h"
#include "pvdbnode.h"
#include "pvdbconcept.h"
#include "pvdbconceptmap.h"
#include "pvdbconceptmapfactory.h"
#include "pvdbconceptfactory.h"
#include "pvdbexamples.h"
#include "pvdbrating.h"
#include "pvdbnodefactory.h"
#include "trace.h"
#include "pvdbexamplesfactory.h"
#include "qtpvdbrateconceptautodialog.h"
#include "pvdbconceptmap.h"
#include "ui_qtpvdbrateconceptdialog.h"

QtPvdbRateConceptDialog::QtPvdbRateConceptDialog(
  const boost::shared_ptr<pvdb::ConceptMap> sub_concept_map,
  QWidget* parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtPvdbRateConceptDialog),
    m_concept(sub_concept_map->GetNodes().at(0)->GetConcept()),
    m_sub_concept_map(sub_concept_map)
{
  ui->setupUi(this);
  #ifndef NDEBUG
  Test();
  #endif

  assert(m_sub_concept_map);
  assert(!m_sub_concept_map->GetNodes().empty());
  assert(m_sub_concept_map->GetNodes()[0]);

  ui->widget->ReadFromConceptMap(sub_concept_map);

  assert(m_concept);

  ui->box_complexity->setCurrentIndex(m_concept->GetRatingComplexity());
  ui->box_concreteness->setCurrentIndex(m_concept->GetRatingConcreteness());
  ui->box_specificity->setCurrentIndex(m_concept->GetRatingSpecificity());
  ui->box_complexity->setFocus();

  //Set suggestions
  {
    const std::string s = "Formeel uitgangspunt: "
      + boost::lexical_cast<std::string>(pvdb::Rating::SuggestComplexity(m_sub_concept_map));
    ui->box_complexity->setToolTip(s.c_str());
  }
  {
    const std::string s = "Formeel uitgangspunt: "
      + boost::lexical_cast<std::string>(pvdb::Rating::SuggestConcreteness(m_sub_concept_map));
    ui->box_concreteness->setToolTip(s.c_str());
  }
  {
    const std::string s = "Formeel uitgangspunt: "
      + boost::lexical_cast<std::string>(pvdb::Rating::SuggestSpecificity(m_sub_concept_map));
    ui->box_specificity->setToolTip(s.c_str());
  }

  //Center the dialog
  {
    const QRect screen = QApplication::desktop()->screenGeometry();
    this->setGeometry(screen.adjusted(64,64,-64,-64));
    this->move( screen.center() - this->rect().center() );
  }
}

QtPvdbRateConceptDialog::~QtPvdbRateConceptDialog()
{
  delete ui;
}

void QtPvdbRateConceptDialog::keyPressEvent(QKeyEvent* e)
{
  if (e->key()  == Qt::Key_Escape) { close(); return; }
  QDialog::keyPressEvent(e);
}

void QtPvdbRateConceptDialog::on_button_ok_clicked()
{
  //Change concept
  assert(m_concept);
  assert(ui->box_complexity->currentIndex() >= -1);
  assert(ui->box_complexity->currentIndex() <=  2);

  m_concept->SetRatingComplexity(ui->box_complexity->currentIndex());
  m_concept->SetRatingConcreteness(ui->box_concreteness->currentIndex());
  m_concept->SetRatingSpecificity(ui->box_specificity->currentIndex());
  close();
}

#ifndef NDEBUG
void QtPvdbRateConceptDialog::Test()
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  #ifdef COMPILER_SUPPORTS_THREADS_20130507
  std::thread t(
    []
    {
  #endif
  {
    const boost::shared_ptr<pvdb::ConceptMap> concept_map
      = pvdb::ConceptMapFactory::GetHeteromorphousTestConceptMaps().at(15);
    assert(concept_map);
    const boost::shared_ptr<pvdb::Concept> concept = concept_map->GetNodes().at(0)->GetConcept();
    assert(concept);
    const boost::shared_ptr<pvdb::Concept> old_concept = pvdb::ConceptFactory::DeepCopy(concept);
    assert(old_concept);
    assert(concept == old_concept);
    QtPvdbRateConceptDialog d(concept_map);
    assert(concept->GetRatingComplexity() == d.ui->box_complexity->currentIndex());
    assert(concept->GetRatingConcreteness() == d.ui->box_concreteness->currentIndex());
    assert(concept->GetRatingSpecificity() == d.ui->box_specificity->currentIndex());
    //Change a box
    d.ui->box_complexity->setCurrentIndex( (d.ui->box_complexity->currentIndex() + 1) % 3);
    //But do not click OK
    assert(concept == old_concept && "Without clicking OK, QtPvdbRateConceptDialog must not change the concept");
  }
  {
    const boost::shared_ptr<pvdb::ConceptMap> concept_map
      = pvdb::ConceptMapFactory::GetHeteromorphousTestConceptMaps().at(15);
    assert(concept_map);
    const boost::shared_ptr<pvdb::Concept> concept = concept_map->GetNodes().at(0)->GetConcept();
    assert(concept);
    const boost::shared_ptr<const pvdb::Concept> old_concept = pvdb::ConceptFactory::DeepCopy(concept);
    assert(old_concept);
    assert(concept == old_concept);
    QtPvdbRateConceptDialog d(concept_map);
    assert(concept->GetRatingComplexity()   == d.ui->box_complexity->currentIndex());
    assert(concept->GetRatingConcreteness() == d.ui->box_concreteness->currentIndex());
    assert(concept->GetRatingSpecificity()  == d.ui->box_specificity->currentIndex());
    //Change a box
    d.ui->box_complexity->setCurrentIndex( (d.ui->box_complexity->currentIndex() + 1) % 3);
    d.ui->button_ok->click();
    assert(concept != old_concept && "QtPvdbRateConceptDialog must change the concept when clicked OK");
  }
  #ifdef COMPILER_SUPPORTS_THREADS_20130507
    }
  );
  t.detach();
  #endif
}
#endif

void QtPvdbRateConceptDialog::on_button_tally_relevancies_clicked()
{
  QtPvdbRateConceptAutoDialog d(m_sub_concept_map);
  this->ShowChild(&d);
}
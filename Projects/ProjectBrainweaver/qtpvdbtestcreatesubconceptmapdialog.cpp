#include "qtpvdbtestcreatesubconceptmapdialog.h"

#include <cassert>
#include <boost/numeric/conversion/cast.hpp>
#include "pvdbconceptmapfactory.h"
#include "pvdbconceptmap.h"
#include "qtpvdbconceptmapdisplaywidget.h"
#include "ui_qtpvdbtestcreatesubconceptmapdialog.h"

QtPvdbTestCreateSubConceptMapDialog::QtPvdbTestCreateSubConceptMapDialog(QWidget *parent) :
  QtHideAndShowDialog(parent),
  ui(new Ui::QtPvdbTestCreateSubConceptMapDialog)
{
  ui->setupUi(this);
  #ifndef NDEBUG
  Test();
  #endif
  const int n_tests = boost::numeric_cast<int>(pvdb::ConceptMapFactory::GetAllTests().size());
  ui->box_index->setMaximum(n_tests - 1); //-1: 0-based counting

  QObject::connect(ui->box_index,SIGNAL(valueChanged(int)),this,SLOT(OnConceptMapChanged()));
  QObject::connect(ui->box_index_sub,SIGNAL(valueChanged(int)),this,SLOT(OnSubConceptMapChanged()));

  OnConceptMapChanged();
  OnSubConceptMapChanged();
}

QtPvdbTestCreateSubConceptMapDialog::~QtPvdbTestCreateSubConceptMapDialog()
{
  delete ui;
}

void QtPvdbTestCreateSubConceptMapDialog::OnConceptMapChanged()
{
  const int i = ui->box_index->value();
  const std::vector<boost::shared_ptr<pvdb::ConceptMap> > v = pvdb::ConceptMapFactory::GetAllTests();
  assert(i < boost::numeric_cast<int>(v.size()));
  assert(v[i]);
  const boost::shared_ptr<pvdb::ConceptMap> concept_map = v[i];
  assert(concept_map);

  if(!ui->widget_concept_map->layout())
  {
    QLayout * const my_layout = new QVBoxLayout;
    ui->widget_concept_map->setLayout(my_layout);
  }

  assert(ui->widget_concept_map->layout());
  m_concept_map.reset(new QtPvdbConceptMapDisplayWidget(concept_map));
  ui->widget_concept_map->layout()->addWidget(m_concept_map.get());

  const std::vector<boost::shared_ptr<pvdb::ConceptMap> > subs = concept_map->CreateSubs();
  const int n_subs = boost::numeric_cast<int>(subs.size());
  assert(n_subs != 0);
  ui->box_index_sub->setMaximum(n_subs - 1); //-1: 0-based counting
  ui->box_index_sub->setValue(0);
}

void QtPvdbTestCreateSubConceptMapDialog::OnSubConceptMapChanged()
{
  const int i = ui->box_index->value();
  const std::vector<boost::shared_ptr<pvdb::ConceptMap> > v = pvdb::ConceptMapFactory::GetAllTests();
  assert(i < boost::numeric_cast<int>(v.size()));
  const boost::shared_ptr<pvdb::ConceptMap> concept_map = v[i];
  const std::vector<boost::shared_ptr<pvdb::ConceptMap> > subs = concept_map->CreateSubs();
  const int j = ui->box_index_sub->value();
  assert(j < boost::numeric_cast<int>(subs.size()));
  const boost::shared_ptr<pvdb::ConceptMap> sub = subs[j];

  if(!ui->widget_sub_concept_map->layout())
  {
    QLayout * const my_layout = new QVBoxLayout;
    ui->widget_sub_concept_map->setLayout(my_layout);
  }

  assert(ui->widget_sub_concept_map->layout());
  m_sub_concept_map.reset(new QtPvdbConceptMapDisplayWidget(sub));
  ui->widget_sub_concept_map->layout()->addWidget(m_sub_concept_map.get());
}


#ifndef NDEBUG
void QtPvdbTestCreateSubConceptMapDialog::Test()
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  QtPvdbTestCreateSubConceptMapDialog d;
  const int max = d.ui->box_index->maximum();
  for (int i=0; i!=max; ++i)
  {
    d.ui->box_index->setValue(i);

    const int max_sub = d.ui->box_index_sub->maximum();
    for (int j=0; j!=max_sub; ++j)
    {
      d.ui->box_index_sub->setValue(j);
    }
  }
}
#endif

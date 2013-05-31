#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtpvdbconceptmapdialog.h"

#include <cassert>
#include <boost/lambda/lambda.hpp>

#include <QDesktopWidget>
#include <QFileDialog>
#include <QKeyEvent>
#include <QLabel>
#include <QMessageBox>
#include <QPrintDialog>
#include <QPrinter>

#include "pvdbcluster.h"
#include "pvdbconcept.h"
#include "pvdbconceptmapfactory.h"
#include "pvdbconceptmap.h"
#include "pvdbedge.h"
#include "pvdbfile.h"
#include "pvdbnode.h"
#include "qtpvdbconcepteditdialog.h"
#include "qtpvdbconceptmapitem.h"
#include "qtpvdbedgeitem.h"
#include "qtpvdbprintconceptmapdialog.h"
#include "qtpvdbnodeitem.h"
#include "qtscopeddisable.h"
#include "trace.h"
#include "ui_qtpvdbconceptmapdialog.h"

QtPvdbConceptMapDialog::QtPvdbConceptMapDialog(
  const boost::shared_ptr<pvdb::File> file,
  QWidget *parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtPvdbConceptMapDialog),
    m_back_to_menu(false),
    m_file(file)
{
  ui->setupUi(this);
  #ifndef NDEBUG
  Test();
  assert(file);
  assert(m_file);
  assert(IsEqual(*file,*m_file));
  #endif

  //If user has added one Node at least, put it in the widget
  if (m_file->GetConceptMap()->GetNodes().size() > 1)
  {
    //TRACE("User supplied a filled-in concept map");
    assert(GetWidget());
    assert(m_file->GetConceptMap());
    GetWidget()->ReadFromConceptMap(m_file->GetConceptMap());

    assert(
      pvdb::ConceptMap::HasSameContent(
        m_file->GetConceptMap(),GetWidget()->WriteToConceptMap()));
  }
  //Read the concept map
  else if (!m_file->GetCluster()->Empty())
  {
    //TRACE("User supplied a filled-in cluster");
    assert(m_file->GetCluster());
    const boost::shared_ptr<pvdb::ConceptMap> concept_map(
      pvdb::ConceptMapFactory::CreateFromCluster(
        m_file->GetConceptMap()->GetQuestion(),
        m_file->GetCluster()
      )
    );

    assert(concept_map);

    assert((m_file->GetCluster()->Get().size() + 1)
      == (concept_map->GetNodes().size())
      && "As much cluster items as nodes + focus question");


    m_file->SetConceptMap(concept_map);
    assert(m_file->GetConceptMap());
    assert(m_file->GetConceptMap()->GetNodes().size() >= 1);

    GetWidget()->ReadFromConceptMap(m_file->GetConceptMap());
  }
  //Create a concept map from the single-node concept map
  else
  {
    //TRACE("User starts constructing a concept map from scratch");
    assert(GetWidget());
    assert(m_file->GetConceptMap());
    GetWidget()->ReadFromConceptMap(m_file->GetConceptMap());

    assert(
      pvdb::ConceptMap::HasSameContent(
        m_file->GetConceptMap(),GetWidget()->WriteToConceptMap()));
  }
  assert(m_file);
  assert(m_file->GetConceptMap());
  assert(ui);
  assert(ui->widget);
  assert(GetWidget());

  //Put the question in the concept map
  assert(m_file->GetConceptMap()->GetQuestion() == m_file->GetConceptMap()->GetQuestion());
  GetWidget()->ReadFromConceptMap(m_file->GetConceptMap());

  //Center the dialog
  {
    const QRect screen = QApplication::desktop()->screenGeometry();
    this->setGeometry(screen.adjusted(64,64,-64,-64));
    this->move( screen.center() - this->rect().center() );
  }

  ui->widget->m_signal_conceptmapitem_requests_edit.connect(
    boost::bind(
      &QtPvdbConceptMapDialog::OnConceptMapItemRequestsEdit,
      this,boost::lambda::_1));
}

QtPvdbConceptMapDialog::~QtPvdbConceptMapDialog()
{
  delete ui;
}


void QtPvdbConceptMapDialog::DoRandomStuff()
{
  assert(pvdb::ConceptMap::HasSameContent(
    this->m_file->GetConceptMap(),
    this->GetWidget()->WriteToConceptMap()));

  //Do random stuff
  this->GetWidget()->DoRandomStuff();

  assert(!pvdb::ConceptMap::HasSameContent(
      this->m_file->GetConceptMap(),
      this->GetWidget()->WriteToConceptMap()));

  const boost::shared_ptr<pvdb::ConceptMap> concept_map
    = this->GetWidget()->WriteToConceptMap();
  m_file->SetConceptMap(concept_map);

  assert(pvdb::ConceptMap::HasSameContent(
      this->m_file->GetConceptMap(),
      this->GetWidget()->WriteToConceptMap()));

  assert(m_file->GetConceptMap()->GetNodes().size() > 1);
  assert(!m_file->GetConceptMap()->GetEdges().empty());
}

const QtPvdbConceptMapWidget * QtPvdbConceptMapDialog::GetWidget() const
{
  assert(ui);
  assert(ui->widget);
  return ui->widget;
}

QtPvdbConceptMapWidget * QtPvdbConceptMapDialog::GetWidget()
{
  //Calls the const version of operator[]
  //To avoid duplication in const and non-const member functions [1]
  return const_cast<QtPvdbConceptMapWidget*>(
    const_cast<const QtPvdbConceptMapDialog*>(this)->GetWidget());
}

void QtPvdbConceptMapDialog::keyPressEvent(QKeyEvent* e)
{
  if (e->key()  == Qt::Key_Escape) { close(); return; }
  if ((e->modifiers() & Qt::ControlModifier) && e->key() == Qt::Key_S) { on_button_save_clicked(); return; }
  if ((e->modifiers() & Qt::ControlModifier)
    && !(e->modifiers() & Qt::ShiftModifier)
    && e->key() == Qt::Key_Z)
  {
    QMessageBox box;
    box.setText("TODO: Undo");
    box.exec();
    return;
  }
  if ( (e->modifiers() & Qt::ControlModifier)
    && (e->modifiers() & Qt::ShiftModifier)
    && e->key() == Qt::Key_Z)
  {
    QMessageBox box;
    box.setText("TODO: Redo");
    box.exec();
    return;
  }

  QDialog::keyPressEvent(e);
}

void QtPvdbConceptMapDialog::on_button_print_clicked()
{
  Save();
  QtPvdbPrintConceptMapDialog d(this->m_file);
  this->ShowChild(&d);
}

void QtPvdbConceptMapDialog::OnConceptMapItemRequestsEdit(QtPvdbConceptMapItem* const item)
{
  assert(item);
  {
    assert(this);
    assert(item);
    assert(item->GetConcept());
    QtPvdbConceptEditDialog d(item->GetConcept());
    this->ShowChild(&d);
  }
  //item->GetConcept()->m_signal_examples_changed(item->GetConcept().get()); //NEW 2013-01-08 21:40
  item->m_signal_item_has_updated(item);
  item->update();
}

void QtPvdbConceptMapDialog::on_button_save_clicked()
{
  //Temporarily disable to widget, otherwise saving cannot succeed
  const QtScopedDisable<QtPvdbConceptMapWidget> scoped_disable1(GetWidget());
  const QtScopedDisable<QtPvdbConceptMapDialog> scoped_disable2(this);
  this->hide();
  const std::string filter_str = std::string("*.") + pvdb::File::GetFilenameExtension();
  const std::string filename_raw = QFileDialog::getSaveFileName(0,"Sla de concept map op",
    QString(),
    filter_str.c_str()).toStdString();
  if (!filename_raw.empty())
  {
    const std::string filename
      =  (filename_raw.size() < pvdb::File::GetFilenameExtension().size()
        || filename_raw.substr( filename_raw.size() - 3, 3 ) != pvdb::File::GetFilenameExtension()
       ? filename_raw + std::string(".") + pvdb::File::GetFilenameExtension()
       : filename_raw);
    assert(filename.size() > 3
      && filename.substr( filename.size() - 3, 3 ) == pvdb::File::GetFilenameExtension()
      && "File must have correct file extension name");
    Save(filename);
    //this->m_back_to_menu = true; //2013-04-19 Request by client
    //close(); //2013-04-19 Request by client
  }
  else
  {
    this->show();
  }
}

void QtPvdbConceptMapDialog::Save() const
{
  const boost::shared_ptr<pvdb::ConceptMap> concept_map = GetWidget()->WriteToConceptMap();
  assert(concept_map);
  assert(m_file);
  m_file->SetConceptMap(concept_map);
}

void QtPvdbConceptMapDialog::Save(const std::string& filename) const
{
  assert(filename.size() > 3
    && filename.substr( filename.size() - 3, 3 ) == pvdb::File::GetFilenameExtension()
    && "File must have correct file extension name");
  Save();
  m_file->Save(filename);
}

void QtPvdbConceptMapDialog::Shuffle()
{
  this->GetWidget()->Shuffle();
}

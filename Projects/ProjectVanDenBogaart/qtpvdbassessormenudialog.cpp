#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtpvdbassessormenudialog.h"

#include <QFileDialog>
#include <QKeyEvent>

#include "qtpvdbaboutdialog.h"
//#include "pvdbmenudialog.h"
#include "qtpvdbrateconceptdialog.h"
#include "qtpvdbcreateassessmentcompletedialog.h"
#include "qtpvdbcreateassessmentmenudialog.h"
#include "qtpvdbrateconceptmapdialog.h"
#include "trace.h"


#include "ui_qtpvdbassessormenudialog.h"


QtPvdbAssessorMenuDialog::QtPvdbAssessorMenuDialog(QWidget* parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtPvdbAssessorMenuDialog)
{
  ui->setupUi(this);
}

QtPvdbAssessorMenuDialog::~QtPvdbAssessorMenuDialog()
{
  delete ui;
}

void QtPvdbAssessorMenuDialog::keyPressEvent(QKeyEvent* e)
{
  if (e->key()  == Qt::Key_Escape) { close(); return; }
}

void QtPvdbAssessorMenuDialog::on_button_create_assessment_clicked()
{
  QtPvdbCreateAssessmentMenuDialog d;
  this->ShowChild(&d);
}


void QtPvdbAssessorMenuDialog::on_button_about_clicked()
{
  const auto d(QtPvdbAboutDialog::Get());
  this->hide();
  d->exec();
  this->show();
}

void QtPvdbAssessorMenuDialog::on_button_quit_clicked()
{
  close();
}

void QtPvdbAssessorMenuDialog::on_button_assess_result_clicked()
{

  //Load file
  const std::string filter_str = std::string("*.") + pvdb::File::GetFilenameExtension();
  const std::string filename
    = QFileDialog::getOpenFileName(0,"Kies een assessment bestand",QString(),
      filter_str.c_str()).toStdString();
  if (!filename.empty())
  {
    const boost::shared_ptr<pvdb::File> file(pvdb::File::Load(filename));
    assert(file);
    QtPvdbRateConceptMapDialog d(file);
    this->ShowChild(&d);
  }
}

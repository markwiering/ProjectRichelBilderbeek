#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorPperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtkalmanfilterermenudialog.h"

#include <QDesktopWidget>
#include <QKeyEvent>

#include "kalmanfilterermenudialog.h"
#include "kalmanfilterexample.h"
#include "matrix.h"
#include "qtaboutdialog.h"
#include "qthideandshowdialog.h"
#include "qtkalmanfilterermaindialog.h"
#include "qtmatrix.h"
#include "qtstdvectorfunctionmodel.h"
#include "qtstdvectorstringmodel.h"
#include "qtublasmatrixdoublemodel.h"
#include "qtublasvectordoublemodel.h"
#include "qtwhitenoisesystemparametersdialog.h"
#include "standardwhitenoisesystemparameters.h"
#include "trace.h"
#include "ui_qtkalmanfilterermenudialog.h"

QtKalmanFiltererMenuDialog::QtKalmanFiltererMenuDialog(QWidget *parent) :
    QtHideAndShowDialog(parent),
    ui(new Ui::QtKalmanFiltererMenuDialog)
{
  ui->setupUi(this);
  #ifndef NDEBUG
  Test();
  #endif
}

QtKalmanFiltererMenuDialog::~QtKalmanFiltererMenuDialog()
{
  delete ui;
}

void QtKalmanFiltererMenuDialog::changeEvent(QEvent *e)
{
  QDialog::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}

void QtKalmanFiltererMenuDialog::keyPressEvent(QKeyEvent * event)
{
  if (event->key() == Qt::Key_Escape) { close(); return; }
}

void QtKalmanFiltererMenuDialog::on_button_about_clicked()
{
  About a = KalmanFiltererMenuDialog::GetAbout();
  a.AddLibrary("QtHideAndShowDialog version: " + QtHideAndShowDialog::GetVersion());
  a.AddLibrary("QtMatrix version: " + QtMatrix::GetVersion());
  a.AddLibrary("QtStdVectorFunctionModel version: " + QtStdVectorFunctionModel::GetVersion());
  a.AddLibrary("QtStdVectorStringModel version: " + QtStdVectorStringModel::GetVersion());
  a.AddLibrary("QtUblasMatrixDoubleModel version: " + QtUblasMatrixDoubleModel::GetVersion());
  a.AddLibrary("QtUblasVectorDoubleModel version: " + QtUblasVectorDoubleModel::GetVersion());
  QtAboutDialog d(a);
  d.setWindowIcon(this->windowIcon());
  d.setStyleSheet(this->styleSheet());
  this->hide();
  d.exec();
  this->show();
}

void QtKalmanFiltererMenuDialog::on_button_quit_clicked()
{
  close();
}

void QtKalmanFiltererMenuDialog::on_button_start_clicked()
{
  const boost::shared_ptr<QtKalmanFiltererMainDialog> d = QtKalmanFiltererMainDialog::Create();
  assert(d);
  ShowChild(d.get());
}

#ifndef NDEBUG
void QtKalmanFiltererMenuDialog::Test()
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  {
    Matrix::Test();
    QtMatrix::Test();
    TRACE("Starting QtKalmanFiltererMenuDialog::Test()")
    const boost::shared_ptr<QtKalmanFiltererMainDialog> d = QtKalmanFiltererMainDialog::Create();
    assert(d);
    TRACE("Finished QtKalmanFiltererMenuDialog::Test()")
  }
}
#endif

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorPperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtkalmanfiltererparameterdialog.h"

#include <cassert>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <boost/lexical_cast.hpp>
#pragma GCC diagnostic pop

#include <QKeyEvent>
#include <QTableWidgetItem>

#include "fixedlagsmootherkalmanfilter.h"
#include "kalmanfilterexperimentparameter.h"
#include "kalmanfilterparameter.h"
#include "kalmanfilterparametertype.h"
#include "matrix.h"
#include "qtmatrix.h"
#include "kalmanfilterexperimentparameter.h"
#include "whitenoisesystemparameter.h"
#include "qtkalmanfilterermodel.h"
#include "qtublasmatrixdoublemodel.h"
#include "qtublasvectordoublemodel.h"
#include "qtstdvectorfunctionmodel.h"

#include "qtstdvectorstringmodel.h"
#include "standardkalmanfilter.h"
#include "standardkalmanfilterfactory.h"
#include "steadystatekalmanfilter.h"
#include "qtkalmanfilterexperimentdialog.h"
#include "steadystatekalmanfilterfactory.h"
#include "trace.h"
#include "ui_qtkalmanfiltererparameterdialog.h"

QtKalmanFiltererParameterDialog::QtKalmanFiltererParameterDialog(
  const std::string& parameter_name,
  const std::string& parameter_description,
  QAbstractTableModel * const model,
  QWidget *parent)
  : QDialog(parent),
    ui(new Ui::QtKalmanFiltererParameterDialog)
{
  

  ui->setupUi(this);
  this->setFocusPolicy(Qt::NoFocus);
  
  ui->table->setModel(model);
  ui->label->setText(parameter_name.c_str());
  this->setToolTip(parameter_description.c_str());

  ui->table->setAlternatingRowColors(true);
  ui->table->setWordWrap(false);

  //ui->table->horizontalHeader()->setResizeMode(QHeaderView::ResizeToContents);
  //ui->table->verticalHeader()->setResizeMode(QHeaderView::ResizeToContents);
  QObject::connect(ui->table->model(),SIGNAL(layoutChanged()),
    this,SLOT(OnModelSizeChanged()));
}

QtKalmanFiltererParameterDialog::~QtKalmanFiltererParameterDialog()
{
  delete ui;
}

void QtKalmanFiltererParameterDialog::keyPressEvent(QKeyEvent * event)
{
  if (event->key() == Qt::Key_Escape) return;
  QDialog::keyPressEvent(event);
}

const std::string QtKalmanFiltererParameterDialog::ToHtml() const
{
  std::string s;
  s+="<table summary=\"" + ui->label->text().toStdString() + "\" border=\"1\">";
  const int n_cols = ui->table->model()->columnCount();
  const int n_rows = ui->table->model()->rowCount();
  for (int row = 0; row!=n_rows; ++row)
  {
    s +="<tr>";
    for (int col = 0; col!=n_cols; ++col)
    {
      s +="<td>";
      const QModelIndex index = ui->table->model()->index(row,col);
      const QString q = ui->table->model()->data(index).toString();
      s += q.toStdString();
      s +="</td>";
    }
    s +="</tr>";
  }
  s += "</table>";
  return s;
}

void QtKalmanFiltererParameterDialog::OnModelSizeChanged()
{
  ui->table->resizeColumnsToContents();
  ui->table->resizeRowsToContents();
  ui->table->update();
  ui->table->repaint();
  //Set height
  {
    const int scrollbar_height = 16;
    int height
      = ui->table->horizontalHeader()->height()
      + (2 * ui->table->frameWidth())
      + scrollbar_height;
    const int n_rows = ui->table->model()->rowCount();
    for (int i=0; i!=n_rows; ++i)
    {
      height += ui->table->rowHeight(i);
    }
    ui->table->setMinimumHeight(height);
    ui->table->setMaximumHeight(height);
  }
  #ifdef FOUND_OUT_HOW_THIS_WORKS_CORRECTLY_782346928497284639876487987698742362571101928364
  //Set width
  {
    const int scrollbar_width = 100; //0; //16;
    int width
      = ui->table->verticalHeader()->geometry().width()
      + (2 * ui->table->frameWidth())
      + scrollbar_width;
    const int n_cols = ui->table->model()->columnCount();
    for (int i=0; i!=n_cols; ++i)
    {
      width += std::max(
        ui->table->columnWidth(i),
        ui->table->horizontalHeader()->sectionSize(i));
    }
    ui->table->setMinimumWidth(width);
    ui->table->setMaximumWidth(width);
  }
  #endif
}

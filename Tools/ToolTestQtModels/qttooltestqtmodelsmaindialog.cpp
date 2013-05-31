//---------------------------------------------------------------------------
/*
TestQtModels, tool to test the QtModel classes
Copyright (C) 2013 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ToolTestQtModels.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qttooltestqtmodelsmaindialog.h"

#include <cassert>

#include <boost/lexical_cast.hpp>

#include <QKeyEvent>

#include "qtublasmatrixdoublemodel.h"
#include "qtublasvectordoublemodel.h"
#include "qtstdvectorfunctionmodel.h"
#include "qtstdvectorstringmodel.h"
#include "trace.h"
#include "ui_qttooltestqtmodelsmaindialog.h"

QtToolTestQtModelsMainDialog::QtToolTestQtModelsMainDialog(QWidget *parent) :
  QtHideAndShowDialog(parent),
  ui(new Ui::QtToolTestQtModelsMainDialog)
{
  ui->setupUi(this);
}

QtToolTestQtModelsMainDialog::~QtToolTestQtModelsMainDialog()
{
  delete ui;
}

const std::string QtToolTestQtModelsMainDialog::CreateRandomText()
{
  const int sz = (std::rand() >> 4) % 10;
  std::string s;
  for (int i=0; i!=sz; ++i)
  {
    const std::string t = boost::lexical_cast<std::string,char>('a' + std::rand() % 26);
    s += t;
  }
  return s;
}

const std::vector<std::string> QtToolTestQtModelsMainDialog::CreateRandomTexts()
{
  const int sz = (std::rand() >> 4) % 10;
  std::vector<std::string> v;
  for (int i=0; i!=sz; ++i)
  {
    const std::string s = CreateRandomText();
    v.push_back(s);
  }
  return v;
}

void QtToolTestQtModelsMainDialog::keyPressEvent(QKeyEvent * event)
{
  if (event->key() == Qt::Key_Escape) { close(); return; }
}

void QtToolTestQtModelsMainDialog::on_button_data_clicked()
{
  const int index = ui->box_type->currentIndex();
  switch (index)
  {
    case 0:
    {
      typedef QtStdVectorStringModel Model;
      Model * const model
        = dynamic_cast<Model *>(ui->table->model())
        ? dynamic_cast<Model *>(ui->table->model())
        : new Model;
      std::vector<std::string> v = CreateRandomTexts();
      model->SetRawData(v);
      ui->table->setModel(model);
    }
    break;
    case 1:
    {
      const std::string variable = "x";
      typedef QtStdVectorFunctionModel Model;
      Model * const model
        = dynamic_cast<Model *>(ui->table->model())
        ? dynamic_cast<Model *>(ui->table->model())
        : new Model(variable);
      const int sz = (std::rand() >> 4) % 10;
      std::vector<std::string> v;
      for (int i=0; i!=sz; ++i)
      {
        const std::string s
          = boost::lexical_cast<std::string>(i)
          + " * " + variable;
        v.push_back(s);
      }
      model->SetRawData(v);
      ui->table->setModel(model);
    }
    break;
    case 2:
    {
      typedef QtUblasMatrixDoubleModel Model;
      Model * const model
        = dynamic_cast<Model *>(ui->table->model())
        ? dynamic_cast<Model *>(ui->table->model())
        : new Model;
      const int n_cols = (std::rand() >> 4) % 10;
      const int n_rows = (std::rand() >> 4) % 10;
      boost::numeric::ublas::matrix<double> m(n_rows,n_cols);
      for (int row=0; row!=n_rows; ++row)
      {
        for (int col=0; col!=n_cols; ++col)
        {
          const double x = boost::numeric_cast<double>(std::rand());
          m(row,col) = x;
        }
      }
      model->SetRawData(m);
      ui->table->setModel(model);
    }
    break;
    case 3:
    {
      typedef QtUblasVectorDoubleModel Model;
      Model * const model
        = dynamic_cast<Model *>(ui->table->model())
        ? dynamic_cast<Model *>(ui->table->model())
        : new Model;
      const int sz = (std::rand() >> 4) % 10;
      boost::numeric::ublas::vector<double> v(sz);
      for (int i=0; i!=sz; ++i)
      {
        const double x = boost::numeric_cast<double>(std::rand());
        v(i) = x;
      }
      model->SetRawData(v);
      ui->table->setModel(model);
    }
    break;
  }

}

void QtToolTestQtModelsMainDialog::on_button_headers_clicked()
{

  const int index = ui->box_type->currentIndex();
  switch (index)
  {
    case 0:
    {
      typedef QtStdVectorStringModel Model;
      Model * const model
        = dynamic_cast<Model *>(ui->table->model())
        ? dynamic_cast<Model *>(ui->table->model())
        : new Model;
      const std::string h = CreateRandomText();
      const std::vector<std::string> v = CreateRandomTexts();
      model->SetHeaderData(h,v);
      ui->table->setModel(model);
    }
    break;
    case 1:
    {
      const std::string variable = "x";
      typedef QtStdVectorFunctionModel Model;
      Model * const model
        = dynamic_cast<Model *>(ui->table->model())
        ? dynamic_cast<Model *>(ui->table->model())
        : new Model(variable);
      const std::string h = CreateRandomText();
      const std::vector<std::string> v = CreateRandomTexts();
      model->SetHeaderData(h,v);
      ui->table->setModel(model);
    }
    break;
    case 2:
    {
      typedef QtUblasMatrixDoubleModel Model;
      Model * const model
        = dynamic_cast<Model *>(ui->table->model())
        ? dynamic_cast<Model *>(ui->table->model())
        : new Model;
      const std::vector<std::string> v = CreateRandomTexts();
      const std::vector<std::string> w = CreateRandomTexts();
      model->SetHeaderData(v,w);
      ui->table->setModel(model);
    }
    break;
    case 3:
    {
      typedef QtUblasVectorDoubleModel Model;
      Model * const model
        = dynamic_cast<Model *>(ui->table->model())
        ? dynamic_cast<Model *>(ui->table->model())
        : new Model;
      const std::string h = CreateRandomText();
      const std::vector<std::string> v = CreateRandomTexts();
      model->SetHeaderData(h,v);
      ui->table->setModel(model);
    }
    break;
  }
}
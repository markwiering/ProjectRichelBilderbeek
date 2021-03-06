//---------------------------------------------------------------------------
/*
TestShape, tool to test the Shape and ShapeWidget classes
Copyright (C) 2011 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTestShape.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qttestshapemenudialog.h"

#include "about.h"
#include "qtaboutdialog.h"
#include "qtshapewidget.h"
#include "qttestshapemaindialog.h"
#include "shape.h"
#include "shapewidget.h"
#include "testshapemenudialog.h"
#include "ui_qttestshapemenudialog.h"

QtTestShapeMenuDialog::QtTestShapeMenuDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtTestShapeMenuDialog),
  m_dialog(new TestShapeMenuDialog)
{
  ui->setupUi(this);
  #ifndef NDEBUG
  Test();
  #endif
}

QtTestShapeMenuDialog::~QtTestShapeMenuDialog()
{
  delete ui;
}

void QtTestShapeMenuDialog::on_button_start_clicked()
{
  hide();
  QtTestShapeMainDialog d;
  d.exec();
  show();
}

void QtTestShapeMenuDialog::on_button_about_clicked()
{
  hide();
  About a = m_dialog->GetAbout();
  a.AddLibrary("QtShapeWidget version: " + QtShapeWidget::GetVersion());
  QtAboutDialog d(a);
  d.exec();
  show();
}

void QtTestShapeMenuDialog::on_button_quit_clicked()
{
  close();
}

void QtTestShapeMenuDialog::Test()
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  {
    const QtTestShapeMainDialog d;
  }
  {
    const TestShapeMenuDialog d;
  }
}



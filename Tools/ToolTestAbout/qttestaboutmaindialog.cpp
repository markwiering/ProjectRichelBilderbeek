//---------------------------------------------------------------------------
/*
TestAbout, tests the About classes
Copyright (C) 2012 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTestAbout.htm
//---------------------------------------------------------------------------
#include "qtaboutdialog.h"
#include "qttestaboutmaindialog.h"
#include "ui_qttestaboutmaindialog.h"
//---------------------------------------------------------------------------
QtTestAboutMainDialog::QtTestAboutMainDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtTestAboutMainDialog)
{
  ui->setupUi(this);
}
//---------------------------------------------------------------------------
QtTestAboutMainDialog::~QtTestAboutMainDialog()
{
  delete ui;
}
//---------------------------------------------------------------------------
const std::string QtTestAboutMainDialog::GetVersion()
{
  return "1.0";
}
//---------------------------------------------------------------------------
const std::vector<std::string> QtTestAboutMainDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2012-01-25: Version 1.0: initial version");
  return v;
}
//---------------------------------------------------------------------------
void QtTestAboutMainDialog::on_button_about_clicked()
{
  About a(
    "Richel Bilderbeek",
    "TestAbout",
    "test the About classes",
    "the 25th of January 2012",
    "2012",
    "http://www.richelbilderbeek.nl/ToolTestAbout.htm",
    GetVersion(),
    GetVersionHistory());
  //a.AddLibrary("SomeLibrary version: X.Y");
  QtAboutDialog d(a);
  this->hide();
  d.exec();
  this->show();
}
//---------------------------------------------------------------------------
void QtTestAboutMainDialog::on_button_quit_clicked()
{
  close();
}
//---------------------------------------------------------------------------
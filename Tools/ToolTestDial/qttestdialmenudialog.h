//---------------------------------------------------------------------------
/*
TestDial, tool to test the Dial and DialWidget classes
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
//From http://www.richelbilderbeek.nl/ToolTestDial.htm
//---------------------------------------------------------------------------
#ifndef QTTESTDIALMENUDIALOG_H
#define QTTESTDIALMENUDIALOG_H

#include <QDialog>

namespace Ui {
class QtTestDialMenuDialog;
}

class QtTestDialMenuDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtTestDialMenuDialog(QWidget *parent = 0);
  ~QtTestDialMenuDialog();

private slots:
  void on_button_start_clicked();
  void on_button_about_clicked();
  void on_button_quit_clicked();

private:
  Ui::QtTestDialMenuDialog *ui;

  ///Test this class
  void Test();
};

#endif // QTTESTDIALMENUDIALOG_H

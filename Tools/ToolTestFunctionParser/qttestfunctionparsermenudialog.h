//---------------------------------------------------------------------------
/*
TestFunctionParser, tool to demonstrate Warp's FunctionParser class
Copyright (C) 2010-2013 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTestFunctionParser.htm
//---------------------------------------------------------------------------
#ifndef QTTESTFUNCTIONPARSERMENUDIALOG_H
#define QTTESTFUNCTIONPARSERMENUDIALOG_H

#include <QDialog>

namespace Ui {
class QtTestFunctionParserMenuDialog;
}

class QtTestFunctionParserMenuDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtTestFunctionParserMenuDialog(QWidget *parent = 0);
  ~QtTestFunctionParserMenuDialog();

private slots:
  void on_button_start_clicked();
  void on_button_about_clicked();
  void on_button_quit_clicked();

private:
  Ui::QtTestFunctionParserMenuDialog *ui;
};

#endif // QTTESTFUNCTIONPARSERMENUDIALOG_H

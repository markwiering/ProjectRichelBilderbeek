//---------------------------------------------------------------------------
/*
TestTwoDigitNewick, tool to test the two-digit-Newick architecture
Copyright (C) 2010-2011 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ToolTestTwoDigitNewick.htm
//---------------------------------------------------------------------------
#ifndef QTTESTTWODIGITNEWICKDIALOG_H
#define QTTESTTWODIGITNEWICKDIALOG_H
//---------------------------------------------------------------------------
#include <QDialog>
//---------------------------------------------------------------------------
namespace Ui {
  class QtTestTwoDigitNewickDialog;
}
//---------------------------------------------------------------------------
class QtTestTwoDigitNewickDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtTestTwoDigitNewickDialog(QWidget *parent = 0);
  ~QtTestTwoDigitNewickDialog();
  static const std::string GetVersion();
  static const std::vector<std::string> GetVersionHistory();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::QtTestTwoDigitNewickDialog *ui;

private slots:
  void on_button_help_clicked();
  void OnAnyChange();
  void OnAboutClick();
};
//---------------------------------------------------------------------------
#endif // QTTESTTWODIGITNEWICKDIALOG_H

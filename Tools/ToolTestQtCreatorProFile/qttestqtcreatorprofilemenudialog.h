//---------------------------------------------------------------------------
/*
TestQtCreatorProFile, tool to test the QtCreatorProFile class
Copyright (C) 2010-2013 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTestQtCreatorProFile.htm
//---------------------------------------------------------------------------
#ifndef QTTESTQTCREATORPROFILEMENUDIALOG_H
#define QTTESTQTCREATORPROFILEMENUDIALOG_H

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#include <QDialog>

namespace Ui {
class QtTestQtCreatorProFileMenuDialog;
}

class QtTestQtCreatorProFileMenuDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtTestQtCreatorProFileMenuDialog(QWidget *parent = 0);
  ~QtTestQtCreatorProFileMenuDialog();

private slots:
  void on_button_start_clicked();
  void on_button_about_clicked();
  void on_button_quit_clicked();

private:
  Ui::QtTestQtCreatorProFileMenuDialog *ui;
};

#endif // QTTESTQTCREATORPROFILEMENUDIALOG_H

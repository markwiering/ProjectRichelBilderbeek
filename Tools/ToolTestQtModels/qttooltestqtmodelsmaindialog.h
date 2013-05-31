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
#ifndef QTTOOLTESTQTMODELSMAINDIALOG_H
#define QTTOOLTESTQTMODELSMAINDIALOG_H

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#include "qthideandshowdialog.h"

namespace Ui {
  class QtToolTestQtModelsMainDialog;
}

class QtToolTestQtModelsMainDialog : public QtHideAndShowDialog
{
  Q_OBJECT
  
public:
  explicit QtToolTestQtModelsMainDialog(QWidget *parent = 0);
  ~QtToolTestQtModelsMainDialog();
  
private slots:
  void keyPressEvent(QKeyEvent *);
  void on_button_data_clicked();
  void on_button_headers_clicked();

private:
  Ui::QtToolTestQtModelsMainDialog *ui;

  static const std::string CreateRandomText();
  static const std::vector<std::string> CreateRandomTexts();
};

#endif // QTTOOLTESTQTMODELSMAINDIALOG_H
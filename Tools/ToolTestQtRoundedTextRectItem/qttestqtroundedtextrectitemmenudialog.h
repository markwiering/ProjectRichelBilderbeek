//---------------------------------------------------------------------------
/*
TestQtRoundedTextRectItem, tool to test QtRoundedTextRectItem
Copyright (C) 2012  Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTestQtRoundedTextRectItem.htm
//---------------------------------------------------------------------------
#ifndef QTTESTQTROUNDEDTEXTRECTITEMMENUDIALOG_H
#define QTTESTQTROUNDEDTEXTRECTITEMMENUDIALOG_H

#include "qthideandshowdialog.h"

namespace Ui {
  class QtTestQtRoundedTextRectItemMenuDialog;
}

class QtTestQtRoundedTextRectItemMenuDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtTestQtRoundedTextRectItemMenuDialog(QWidget *parent = 0);
  ~QtTestQtRoundedTextRectItemMenuDialog();

protected:
  void changeEvent(QEvent *e);
  void keyPressEvent(QKeyEvent * event);

private:
  Ui::QtTestQtRoundedTextRectItemMenuDialog *ui;

private slots:
  void on_button_about_clicked();
  void on_button_quit_clicked();
  void on_button_start_clicked();
};

#endif // QTTESTQTROUNDEDTEXTRECTITEMMENUDIALOG_H

// ---------------------------------------------------------------------------
/*
TestQtArrowItems, tool to test Qt arrow QGraphicsItems
Copyright (C) 2012-2013  Richel Bilderbeek

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
// ---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ToolTestQtArrowItems.htm
// ---------------------------------------------------------------------------
#ifndef QTTESTQTARROWITEMSMAINDIALOG_H
#define QTTESTQTARROWITEMSMAINDIALOG_H

#include <string>
#include <vector>

#include <QDialog>

#include "about.h"
#include "qthideandshowdialog.h"


struct QPlainTextEdit;

namespace Ui {
  class QtTestQtArrowItemsMainDialog;
}

class QtTestQtArrowItemsMainDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtTestQtArrowItemsMainDialog(QWidget *parent = 0);
  ~QtTestQtArrowItemsMainDialog();

protected:
  void keyPressEvent(QKeyEvent *);

private:
  Ui::QtTestQtArrowItemsMainDialog *ui;

  //Obtain a random value from zero to 1.0
  static double GetRandomUniform();

  void OnRequestSceneUpdate();

};

#endif // QTTESTQTARROWITEMSMAINDIALOG_H

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
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qttestqtroundedtextrectitemmaindialog.h"

#include <QKeyEvent>
#include "ui_qttestqtroundedtextrectitemmaindialog.h"

QtTestQtRoundedTextRectItemMainDialog::QtTestQtRoundedTextRectItemMainDialog(QWidget *parent) :
    QtHideAndShowDialog(parent),
    ui(new Ui::QtTestQtRoundedTextRectItemMainDialog)
{
  ui->setupUi(this);
}

QtTestQtRoundedTextRectItemMainDialog::~QtTestQtRoundedTextRectItemMainDialog()
{
  delete ui;
}

void QtTestQtRoundedTextRectItemMainDialog::keyPressEvent(QKeyEvent * event)
{
  if (event->key() == Qt::Key_Escape) { close(); return; }
}


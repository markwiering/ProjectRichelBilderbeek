//---------------------------------------------------------------------------
/*
TestKeyboardFriendlyGraphicsView, tests QtKeyboardFriendlyGraphicsView
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
//From http://www.richelbilderbeek.nl/ToolTestKeyboardFriendlyGraphicsView.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qttestqtkeyboardfriendlygraphicsviewmenudialog.h"

#include <QDesktopWidget>
#include <QKeyEvent>
#include "about.h"
#include "qtaboutdialog.h"
#include "qtarrowitem.h"
#include "qtdisplaypositem.h"
#include "qtleftrightrectitem.h"
#include "qtpatharrowitem.h"
#include "qtquadbezierarrowitem.h"
#include "qtroundedrectitem.h"
#include "qtroundedtextrectitem.h"
#include "qttestqtkeyboardfriendlygraphicsviewwidget.h"
#include "testqtkeyboardfriendlygraphicsviewmenudialog.h"
#include "ui_qttestqtkeyboardfriendlygraphicsviewmenudialog.h"

QtTestKeyboardFriendlyGraphicsViewMenuDialog::QtTestKeyboardFriendlyGraphicsViewMenuDialog(QWidget *parent) :
  QtHideAndShowDialog(parent),
  ui(new Ui::QtTestKeyboardFriendlyGraphicsViewMenuDialog)
{
  ui->setupUi(this);
  {
    typedef QtTestKeyboardFriendlyGraphicsViewWidget Widget;
    Widget * const widget = new Widget;
    widget->m_signal_request_about.connect(
      boost::bind(&QtTestKeyboardFriendlyGraphicsViewMenuDialog::ShowAbout,this));
    widget->m_signal_request_quit.connect(
      boost::bind(&QtTestKeyboardFriendlyGraphicsViewMenuDialog::Quit,this));
    ui->layout->addWidget(widget,0,0);
  }
  //Make this dialog big and centered
  {
    const QRect rect = QDesktopWidget().geometry();
    this->setGeometry(rect.adjusted(64,64,-64,-64));
  }
}

QtTestKeyboardFriendlyGraphicsViewMenuDialog::~QtTestKeyboardFriendlyGraphicsViewMenuDialog()
{
  delete ui;
}

void QtTestKeyboardFriendlyGraphicsViewMenuDialog::keyPressEvent(QKeyEvent* e)
{
  if (e->key()  == Qt::Key_Escape) close();
}

void QtTestKeyboardFriendlyGraphicsViewMenuDialog::ShowAbout()
{
  About about = TestKeyboardFriendlyGraphicsViewMenuDialog::GetAbout();
  about.AddLibrary("QtArrowItem version: " + QtArrowItem::GetVersion());
  about.AddLibrary("QtHideAndShowDialog version: " + QtHideAndShowDialog::GetVersion());
  about.AddLibrary("QtDisplayPosItem version: " + QtDisplayPosItem::GetVersion());
  about.AddLibrary("QtKeyboardFriendlyGraphicsView version: " + QtKeyboardFriendlyGraphicsView::GetVersion());
  about.AddLibrary("QtLeftRightRectItem version: " + QtLeftRightRectItem::GetVersion());
  about.AddLibrary("QtPathArrowItem version: " + QtPathArrowItem::GetVersion());
  about.AddLibrary("QtQuadBezierArrowItem version: " + QtQuadBezierArrowItem::GetVersion());
  about.AddLibrary("QtRoundedRectItem version: " + QtRoundedRectItem::GetVersion());
  about.AddLibrary("QtRoundedTextRectItem version: " + QtRoundedTextRectItem::GetVersion());
  QtAboutDialog d(about);
  d.setWindowIcon(this->windowIcon());
  this->hide();
  d.exec();
  this->show();
}

void QtTestKeyboardFriendlyGraphicsViewMenuDialog::Quit()
{
  close();
}

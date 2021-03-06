//---------------------------------------------------------------------------
/*
MusicTheory, tool for visualizing my music theory
Copyright (C)  2012  Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolMusicTheory.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtmusictheorymenudialog.h"

#include <QDesktopWidget>

#include "musictheorymenudialog.h"
#include "qtaboutdialog.h"
#include "qtchordedge.h"
#include "qtchordrelationswidget.h"
#include "qtchordvertex.h"
#include "qtmultiscalechordrelationswidget.h"
#include "qtmusictheorysinglescaledialog.h"
#include "qtmusictheorymultiscaledialog.h"
#include "ui_qtmusictheorymenudialog.h"

QtMusicTheoryMenuDialog::QtMusicTheoryMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtMusicTheoryMenuDialog)
{
  ui->setupUi(this);
}

QtMusicTheoryMenuDialog::~QtMusicTheoryMenuDialog()
{
  delete ui;
}

void QtMusicTheoryMenuDialog::changeEvent(QEvent *e)
{
  QDialog::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}

void QtMusicTheoryMenuDialog::on_button_about_clicked()
{
  About a = MusicTheoryMenuDialog::GetAbout();
  a.AddLibrary("QtChordEdge version: " + QtChordEdge::GetVersion());
  a.AddLibrary("QtChordVertex version: " + QtChordVertex::GetVersion());
  a.AddLibrary("QtChordRelationsWidget version: " + QtChordRelationsWidget::GetVersion());
  a.AddLibrary("QtMultiScaleChordRelationsWidget version: " + QtMultiScaleChordRelationsWidget::GetVersion());
  QtAboutDialog d(a);

  d.setWindowIcon(this->windowIcon());
  d.setStyleSheet(this->styleSheet());
  this->hide();
  d.exec();
  this->show();
}

void QtMusicTheoryMenuDialog::on_button_quit_clicked()
{
  close();
}

void QtMusicTheoryMenuDialog::on_button_start_singlescale_clicked()
{
  //Make a screenshot
  QPixmap::grabWidget(this,this->window()->rect()).save("ToolMusicTheoryMenuDialog.png");

  QtMusicTheorySingleScaleDialog d;
  this->hide();
  d.exec();
  this->show();
}


void QtMusicTheoryMenuDialog::on_button_start_multiscale_clicked()
{
  QtMusicTheoryMultiScaleDialog d;
  this->hide();
  d.exec();
  this->show();
}

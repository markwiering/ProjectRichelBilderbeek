//---------------------------------------------------------------------------
/*
Boenken. A multiplayer soccer/billiards game.
Copyright (C) 2007-2012 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/GameBoenken.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtboenkenarenadialog.h"

#include <cassert>
#include <stdexcept>

#include <QDesktopWidget>

#include "ui_qtboenkenarenadialog.h"

QtBoenkenArenaDialog::QtBoenkenArenaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtBoenkenArenaDialog)
{
  ui->setupUi(this);
  QObject::connect(ui->button_done,SIGNAL(clicked()),this,SLOT(close()));
}

QtBoenkenArenaDialog::~QtBoenkenArenaDialog()
{
  delete ui;
}

void QtBoenkenArenaDialog::changeEvent(QEvent *e)
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

///The purpose of QtBoenkenArenaDialog is to create
///an ArenaSettings
const Boenken::ArenaSettings QtBoenkenArenaDialog::GetSettings() const
{
  Boenken::ArenaSettings s;
  s.formation = this->GetFormation();
  s.friction = this->GetFriction();
  s.n_balls = this->GetNballs();
  s.n_obstacles = this->GetNobstacles();
  s.screen_size = this->GetScreenSize();
  return s;
}

const std::pair<int,int> QtBoenkenArenaDialog::GetScreenSize() const
{
  //Makes the code shorter and copy-pastable
  const QComboBox * const b = ui->box_screen_size;
  assert(b->count()==2);
  switch(b->currentIndex())
  {
    case 0:
      assert(b->currentText() == "Full screen");
      {
        // -8, because of the application fame
        const int width
          = QApplication::desktop()->width()
          - 8;
        // -50, because of the app's title bar and those Ubuntu panels
        const int height
          = QApplication::desktop()->height() - 96;
        return std::make_pair(width,height);
      }
    case 1:
      assert(b->currentText() == "640x400");
      return std::make_pair(640,400);
    default:
      assert(!"Should not get here");
      throw std::logic_error("QtBoenkenArenaDialog::GetScreenSize");
  }
}

int QtBoenkenArenaDialog::GetNballs() const
{
  //Makes the code shorter and copy-pastable
  const QComboBox * const b = ui->box_nballs;
  assert(b->count()==2);
  switch(b->currentIndex())
  {
    case 0:
      assert(b->currentText() == "One");
      return 1;
    case 1:
      assert(b->currentText() == "Two");
      return 2;
    default:
      assert(!"Should not get here");
      throw std::logic_error("QtBoenkenArenaDialog::GetNballs");
  }
}

int QtBoenkenArenaDialog::GetNobstacles() const
{
  //Makes the code shorter and copy-pastable
  const QComboBox * const b = ui->box_obstacles;
  assert(b->count()==2);
  switch(b->currentIndex())
  {
    case 0:
      assert(b->currentText() == "None");
      return 0;
    case 1:
      assert(b->currentText() == "Two");
      return 2;
  }
  assert(!"Should not get here");
  throw std::logic_error("QtBoenkenArenaDialog::GetNobstacles");
}

Boenken::Formation QtBoenkenArenaDialog::GetFormation() const
{
  //Makes the code shorter and copy-pastable
  const QComboBox * const b = ui->box_formation;
  assert(b->count()==3);
  switch(b->currentIndex())
  {
    case 0:
      assert(b->currentText() == "Line");
      return Boenken::straight_line;
    case 1:
      assert(b->currentText() == "Circle, inward");
      return Boenken::circle_inward;
    case 2:
      assert(b->currentText() == "Circle, outward");
      return Boenken::circle_outward;
  }
  assert(!"Should not get here");
  throw std::logic_error("QtBoenkenArenaDialog::GetFormation");
}

double QtBoenkenArenaDialog::GetFriction() const
{
  //Makes the code shorter and copy-pastable
  const QComboBox * const b = ui->box_friction;
  assert(b->count()==2);
  switch(b->currentIndex())
  {
    case 0:
      assert(b->currentText() == "None");
      return 1.0;
    case 1:
      assert(b->currentText() == "Low");
      return 0.999;
  }
  assert(!"Should not get here");
  throw std::logic_error("QtBoenkenArenaDialog::GetFriction");
}


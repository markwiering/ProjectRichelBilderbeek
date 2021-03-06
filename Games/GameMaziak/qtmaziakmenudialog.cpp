
/*
Maziak, a simple maze game
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

//From http://www.richelbilderbeek.nl/GameMaziak.htm

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtmaziakmenudialog.h"

#include <cassert>
#include <iostream>
#include <stdexcept>

#include <boost/scoped_ptr.hpp>

#include <QDesktopWidget>
#include <QDialog>
#include <QKeyEvent>
#include <QPainter>
#include <QMouseEvent>

#include "about.h"
#include "maziakmenudialog.h"
#include "qtaboutdialog.h"
#include "qtmaziakinstructionsdialog.h"
#include "qtmaziakmaindialog.h"
#include "ui_qtmaziakmenudialog.h"

QtMaziakMenuDialog::QtMaziakMenuDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtMaziakMenuDialog),
    m_difficulty(easy)
{
  ui->setupUi(this);

  //Put the dialog in the screen's center
  const QRect screen = QApplication::desktop()->screenGeometry();
  this->move( screen.center() - this->rect().center() );
}

QtMaziakMenuDialog::~QtMaziakMenuDialog()
{
  delete ui;
}

void QtMaziakMenuDialog::changeEvent(QEvent *e)
{
  QWidget::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}

void QtMaziakMenuDialog::mousePressEvent(QMouseEvent * event)
{
  if (ui->widget_easy->geometry().contains(
    event->x(), event->y()))
  {
    m_difficulty = easy;
    repaint();
    return;
  }
  if (ui->widget_medium->geometry().contains(
    event->x(), event->y()))
  {
    m_difficulty = medium;
    repaint();
    return;
  }
  if (ui->widget_hard->geometry().contains(
    event->x(), event->y()))
  {
    m_difficulty = hard;
    repaint();
    return;
  }
  if (ui->widget_start->geometry().contains(
    event->x(), event->y()))
  {
    onStart(); return;
  }
  if (ui->widget_instructions->geometry().contains(
    event->x(), event->y()))
  {
    onInstructions();
    return;
  }
  if (ui->widget_about->geometry().contains(
    event->x(), event->y()))
  {
    onAbout();
    return;
  }
  if (ui->widget_quit->geometry().contains(
    event->x(), event->y()))
  {
    close();
  }
}

void QtMaziakMenuDialog::keyPressEvent(QKeyEvent * event)
{
  switch (event->key())
  {
    case Qt::Key_Up: case Qt::Key_Left:
    {
      switch (m_difficulty)
      {
        case easy: return;
        case medium: m_difficulty = easy; repaint(); return;
        case hard: m_difficulty = medium; repaint(); return;
        default: assert(!"Should not get here");
      }
    }
    case Qt::Key_Down: case Qt::Key_Right:
    {
      switch (m_difficulty)
      {
        case easy: m_difficulty = medium; repaint(); return;
        case medium: m_difficulty = hard; repaint(); return;
        case hard: return;
        default: assert(!"Should not get here");
      }
    }
    case Qt::Key_S: onStart(); break;
    case Qt::Key_I: onInstructions(); break;
    case Qt::Key_A: onAbout(); break;
    case Qt::Key_Q: close(); break;
    default:
      break;
  }
}

void QtMaziakMenuDialog::paintEvent(QPaintEvent*)
{
  QPainter painter(this);
  {
    //Top left
    QPixmap pixmap;
    switch (m_difficulty)
    {
      case easy:
        pixmap = QPixmap(":/images/PlayerWon1.png");
        break;
      case medium:
        pixmap = QPixmap(":/images/PlayerLookDown.png");
        break;
      case hard:
        pixmap = QPixmap(":/images/PlayerScared.png");
        break;
      default:
        assert(!"Should not get here");
    }
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_top_left->geometry(),pixmap);
  }
  {
    //Top right
    QPixmap pixmap;
    switch (m_difficulty)
    {
      case easy:
        pixmap = QPixmap(":/images/Fight2.png");
        break;
      case medium:
        pixmap = QPixmap(":/images/Fight3.png");
        break;
      case hard:
        pixmap = QPixmap(":/images/Fight4.png");
        break;
      default:
        assert(!"Should not get here");
    }
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_top_right->geometry(),pixmap);
  }
  {
    //Easy
    QPixmap pixmap(m_difficulty == easy
      ? ":/images/Easy_selected.png"
      : ":/images/Easy_not_selected.png");
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_easy->geometry(),pixmap);
  }
  {
    //Medium
    QPixmap pixmap(m_difficulty == medium
      ? ":/images/Medium_selected.png"
      : ":/images/Medium_not_selected.png");
    assert(!pixmap.isNull());

    painter.drawPixmap(ui->widget_medium->geometry(),pixmap);
  }
  {
    //Hard
    QPixmap pixmap(m_difficulty == hard
      ? ":/images/Hard_selected.png"
      : ":/images/Hard_not_selected.png");
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_hard->geometry(),pixmap);
  }
  {
    //Start
    QPixmap pixmap(":/images/Start.png");
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_start->geometry(),pixmap);
  }
  {
    //Instructions
    QPixmap pixmap(":/images/Instructions.png");
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_instructions->geometry(),pixmap);
  }
  {
    //About
    QPixmap pixmap(":/images/About.png");
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_about->geometry(),pixmap);
  }
  {
    //Quit
    QPixmap pixmap(":/images/Quit.png");
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_quit->geometry(),pixmap);
  }


}

void QtMaziakMenuDialog::onStart()
{
  boost::scoped_ptr<QtMaziakMainDialog> d(new QtMaziakMainDialog(0,getMazeSize()));
  this->hide();
  d->exec();
  this->show();
}

void QtMaziakMenuDialog::onInstructions()
{
  boost::scoped_ptr<QtMaziakInstructionsDialog> d(new QtMaziakInstructionsDialog);
  this->hide();
  d->exec();
  this->show();
}

void QtMaziakMenuDialog::onAbout()
{
  About a = MaziakMenuDialog::GetAbout();
  boost::scoped_ptr<QtAboutDialog> d(new QtAboutDialog(a));
  this->hide();
  d->exec();
  this->show();
}

int QtMaziakMenuDialog::getMazeSize() const
{
  switch (m_difficulty)
  {
    case easy  : return  99;
    case medium: return 499;
    case hard  : return 999;
  }
  assert(!"Should not get here");
  throw std::logic_error("Unsupported value of mDifficulty");
}



/*
#include <vcl.h>
#pragma hdrstop

#include <ctime>
#include <stdexcept>
#include <cstdlib>
#include <boost/scoped_ptr.hpp>
#include "UnitMazeCreater.h"

#include "UnitFormMaziakMenu.h"
#include "UnitFormMaziakAbout.h"
#include "UnitFormMaziakGame.h"
#include "UnitFormMaziakInstructions.h"

#pragma package(smart_init)
#pragma resource "*.dfm"
TFormMaziakMenu *FormMaziakMenu;

__fastcall TFormMaziakMenu::TFormMaziakMenu(TComponent* Owner)
  : TForm(Owner),
    mDifficulty(easy)
{
  RandomizeTimer();
  ImageEasyClick(0);
}

const int TFormMaziakMenu::GetSize() const
{
  switch (mDifficulty)
  {
    case easy  : return  99;
    case medium: return 499;
    case hard  : return 999;
  }
  assert(!"Should not get here");
  throw std::logic_error("Unsupported value of mDifficulty");
}


void __fastcall TFormMaziakMenu::ImageStartClick(TObject *Sender)
{
  boost::scoped_ptr<TFormMaziakGame> f(new TFormMaziakGame(0,GetSize()));
  f->WindowState = wsMaximized;
  f->ShowModal();
}

void __fastcall TFormMaziakMenu::ImageAboutClick(TObject *Sender)
{
  boost::scoped_ptr<TFormMaziakAbout> f(new TFormMaziakAbout(0));
  f->ShowModal();
}

void __fastcall TFormMaziakMenu::ImageQuitClick(TObject *Sender)
{
  Close();
}

void __fastcall TFormMaziakMenu::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  switch (Key)
  {
    case 's': case 'S': ImageStartClick(0); break;
    case 'i': case 'I': ImageInstructionsClick(0); break;
    case 'a': case 'A': ImageAboutClick(0); break;
    case 'q': case 'Q': ImageQuitClick(0); break;
    case '+': case VK_NEXT: case VK_DOWN: case VK_ADD: case VK_RIGHT:
    {
      switch (mDifficulty)
      {
        case easy  : ImageMediumClick(0); break;
        case medium: ImageHardClick(0); break;
        case hard  : break;
      }
    }
    break;
    case '-': case VK_PRIOR: case VK_UP: case VK_SUBTRACT: case VK_LEFT:
    {
      switch (mDifficulty)
      {
        case easy  : break;
        case medium: ImageEasyClick(0); break;
        case hard  : ImageMediumClick(0);break;
      }
    }
    break;
  }
}

//From http://www.richelbilderbeek.nl/CppRandomizeTimer.htm
void RandomizeTimer()
{
  std::srand(std::time(0));
}


void __fastcall TFormMaziakMenu::ImageInstructionsClick(TObject *Sender)
{
  boost::scoped_ptr<TFormMaziakInstructions> f(new TFormMaziakInstructions(0));
  f->ShowModal();
}



void __fastcall TFormMaziakMenu::ImageEasyClick(TObject *Sender)
{
  ImageEasy->Picture   = ImageEasySelected->Picture;
  ImageMedium->Picture = ImageMediumNotSelected->Picture;
  ImageHard->Picture   = ImageHardNotSelected->Picture;
  mDifficulty = easy;
  ImagePlayer->Picture = ImagePlayerEasy->Picture;
  ImageEnemy->Picture  = ImageEnemyEasy->Picture;
}


void __fastcall TFormMaziakMenu::ImageMediumClick(TObject *Sender)
{
  ImageEasy->Picture   = ImageEasyNotSelected->Picture;
  ImageMedium->Picture = ImageMediumSelected->Picture;
  ImageHard->Picture   = ImageHardNotSelected->Picture;
  mDifficulty = medium;
  ImagePlayer->Picture = ImagePlayerMedium->Picture;
  ImageEnemy->Picture  = ImageEnemyMedium->Picture;
}

void __fastcall TFormMaziakMenu::ImageHardClick(TObject *Sender)
{
  ImageEasy->Picture   = ImageEasyNotSelected->Picture;
  ImageMedium->Picture = ImageMediumNotSelected->Picture;
  ImageHard->Picture   = ImageHardSelected->Picture;
  mDifficulty = hard;
  ImagePlayer->Picture = ImagePlayerHard->Picture;
  ImageEnemy->Picture  = ImageEnemyHard->Picture;
}

*/

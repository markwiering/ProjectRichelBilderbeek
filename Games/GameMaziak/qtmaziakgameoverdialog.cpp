//---------------------------------------------------------------------------
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
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/GameMaziak.htm
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
#include "qtmaziakgameoverdialog.h"

#include <cassert>

#include <boost/timer.hpp>

#include <QPainter>
#include <QPaintEvent>
#include <QTimer>

#include "ui_qtmaziakgameoverdialog.h"

QtMaziakGameOverDialog::QtMaziakGameOverDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtMaziakGameOverDialog),
  m_timer(new QTimer),
  m_allow_close(false)
{
  ui->setupUi(this);
  m_timer->setInterval(2500);
  QObject::connect(m_timer.get(),SIGNAL(timeout()),this,SLOT(onTimer()));
  m_timer->start();
}

QtMaziakGameOverDialog::~QtMaziakGameOverDialog()
{
  delete ui;
}

void QtMaziakGameOverDialog::changeEvent(QEvent *e)
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

void QtMaziakGameOverDialog::onTimer()
{
  m_allow_close = true;
  m_timer->stop();
}

void QtMaziakGameOverDialog::paintEvent(QPaintEvent*)
{
  QPainter painter(this);
  {
    //Top
    QPixmap pixmap(":/images/GameOver.png");
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_top->geometry(),pixmap);
  }
  {
    //Center
    QPixmap pixmap(":/images/Rip.png");
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_center->geometry(),pixmap);
  }
  {
    //Bottom
    QPixmap pixmap(":/images/GameOver.png");
    assert(!pixmap.isNull());
    painter.drawPixmap(ui->widget_bottom->geometry(),pixmap);
  }
}

void QtMaziakGameOverDialog::mousePressEvent(QMouseEvent*)
{
  if (m_allow_close) close();
}

void QtMaziakGameOverDialog::keyPressEvent(QKeyEvent*)
{
  if (m_allow_close) close();
}



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
#ifndef QTBOENKENMAINDIALOG_H
#define QTBOENKENMAINDIALOG_H

#include <vector>

#include <boost/shared_ptr.hpp>

#include <QDialog>
#include <QPixmap>
#include <QTimer>

namespace Boenken { struct Game; }
boost::shared_ptr<Boenken::Game> CreateNoBoenken();

namespace Ui {
  class QtBoenkenMainDialog;
}

///QtBoenkenMainDialog displays Boenken and handles user events
class QtBoenkenMainDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtBoenkenMainDialog(
    QWidget *parent = 0,
    boost::shared_ptr<Boenken::Game> boenken = CreateNoBoenken(),
    const bool is_training = false
  );
  ~QtBoenkenMainDialog();

protected:
  void changeEvent(QEvent *e);
  void paintEvent(QPaintEvent*);
  void keyPressEvent(QKeyEvent*);

private:
  //UI
  Ui::QtBoenkenMainDialog *ui;
  //Graphics
  boost::shared_ptr<QPixmap> m_background;
  //Other Qthings
  ///The main game timer
  boost::shared_ptr<QTimer> m_timer;
  ///The timer that does the countdown
  boost::shared_ptr<QTimer> m_timer_countdown;
  //Other member variables
  boost::shared_ptr<Boenken::Game> m_boenken;
  const bool m_is_training;

  ///Paint paints a Pixmap to a single color fast,
  ///from http://www.richelbilderbeek.nl/CppPaint.htm
  static void Paint(
    QPixmap& pixmap,
    const unsigned char r,
    const unsigned char g,
    const unsigned char b,
    const unsigned char a = 255);

  ///Test this class
  static void Test();

private slots:
  void onTimer();
  void onCountdownTimer();
};
#endif // QTBOENKENMAINDIALOG_H

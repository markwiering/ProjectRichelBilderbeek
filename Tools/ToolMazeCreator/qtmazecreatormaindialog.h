//---------------------------------------------------------------------------
/*
MazeCreator, creates a maze and displays it on screen.
Copyright (C) 2007-2012 Richel Bilderbeek

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
//From hhtp://www.richelbilderbeek.nl/ToolMazeCreator.htm
//---------------------------------------------------------------------------
#ifndef QTMAZECREATORMAINDIALOG_H
#define QTMAZECREATORMAINDIALOG_H

#include <boost/shared_ptr.hpp>
#include <QDialog>
struct QGraphicsPixmapItem;
struct QGraphicsScene;
struct QTimer;

namespace Ui {
  class QtMazeCreatorMainDialog;
}

class QtMazeCreatorMainDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtMazeCreatorMainDialog(QWidget *parent = 0);
  ~QtMazeCreatorMainDialog();

  //From http://www.richelbilderbeek.nl/CppCreateMaze.htm
  static const std::vector<std::vector<int> > CreateMaze(const int size);


protected:
  void changeEvent(QEvent *e);

private:
  Ui::QtMazeCreatorMainDialog *ui;
  boost::shared_ptr<QGraphicsScene> m_scene;
  boost::shared_ptr<QGraphicsPixmapItem> m_background;
  boost::shared_ptr<QTimer> m_timer;

  std::size_t m_maze_sz;
  double m_rotation;


  void resizeEvent(QResizeEvent*);
  void keyPressEvent(QKeyEvent* event);
  void drawMaze();

private slots:
  void onTimer();

};


#endif // QTMAZECREATORMAINDIALOG_H

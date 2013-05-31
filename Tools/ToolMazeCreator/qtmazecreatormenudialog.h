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
#ifndef QTMAZECREATORMENUDIALOG_H
#define QTMAZECREATORMENUDIALOG_H

#include <QDialog>

namespace Ui {
class QtMazeCreatorMenuDialog;
}

class QtMazeCreatorMenuDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtMazeCreatorMenuDialog(QWidget *parent = 0);
  ~QtMazeCreatorMenuDialog();

private slots:

  void on_button_start_clicked();

  void on_button_about_clicked();

  void on_button_quit_clicked();

private:
  Ui::QtMazeCreatorMenuDialog *ui;
};

#endif // QTMAZECREATORMENUDIALOG_H
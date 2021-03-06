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
#ifndef QTBOENKENARENADIALOG_H
#define QTBOENKENARENADIALOG_H

#include <QDialog>
#include "boenkenarenasettings.h"

namespace Ui {
  class QtBoenkenArenaDialog;
}

///QtBoenkenArenaDialog
///
///Dialog to setup up the arena
class QtBoenkenArenaDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtBoenkenArenaDialog(QWidget *parent = 0);
  ~QtBoenkenArenaDialog();
  const std::pair<int,int> GetScreenSize() const;
  int GetNballs() const;
  int GetNobstacles() const;
  Boenken::Formation GetFormation() const;
  double GetFriction() const;
  const Boenken::ArenaSettings GetSettings() const;

protected:
  void changeEvent(QEvent *e);

private:
  Ui::QtBoenkenArenaDialog *ui;
};

#endif // QTBOENKENARENADIALOG_H

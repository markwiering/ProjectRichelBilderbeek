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
#ifndef QTMUSICTHEORYMULTISCALEDIALOG_H
#define QTMUSICTHEORYMULTISCALEDIALOG_H

#include <QDialog>

namespace Ui {
class QtMusicTheoryMultiScaleDialog;
}

class QtMusicTheoryMultiScaleDialog : public QDialog
{
  Q_OBJECT
    
public:
  explicit QtMusicTheoryMultiScaleDialog(QWidget *parent = 0);
  ~QtMusicTheoryMultiScaleDialog();

  void resizeEvent(QResizeEvent *);
    
private slots:
  //Called whenever there is a change
  //Cannot call this slot 'any_change', because this will result in the warning
  //'QMetaObject::connectSlotsByName: No matching signal for any_change()'
  void any_change();

private:
  Ui::QtMusicTheoryMultiScaleDialog *ui;
};

#endif // QTMUSICTHEORYMULTISCALEDIALOG_H

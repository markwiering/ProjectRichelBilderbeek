//---------------------------------------------------------------------------
/*
Project Richel Bilderbeek, Richel Bilderbeek's work
Copyright (C) 2010-2013 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ProjectRichelBilderbeek.htm
//---------------------------------------------------------------------------
#ifndef QTRICHELBILDERBEEKMENUDIALOG_H
#define QTRICHELBILDERBEEKMENUDIALOG_H

#include <map>
#include <boost/function.hpp>
#include "qthideandshowdialog.h"
#include "richelbilderbeekprogramtype.h"
#include "about.h"

namespace Ui {
class QtRichelBilderbeekMenuDialog;
}
struct ShinyButtonWidget;

class QtRichelBilderbeekMenuDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtRichelBilderbeekMenuDialog(QWidget *parent = 0);
  ~QtRichelBilderbeekMenuDialog();

  static const About GetAbout();

private slots:
  void OnAbout();

private:
  Ui::QtRichelBilderbeekMenuDialog *ui;

  void keyPressEvent(QKeyEvent *);

  #ifndef NDEBUG
  ///Test this class
  static void Test();
  #endif
};

#endif // QTRICHELBILDERBEEKMENUDIALOG_H
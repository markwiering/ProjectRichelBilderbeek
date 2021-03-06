//---------------------------------------------------------------------------
/*
RubiksClock. Rubik's Clock game.
Copyright (C) 2007-2012  Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/GameRubiksClock.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#include "trace.h"
#include "qtrubiksclockmenudialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);

  START_TRACE();
  //Perform tests
  #ifndef NDEBUG
  std::clog << "DEBUG mode" << std::endl;
  //QtPvdbMenuDialog::Test();
  #else
  std::clog << "RELEASE mode" << std::endl;
  assert(1==2 && "Assume debugging is really disabled");
  #endif

  QtRubiksClockMenuDialog d;
  d.show();
  a.exec();
}

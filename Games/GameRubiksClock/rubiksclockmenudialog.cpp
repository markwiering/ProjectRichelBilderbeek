
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

//From http://www.richelbilderbeek.nl/GameRubiksClock.htm

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "rubiksclockmenudialog.h"

#include "about.h"
#include "dial.h"
#include "dialwidget.h"
#include "rectangle.h"
#include "rubiksclock.h"
#include "rubiksclockdial.h"
#include "rubiksclockdialwidget.h"
#include "rubiksclockwidget.h"
#include "togglebutton.h"
#include "togglebuttonwidget.h"
#include "trace.h"

const About RubiksClockMenuDialog::GetAbout()
{
  About a(
    "Richel Bilderbeek",
    "RubiksClock",
    "simulates a Rubik's Clock",
    "the 23rd of December 2012",
    "2007-2012",
    "http://www.richelbilderbeek.nl/GameRubiksClock.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("Dial version: " + Dial::GetVersion());
  a.AddLibrary("DialWidget version: " + DialWidget::GetVersion());
  a.AddLibrary("Rectangle version: " + Rect::GetVersion());
  a.AddLibrary("RubiksClock version: " + RubiksClock::GetVersion());
  a.AddLibrary("RubiksClockDial version: " + RubiksClockDial::GetVersion());
  a.AddLibrary("RubiksClockDialWidget version: " + RubiksClockDialWidget::GetVersion());
  a.AddLibrary("RubiksClockWidget version: " + RubiksClockWidget::GetVersion());
  a.AddLibrary("ToggleButton version: " + ToggleButton::GetVersion());
  a.AddLibrary("ToggleButtonWidget version: " + ToggleButtonWidget::GetVersion());
  a.AddLibrary("Trace version: " + Trace::GetVersion());
  a.AddLibrary("Widget version: " + Widget::GetVersion());
  return a;
}

const std::string RubiksClockMenuDialog::GetVersion()
{
  return "2.2";
}

const std::vector<std::string> RubiksClockMenuDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2007-12-19: Version 1.0: initial Windows-only version using C++ Builder");
  v.push_back("2011-09-08: Version 2.0: initial port to Qt using Qt Creator, but not complete yet");
  v.push_back("2011-09-15: Version 2.1: created web application version, RubiksClock has all functionality");
  v.push_back("2012-12-23: Version 2.2: created desktop version");
  return v;
}


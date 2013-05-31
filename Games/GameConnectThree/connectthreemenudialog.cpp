//---------------------------------------------------------------------------
/*
GameConnectThree, connect-three game
Copyright (C) 2010 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/GameConnectThree.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "connectthreemenudialog.h"

//---------------------------------------------------------------------------
#include "connectthree.h"
#include "connectthreewidget.h"
//---------------------------------------------------------------------------
#include <cassert>
//---------------------------------------------------------------------------
const About ConnectThreeMenuDialog::GetAbout()
{
  About a(
    "Richel Bilderbeek",
    "ConnectThree",
    "connect-three game",
    "the 25th of April 2011",
    "2010-2011",
    "http://www.richelbilderbeek.nl/GameConnectThree.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("ConnectThree version: " + ConnectThree::GetVersion());
  a.AddLibrary("ConnectThreeWidget version: " + ConnectThreeWidget::GetVersion());
  return a;
}
//---------------------------------------------------------------------------
const std::string ConnectThreeMenuDialog::GetVersion()
{
  return "6.2";
}
//---------------------------------------------------------------------------
const std::vector<std::string> ConnectThreeMenuDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2011-01-10: version 5.0: initial version");
  v.push_back("2011-01-11: version 5.2: support that the game can end in a draw");
  v.push_back("2011-04-22: version 6.0: major architectural changes");
  v.push_back("2011-04-24: version 6.1: fixed a bug that showed when deploying to my WtWebsite");
  v.push_back("2011-04-25: version 6.2: hopefully fixed the bug as in 6.1, fixed desktop version");
  return v;
}
//---------------------------------------------------------------------------


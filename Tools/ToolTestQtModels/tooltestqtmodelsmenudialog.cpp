//---------------------------------------------------------------------------
/*
TestQtModels, tool to test the QtModel classes
Copyright (C) 2013 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTestQtModels.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "tooltestqtmodelsmenudialog.h"

#include "trace.h"

const About ToolTestQtModelsMenuDialog::GetAbout()
{
  About a(
    "Richel Bilderbeek",
    "TestQtModels",
    "tool to test the QtModel classes",
    "the 27th of June 2013",
    "2013",
    "http://www.richelbilderbeek.nl/ToolTestQtModels.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("Trace version: " + Trace::GetVersion());
  return a;
}

const std::string ToolTestQtModelsMenuDialog::GetVersion()
{
  return "1.1";
}

const std::vector<std::string> ToolTestQtModelsMenuDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2013-05-15: version 1.0: initial version");
  v.push_back("2013-06-27: version 1.1: added QtUblasVectorIntModel");
  return v;
}

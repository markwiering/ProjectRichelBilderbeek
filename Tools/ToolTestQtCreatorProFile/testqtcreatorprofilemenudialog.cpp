//---------------------------------------------------------------------------
/*
TestQtCreatorProFile, tool to test the QtCreatorProFile class
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
//From http://www.richelbilderbeek.nl/ToolTestQtCreatorProFile.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "testqtcreatorprofilemenudialog.h"

#include "trace.h"
#include "qtcreatorprofile.h"

const About TestQtCreatorProFileMenuDialog::GetAbout()
{
  About a(
    "Richel Bilderbeek",
    "TestQtCreatorProFile",
    "tool to test the QtCreatorProFile class",
    "the 18th May 2013",
    "2010-2013",
    "http://www.richelbilderbeek.nl/ToolTestQtCreatorProFile.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("QtCreatorProFile version: " + QtCreatorProFile::GetVersion());
  a.AddLibrary("Trace version: " + Trace::GetVersion());
  return a;
}

const std::string TestQtCreatorProFileMenuDialog::GetVersion()
{
  return "1.2";
}

const std::vector<std::string> TestQtCreatorProFileMenuDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2010-xx-xx: version 1.0: initial version, called TestProFile");
  v.push_back("2012-02-27: version 1.1: initial version with About information");
  v.push_back("2013-05-18: version 1.2: renamed this tool to TestQtCreatorProFile");
  return v;
}


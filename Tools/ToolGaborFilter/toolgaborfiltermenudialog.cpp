
/*
GaborFilter, tool to demonstrate Gabor filtering
Copyright (C) 2012  Richel Bilderbeek

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

//From http://www.richelbilderbeek.nl/ToolGaborFilter.htm

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "toolgaborfiltermenudialog.h"

#include "qtcreatorprofile.h"

const About ToolGaborFilterMenuDialog::GetAbout()
{
  About a(
    "Richel Bilderbeek",
    "GaborFilter",
    "tool to demonstrate Gabor filtering",
    "the 7th of July 2012",
    "2012",
    "http://www.richelbilderbeek.nl/ToolGaborFilter.htm",
    GetVersion(),
    GetVersionHistory());
  //a.AddLibrary("ProFile version: " + QtCreatorProFile::GetVersion());
  return a;
}

const std::string ToolGaborFilterMenuDialog::GetVersion()
{
  return "2.0";
}

const std::vector<std::string> ToolGaborFilterMenuDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2010-xx-xx: version 1.0: initial Windows-only version");
  v.push_back("2012-07-07: version 2.0: port to Qt");
  return v;
}


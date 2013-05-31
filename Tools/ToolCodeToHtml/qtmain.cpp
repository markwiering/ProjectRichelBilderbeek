//---------------------------------------------------------------------------
/*
CodeToHtml, converts C++ code to HTML
Copyright (C) 2010-2013  Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolCodeToHtml.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#include <QApplication>
#include "codetohtml.h"
#include "qtcreatorprofile.h"
#include "qtcodetohtmlmenudialog.h"
#include "codetohtmldialog.h"
#include "trace.h"

int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  START_TRACE();
  #ifndef NDEBUG
  assert(c2h::IsTidyInstalled() && "I really want to be sure that tidy is installed");
  c2h::Test();
  c2h::Dialog::Test();
  #endif
  QtCodeToHtmlMenuDialog w;
  w.show();
  return a.exec();
}

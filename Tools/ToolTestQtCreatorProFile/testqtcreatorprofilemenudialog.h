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
#ifndef TESTQTCREATORPROFILEMENUDIALOG_H
#define TESTQTCREATORPROFILEMENUDIALOG_H

#include "about.h"

struct TestQtCreatorProFileMenuDialog
{

  ///Obtain this class its About information
  static const About GetAbout();

  ///Obtain this class its version
  static const std::string GetVersion();

  ///Obtain this class its version history
  static const std::vector<std::string> GetVersionHistory();
};

#endif // TESTQTCREATORPROFILEMENUDIALOG_H

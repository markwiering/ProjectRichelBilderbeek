//---------------------------------------------------------------------------
/*
CreateGlossary, tool to create my glossaries
Copyright (C) 2011-2012 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolCreateGlossary.htm
//---------------------------------------------------------------------------
#include <iostream>
#include <boost/filesystem.hpp>
#include "createglossarymaindialog.h"

int main(int, char * argv[])
{
  std::cout << "Working...\n\n";
  CreateGlossaryMainDialog();

  std::cout << "Successfully created glossaries in folder "
    << boost::filesystem::path(argv[0]).parent_path().string() << "\n";
}
//---------------------------------------------------------------------------

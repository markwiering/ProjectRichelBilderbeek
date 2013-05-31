//---------------------------------------------------------------------------
/*
PicToCode, tool to convert a picture to C++ code
Copyright (C) 2010-2011 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolPicToCode.htm
//---------------------------------------------------------------------------
#include <boost/filesystem.hpp>
//---------------------------------------------------------------------------
#include <Wt/WApplication>
#include <Wt/WEnvironment>
//---------------------------------------------------------------------------
#include "wtautoconfig.h"
#include "wtpictocodemenudialog.h"
//---------------------------------------------------------------------------
#include <QFile>
//---------------------------------------------------------------------------
struct WtPicToCodeApplication : public Wt::WApplication
{
  WtPicToCodeApplication(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
  {
    this->setTitle("PicToCode");
    const std::string css_filename = "wt.css";
    this->useStyleSheet(css_filename);
    root()->addWidget(new WtPicToCodeMenuDialog);
  }
};
//---------------------------------------------------------------------------
Wt::WApplication * createApplication(
  const Wt::WEnvironment& env)
{
  return new WtPicToCodeApplication(env);
}
//---------------------------------------------------------------------------
int main(int argc, char* argv[])
{
  {
    QFile f(":/images/RichelbilderbeekNlBackground.png");
    f.copy("RichelbilderbeekNlBackground.png");
  }
  WtAutoConfig::SaveDefaultStylesheet();
  WtAutoConfig a(argc,argv,createApplication);
  return a.Run();
}
//---------------------------------------------------------------------------

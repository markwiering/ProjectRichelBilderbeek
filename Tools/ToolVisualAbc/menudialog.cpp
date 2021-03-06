//---------------------------------------------------------------------------
#include "menudialog.h"
//---------------------------------------------------------------------------
const About VisualAbcMenuDialog::GetAbout()
{
  About a(
    "Richel Bilderbeek",
    "Visual ABC",
    "visual ABC editor",
    "the 5th of May 2011",
    "2011",
    "http://www.richelbilderbeek.nl/ToolVisualAbc.htm",
    GetVersion(),
    GetVersionHistory());
  //a.AddLibrary("Encranger version: " + Encranger::GetVersion());
  //a.AddLibrary("LoopReader version: " + LoopReader<int>::GetVersion());
  return a;
}
//---------------------------------------------------------------------------
const std::string VisualAbcMenuDialog::GetVersion()
{
  return "1.1";
}
//---------------------------------------------------------------------------
const std::vector<std::string> VisualAbcMenuDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2011-05-01: Version 1.0: initial version");
  v.push_back("2011-05-01: Version 1.1: added button to save ABC text");
  return v;
}
//---------------------------------------------------------------------------

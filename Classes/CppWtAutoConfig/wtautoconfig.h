//---------------------------------------------------------------------------
/*
WtAutoConfig, configures a Wt server in a default way
Copyright (C) 2011 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/CppWtAutoConfig.htm
//---------------------------------------------------------------------------
#ifndef WTAUTOCONFIG_H
#define WTAUTOCONFIG_H
//---------------------------------------------------------------------------
#include <string>
#include <vector>
//---------------------------------------------------------------------------
namespace Wt
{
  struct WApplication;
  struct WEnvironment;
}
//---------------------------------------------------------------------------
///WtAutoConfig is a class to automatically start a Wt
///server in a default configuration.
struct WtAutoConfig
{
  typedef Wt::WApplication * (*FunctionType)(const Wt::WEnvironment&);

  WtAutoConfig(const int argc, char ** const argv, const FunctionType function);
  int Run();

  private:
  const int m_argc;
  char ** const m_argv; //m_argv must be non-const for boost::program_options::parse_command_line
  const FunctionType m_function;

  public:
  static const std::vector<std::string> CreateDefaultStylesheet();

  ///Obtain the version of this class
  static const std::string GetVersion();

  ///Obtain the version history of this class
  static const std::vector<std::string> GetVersionHistory();
  static void SaveDefaultStylesheet();

};
//---------------------------------------------------------------------------
#endif // WTAUTOCONFIG_H
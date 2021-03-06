//---------------------------------------------------------------------------
/*
Counter, an incrementing counter
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
//From http://www.richelbilderbeek.nl/CppCounter.htm
//---------------------------------------------------------------------------
#ifndef COUNTER_H
#define COUNTER_H
//---------------------------------------------------------------------------
#include <string>
#include <vector>
//---------------------------------------------------------------------------
///Counter is a counter
struct Counter
{
  ///Counter is constructed with an initial count, which is initialized to
  ///zero by default
  explicit Counter(const int initial_count = 0) : m_count(initial_count) {}

  ///Count returns the current count and increments it afterwards
  int Count() { return m_count++; }

  ///Obtain this class its version
  static const std::string GetVersion();

  ///Obtain this class its version history
  static const std::vector<std::string> GetVersionHistory();

  private:
  ///The count
  int m_count;
};
//---------------------------------------------------------------------------
#endif // COUNTER_H

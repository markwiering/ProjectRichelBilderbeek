//---------------------------------------------------------------------------
/*
Pylos::Coordinat, Pylos/Phyraos coordinat class
Copyright (C) 2010-2012 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/CppPylos.htm
//---------------------------------------------------------------------------
#ifndef PYLOSCOORDINAT_H
#define PYLOSCOORDINAT_H

#include <iosfwd>
#include <string>
#include <vector>

namespace Pylos {

struct Coordinat
{
  Coordinat(const int layer, const int x, const int y);

  ///Construct a Coordinat from a std::string.
  ///For example, (0,1,2) is the coordinat Z=0=bottom,X=1=leftmost-but-one,Y=2=frontmost-but-two
  Coordinat(const std::string& s);

  ///Obtain the layer or Z-coordinat
  ///0: bottom 4x4 layer, 3: top 1x1 layer
  int GetLayer() const { return m_layer; }

  ///Obtain this class its version
  static const std::string GetVersion();

  ///Obtain this class its version history
  static const std::vector<std::string> GetVersionHistory();

  ///Obtain this coordinat its X coordinat
  ///0: Left
  int GetX() const { return m_x; }

  ///Obtain this coordinat its Y coordinat
  ///0: Top
  int GetY() const { return m_y; }

  ///IsValid returns if the proposed coordinat is a valid Pylos coordinat
  static bool IsValid(const int layer, const int x, const int y);

  ///IsValid returns if this coordinat is a valid Pylos coordinat
  bool IsValid() const;

  ///ToStr() converts the coordinat to a std::string
  ///of the form '(layer,x,y)'.
  const std::string ToStr() const;

  private:
  int m_layer;
  int m_x;
  int m_y;

  #ifndef NDEBUG
  ///Test this class
  static void Test();
  #endif

};

bool operator==(const Coordinat& lhs, const Coordinat& rhs);
bool operator!=(const Coordinat& lhs, const Coordinat& rhs);
std::ostream& operator<<(std::ostream& os,const Coordinat& c);

///GetAbove returns the coordinats physically
///above the entered coordinat
const std::vector<Coordinat> GetAbove(
  const Coordinat& c);

///GetAllPylosCoordinats returns all possible PylosCoordinats
const std::vector<Coordinat> GetAllCoordinats();

///GetBelow returns the four coordinats physically
///below the entered coordinat
const std::vector<Coordinat> GetBelow(
  const Coordinat& c);

///GetLines returns the possible 2x2 squares around the coordinat
const std::vector<std::vector<Coordinat> > GetLines(
  const Coordinat& c);

///GetRandomPylosCoordinat returns a random valid PylosCoordinat
const Coordinat GetRandomCoordinat();

///GetSquares returns the possible 2x2 squares around the coordinat
const std::vector<std::vector<Coordinat> > GetSquares(
  const Coordinat& c);

} //~namespace Pylos

#endif // PYLOSCOORDINAT_H

//---------------------------------------------------------------------------
/*
TicTacToeValuer, tool to solve TicTacToe
Copyright (C) 2010 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTicTacToeValuer.htm
//---------------------------------------------------------------------------
#include <boost/lexical_cast.hpp>
//---------------------------------------------------------------------------
#include "statevaluevertex.h"
//---------------------------------------------------------------------------
const std::string StateValueVertex::ToStr() const
{
  return boost::lexical_cast<std::string>(m_state)
    + std::string(": ")
    + boost::lexical_cast<std::string>(m_value);
}
//---------------------------------------------------------------------------
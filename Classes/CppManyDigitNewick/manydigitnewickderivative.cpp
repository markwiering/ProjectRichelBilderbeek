//---------------------------------------------------------------------------
/*
ManyDigitNewick, Newick class
Copyright (C) 2011 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/CppManyDigitNewick.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "manydigitnewickderivative.h"

#include <cassert>

ManyDigitNewickDerivative::ManyDigitNewickDerivative(
  const int derived_index,
  const int value_changed,
  const int other_value_changed)
  : m_derived_index(derived_index),
    m_value_changed(value_changed),
    m_other_value_changed(other_value_changed)
{
  assert(m_derived_index > 0);
  assert(m_value_changed > 0);
  assert( (m_value_changed == 1 && m_other_value_changed  > 0)
       || (m_value_changed  > 1 && m_other_value_changed == 0) );
}
//---------------------------------------------------------------------------

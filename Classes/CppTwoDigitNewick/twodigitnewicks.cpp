//---------------------------------------------------------------------------
/*
TestTwoDigitNewick, tool to test the two-digit-Newick architecture
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
//From http://www.richelbilderbeek.nl/ToolTestTwoDigitNewick.htm
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
#include "twodigitnewicks.h"

//---------------------------------------------------------------------------
#include <cassert>
//---------------------------------------------------------------------------
#include <boost/foreach.hpp>
#include <boost/numeric/conversion/cast.hpp>
//---------------------------------------------------------------------------
#include "newick.h"
#include "binarynewickvector.h"
//---------------------------------------------------------------------------
TwoDigitNewicks::TwoDigitNewicks(const int n_reserved, const double theta)
{
  //Create derivatives of simplest and reserved TwoDigitNewicks

  //Create the Newick at index 0
  //this->SetNewick(0,TwoDigitNewick(std::vector<TwoDigitNewickDerivative>(TwoDigitNewickDerivative(),0,0));

  //Let i start at 1, because '(0)' is no valid Newick
  for (int i=1; i!=n_reserved; ++i)
  {
    std::vector<TwoDigitNewickDerivative> v;
    if (i > 1)
    {
      const int value_changed = i;
      const int other_value_changed = 0; //<There is no other value
      v.push_back(TwoDigitNewickDerivative(i-1,value_changed,other_value_changed));
    }
    //saz = sum above zero
    const int saz = i;
    //sao = sum above one
    const int sao = (i > 1 ? i : 0);

    TwoDigitNewick n(v,saz,sao);

    assert(i!=0 && "'(0)' is no valid Newick");

    n.SetProbability(Newick::CalcProbabilitySimpleNewick(
      Newick::CreateVector(
        static_cast<int>(Newick::bracket_open),
        i,
        static_cast<int>(Newick::bracket_close)),
      theta));
    this->SetNewick(i,n);

    assert( (i < 2 || this->GetNewick(i).IsComplete())
     && "All newick with index >= 2 must be complete");
  }
}
//---------------------------------------------------------------------------
///Empty returns if an index is empty
bool TwoDigitNewicks::Empty(const int i) const
{
  assert(i >= 0);
  assert(i < this->Size());
  return m_v[i].Empty();
}
//---------------------------------------------------------------------------
const TwoDigitNewick& TwoDigitNewicks::GetNewick(
    const int i) const
{
  //Check if i is in range
  assert(i>=0);
  assert(i < this->Size());
  //Check if returned indices are okay
  #ifndef NDEBUG
  const TwoDigitNewick& v = m_v[i];
  BOOST_FOREACH(const TwoDigitNewickDerivative& j,v.GetDerivatives())
  {
    assert(j.m_derived_index >= 0);
    assert(j.m_derived_index < this->Size() );
  }
  #endif
  return m_v[i];
}
//---------------------------------------------------------------------------
void TwoDigitNewicks::SetNewick(const int i, const TwoDigitNewick& v)
{
  //std::clog << __LINE__ << " - " << i << '\n';
  //Allocate storage
  //TODO: replace by push_back
  if (i >= boost::numeric_cast<int>(m_v.size()))
  {
    m_v.resize(i + 1);
    assert(m_v[m_v.size()-1].Empty());
  }
  //
  //std::clog << "Adding a Newick at index " << i << '\n';
  assert(m_v[i].Empty());

  #ifndef NDEBUG
  BOOST_FOREACH(const TwoDigitNewickDerivative& j, v.GetDerivatives())
  {
    assert(j.m_derived_index > 0);
    assert(j.m_derived_index < boost::numeric_cast<int>(m_v.size())
      && "Cannot set a derivative index "
         "bigger than the number of derivatives");
  }
  #endif

  m_v[i] = v;
}
//---------------------------------------------------------------------------
void TwoDigitNewicks::SetNewickProbability(
  const int i,const double p)
{
  assert(i >= 0);
  assert(i  < Size());
  assert(p >= 0.0);
  assert(p <= 1.0);
  m_v[i].SetProbability(p);
}
//---------------------------------------------------------------------------
int TwoDigitNewicks::Size() const
{
  return boost::numeric_cast<int>(m_v.size());
}
//---------------------------------------------------------------------------

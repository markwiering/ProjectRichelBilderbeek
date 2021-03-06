//---------------------------------------------------------------------------
/*
RubiksClockWidget, class for displaying a RubiksClock
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
//From http://www.richelbilderbeek.nl/CppRubiksClockWidget.htm
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
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#pragma GCC diagnostic ignored "-Wunused-but-set-parameter"
#include "rubiksclockwidget.h"

#include <cassert>
#include <cmath>

#include <iostream>

#include <boost/numeric/conversion/cast.hpp>

#include "dial.h"
#include "rubiksclock.h"
#include "rubiksclockdial.h"
#include "rubiksclockdialwidget.h"
#include "rectangle.h"
#include "togglebutton.h"
#include "togglebuttonwidget.h"
//#include "trace.h"

#pragma GCC diagnostic pop

RubiksClockWidget::RubiksClockWidget(
  const int x,
  const int y,
  const int width,
  const int height)
  : m_clock(new RubiksClock()),
    m_display_front(true)
{
  m_signal_geometry_changed.connect(
    boost::bind(
      &RubiksClockWidget::OnResize,
      this));

  this->SetGeometry(Rect(x,y,width,height));
}

void RubiksClockWidget::Click(const int x,const int y,const bool button_left)
{
  RubiksClock::Times& times = (m_display_front ? m_clock->GetFrontTimes() : m_clock->GetBackTimes());
  RubiksClock::Pegs& pegs = m_clock->GetFrontPegs();

  for (int i=0; i!=2; ++i)
  {
    for (int j=0; j!=2; ++j)
    {
      if (times.times[i*2][j*2]->IsClicked(x,y))
      {
        if(m_display_front)
        {
          this->m_clock->TurnWheel(
            i
            ? (j ? RubiksClock::bottomRight : RubiksClock::topRight)
            : (j ? RubiksClock::bottomLeft : RubiksClock::topLeft),
            button_left ? 1 : -1);
        }
        else
        {
          this->m_clock->TurnWheel(
            i
            ? (j ? RubiksClock::bottomLeft : RubiksClock::topLeft)
            : (j ? RubiksClock::bottomRight : RubiksClock::topRight),
            button_left ? 1 : -1);
        }
      }
      else if (pegs.pegs[i][j]->GetGeometry().IsIn(x,y))
      {
        m_clock->TogglePeg(
          i
          ? (j ? RubiksClock::bottomRight : RubiksClock::topRight)
          : (j ? RubiksClock::bottomLeft : RubiksClock::topLeft));
      }
    }
  }
}

void RubiksClockWidget::Flip()
{
  m_display_front = !m_display_front;
  m_signal_widget_flipped();
}

const std::string RubiksClockWidget::GetVersion()
{
  return "1.2";
}

const std::vector<std::string> RubiksClockWidget::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2011-09-01: Version 1.0: initial version");
  v.push_back("2011-09-09: Version 1.1: use of geometries");
  v.push_back("2011-09-15: Version 1.2: allow flipping the clock");
  return v;
}

void RubiksClockWidget::OnResize()
{
  m_clock->SetGeometry(this->GetGeometry());
}

std::ostream& operator<<(std::ostream& os, const RubiksClockWidget& widget)
{
  os
    << "<RubiksClockWidget>"
    << *widget.m_clock
    << widget.GetGeometry()
    << "</RubiksClockWidget>";
  return os;
}



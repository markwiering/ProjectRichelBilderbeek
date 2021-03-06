//---------------------------------------------------------------------------
/*
MysteryMachineWidget, GUI independent widget for MysteryMachine
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
//From http://www.richelbilderbeek.nl/CppMysteryMachineWidget.htm
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
#include "mysterymachinewidget.h"

#include <iostream>

#include <boost/numeric/conversion/cast.hpp>

#include "dial.h"
#include "dialwidget.h"
#include "led.h"
#include "ledwidget.h"
#include "mysterymachine.h"
#include "rectangle.h"
#include "togglebutton.h"
#include "togglebuttonwidget.h"
//#include "trace.h"

#pragma GCC diagnostic pop

MysteryMachineWidget::MysteryMachineWidget(
  const Rect& geometry)
  : m_machine(new MysteryMachine)

{
  this->m_signal_geometry_changed.connect(boost::bind(
    &MysteryMachineWidget::OnResize,this));
  SetGeometry(geometry);
}

///Respond to the user clicking on the MysteryMachineWidget
void MysteryMachineWidget::Click(const int x, const int y)
{
  if (m_machine->GetDialBack()->IsClicked(x,y))
  {
    m_machine->GetDialBack()->Click(x,y);
  }
  if (m_machine->GetDialFront()->IsClicked(x,y))
  {
    m_machine->GetDialFront()->Click(x,y);
  }
  if (m_machine->GetToggleButton()->GetGeometry().IsIn(x,y))
  {
    m_machine->GetToggleButton()->Click(x,y);
  }
}

const std::string MysteryMachineWidget::GetVersion()
{
  return "1.1";
}

const std::vector<std::string> MysteryMachineWidget::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("YYYY-MM-DD: version X.Y: [description]");
  v.push_back("2011-07-03: version 1.0: initial version");
  v.push_back("2011-08-20: Version 1.1: added operator<<");
  return v;
}

//void MysteryMachineWidget::OnMysteryMachineChanged()
//{
//  m_signal_mysterymachine_changed();
//}

void MysteryMachineWidget::OnResize()
{
  const double w = boost::numeric_cast<double>(GetGeometry().GetWidth());
  const double h = boost::numeric_cast<double>(GetGeometry().GetHeight());
  const double s = std::min(w/4.0,h/8.0);
  const double w8 = w / 8.0;


  m_machine->GetDialBack()->SetGeometry(Rect((w8 * 1.0) - (s * 0.5),0,s,s));
  m_machine->GetDialFront()->SetGeometry(Rect((w8 * 7.0) - (s * 0.5),h-s,s,s));
  m_machine->GetToggleButton()->SetGeometry(Rect(
    (w8 * 4.0) + (s * 0.5),
    (h * 0.5) - (s * 0.5),
    s,s));



  m_machine->GetLedBack1()->SetGeometry(Rect((w8 * 3.0) - (s * 0.5),0,s,s));
  m_machine->GetLedBack2()->SetGeometry(Rect((w8 * 5.0) - (s * 0.5),0,s,s));
  m_machine->GetLedBack3()->SetGeometry(Rect((w8 * 7.0) - (s * 0.5),0,s,s));

  m_machine->GetLedFront1()->SetGeometry(Rect((w8 * 1.0) - (s * 0.5),h-s,s,s));
  m_machine->GetLedFront2()->SetGeometry(Rect((w8 * 3.0) - (s * 0.5),h-s,s,s));
  m_machine->GetLedFront3()->SetGeometry(Rect((w8 * 5.0) - (s * 0.5),h-s,s,s));

  m_machine->GetLedTopFront()->SetGeometry(Rect(
    (w8 * 5.0) - (s * 0.5),
    (((h - (s * 0.5)) + (h * 0.5)) * 0.5) - (s * 0.5),
    s,s));
  m_machine->GetLedTopMiddle()->SetGeometry(Rect((w8 * 4.0) - (s * 0.5),
    (h * 0.5) - (s * 0.5),
    s,s));
  m_machine->GetLedTopBack()->SetGeometry(Rect((w8 * 3.0) - (s * 0.5),
    (((s * 0.5) + (h * 0.5)) * 0.5) - (s * 0.5),
    s,s));
  //m_signal_mysterymachine_changed();
}

std::ostream& operator<<(std::ostream& os, const MysteryMachineWidget& widget)
{
  os
    << "<MysteryMachineWidget>"
    << "<geometry>"
    << widget.GetGeometry()
    << "</geometry>"
    << "<machine>"
    << *widget.m_machine
    << "</machine>"
    << "</MysteryMachineWidget>";
  return os;
}


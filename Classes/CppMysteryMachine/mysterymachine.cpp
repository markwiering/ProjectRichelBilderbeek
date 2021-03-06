//---------------------------------------------------------------------------
/*
MysteryMachine, my mystery machine class
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
//From http://www.richelbilderbeek.nl/CppMysteryMachine.htm
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
#include "mysterymachine.h"

#include <boost/lexical_cast.hpp>

#include "dial.h"
#include "dialwidget.h"
#include "led.h"
#include "ledwidget.h"
#include "togglebutton.h"
#include "togglebuttonwidget.h"

#pragma GCC diagnostic pop

MysteryMachine::MysteryMachine()
  : m_dial_back(new DialWidget),
    m_dial_front(new DialWidget),
    m_led_front_1(new LedWidget(0,0,32,32,1.0,255,  0,  0)),
    m_led_front_2(new LedWidget(0,0,32,32,0.0,  0,255,  0)),
    m_led_front_3(new LedWidget(0,0,32,32,0.0,  0,  0,255)),
    m_led_back_1(new LedWidget(0,0,32,32,1.0,255,  0,  0)),
    m_led_back_2(new LedWidget(0,0,32,32,0.0,  0,255,  0)),
    m_led_back_3(new LedWidget(0,0,32,32,0.0,  0,  0,255)),
    m_led_top_front( new LedWidget(0,0,32,32,0.0,255,0,0)),
    m_led_top_middle(new LedWidget(0,0,32,32,0.0,255,0,0)),
    m_led_top_back(  new LedWidget(0,0,32,32,0.0,255,0,0)),
    m_toggle_button(new ToggleButtonWidget)
    //m_back(0),
    //m_front(0),
{
  m_dial_back->GetDial()->m_signal_position_changed.connect(boost::bind(
    &MysteryMachine::Update,this));
  m_dial_front->GetDial()->m_signal_position_changed.connect(boost::bind(
    &MysteryMachine::Update,this));
  m_toggle_button->GetToggleButton()->m_signal_toggled.connect(boost::bind(
    &MysteryMachine::Update,this));
  Update();
}

const std::string MysteryMachine::GetVersion()
{
  return "1.1";
}

const std::vector<std::string> MysteryMachine::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2011-04-10: Version 1.0: initial version");
  v.push_back("2011-08-20: Version 1.1: added operator<<");
  return v;
}

void MysteryMachine::Update()
{
  const int back = static_cast<int>(GetDialBack()->GetDial()->GetPosition() * 16.0) % 3;
  const int front = static_cast<int>(GetDialFront()->GetDial()->GetPosition() * 16.0) % 3;
  int top = (GetToggleButton()->GetToggleButton()->IsPressed()
    ? (1 + front - back + 3) % 3
    : -1);
  assert(front >= 0);
  assert(front  < 3);
  assert(back >= 0);
  assert(back  < 3);
  assert(top >= -1); //-1 denotes off
  assert(top  < 3);
  m_led_front_1->GetLed()->SetIntensity(front == 0 ? 1.0 : 0.0);
  m_led_front_2->GetLed()->SetIntensity(front == 1 ? 1.0 : 0.0);
  m_led_front_3->GetLed()->SetIntensity(front == 2 ? 1.0 : 0.0);
  m_led_back_1->GetLed()->SetIntensity(back == 0 ? 1.0 : 0.0);
  m_led_back_2->GetLed()->SetIntensity(back == 1 ? 1.0 : 0.0);
  m_led_back_3->GetLed()->SetIntensity(back == 2 ? 1.0 : 0.0);
  m_led_top_front->GetLed()->SetIntensity( top == 0 ? 1.0 : 0.0);
  m_led_top_middle->GetLed()->SetIntensity(top == 1 ? 1.0 : 0.0);
  m_led_top_back->GetLed()->SetIntensity(  top == 2 ? 1.0 : 0.0);
}

std::ostream& operator<<(std::ostream& os, const MysteryMachine& machine)
{
  os
    << "<MysteryMachine>"
    << "<dial_back>"
      << *machine.m_dial_back
    << "</dial_back>"
    << "<dial_front>"
      << *machine.m_dial_front
    << "</dial_front>"
    << "<led_back_1>"
      << *machine.m_led_back_1
    << "</led_back_1>"
    << "<led_back_2>"
      << *machine.m_led_back_2
    << "</led_back_2>"
    << "<led_back_3>"
      << *machine.m_led_back_3
    << "</led_back_3>"
    << "<led_front_1>"
    << *machine.m_led_front_1
    << "</led_front_1>"
    << "<led_front_2>"
      << *machine.m_led_front_2
    << "</led_front_2>"
    << "<led_front_3>"
      << *machine.m_led_front_3
    << "<led_front_3>"
    << "<led_top_back>"
      << *machine.m_led_top_back
    << "</led_top_back>"
    << "<led_top_front>"
      << *machine.m_led_top_front
    << "</led_top_front>"
    << "<led_top_middle>"
      << *machine.m_led_top_middle
    << "</led_top_middle>"
    << "<toggle_button>"
    << *machine.m_toggle_button
    << "</toggle_button>"
    << "</MysteryMachine>";
  return os;
}


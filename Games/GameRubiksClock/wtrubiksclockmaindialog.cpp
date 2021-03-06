//---------------------------------------------------------------------------
/*
RubiksClock. Rubik's Clock game.
Copyright (C) 2007-2011  Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/GameRubiksClock.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "wtrubiksclockmaindialog.h"

#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <boost/algorithm/string/split.hpp>
#include <boost/foreach.hpp>
#include <boost/numeric/conversion/cast.hpp>
//---------------------------------------------------------------------------
#include <Wt/WBreak>
#include <Wt/WLabel>
#include <Wt/WLineEdit>
#include <Wt/WPaintDevice>
#include <Wt/WPainter>
#include <Wt/WPushButton>
//---------------------------------------------------------------------------
#include "dial.h"
#include "dialwidget.h"
#include "rubiksclock.h"
#include "rubiksclockwidget.h"
#include "widget.h"
#include "wtdialwidget.h"
#include "wtrubiksclockwidget.h"
//---------------------------------------------------------------------------
WtRubiksClockMainDialog::Ui::Ui()
  : m_button_flip(new Wt::WPushButton("Flip clock")),
    m_dial_size(new WtDialWidget),
    m_label_size(new Wt::WLabel),
    m_widget(new WtRubiksClockWidget)
{
}
//---------------------------------------------------------------------------
WtRubiksClockMainDialog::WtRubiksClockMainDialog()
{
  this->clear();
  this->setContentAlignment(Wt::AlignCenter);
  this->addWidget(new Wt::WBreak);
  this->addWidget(new Wt::WBreak);
  this->addWidget(ui.m_widget);
  this->addWidget(new Wt::WBreak);
  this->addWidget(new Wt::WBreak);
  this->addWidget(ui.m_button_flip);
  this->addWidget(new Wt::WBreak);
  this->addWidget(new Wt::WBreak);
  this->addWidget(ui.m_label_size);
  this->addWidget(ui.m_dial_size);

  ui.m_button_flip->clicked().connect(
    this,
    &WtRubiksClockMainDialog::OnFlip);

  ui.m_dial_size->GetWidget()->GetDial()->m_signal_position_changed.connect(
    boost::bind(
      &WtRubiksClockMainDialog::OnSizeChanged,
      this));

  ui.m_dial_size->GetWidget()->SetGeometry(Rect(0,0,32,32));
  ui.m_label_size->setText("Size: ?x? (width x height)");
  ui.m_widget->GetWidget()->SetGeometry(Rect(0,0,300,300));

  ui.m_dial_size->GetWidget()->GetDial()->SetPosition(0.5);
}
//---------------------------------------------------------------------------
void WtRubiksClockMainDialog::OnFlip()
{
  ui.m_widget->GetWidget()->Flip();
}
//---------------------------------------------------------------------------
void WtRubiksClockMainDialog::OnSizeChanged()
{
  const int size = boost::numeric_cast<int>(
    500.0 * ui.m_dial_size->GetWidget()->GetDial()->GetPosition());
  ui.m_widget->GetWidget()->SetGeometry(Rect(0,0,size,size));
  std::string text
    = std::string("Size: ")
    + boost::lexical_cast<std::string>(size)
    + std::string("x")
    + boost::lexical_cast<std::string>(size)
    + std::string(" (width x height)");
  ui.m_label_size->setText(text.c_str());
}
//---------------------------------------------------------------------------

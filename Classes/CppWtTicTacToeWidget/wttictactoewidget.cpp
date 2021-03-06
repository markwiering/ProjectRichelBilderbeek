//---------------------------------------------------------------------------
/*
WtTicTacToeWidget, Wt widget to display the TicTacToe class
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
//From http://www.richelbilderbeek.nl/CppWtTicTacToeWidget.htm
//---------------------------------------------------------------------------
#include <Wt/WPainter>
#include <Wt/WPen>
#include <Wt/WBrush>
//---------------------------------------------------------------------------
#include "tictactoe.h"
#include "wttictactoewidget.h"
//---------------------------------------------------------------------------
//Enable debugging
#undef NDEBUG
#include <cassert>
//---------------------------------------------------------------------------
WtTicTacToeWidget::WtTicTacToeWidget()
{
  //Without resize, there is nothing to paint on
  this->resize(GetWidth(),GetHeight());
  this->clicked().connect(this,&WtTicTacToeWidget::OnClicked);
  this->update();
}
//---------------------------------------------------------------------------
int WtTicTacToeWidget::GetState() const
{
  return m_tictactoe.GetWinner();
}
//---------------------------------------------------------------------------
int WtTicTacToeWidget::GetHeight() const
{
  return 300.0;
}
//---------------------------------------------------------------------------
const std::string WtTicTacToeWidget::GetVersion()
{
  return "1.0";
}
//---------------------------------------------------------------------------
const std::vector<std::string> WtTicTacToeWidget::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("YYYY-MM-DD: version X.Y: [description]");
  v.push_back("2011-01-06: version 1.0: initial version");
  return v;
}
//---------------------------------------------------------------------------
int WtTicTacToeWidget::GetWidth() const
{
  return 300.0;
}
//---------------------------------------------------------------------------
void WtTicTacToeWidget::OnClicked(const Wt::WMouseEvent& e)
{
  if (m_tictactoe.GetWinner() != TicTacToe::no_winner) return;
  const int x = 3 * e.widget().x / this->GetWidth();
  if (x < 0 || x > 2) return;
  const int y = 3 * e.widget().y / this->GetHeight();
  if (y < 0 || y > 2) return;
  if (m_tictactoe.CanDoMove(x,y))
  {
    m_tictactoe.DoMove(x,y);
    //emit that the state has changed
    this->m_signal_state_changed();
  }
  if (m_tictactoe.GetWinner() != TicTacToe::no_winner)
  {
    //emit that there is a winner
    this->m_signal_has_winner();
  }
  this->update();
}
//---------------------------------------------------------------------------
void WtTicTacToeWidget::paintEvent(Wt::WPaintDevice *paintDevice)
{
  Wt::WPainter painter(paintDevice);
  const int width  = GetWidth();
  const int height = GetHeight();
  //Set black pen
  Wt::WPen pen = painter.pen();
  pen.setCapStyle(Wt::RoundCap);
  pen.setColor(Wt::WColor(255,255,255));
  painter.setPen(pen);
  painter.setBrush(Wt::WBrush(Wt::WColor(255,255,255)));
  painter.drawRect(0.0,0.0,GetWidth(),GetHeight());
  //Set thick white pen
  pen.setColor(Wt::WColor(0,0,0));
  const int line_width = std::min(width,height) / 15;
  pen.setWidth(line_width);
  painter.setPen(pen);
  //Vertical lines
  painter.drawLine(
      ((1*width)/3)+4,     0+(line_width/2),
      ((1*width)/3)-4,height-(line_width/2));
  painter.drawLine(
      ((2*width)/3)-4,     0+(line_width/2),
      ((2*width)/3)+8,height-(line_width/2));
  //Horizontal lines
  painter.drawLine(
      0+(line_width/2),((1*height)/3)+4,
      width-(line_width/2),((1*height)/3)-4);
  painter.drawLine(
      0+(line_width/2),((2*height)/3)-4,
      width-(line_width/2),((2*height)/3)+8);
  for (int row=0; row!=3; ++row)
  {
    const int x1 = ((row + 0) * (width / 3)) + (line_width/1) + 4;
    const int x2 = ((row + 1) * (width / 3)) - (line_width/1) - 4;
    for (int col=0; col!=3; ++col)
    {
      const int y1 = ((col + 0) * (height / 3)) + (line_width/1) + 4;
      const int y2 = ((col + 1) * (height / 3)) - (line_width/1) - 4;
      const int state = m_tictactoe.GetSquare(row,col);
      if (state == TicTacToe::player1)
      {
        //player1 = cross
        painter.drawLine(x1,y1,x2,y2);
        painter.drawLine(x1,y2,x2,y1);
      }
      else if (state == TicTacToe::player2)
      {
        //player1 = circle
        painter.drawEllipse(x1,y1,x2-x1,y2-y1);
      }
    }
  }
}
//---------------------------------------------------------------------------
void WtTicTacToeWidget::Restart()
{
  m_tictactoe = TicTacToe();
  this->update();
}
//---------------------------------------------------------------------------

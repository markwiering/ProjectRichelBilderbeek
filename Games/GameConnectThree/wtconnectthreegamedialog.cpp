//---------------------------------------------------------------------------
/*
GameConnectThree, connect-three game
Copyright (C) 2010-2011 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/GameConnectThree.htm
//---------------------------------------------------------------------------
#include <Wt/WBreak>
#include <Wt/WImage>
#include <Wt/WPushButton>
#include <Wt/WText>
#include <Wt/WTimer>
#include <Wt/WResource>
//---------------------------------------------------------------------------
#include "connectthree.h"
#include "wtconnectthreeresources.h"
#include "trace.h"
#include "wtconnectthreegamedialog.h"
#include "wtconnectthreewidget.h"
//---------------------------------------------------------------------------
//Enable debugging
#undef NDEBUG
#include <cassert>
//---------------------------------------------------------------------------
WtConnectThreeGameDialog::WtConnectThreeGameDialog(
  const std::bitset<3>& is_player_human)
  : m_is_player_human(is_player_human),
    m_state(state_playing),
    m_timer(new Wt::WTimer(this))
{

  this->setContentAlignment(Wt::AlignCenter);

  m_timer->timeout().connect(
    this,
    &WtConnectThreeGameDialog::DoComputerTurn);
  m_timer->setInterval(100);


  ShowGame();
  //OnValidMove(); //Draw screen
}
//---------------------------------------------------------------------------
WtConnectThreeGameDialog::~WtConnectThreeGameDialog()
{
  m_timer->stop();
}
//---------------------------------------------------------------------------
void WtConnectThreeGameDialog::DoComputerTurn()
{
  assert(m_board);
  if (m_board->IsComputerTurn()
    && m_board->GetWinner() == ConnectThree::no_player)
  {
    m_board->DoComputerTurn();
    OnValidMove();
  }
}
//---------------------------------------------------------------------------
///OnValidMove is called after a valid move. The game
///is either terminated, or the next player can do
///his/her move.
void WtConnectThreeGameDialog::OnValidMove()
{
  if (m_board->GetWinner() == ConnectThree::no_player)
  {
    UpdatePlayersPanel();
    return;
  }
  m_state = state_winner;
  this->PauseTimer();
  ShowWinner();
}
//---------------------------------------------------------------------------
void WtConnectThreeGameDialog::RestartGame()
{
  m_state = state_playing;
  ShowGame();
  assert(m_board);
  m_board->Restart();
  UpdatePlayersPanel();
  StartTimer();
}
//---------------------------------------------------------------------------
void WtConnectThreeGameDialog::SetIsPlayerHuman(const std::bitset<3>& is_player_human)
{
  if (m_is_player_human != is_player_human)
  {
    m_is_player_human = is_player_human;
    assert(m_board);
    m_board->SetIsPlayerHuman(m_is_player_human);
    m_board->update();
    UpdatePlayersPanel();
  }
}
//---------------------------------------------------------------------------
void WtConnectThreeGameDialog::ShowGame()
{
  assert(m_state == state_playing);
  this->clear();
  m_board = new WtConnectThreeWidget(m_is_player_human,16,8);
  m_board->m_signal_valid_move.connect(
    boost::bind(
      &WtConnectThreeGameDialog::OnValidMove,
      this));
  assert(m_board);
  assert(m_board->GetWinner() == ConnectThree::no_player);
  this->addWidget(m_board);
  this->addWidget(new Wt::WBreak);
  this->addWidget(new Wt::WBreak);
  m_players = {
    new Wt::WImage(
      WtConnectThreeResources::GetInstance()->GetPlayersFilenames()[0],
        "Player 1"),
    new Wt::WImage(
      WtConnectThreeResources::GetInstance()->GetPlayersFilenames()[1],
        "Player 2"),
    new Wt::WImage(
      WtConnectThreeResources::GetInstance()->GetPlayersFilenames()[2],
        "Player 3")
    };
  assert(m_players.size() == 3);
  assert(m_players[0]);
  assert(m_players[1]);
  assert(m_players[2]);
  this->addWidget(m_players[0]);
  this->addWidget(m_players[1]);
  this->addWidget(m_players[2]);
  UpdatePlayersPanel();
}
//---------------------------------------------------------------------------
void WtConnectThreeGameDialog::ShowWinner()
{
  assert(m_state = state_winner);
  assert(m_board->GetWinner() != ConnectThree::no_player);
  assert(!m_timer->isActive());
  //Request all info from m_board, before deleting it
  const int winner_index = m_board->GetWinner();
  const std::string text
    = (m_board->GetWinner() == ConnectThree::draw
    ? "draw" : "winner");

  //There is a winner
  this->clear();
  Wt::WImage * winner = new Wt::WImage;

  switch(winner_index)
  {
      case ConnectThree::player1:
        winner->setImageRef(
          WtConnectThreeResources::GetInstance()
            ->GetPlayersFilenames()[0]);
        break;
      case ConnectThree::player2:
        winner->setImageRef(
          WtConnectThreeResources::GetInstance()
            ->GetPlayersFilenames()[1]);
        break;
      case ConnectThree::player3:
        winner->setImageRef(
          WtConnectThreeResources::GetInstance()
            ->GetPlayersFilenames()[2]);
        break;
      case ConnectThree::draw:
        winner->setImageRef(
          WtConnectThreeResources::GetInstance()
            ->GetEmptyFilename());
        break;
      default:
        assert(!"Should not get here");
        throw std::logic_error("Known value of GetCurrentPlayer in WtConnectThreeGameDialog::OnValidMove");
  }
  this->addWidget(winner);
  this->addWidget(new Wt::WBreak);
  {
    Wt::WText * const title = new Wt::WText(text.c_str());
    title->setStyleClass("title");
    this->addWidget(title);
  }
  this->addWidget(new Wt::WBreak);
  {
    Wt::WPushButton * const button(new Wt::WPushButton("Restart",this));
    button->clicked().connect(
      this,
      &WtConnectThreeGameDialog::RestartGame);
  }
}
//---------------------------------------------------------------------------
void WtConnectThreeGameDialog::UpdatePlayersPanel()
{
  assert(m_board);
  assert(m_players.size() == 3);
  assert(m_players[0]);
  assert(m_players[1]);
  assert(m_players[2]);
  const std::bitset<3>& is_player_human = m_board->GetIsPlayerHuman();
  const int n_players = 3; //as the name is 'ConnectThree'
  for (int i=0; i!=n_players; ++i)
  {
    if (is_player_human[i])
    {
      if (m_board->GetActivePlayer() == i)
      {
        m_players[i]->setImageRef(WtConnectThreeResources::GetInstance()->GetPlayersFilenames()[i]);
      }
      else
      {
        m_players[i]->setImageRef(WtConnectThreeResources::GetInstance()->GetPlayersGreyFilenames()[i]);
      }
    }
    else
    {
      if (m_board->GetActivePlayer() == i)
      {
        m_players[i]->setImageRef(WtConnectThreeResources::GetInstance()->GetComputersFilenames()[i]);
      }
      else
      {
        m_players[i]->setImageRef(WtConnectThreeResources::GetInstance()->GetComputerGreyFilename());
      }
    }
  }
}
//---------------------------------------------------------------------------
void WtConnectThreeGameDialog::PauseTimer()
{
  m_timer->stop();
}
//---------------------------------------------------------------------------
void WtConnectThreeGameDialog::StartTimer()
{
  m_timer->start();
}
//---------------------------------------------------------------------------


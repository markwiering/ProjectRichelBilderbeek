//---------------------------------------------------------------------------
/*
Pylos::CurrentMoveState, Pylos/Phyraos current move state class
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
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "pyloscurrentmovestate.h"

#include <cassert>
//---------------------------------------------------------------------------
#include "trace.h"
//---------------------------------------------------------------------------
namespace Pylos {
//---------------------------------------------------------------------------
CurrentMoveState::CurrentMoveState()
  : m_must_remove(MustRemoveState::no)
{
  #ifndef NDEBUG
  Test();
  #endif

  assert(IsMoveUnknown());
  //assert(IsRemoveUnknown());
}
//---------------------------------------------------------------------------
const std::string CurrentMoveState::GetVersion()
{
  return "2.0";
}
//---------------------------------------------------------------------------
const std::vector<std::string> CurrentMoveState::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2012-05-05: version 2.0: initial release version");
  return v;
}
//---------------------------------------------------------------------------
bool CurrentMoveState::IsMoveMove() const
{
  Test();

  assert(m_current_move.m_move.size() < 3);
  return m_current_move.m_move.size() == 2;
}
//---------------------------------------------------------------------------
bool CurrentMoveState::IsMovePlace() const
{
  assert(m_current_move.m_move.size() < 3);
  return m_current_move.m_move.size() == 1;
}
//---------------------------------------------------------------------------
bool CurrentMoveState::IsMoveUnknown() const
{
  assert(m_current_move.m_move.size() < 3);
  return m_current_move.m_move.size() == 0;
}
//---------------------------------------------------------------------------
/*
bool PylosCurrentMoveState::IsRemoveUnknown() const
{
  return
       (!m_move_flag_remove_zero)
    && (!m_move_flag_remove_zero)
    && (!m_move_flag_remove_two);
}
*/
//---------------------------------------------------------------------------
MustRemoveState CurrentMoveState::GetMustRemove() const
{
  return m_must_remove;
}
//---------------------------------------------------------------------------
void CurrentMoveState::Restart()
{
  m_must_remove = MustRemoveState::no;
  m_current_move = Move();
  assert(IsMoveUnknown());
}
//---------------------------------------------------------------------------
void CurrentMoveState::SetMove(const Move& move)
{
  assert(m_current_move.m_move.empty());
  assert(m_current_move.m_remove.empty());
  m_current_move = move;
  m_must_remove = MustRemoveState::no;
}
//---------------------------------------------------------------------------
void CurrentMoveState::SetMoveTransfer(const Coordinat& from, const Coordinat& to)
{
  assert(IsMoveUnknown());
  assert(m_current_move.m_move.empty());
  m_current_move.m_move.push_back(from);
  m_current_move.m_move.push_back(to);
}
//---------------------------------------------------------------------------
void CurrentMoveState::SetMoveSet(const Coordinat& c)
{
  assert(IsMoveUnknown());
  assert(m_current_move.m_move.empty());
  m_current_move.m_move.push_back(c);
}
//---------------------------------------------------------------------------
void CurrentMoveState::SetMustRemove(const MustRemoveState must_remove)
{
  assert(!(must_remove == MustRemoveState::player2
    &&   m_must_remove == MustRemoveState::player1)
    && "Cannot set duty to remove from player 1 to player 2");
  assert(!(must_remove == MustRemoveState::player1
    &&   m_must_remove == MustRemoveState::player2)
    && "Cannot set duty to remove from player 2 to player 1");
  m_must_remove = must_remove;
}
//---------------------------------------------------------------------------
void CurrentMoveState::SetRemove(const std::vector<Coordinat>& v)
{
  assert(m_must_remove != MustRemoveState::no);
  m_current_move.m_remove = v;
}
//---------------------------------------------------------------------------
void CurrentMoveState::Test()
{
  static bool tested = false;
  if (tested) return;
  tested = true;

  TRACE("Test PylosCurrentMoveState");
  {
    const Coordinat c(0,1,1);
    Pylos::CurrentMoveState s;
    assert(s.IsMoveUnknown());
    assert(!s.GetMustRemove());
    s.SetMoveSet(c);
    assert(!s.IsMoveUnknown());
    const Pylos::Move m = s.GetMove();
    assert(m.m_move.size() == 1);
    assert(m.m_move[0] == c);
    assert(m.m_remove.empty());
    s.Restart();
    Pylos::CurrentMoveState t;
    assert(s == t);
  }
}
//---------------------------------------------------------------------------
bool operator==(const CurrentMoveState& lhs, const CurrentMoveState& rhs)
{
  return lhs.GetMustRemove() == rhs.GetMustRemove()
    && lhs.GetMove() == rhs.GetMove();
}
//---------------------------------------------------------------------------
} //~namespace Pylos
//---------------------------------------------------------------------------

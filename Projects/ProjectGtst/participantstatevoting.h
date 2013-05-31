//---------------------------------------------------------------------------
/*
GTST, Game Theory Server
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
//From http://www.richelbilderbeek.nl/ProjectGtst.htm
//---------------------------------------------------------------------------
#ifndef PROJECTGTSTPARTICIPANTSTATEVOTING_H
#define PROJECTGTSTPARTICIPANTSTATEVOTING_H
//---------------------------------------------------------------------------
#include <boost/checked_delete.hpp>
//---------------------------------------------------------------------------
#include "state.h"
#include "participantstate.h"
//---------------------------------------------------------------------------
///The Participant is in the StateVoting ParticipantState
struct ParticipantStateVoting
  : public ParticipantState, StateVoting
{
  ///Contruct every ParticipantState from a pointer to its Participant
  ParticipantStateVoting(Participant * const participant,Server * const server);
  ///Represent the ParticipantState as a std::string for an Administrator
  const std::string ToAdminStr() const;
  ///Represent the State at a std::string
  const std::string ToStr() const { return this->StateVoting::ToStr(); }
  protected:
  ///Only let a smart pointer delete this ParticipantState
  virtual ~ParticipantStateVoting() {}
  ///Only let a smart pointer delete this ParticipantState
  friend void boost::checked_delete<>(ParticipantStateVoting*);
};
//---------------------------------------------------------------------------
#endif // PARTICIPANTSTATEVOTING_H
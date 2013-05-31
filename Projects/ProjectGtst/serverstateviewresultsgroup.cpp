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
#include <iostream>
//---------------------------------------------------------------------------
#include "all_parameters.h"
#include "all_serverstates.h"
#include "chooseactionoption.h"
#include "group.h"
#include "groupfinished.h"
#include "grouploggedin.h"
#include "groupnotloggedin.h"
#include "groupparticipating.h"
#include "groups.h"
#include "logfile.h"
#include "participant.h"
#include "repeatassigner.h"
#include "state.h"
#include "stopwatch.h"
#include "server.h"
//---------------------------------------------------------------------------
ServerStateViewResultsGroup::ServerStateViewResultsGroup(
  Server * const server, const int period, const int cycle,
  const boost::shared_ptr<const ParametersViewResultsGroup>& parameters)
  : ServerState(server,period,cycle),
    m_parameters(parameters)
{
  assert(m_parameters);
}
//---------------------------------------------------------------------------
///Check if this state can go to the next state.
bool ServerStateViewResultsGroup::CanGoToNextState() const
{
  return GetTimeLeft() < 0;
}
//---------------------------------------------------------------------------
///Obtain the duration of the state in seconds
int ServerStateViewResultsGroup::GetStateDuration() const
{
  return m_parameters->GetDuration();
}
//---------------------------------------------------------------------------
void ServerStateViewResultsGroup::OnTimer()
{
  if (CanGoToNextState()) GoToNextState();
}
//---------------------------------------------------------------------------
/*
void ServerStateViewResultsGroup::SetParameters(const boost::shared_ptr<const ParametersViewResultsGroup>& parameters)
{
  assert(parameters);
  m_parameters = parameters;

  ResetTimeLeft();
  assert(this->GetTimeLeft() >= 0);
}
*/
//---------------------------------------------------------------------------
///Start or restart the state
void ServerStateViewResultsGroup::Start()
{
  assert(m_parameters);

  const auto ps = GetServer()->GetGroups()->CollectParticipants(false,false,true,false);
  std::for_each(ps.begin(),ps.end(),
    [this](const boost::shared_ptr<const Participant>& p)
    {
      StateViewResultsGroup * const state
        = dynamic_cast<const StateViewResultsGroup*>(this);
      assert(state);
      this->FindParticipant(p)->SetState(state);
    }
  );
}
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os,const ServerStateViewResultsGroup& s)
{
  os
    << "<state_" << s.ToStr() << ">"
    << s.m_parameters
    << "</state_" << s.ToStr() << ">";
  return os;
}
//---------------------------------------------------------------------------
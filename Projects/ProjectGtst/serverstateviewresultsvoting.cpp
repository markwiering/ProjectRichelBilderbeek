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
#include <algorithm>
#include <cassert>
#include <iostream>

#include <boost/bind.hpp>
#include <boost/foreach.hpp>
#include <boost/lambda/bind.hpp>
#include <boost/lambda/lambda.hpp>
#include <boost/numeric/conversion/cast.hpp>
#include <boost/shared_ptr.hpp>

#include "all_parameters.h"
#include "all_serverstates.h"
#include "group.h"
#include "groupfinished.h"
#include "grouploggedin.h"
#include "groupnotloggedin.h"
#include "groupparticipating.h"
#include "groups.h"
#include "state.h"
#include "logfile.h"
#include "participant.h"
#include "stopwatch.h"
#include "server.h"
#include "trace.h"
#include "vote.h"
#include "votingoption.h"

ServerStateViewResultsVoting::ServerStateViewResultsVoting(
  Server * const server, const int period, const int cycle,
  const boost::shared_ptr<const ParametersViewResultsVoting>& parameters)
  : ServerState(server,period,cycle),
    m_parameters(parameters)
{
  assert(m_parameters);
}

///Check if this state can go to the next state.
bool ServerStateViewResultsVoting::CanGoToNextState() const
{
  return GetTimeLeft() < 0;
}

const std::vector<boost::shared_ptr<Vote> > ServerStateViewResultsVoting::GetGroupResults(
  const boost::shared_ptr<const Participant>& participant) const
{
  assert(participant);
  assert(GetServer());
  assert(GetServer()->GetParameters());
  assert(GetServer()->GetParameters()->GetVoting());

  std::vector<boost::shared_ptr<Vote> > v;

  const Group * const group
    = GetServer()->GetGroups()->FindMyGroup(participant);
  assert(group);

  BOOST_FOREACH(const boost::shared_ptr<const Participant>& participant,
    group->CollectParticipants())
  {
    assert(!participant->GetVotes().empty());

    v.push_back(
      boost::shared_ptr<Vote>(
        new Vote(
          participant,
          participant->GetVotes().back().get())));
  }
  return v;
}

///Obtain the duration of the state in seconds
int ServerStateViewResultsVoting::GetStateDuration() const
{
  assert(m_parameters);
  return m_parameters->GetDuration();
}

void ServerStateViewResultsVoting::OnTimer()
{
  if (CanGoToNextState()) GoToNextState();
}

/*
void ServerStateViewResultsVoting::SetParameters(
  const boost::shared_ptr<const ParametersViewResultsVoting>& parameters)
{
  assert(parameters);
  m_parameters = parameters;
  ResetTimeLeft();
  assert(this->GetTimeLeft() >= 0);
}
*/

///Start or restart the state
void ServerStateViewResultsVoting::Start()
{
  ///Setting the group its vote
  m_voted_concensus.clear();

  BOOST_FOREACH(const Group * const group,
    GetServer()->GetGroups()->CollectGroups(false,false,true,false))
  {
    //Only participating groups will have voted
    assert(dynamic_cast<const GroupParticipating*>(group));

    if(group->CollectParticipants().empty())
    {
      TRACE(group->GetId());
    }
    assert(!group->CollectParticipants().empty()
      && "Assume a group is never empty");

    //Tally all votes
    std::map<std::string,int> vote_tally;
    BOOST_FOREACH(const boost::shared_ptr<const Participant>& participant,
      group->CollectParticipants())
    {
      assert(!participant->GetVotes().empty());
      const std::string s = participant->GetVotes().back()->GetDescription();
      if (vote_tally.find(s) == vote_tally.end())
      {
        vote_tally[s] = 0;
      }
      else
      {
        ++vote_tally[s];
      }
    }

    //Get the highest tally value (that is: the second int)
    const std::map<std::string,int>::const_iterator max
      = std::max_element(
        vote_tally.begin(),
        vote_tally.end(),
        boost::lambda::bind(&std::pair<const std::string,int>::second, boost::lambda::_2)
         > boost::lambda::bind(&std::pair<const std::string,int>::second, boost::lambda::_1));
    const int max_count
      = std::count_if(
       vote_tally.begin(),
       vote_tally.end(),
       boost::lambda::bind(&std::pair<const std::string,int>::second, boost::lambda::_1)
         == max->second);

    if (max_count == 0)
    {
      BOOST_FOREACH(const boost::shared_ptr<const Participant>& participant,
        group->CollectParticipants())
      {
        const int id = participant->GetId();
        const std::string s = participant->GetVotes().back()->GetDescription();
        std::cerr << "ID: " << id << " vote: " << s << '\n';
      }
      std::cerr << "max->first: " << max->first << '\n';
      std::cerr << "max->second: " << max->second << '\n';
      std::cerr << "max_count: " << max_count << '\n';
    }
    assert(max_count >= 1);

    if (max_count == 1)
    {
      //Unique!
      //assert(max->first < boost::numeric_cast<int>(
      //  GetServer()->GetParameters()->GetVoting()->GetOptions().size()));
      const std::vector<boost::shared_ptr<VotingOption> > v
        = GetServer()->GetParameters()->GetVoting()->GetOptions();
      assert(
        std::find_if(v.begin(),v.end(),
          boost::bind(&VotingOption::GetDescription,boost::lambda::_1) == max->first)
          != v.end());
      m_voted_concensus[group]
        = (*std::find_if(v.begin(),v.end(),
          boost::bind(&VotingOption::GetDescription,boost::lambda::_1) == max->first)).get();

    }
    else
    {
      //No consensus in voting
      m_voted_concensus[group] = 0;
    }

  }
  BOOST_FOREACH(const boost::shared_ptr<const Participant>& p,
    GetServer()->GetGroups()->CollectParticipants(false,false,true,false))
  {
    StateViewResultsVoting * const state
      = dynamic_cast<const StateViewResultsVoting*>(this);
    assert(state);
    FindParticipant(p)->SetState(state);
  }
}

std::ostream& operator<<(std::ostream& os,const ServerStateViewResultsVoting& s)
{
  os
    << "<state_" << s.ToStr() << ">"
    << s.m_parameters
    << "</state_" << s.ToStr() << ">";
  return os;
}


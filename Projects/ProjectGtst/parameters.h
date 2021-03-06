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
#ifndef PROJECTGTSTPARAMETERS_H
#define PROJECTGTSTPARAMETERS_H
//---------------------------------------------------------------------------
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
//---------------------------------------------------------------------------
#include "forward_declarations.h"
//---------------------------------------------------------------------------
///\brief
///Parameters for an experiment
struct Parameters : public boost::noncopyable
{
  ///Create a default-constructed Parameters
  Parameters(Server * const server);

  ///Create a default non-logged in Participant
  boost::shared_ptr<Participant> CreateDefaultParticipant();

  ///Deletes all Participant instances
  void DeleteParticipants();

  ///Set a Parameter from file
  void ReadFromFile(const std::string& filename);

  ///Get the ParametersAssignPayoff as a read-and-write pointer
  boost::shared_ptr<ParametersAssignPayoff> GetAssignPayoff() { return m_assign_payoff; }
  ///Get the ParametersAssignPayoff as a read-only pointer
  boost::shared_ptr<const ParametersAssignPayoff> GetAssignPayoff() const { return m_assign_payoff; }
  ///Get the ParametersChat as a read-and-write pointer
  boost::shared_ptr<ParametersChat> GetChat() { return m_chat; }
  ///Get the ParametersChat as a read-only pointer
  boost::shared_ptr<const ParametersChat> GetChat() const { return m_chat; }
  ///Get the ParametersChooseAction as a read-and-write pointer
  boost::shared_ptr<ParametersChooseAction> GetChooseAction() { return m_choose_action; }
  ///Get the ParametersChooseAction as a read-only pointer
  boost::shared_ptr<const ParametersChooseAction> GetChooseAction() const { return m_choose_action; }
  ///Get the ParametersFinished as a read-and-write pointer
  boost::shared_ptr<ParametersFinished> GetFinished() { return m_finished; }
  ///Get the ParametersFinished as a read-only pointer
  boost::shared_ptr<const ParametersFinished> GetFinished() const { return m_finished; }
  ///Get the ParametersGroupAssign as a read-and-write pointer
  boost::shared_ptr<ParametersGroupAssign> GetGroupAssign() { return m_group_assign; }
  ///Get the ParametersGroupAssign as a read-only pointer
  boost::shared_ptr<const ParametersGroupAssign> GetGroupAssign() const { return m_group_assign; }
  ///Get the ParametersGroupReAssign as a read-and-write pointer
  boost::shared_ptr<ParametersGroupReAssign> GetGroupReAssign() { return m_group_reassign; }
  ///Get the ParametersGroupReAssign as a read-only pointer
  boost::shared_ptr<const ParametersGroupReAssign> GetGroupReAssign() const { return m_group_reassign; }
  ///Get the ParametersQuiz as a read-and-write pointer
  boost::shared_ptr<ParametersQuiz> GetQuiz() { return m_quiz; }
  ///Get the ParametersQuiz as a read-only pointer
  boost::shared_ptr<const ParametersQuiz> GetQuiz() const { return m_quiz; }
  ///Get the ParametersViewResultsAll as a read-and-write pointer
  //ParametersViewResultsAll * GetViewResultsAll();
  ///Get the ParametersViewResultsAll as a read-only pointer
  //const ParametersViewResultsAll * GetViewResultsAll() const;
  ///Get the ParametersViewResultsGroup as a read-and-write pointer
  boost::shared_ptr<ParametersViewResultsGroup> GetViewResultsGroup() { return m_view_results_group; }
  ///Get the ParametersViewResultsGroup as a read-only pointer
  boost::shared_ptr<const ParametersViewResultsGroup> GetViewResultsGroup() const { return m_view_results_group; }
  ///Get the ParametersViewResultsVoting as a read-and-write pointer
  boost::shared_ptr<ParametersViewResultsVoting> GetViewResultsVoting() { return m_view_results_voting; }
  ///Get the ParametersViewResultsVoting as a read-only pointer
  boost::shared_ptr<const ParametersViewResultsVoting> GetViewResultsVoting() const { return m_view_results_voting; }
  ///Get the ParametersVoting as a read-and-write pointer
  boost::shared_ptr<ParametersVoting> GetVoting() { return m_voting; }
  ///Get the ParametersVoting as a read-only pointer
  boost::shared_ptr<const ParametersVoting> GetVoting() const { return m_voting; }

  ///Get the Participants as a read-only reference
  const std::vector<boost::shared_ptr<Participant> >& GetParticipants() const { return m_participants; }
  ///Get the Participants as a reference
  std::vector<boost::shared_ptr<Participant> >& GetParticipants() { return m_participants; }

  ///Add Participants to Parameters
  void AddParticipant(boost::shared_ptr<Participant> participant);

  private:
  ///Only allow a Boost smart pointer to delete Administrator
  //to prevent the following trouble,
  //cited from http://www.boost.org/libs/utility/checked_delete.html:
  //The C++ Standard allows, in 5.3.5/5, pointers to incomplete
  //class types to be deleted with a delete-expression.
  //When the class has a non-trivial destructor, or a class-specific operator
  //delete, the behavior is undefined. Some compilers issue a warning when an
  //incomplete type is deleted, but unfortunately, not all do, and programmers
  //sometimes ignore or disable warnings.
  ~Parameters() {}
  ///Only let smart pointers delete Parameters
  //Template syntax from Herb Sutter. Exceptional C++ style. 2005. ISBN: 0-201-76042-8. Item 8: 'Befriending templates'.
  friend void boost::checked_delete<>(Parameters*);


  ///Unassigned Participant colection
  std::vector<boost::shared_ptr<Participant> > m_participants;

  ///The ParametersAssignPayoff
  boost::shared_ptr<ParametersAssignPayoff> m_assign_payoff;
  ///The ParametersChat
  boost::shared_ptr<ParametersChat> m_chat;
  ///The ParametersChooseAction
  boost::shared_ptr<ParametersChooseAction> m_choose_action;
  ///The ParametersFinished
  boost::shared_ptr<ParametersFinished> m_finished;
  ///The ParametersGroupAssign
  boost::shared_ptr<ParametersGroupAssign> m_group_assign;
  ///The ParametersGroupReAssign
  boost::shared_ptr<ParametersGroupReAssign> m_group_reassign;
  ///The ParametersQuiz
  boost::shared_ptr<ParametersQuiz> m_quiz;

  Server * const m_server;

  ///The ParametersViewResultsGroup
  boost::shared_ptr<ParametersViewResultsGroup> m_view_results_group;
  ///The ParametersViewResultsVoting
  boost::shared_ptr<ParametersViewResultsVoting> m_view_results_voting;
  ///The ParametersVoting
  boost::shared_ptr<ParametersVoting> m_voting;


  ///Parse a line in a Parameter file
  void Parse(const std::string& s);

  ///Convert a file to a std::vector
  ///From http://www.richelbilderbeek.nl/CppFileToVector.htm
  static const std::vector<std::string> FileToVector(const std::string& filename);

  ///Split a std::string
  ///From http://www.richelbilderbeek.nl/CppSeperateString.htm
  static const std::vector<std::string> SeperateString(
    const std::string& input,const char seperator);
};
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os,const Parameters& parameters);
//---------------------------------------------------------------------------
#endif // PARAMETERS_H

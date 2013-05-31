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
#ifndef PROJECTGTSTLOGFILE_H
#define PROJECTGTSTLOGFILE_H
//---------------------------------------------------------------------------
#include <ctime>
#include <iosfwd>
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include <boost/shared_ptr.hpp>
#include <boost/noncopyable.hpp>
//---------------------------------------------------------------------------
#include "forward_declarations.h"
//---------------------------------------------------------------------------
///\brief
///LogFile is the log file.
///
///A crashed session should be able to be restored it.
struct LogFile : public boost::noncopyable
{
  LogFile();

  //Clear the LogFile NEVER DO SO!
  //static void ClearLogFile();

  ///Log a Participant his/her last action
  void LogAction(const boost::shared_ptr<const Participant>& participant);

  ///Log a Participant being assigned to a group
  void LogAssignGroup(
    const Group * const group,
    const boost::shared_ptr<const Participant>& participant);

  ///Log a Participant having assigned his/her Payoff
  void LogAssignPayoff(const boost::shared_ptr<const Participant>& participant);

  ///Log a ChatMessage from a Participant
  void LogChatMessage(
    const boost::shared_ptr<const Participant>& participant,
    const boost::shared_ptr<ChatMessage>& message);

  ///Log that the experiment its state/phase has been changed
  void LogExperimentStateChanged(const ServerState* const new_state);

  ///Log that a Participant has logged in
  void Login(const boost::shared_ptr<const Participant>& participant);

  ///Log a Participant has logged out (although he/she will remain in memory)
  void Logout(const boost::shared_ptr<const Participant>& participant);

  ///Log the parameters
  void LogParameters(boost::shared_ptr<Parameters> parameters);

  ///Log that a ParticipantDialog has its ParticipantDialogState changed
  void LogParticipantDialogStateChanged(const ParticipantDialogState* const new_state);

  ///Log a Participant having survived a period
  void LogReAssignPayoff(const boost::shared_ptr<const Participant>& participant);

  ///Log a Participant being removed from a group
  void LogRemoveParticipant(
    const Group * const group,
    const boost::shared_ptr<const Participant>& participant);

  ///Log a Participant his/her vote
  void LogVote(const boost::shared_ptr<const Participant>& participant);

  ///The filename of the log file where all logged operations are written to
  const std::string m_log_filename;

  private:
  ///Only allow a Boost smart pointer to delete LogFile
  //to prevent the following trouble,
  //cited from http://www.boost.org/libs/utility/checked_delete.html:
  //The C++ Standard allows, in 5.3.5/5, pointers to incomplete
  //class types to be deleted with a delete-expression.
  //When the class has a non-trivial destructor, or a class-specific operator
  //delete, the behavior is undefined. Some compilers issue a warning when an
  //incomplete type is deleted, but unfortunately, not all do, and programmers
  //sometimes ignore or disable warnings.
  ~LogFile();
  ///Only allow a Boost smart pointer to delete LogFile
  //Template syntax from Herb Sutter. Exceptional C++ style. 2005. ISBN: 0-201-76042-8. Item 8: 'Befriending templates'.
  friend void boost::checked_delete<>(LogFile*);

  ///Befriend operator<<
  friend std::ostream& operator<<(std::ostream& os,const LogFile& logfile);

  ///Returns date in YYYY-MM-DD format
  //From http://www.richelbilderbeek.nl/CppGetDateIso8601.htm
  static const std::string GetDateIso8601();

  ///Get the current time
  //From http://www.richelbilderbeek.nl/CppGetTime.htm
  static const std::string GetTime();

  ///Returns the current date and time as a YYYY_MM_DD_HH_MM_SS std::string,
  ///for example '2011_07_01_11_35_38'
  //From http://www.richelbilderbeek.nl/CppGetTimestamp.htm
  static const std::string GetTimestamp();
};
//---------------------------------------------------------------------------
std::ostream& operator<<(std::ostream& os,const LogFile& logfile);
//---------------------------------------------------------------------------
#endif // LOGFILE_H
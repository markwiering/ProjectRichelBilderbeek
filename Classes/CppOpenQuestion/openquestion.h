//---------------------------------------------------------------------------
/*
OpenQuestion, class for an open question
Copyright (C) 2011  Richl Bilderbeek

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
// From http://www.richelbilderbeek.nl/CppOpenQuestion
//---------------------------------------------------------------------------
#ifndef OPENQUESTION_H
#define OPENQUESTION_H
//---------------------------------------------------------------------------
#include <string>
#include <vector>
//---------------------------------------------------------------------------
#include "question.h"
//---------------------------------------------------------------------------
///class for an open question
struct OpenQuestion : public Question
{
  ///Throws nothing or std::out_of_range or std::runtime_error
  explicit OpenQuestion(const std::string& question);

  ///An open question has multiple possible answers
  OpenQuestion(
    const std::string& filename,
    const std::string& question,
    const std::vector<std::string>& answers);

  ///Create a copy of the Question, depending on the derived class its type
  Question * Clone() const;

  const std::vector<std::string>& GetAnswers() const;

  static const std::string GetVersion();
  static const std::vector<std::string> GetVersionHistory();

  private:
  friend void boost::checked_delete<>(OpenQuestion *);
  ~OpenQuestion() {}

  ///The wrong answers are at indices 2 to SeperateString(input,',').size()
  static const std::vector<std::string> ExtractAnswers(
    const std::string& input);

  //Split a string
  //From http://www.richelbilderbeek.nl/CppSeperateString.htm
  static const std::vector<std::string> SeperateString(
    const std::string& input,
    const char seperator);

};
//---------------------------------------------------------------------------
#endif // OPENQUESTION_H
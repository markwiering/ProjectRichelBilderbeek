//---------------------------------------------------------------------------
/*
TestQuestion, tool to test the Question and QuestionDialog classes
Copyright (C) 2011-2012 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTestQuestion.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "testquestionmenudialog.h"

#include <boost/foreach.hpp>

#include "multiplechoicequestion.h"
#include "multiplechoicequestiondialog.h"
#include "openquestion.h"
#include "openquestiondialog.h"
#include "question.h"
#include "questiondialog.h"
//#include "trace.h"

#include <QFile>

TestQuestionMenuDialog::TestQuestionMenuDialog()
{
  const std::vector<std::string> files = { "question.png" };
  BOOST_FOREACH(const std::string& filename,files)
  {
    if (!QFile::exists(filename.c_str()))
    {
      QFile f( (std::string(":/images/") + filename).c_str() );
        f.copy(filename.c_str());
    }
    assert(QFile::exists(filename.c_str()));
  }
}

const About TestQuestionMenuDialog::GetAbout() const
{
  About a(
    "Richel Bilderbeek",
    "TestQuestion",
    "tool to test the Question and QuestionDialog classes",
    "the 23rd of December 2012",
    "2011-2012",
    "http://www.richelbilderbeek.nl/ToolTestQuestion.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("MultipleChoiceQuestion version: " + MultipleChoiceQuestion::GetVersion());
  a.AddLibrary("MultipleChoiceQuestionDialog version: " + MultipleChoiceQuestionDialog::GetVersion());
  a.AddLibrary("OpenQuestion version: " + OpenQuestion::GetVersion());
  a.AddLibrary("OpenQuestionDialog version: " + OpenQuestionDialog::GetVersion());
  a.AddLibrary("Question version: " + Question::GetVersion());
  a.AddLibrary("QuestionDialog version: " + QuestionDialog::GetVersion());
  //a.AddLibrary("Trace version: " + Trace::GetVersion());
  return a;
}

const std::string TestQuestionMenuDialog::GetVersion()
{
  return "2.1";
}

const std::vector<std::string> TestQuestionMenuDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2011-06-28: Version 1.0: initial version");
  v.push_back("2011-09-16: Version 2.0: show QuestionDialog from std::string in website version");
  v.push_back("2012-12-23: Version 2.1: finished desktop application");
  return v;
}


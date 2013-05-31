//---------------------------------------------------------------------------
/*
QuestionDialog, dialog for Question
Copyright (C) 2011-2013 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/CppQuestionDialog.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "questiondialog.h"

#include "openquestion.h"
#include "openquestiondialog.h"

QuestionDialog::QuestionDialog(const boost::shared_ptr<Question>& question)
  : m_has_submitted(false),
    m_is_correct(false)
{
  SetQuestion(question);

  if (question)
  {
    assert(CanSubmit());
    assert(!HasSubmitted());
    assert(GetQuestion());
  }
}

const std::string QuestionDialog::GetVersion()
{
  return "1.0";
}

const std::vector<std::string> QuestionDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2011-06-29: version 1.0: initial version");
  return v;
}

bool QuestionDialog::IsAnswerCorrect() const
{
  assert(HasSubmitted());
  return m_is_correct;
}

void QuestionDialog::SetQuestion(const boost::shared_ptr<Question>& question)
{
  assert(question);
  if (question && question.get() != m_question.get())
  {
    m_question = question;
    m_has_submitted = false;
  }
}

void QuestionDialog::Submit(const std::string& s)
{
  assert(CanSubmit());

  m_is_correct = m_question->IsCorrect(s);

  m_has_submitted = true;
  assert(!CanSubmit());
}

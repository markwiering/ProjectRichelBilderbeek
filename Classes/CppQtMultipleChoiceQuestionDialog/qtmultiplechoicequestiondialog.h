//---------------------------------------------------------------------------
/*
QtMultipleChoiceQuestionDialog, Qt dialog for MultipleChoiceQuestion
Copyright (C) 2011 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/QtMultipleChoiceQuestionDialog.htm
//---------------------------------------------------------------------------
#ifndef QTMULTIPLECHOICEQUESTIONDIALOG_H
#define QTMULTIPLECHOICEQUESTIONDIALOG_H
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#include <boost/scoped_ptr.hpp>
#include <boost/shared_ptr.hpp>
//---------------------------------------------------------------------------
#include <QDialog>
//---------------------------------------------------------------------------
#include "questiondialog.h"
#include "qtquestiondialog.h"
//---------------------------------------------------------------------------
namespace Ui {
  class QtMultipleChoiceQuestionDialog;
}
struct Question;
struct MultipleChoiceQuestion;
struct MultipleChoiceQuestionDialog;
//---------------------------------------------------------------------------
class QtMultipleChoiceQuestionDialog : public QtQuestionDialog
{
  Q_OBJECT

public:
  explicit QtMultipleChoiceQuestionDialog(
    QWidget *parent = 0);

  QtMultipleChoiceQuestionDialog(
    const boost::shared_ptr<QuestionDialog>& dialog,
    QWidget *parent = 0);

  ~QtMultipleChoiceQuestionDialog();

  ///Obtain the version of this class
  static const std::string GetVersion();

  ///Obtain the version history of this class
  static const std::vector<std::string> GetVersionHistory();

private slots:
  void on_button_submit_clicked();

private:
  Ui::QtMultipleChoiceQuestionDialog *ui;
  //boost::scoped_ptr<MultipleChoiceQuestionDialog> m_dialog;

  ///Set the Question
  void SetQuestion(
    const boost::shared_ptr<Question>& question
    //const boost::shared_ptr<MultipleChoiceQuestion>& question
    //const MultipleChoiceQuestion * const question
    );

};
//---------------------------------------------------------------------------
#endif // QTMULTIPLECHOICEQUESTIONDIALOG_H

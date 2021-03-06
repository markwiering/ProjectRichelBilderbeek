//---------------------------------------------------------------------------
/*
RegexTester, regular expression tester
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
//From http://www.richelbilderbeek.nl/ToolRegexTester.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtregextestermaindialog.h"

#include <boost/foreach.hpp>

#include "regextestermaindialog.h"
#include "regextestermaindialog.h"
#include "ui_qtregextestermaindialog.h"

QtRegexTesterMainDialog::QtRegexTesterMainDialog(
  const boost::shared_ptr<RegexTesterMainDialog> dialog,
  QWidget *parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtRegexTesterMainDialog),
    m_dialog(dialog)
{
  ui->setupUi(this);

  QObject::connect(ui->edit_line,SIGNAL(textEdited(QString)),this,SLOT(onAnyChange()));
  QObject::connect(ui->edit_regex,SIGNAL(textEdited(QString)),this,SLOT(onAnyChange()));
  QObject::connect(ui->edit_format,SIGNAL(textEdited(QString)),this,SLOT(onAnyChange()));


  ui->edit_regex->setText(m_dialog->GetExampleRegex().c_str());
  ui->edit_format->setText(m_dialog->GetExampleFormat().c_str());
  this->onAnyChange();
}

QtRegexTesterMainDialog::~QtRegexTesterMainDialog()
{
  delete ui;
}

void QtRegexTesterMainDialog::changeEvent(QEvent *e)
{
  QDialog::changeEvent(e);
  switch (e->type()) {
  case QEvent::LanguageChange:
    ui->retranslateUi(this);
    break;
  default:
    break;
  }
}

void QtRegexTesterMainDialog::onAnyChange()
{
  const std::string regex_str = ui->edit_regex->text().toStdString();
  const std::string line = ui->edit_line->text().toStdString();
  const std::string format = ui->edit_format->text().toStdString();

  const boost::shared_ptr<RegexTesterMainDialog> dialog = m_dialog->Clone();

  ui->label_regex_valid->setText(
    QString("Regex valid: ") + (dialog->GetRegexValid(regex_str) ? "yes" : "no"));

  if (dialog->GetRegexMatchLine(line,regex_str))
  {
    ui->label_regex_match->setText("Regex matches line: yes");
  }
  else
  {
    ui->label_regex_match->setText("Regex matches line: no");
  }

  if (!dialog->GetRegexMatches(line,regex_str).empty())
  {
    ui->label_regex_found->setText("Regex found in line: yes");
  }
  else
  {
    ui->label_regex_found->setText("Regex found in line: no");
  }

  ui->edit_matching_regexes->clear();

  const std::vector<std::string>& v = dialog->GetRegexMatches(line,regex_str);

  std::for_each(v.begin(),v.end(),
    [this](const std::string& s)
    {
      this->ui->edit_matching_regexes->appendPlainText(
        QString(s.c_str()));

    }
  );

  ui->edit_replaced_regexes->setPlainText( dialog->GetRegexReplace(line,regex_str,format).c_str());
}


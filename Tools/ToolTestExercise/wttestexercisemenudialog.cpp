//---------------------------------------------------------------------------
/*
TestExercise, tool to test the Exercise class
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
//From http://www.richelbilderbeek.nl/ToolTestExercise.htm
//---------------------------------------------------------------------------
#include <cassert>
//---------------------------------------------------------------------------
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
//---------------------------------------------------------------------------
#include <Wt/WBreak>
#include <Wt/WContainerWidget>
#include <Wt/WGroupBox>
#include <Wt/WImage>
#include <Wt/WLabel>
#include <Wt/WStackedWidget>
#include <Wt/WMenu>
#include <Wt/WMenuItem>
//---------------------------------------------------------------------------
#include "testexercisemenudialog.h"
#include "wtaboutdialog.h"
#include "wtautoconfig.h"
#include "wtexercise.h"
#include "wttestexercisemaindialog.h"
#include "wttestexercisemenudialog.h"
#include "wtmultiplechoicequestiondialog.h"
#include "wtopenquestiondialog.h"
#include "wtquestiondialog.h"
//---------------------------------------------------------------------------
#include <QFile>
//---------------------------------------------------------------------------
WtTestExerciseMenuDialog::WtTestExerciseMenuDialog()
  : m_dialog(new TestExerciseMenuDialog)
{
 {
    std::vector<std::string> image_names;
    image_names.push_back("ToolTestExerciseWelcome.png");
    image_names.push_back("ToolTestExerciseQuestion.png");
    image_names.push_back("ToolTestExerciseQuestionmark.png");

    BOOST_FOREACH(const std::string& filename,image_names)
    {
      if (!(QFile::exists(filename.c_str())))
      {
        QFile f( (std::string(":/images/") + filename).c_str() );
        f.copy(filename.c_str());
      }
      if (!boost::filesystem::exists(filename.c_str()))
      {
        std::cerr << "File not found: " << filename << '\n';
      }
      assert(boost::filesystem::exists(filename.c_str()));
    }
  }
  this->setContentAlignment(Wt::AlignCenter);
  {
    Wt::WLabel * const title = new Wt::WLabel("TestExercise");
    title->setStyleClass("title");
    this->addWidget(title);
  }
  //Menu
  {
    Wt::WStackedWidget * const contents = new Wt::WStackedWidget;
    Wt::WMenu * const menu = new Wt::WMenu(contents,Wt::Horizontal);
    menu->setStyleClass("menu");
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Welcome",
        CreateNewWelcomeDialog());
      menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Start",
        CreateNewMainDialog());
      menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "About",
        CreateNewAboutDialog());
      menu->addItem(item);
    }
    //Display menu on top
    this->addWidget(menu);
    this->addWidget(new Wt::WBreak);
    //Display contents below menu
    this->addWidget(contents);
  }
}
//---------------------------------------------------------------------------
Wt::WWidget * WtTestExerciseMenuDialog::CreateNewAboutDialog() const
{
  About a = m_dialog->GetAbout();
  a.AddLibrary("WtAutoConfig version: " + WtAutoConfig::GetVersion());
  a.AddLibrary("WtExercise version: " + WtExercise::GetVersion());
  a.AddLibrary("WtMultipleChoiceQuestionDialog version: " + WtMultipleChoiceQuestionDialog::GetVersion());
  a.AddLibrary("WtOpenQuestionDialog version: " + WtOpenQuestionDialog::GetVersion());
  a.AddLibrary("WtQuestionDialog version: " + WtQuestionDialog::GetVersion());
  WtAboutDialog * const d = new WtAboutDialog(a,false);
  assert(d);
  return d;
}
//---------------------------------------------------------------------------
Wt::WWidget * WtTestExerciseMenuDialog::CreateNewMainDialog() const
{
  WtTestExerciseMainDialog * const d = new WtTestExerciseMainDialog;
  assert(d);
  return d;
}
//---------------------------------------------------------------------------
Wt::WWidget * WtTestExerciseMenuDialog::CreateNewWelcomeDialog() const
{
  Wt::WContainerWidget * dialog = new Wt::WContainerWidget;
  dialog->setContentAlignment(Wt::AlignCenter);
  dialog->addWidget(new Wt::WBreak);
  new Wt::WLabel("Welcome to TestExercise",dialog);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  new Wt::WLabel("TestExercise tests the Exercise classes",dialog);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
   Wt::WGroupBox * const box = new Wt::WGroupBox("Explanation",dialog);
  box->addWidget(new Wt::WImage("ToolTestExerciseWelcome.png"));
  return dialog;
}
//---------------------------------------------------------------------------

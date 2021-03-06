//---------------------------------------------------------------------------
/*
TestLed, tool to test the Led class
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
//From http://www.richelbilderbeek.nl/ToolTestLed.htm
//---------------------------------------------------------------------------
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/numeric/conversion/cast.hpp>
//---------------------------------------------------------------------------
#include <Wt/WBreak>
#include <Wt/WGroupBox>
#include <Wt/WImage>
#include <Wt/WLabel>
#include <Wt/WPushButton>
#include <Wt/WStackedWidget>
#include <Wt/WMenu>
#include <Wt/WMenuItem>
//---------------------------------------------------------------------------
#include "about.h"
#include "simmysterymachinemenudialog.h"
#include "wtaboutdialog.h"
#include "wtautoconfig.h"
#include "wtdialwidget.h"
#include "wtledwidget.h"
#include "wtmysterymachinewidget.h"
#include "wtsimmysterymachinemaindialog.h"
#include "wtsimmysterymachinemenudialog.h"
#include "wttogglebuttonwidget.h"
//---------------------------------------------------------------------------
#include <QFile>
//---------------------------------------------------------------------------
WtSimMysteryMachineMenuDialog::WtSimMysteryMachineMenuDialog()
{
  {
    std::vector<std::string> image_names;
    image_names.push_back("ToolSimMysteryMachine.png");
    image_names.push_back("ToolSimMysteryMachineWelcome.png");

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
    Wt::WLabel * const title = new Wt::WLabel("SimMysteryMachine");
    title->setStyleClass("title");
    this->addWidget(title);
  }
  //Menu
  {
    Wt::WStackedWidget * const contents = new Wt::WStackedWidget;
    Wt::WMenu * const menu = new Wt::WMenu(contents,Wt::Horizontal);
    //Using CSS styleclass is the best (only?) way to display the menu well
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
Wt::WWidget * WtSimMysteryMachineMenuDialog::CreateNewAboutDialog() const
{
  About a = SimMysteryMachineMenuDialog::GetAbout();
  a.AddLibrary("WtAutoConfig version: " + WtAutoConfig::GetVersion());
  a.AddLibrary("WtDialWidget version: " + WtDialWidget::GetVersion());
  a.AddLibrary("WtLedWidget version: " + WtLedWidget::GetVersion());
  a.AddLibrary("WtMysteryMachineWidget version: " + WtMysteryMachineWidget::GetVersion());
  a.AddLibrary("WtToggleButtonWidget version: " + WtToggleButtonWidget::GetVersion());
  WtAboutDialog * const d = new WtAboutDialog(a,false);
  assert(d);
  return d;
}
//---------------------------------------------------------------------------
Wt::WWidget * WtSimMysteryMachineMenuDialog::CreateNewMainDialog() const
{
  WtSimMysteryMachineMainDialog * const d = new WtSimMysteryMachineMainDialog;
  assert(d);
  return d;
}
//---------------------------------------------------------------------------
Wt::WWidget * WtSimMysteryMachineMenuDialog::CreateNewWelcomeDialog() const
{
  Wt::WContainerWidget * dialog = new Wt::WContainerWidget;
  dialog->setContentAlignment(Wt::AlignCenter);
  dialog->addWidget(new Wt::WBreak);
  new Wt::WLabel("Welcome to SimMysteryMachine",dialog);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  new Wt::WLabel("SimMysteryMachine is a simulation of a machine",dialog);
  new Wt::WBreak(dialog);
  new Wt::WLabel("I designed and built.",dialog);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  new Wt::WLabel("What it does? That's a mystery...",dialog);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  {
    Wt::WGroupBox * const box = new Wt::WGroupBox("Explanation",dialog);
    box->addWidget(new Wt::WImage("ToolSimMysteryMachineWelcome.png"));
  }
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  {
    Wt::WGroupBox * const box = new Wt::WGroupBox("The real MysteryMachine (prototype)",dialog);
    box->addWidget(new Wt::WImage("ToolSimMysteryMachine.png"));
  }
  return dialog;
}
//---------------------------------------------------------------------------

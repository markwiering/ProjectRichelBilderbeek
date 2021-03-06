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
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
//---------------------------------------------------------------------------
#include <boost/filesystem.hpp>
//---------------------------------------------------------------------------
#include <Wt/WAnchor>
#include <Wt/WApplication>
#include <Wt/WBreak>
#include <Wt/WButtonGroup>
#include <Wt/WCheckBox>
#include <Wt/WFileResource>
#include <Wt/WFileUpload>
#include <Wt/WGroupBox>
#include <Wt/WImage>
#include <Wt/WLabel>
#include <Wt/WLineEdit>
#include <Wt/WMenu>
#include <Wt/WPushButton>
#include <Wt/WRadioButton>
#include <Wt/WStackedWidget>
#include <Wt/WTextArea>
//---------------------------------------------------------------------------
#include "administrator.h"
#include "administratordialog.h"
#include "administratordialogstateloggedin.h"
#include "administratordialogstateloggedin.h"
#include "all_groups.h"
#include "all_parameters.h"
#include "all_serverstates.h"
#include "group.h"
#include "groups.h"
#include "logfile.h"
#include "resources.h"
#include "server.h"
#include "shape.h"
#include "shapewidget.h"
#include "stopwatch.h"
#include "trace.h"
#include "wtserverpusher.h"
#include "wtselectfiledialog.h"
#include "wtshapegroupwidget.h"
#include "wtshapewidget.h"
//---------------------------------------------------------------------------
AdministratorDialogStateLoggedIn::AdministratorDialogStateLoggedIn(
  Server * const server,
  AdministratorDialog * const dialog)
  : AdministratorDialogState(server,dialog)

{
  m_safe_compile.m_select_file_dialog.reset(new WtSelectFileDialog);
}
//---------------------------------------------------------------------------
Wt::WContainerWidget * AdministratorDialogStateLoggedIn::CreateStartExperimentDialog()
{
  Wt::WContainerWidget * const dialog = new Wt::WContainerWidget;
  assert(dialog);

  ui.m_fileupload = new Wt::WFileUpload;
  ui.m_label_state_upload = new Wt::WLabel;

  assert(ui.m_fileupload);
  assert(ui.m_label_state_upload);

  dialog->setContentAlignment(Wt::AlignCenter);
  new Wt::WBreak(dialog);
  dialog->addWidget(ui.m_label_state_upload);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  dialog->addWidget(ui.m_fileupload);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);

  ui.m_label_state_upload->setText("Please select a file to upload or press the button");

  //Upload automatically when the user entered a file
  ui.m_fileupload->changed().connect(
    ui.m_fileupload,
    &Wt::WFileUpload::upload);

  //Call WtTextUploadDialog::on_upload_done when file is uploaded
  ui.m_fileupload->uploaded().connect(
    this,
    &AdministratorDialogStateLoggedIn::OnUploadDone);
  return dialog;
}
//---------------------------------------------------------------------------
Wt::WContainerWidget * AdministratorDialogStateLoggedIn::CreateViewGroupsDialog()
{
  Wt::WContainerWidget * const dialog = new Wt::WContainerWidget;
  assert(dialog);

  ui.m_text_groups = new Wt::WTextArea;
  ui.m_group_widget = new WtShapeGroupWidget;

  assert(ui.m_text_groups);
  assert(ui.m_group_widget);

  dialog->setContentAlignment(Wt::AlignCenter);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  dialog->addWidget(ui.m_group_widget);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  dialog->addWidget(ui.m_text_groups);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  new Wt::WImage("Groups.png",dialog);
  ui.m_text_groups->setReadOnly(true);
  ui.m_text_groups->setMinimumSize(600,200);
  ui.m_group_widget->resize(400,400);

  m_server->GetGroups()->m_signal_groups_changed.connect(
    boost::bind(&AdministratorDialogStateLoggedIn::OnGroupsChanged,this));
  ui.m_group_widget->SetShapes(ExtractShapes());

  return dialog;
}
//---------------------------------------------------------------------------
Wt::WContainerWidget * AdministratorDialogStateLoggedIn::CreateViewParametersDialog()
{
  Wt::WContainerWidget * const dialog = new Wt::WContainerWidget;
  assert(dialog);

  ui.m_text_parameter_file = new Wt::WTextArea;

  assert(ui.m_text_parameter_file);

  dialog->setContentAlignment(Wt::AlignCenter);
  new Wt::WBreak(dialog);
  ui.m_text_parameter_file->setReadOnly(true);
  ui.m_text_parameter_file->setMinimumSize(600,300);
  dialog->addWidget(ui.m_text_parameter_file);

  return dialog;
}
//---------------------------------------------------------------------------
Wt::WContainerWidget * AdministratorDialogStateLoggedIn::CreateViewParticipantsDialog()
{
  Wt::WContainerWidget * const dialog = new Wt::WContainerWidget;
  assert(dialog);

  ui.m_text_participants = new Wt::WTextArea;

  assert(ui.m_text_participants);

  dialog->setContentAlignment(Wt::AlignCenter);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  dialog->addWidget(ui.m_text_participants);
  ui.m_text_participants->setReadOnly(true);
  ui.m_text_participants->setMinimumSize(600,300);
  return dialog;
}
//---------------------------------------------------------------------------
Wt::WContainerWidget * AdministratorDialogStateLoggedIn::CreateViewServerDialog()
{
  Wt::WContainerWidget * const dialog = new Wt::WContainerWidget;
  assert(dialog);

  ui.m_server_anchor = new Wt::WAnchor;
  ui.m_label_state_server = new Wt::WLabel;
  ui.m_server_select_file_dialog = new WtSelectFileDialog;

  assert(ui.m_label_state_server);
  assert(ui.m_server_select_file_dialog);

  dialog->setContentAlignment(Wt::AlignCenter);
  new Wt::WBreak(dialog);
  dialog->addWidget(ui.m_label_state_server);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  dialog->addWidget(ui.m_server_select_file_dialog);
  dialog->addWidget(ui.m_server_anchor);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  {
    Wt::WPushButton * const button = new Wt::WPushButton("Stop and update server");
    dialog->addWidget(button);
    button->clicked().connect(this,&AdministratorDialogStateLoggedIn::OnStopServer);
  }

  ui.m_label_state_server->setText("Server state: ... (updated automatically)");
  ui.m_server_select_file_dialog->setMinimumSize(600,300);
  ui.m_server_select_file_dialog->SetFilter(".*(\\.xml|\\.txt|\\.sh)");
  ui.m_server_select_file_dialog->SetFilterReadOnly(true);

  ui.m_server_select_file_dialog->m_signal_selected.connect(
    boost::bind(&AdministratorDialogStateLoggedIn::OnViewLogFile,this));

  return dialog;
}
//---------------------------------------------------------------------------
const std::vector<std::vector<const Shape*> > AdministratorDialogStateLoggedIn::ExtractShapes() const
{

  std::vector<std::vector<const Shape*> > v;
  //Instead of collecting the GroupUnassigned, just add an empty group to v
  v.push_back(std::vector<const Shape*>());

  const auto groups = m_server->GetGroups()->CollectGroups(false,true,true,true);
  std::for_each(groups.begin(),groups.end(),
    [&v](const Group * const group)
    {
      std::vector<const Shape*> w;
      const std::vector<boost::shared_ptr<const Participant> > p
        = group->CollectParticipants();
      std::transform(
        p.begin(), p.end(),
        std::back_inserter(w),
        [](const boost::shared_ptr<const Participant>& i)
        {

          return i->GetChatShape()->GetWidget()->GetShape();
        }
      );
      assert(w.size() == p.size());
      v.push_back(w);
    }
  );
  return v;
}
//---------------------------------------------------------------------------
const std::string AdministratorDialogStateLoggedIn::GetExtension(const std::string& filename)
{
  const size_t i = filename.rfind('.');
  assert(i != std::string::npos && "Filename must contain a dot");
  assert(i != filename.size() - 1 && "Filename must not end with a dot");
  assert(filename[i+1] != '\\' && "Filename must have an extension");
  assert(filename[i+1] != '/' && "Filename must have an extension");
  return filename.substr(i+1,filename.size());
}
//---------------------------------------------------------------------------
void AdministratorDialogStateLoggedIn::OnGroupsChanged()
{
  TRACE_FUNC();
  ui.m_group_widget->SetShapes(ExtractShapes());

  //Display textual info
  {
    std::string text;
    //First display the Group its Participants
    const auto groups = m_server->GetGroups()->CollectGroups();
    std::for_each(groups.begin(),groups.end(),
      [&text](const Group * const group)
      {
        text+=std::string("Group #")
          + std::to_string(group->GetId())
          + std::string(" (")
          + group->ToStr()
          + std::string("):\n- Participants: ");
        const auto participants = group->CollectParticipants();
        std::for_each(participants.begin(),participants.end(),
          [&text](const boost::shared_ptr<const Participant>& participant)
          {
            text
              += (participant->CanGetId()
                ? std::to_string(participant->GetId())
                : std::string("no ID"))
              + std::string(", ");
          }
        );
        if (group->CollectParticipants().empty())
        {
          text+= "no participants";
        }
        else
        {
          assert(text.size() >= 2);
          //Pop trailing ', '
          text.resize(text.size() -2);
        }
        text+="\n- Payoffs: ";
        if (!group->GetAveragePayoffs().empty())
        {
          text
            +=std::string(" (")
            + std::to_string(
              group->GetAveragePayoffs().size())
            + std::string("): ");
          const auto payoffs = group->GetAveragePayoffs();
          std::for_each(payoffs.begin(),payoffs.end(),
            [&text](const double& payoff)
            {
              text
                += std::to_string(payoff)
                + std::string(", ");
            }
          );
          text.resize(text.size() - 2);
        }
        else
        {
          text+= "no payoffs assigned";
        }
        text+="\n";
      } );

    assert(!text.empty());
    ui.m_text_groups->setText(text.c_str());
    TRACE_FUNC();
  }
}
//---------------------------------------------------------------------------
///Stops the server
void AdministratorDialogStateLoggedIn::OnStopServer()
{
  Wt::WApplication::instance()->quit();
  std::exit(0);
}
//---------------------------------------------------------------------------
///Show all automatically
void AdministratorDialogStateLoggedIn::OnTimer()
{
   
  //server->Save("server.xml");

  //Update server state
  {
    const std::string text
      = std::string("Current server state: \'")
      + m_server->GetStates()->GetCurrentState()->ToStr()
      + std::string("\' (updated automatically)");
    assert(ui.m_label_state_server);
    ui.m_label_state_server->setText(text.c_str());
  }
  //Display Parameters
  {
    std::stringstream s;
    s << (*m_server->GetParameters());
    const std::vector<std::string> v = XmlToPretty(s.str());
    std::string text;
    std::for_each(v.begin(),v.end(),
      [&text](const std::string& t)
      {
        text += t + '\n';
      }
    );
    assert(!text.empty());
    text.resize(text.size() - 1);
    ui.m_text_parameter_file->setText(text.c_str());
  }
  //Display Participants
  {
    std::string text
      = "Number of participants: "
      + std::to_string(
        m_server->GetGroups()->CollectParticipants().size())
      + '\n';
    const auto participants = m_server->GetGroups()->CollectParticipants();
    std::for_each(participants.begin(),participants.end(),
      [&text](const boost::shared_ptr<const Participant>& participant)
      {
        text+=participant->ToAdminStr()+'\n';
      }
    );
    if (text.empty())
    {
      text = "[No participants]";
    }
    else
    {
      //Pop trailing newline
      text.resize(text.size() - 1);
    }
     ui.m_text_participants->setText(text.c_str());
  }
}
//---------------------------------------------------------------------------
void AdministratorDialogStateLoggedIn::ShowPage(AdministratorDialog * const dialog)
{
  assert(dialog);
  assert(IsLoggedIn() && "Assume a logged in administrator");

  new Wt::WLabel("Welcome administrator",dialog);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);

  //Menu
  {
    Wt::WStackedWidget * const contents = new Wt::WStackedWidget;
    Wt::WMenu * const menu = new Wt::WMenu(contents,Wt::Horizontal,dialog);
    //Using CSS styleclass is the best (only?) way to display the menu well
    menu->setStyleClass("menu");
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Start",
        CreateStartExperimentDialog());
      menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Groups",
        CreateViewGroupsDialog());
      menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Parameters",
        CreateViewParametersDialog());
      menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Participants",
        CreateViewParticipantsDialog());
      menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Server",
        CreateViewServerDialog());
      menu->addItem(item);
    }
    dialog->addWidget(contents);
  }
}
//---------------------------------------------------------------------------
void AdministratorDialogStateLoggedIn::OnUploadDone()
{
   
  assert(boost::filesystem::exists(ui.m_fileupload->spoolFileName()));
  //Display parameter file
  {
    const std::vector<std::string> v = FileToVector(ui.m_fileupload->spoolFileName());
    std::string text;
    std::for_each(v.begin(),v.end(),[&text](const std::string& s) { text+=(s+'\n'); } );
    //Pop trailing newline
    text.resize(text.size() - 1);
    assert(ui.m_text_parameter_file);
    ui.m_text_parameter_file->setText(text.c_str());
  }

  boost::shared_ptr<Parameters> parameters(new Parameters(m_server));
  assert(parameters);
  try
  {
    assert(boost::filesystem::exists(ui.m_fileupload->spoolFileName()));
    parameters->ReadFromFile(ui.m_fileupload->spoolFileName());
  }
  catch (std::runtime_error& e)
  {
    ui.m_label_state_upload->setText(e.what());
    return;
  }

  ui.m_label_state_upload->setText("OK: parameter file loaded");
  m_server->SetParameters(parameters);

  WtServerPusher::GetInstance()->Post();
}
//---------------------------------------------------------------------------
void AdministratorDialogStateLoggedIn::OnViewLogFile()
{
  const std::string filename = ui.m_server_select_file_dialog->GetSelectedFile();

  ui.m_server_anchor->setText((std::string("Download ") + ui.m_server_select_file_dialog->GetSelectedFile()).c_str() );
  ui.m_server_anchor->setResource(new Wt::WFileResource(ui.m_server_select_file_dialog->GetSelectedFile(),ui.m_server_select_file_dialog->GetSelectedFile()));
}
//---------------------------------------------------------------------------
const std::vector<std::string> AdministratorDialogStateLoggedIn::SplitXml(const std::string& s)
{
  std::vector<std::string> v;
  std::string::const_iterator i = s.begin();
  std::string::const_iterator j = s.begin();
  const std::string::const_iterator end = s.end();
  while (j!=end)
  {
    ++j;
    if ((*j=='>' || *j == '<') && std::distance(i,j) > 1)
    {
      std::string t;
      std::copy(
        *i=='<' ? i   : i+1,
        *j=='>' ? j+1 : j,
        std::back_inserter(t));
      v.push_back(t);
      i = j;
    }
  }
  return v;
}
//---------------------------------------------------------------------------
///Pretty-print an XML std::string
//From http://www.richelbilderbeek.nl/CppXmlToPretty.htm
const std::vector<std::string> AdministratorDialogStateLoggedIn::XmlToPretty(const std::string& s)
{
  std::vector<std::string> v = SplitXml(s);
  int n = -2;
  std::for_each(v.begin(),v.end(),
    [&n](std::string& s)
    {
      assert(!s.empty());
      if (s[0] == '<' && s[1] != '/')
      {
        n+=2;
      }
      s = std::string(n,' ') + s;
      if (s[n+0] == '<' && s[n+1] == '/')
      {
        n-=2;
      }
    }
  );
  return v;
}
//---------------------------------------------------------------------------

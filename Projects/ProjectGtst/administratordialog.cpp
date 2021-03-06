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
#include <Wt/WGroupBox>
#include <Wt/WLabel>
//---------------------------------------------------------------------------
#include "all_serverstates.h"
#include "administratordialog.h"
#include "administratordialogstateloggedin.h"
#include "administratordialogstatenotloggedin.h"
#include "led.h"
#include "ledwidget.h"
#include "logfile.h"
#include "server.h"
#include "stopwatch.h"
#include "wtledwidget.h"
#include "wtselectfiledialog.h"
//---------------------------------------------------------------------------
AdministratorDialog::AdministratorDialog(Server * const server)
  : m_state(0),
    m_state_logged_in(new AdministratorDialogStateLoggedIn(server,this)),
    m_state_not_logged_in(new AdministratorDialogStateNotLoggedIn(server,this))
{
  assert(!m_state);
  assert(m_state_logged_in);
  assert(m_state_not_logged_in);
  SetState(GetStateNotLoggedIn());
}
//---------------------------------------------------------------------------
AdministratorDialog::~AdministratorDialog()
{

}
//---------------------------------------------------------------------------
bool AdministratorDialog::CanGetAdministrator() const
{
  assert(m_administrator.empty() || m_administrator.size() == 1);
  return !m_administrator.empty();
}
//---------------------------------------------------------------------------
AdministratorDialog * AdministratorDialog::CreateDialogHeading()
{
  AdministratorDialog * const dialog = this->m_state->GetDialog();
  assert(dialog);

  dialog->clear();
  dialog->setContentAlignment(Wt::AlignCenter);

  #ifndef NDEBUG
  ui.m_led = new WtLedWidget(1.0);
  ui.m_led->GetWidget()->SetGeometry(Rect(0,0,24,24));
  dialog->addWidget(ui.m_led);
  #endif

  return dialog;
}
//---------------------------------------------------------------------------
boost::weak_ptr<Administrator> AdministratorDialog::GetAdministrator() const
{
  assert(CanGetAdministrator());
  assert(m_administrator.size() == 1);
  return m_administrator[0];
}
//---------------------------------------------------------------------------
AdministratorDialogStateLoggedIn * AdministratorDialog::GetStateLoggedIn() const
{
  assert(m_state_logged_in);
  return m_state_logged_in.get();
}
//---------------------------------------------------------------------------
AdministratorDialogStateNotLoggedIn * AdministratorDialog::GetStateNotLoggedIn() const
{
  assert(m_state_not_logged_in);
  return m_state_not_logged_in.get();
}
//---------------------------------------------------------------------------
void AdministratorDialog::SetState(AdministratorDialogState * const state)
{
  assert(state);
  m_state = state;
  assert(m_state);
  m_state->ShowPage(CreateDialogHeading());
}
//---------------------------------------------------------------------------
void AdministratorDialog::OnServerPush()
{
  //OnServerTimer();
  this->m_state->OnTimer();
}
//---------------------------------------------------------------------------
void AdministratorDialog::SetAdministrator(boost::weak_ptr<Administrator> administrator)
{
  assert(m_administrator.empty());
  m_administrator.push_back(administrator);
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------

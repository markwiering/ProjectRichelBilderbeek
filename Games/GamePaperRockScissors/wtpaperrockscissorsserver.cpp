//---------------------------------------------------------------------------
/*
PaperRockScissors, time polling server
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
//From http://www.richelbilderbeek.nl/ToolPaperRockScissors.htm
//---------------------------------------------------------------------------
//#include <algorithm>
#include <numeric>
//---------------------------------------------------------------------------
#include <boost/numeric/conversion/cast.hpp>
//---------------------------------------------------------------------------
#include "wtpaperrockscissorsserver.h"
//#include "wtpaperrockscissorsdialogstate.h"
//---------------------------------------------------------------------------
boost::scoped_ptr<WtPaperRockScissorsServer> WtPaperRockScissorsServer::m_instance;
//---------------------------------------------------------------------------
#undef NDEBUG
#include <cassert>
//---------------------------------------------------------------------------
WtPaperRockScissorsServer::WtPaperRockScissorsServer()
{

}
//---------------------------------------------------------------------------
WtPaperRockScissorsServer * WtPaperRockScissorsServer::GetInstance()
{
  if (!m_instance) m_instance.reset(new WtPaperRockScissorsServer);
  return m_instance.get();
}
//---------------------------------------------------------------------------
///A client sends a message to the server
void WtPaperRockScissorsServer::SendMessageToServer(const int index)
{
  boost::mutex::scoped_lock lock(m_mutex);

  //const std::vector<double> fractions = GetCurrentFractions();
  //Update the current index
  //m_current_index = index;

  //The server emits the message to the clients
  m_change_index_event.emit(
    WtPaperRockScissorsEvent(
      0,std::vector<double>()));
}
//---------------------------------------------------------------------------

//---------------------------------------------------------------------------
/*
WtServerPusher, server to broadcast to all its WtServerPusherClients
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
//From http://www.richelbilderbeek.nl/CppWtServerPusher.htm
//---------------------------------------------------------------------------
#include <algorithm>
#include <chrono>
#include <numeric>
//---------------------------------------------------------------------------
#include <boost/bind.hpp>
//---------------------------------------------------------------------------
#include <Wt/WApplication>
#include <Wt/WServer>
//---------------------------------------------------------------------------
#include "wtserverpusher.h"
//---------------------------------------------------------------------------
boost::scoped_ptr<WtServerPusher> WtServerPusher::m_instance;
//---------------------------------------------------------------------------
WtServerPusher::WtServerPusher()
{

}
//---------------------------------------------------------------------------
WtServerPusher::~WtServerPusher()
{

}
//---------------------------------------------------------------------------
void WtServerPusher::Connect(
   WtServerPusherClient * const client,
   const boost::function<void()>& function)
{
  std::lock_guard<std::mutex> lock(m_mutex);

  m_connections.push_back(
    Connection(
      Wt::WApplication::instance()->sessionId(),
      client,
      function));
}
//---------------------------------------------------------------------------
void WtServerPusher::Disconnect(const WtServerPusherClient* const client)
{
  std::lock_guard<std::mutex> lock(m_mutex);
  m_connections.erase(
    std::remove_if(m_connections.begin(),m_connections.end(),
      [client](const Connection& c) { return c.m_client == client; } ));
}
//---------------------------------------------------------------------------
WtServerPusher * WtServerPusher::GetInstance()
{
  if (!m_instance) m_instance.reset(new WtServerPusher);
  return m_instance.get();
}
//---------------------------------------------------------------------------
const std::string WtServerPusher::GetVersion()
{
  return "1.0";
}
//---------------------------------------------------------------------------
const std::vector<std::string> WtServerPusher::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2011-08-05: version 1.0: initial version");
  return v;
}
//---------------------------------------------------------------------------
void WtServerPusher::Post()
{
  ///Let this thread sleep, to give the other thread a chance
  //std::this_thread::sleep_for(std::chrono::milliseconds(10));
  std::lock_guard<std::mutex> lock(m_mutex);

  std::for_each(m_connections.begin(),m_connections.end(),
    [](const Connection& i) { Wt::WServer::instance()->post(i.m_session_id, i.m_function); });
}
//---------------------------------------------------------------------------

#ifndef QTK3OPEENRIJRESOURCES_H
#define QTK3OPEENRIJRESOURCES_H

#include <boost/logic/tribool.hpp>

#include "connectthreeresources.h"

///QtK3OpEenRijResources is a class containing
///all filenames to be used by the program
///Its base class, ConnectThreeResources,
///ensures the files needed are present upon construction.
struct QtK3OpEenRijResources
  : public ConnectThreeResources
{
  QtK3OpEenRijResources(const boost::logic::tribool is_player3_kathleen
    = boost::logic::indeterminate);

  private:

  const std::vector<std::string> CreatePlayerNames(const boost::logic::tribool is_player3_kathleen);
  const std::vector<std::string> CreatePlayerGreyNames(const boost::logic::tribool is_player3_kathleen);
};

#endif // QTK3OPEENRIJRESOURCES_H

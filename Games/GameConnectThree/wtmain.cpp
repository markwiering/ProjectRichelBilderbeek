//---------------------------------------------------------------------------
//#include <QFile>
//---------------------------------------------------------------------------
#include <Wt/WApplication>
#include <Wt/WEnvironment>
//---------------------------------------------------------------------------
#include "wtautoconfig.h"
#include "wtconnectthreemenudialog.h"
#include "connectthreeresources.h"
//---------------------------------------------------------------------------
//Enable debugging
#undef NDEBUG
#include <cassert>
//---------------------------------------------------------------------------
struct WtConnectThreeApplication : public Wt::WApplication
{
  WtConnectThreeApplication(const Wt::WEnvironment& env)
    : Wt::WApplication(env)
  {
    this->setTitle("ConnectThree");
    this->useStyleSheet("wt.css");
    root()->addWidget(new WtConnectThreeMenuDialog);
  }
};
//---------------------------------------------------------------------------
Wt::WApplication * createApplication(const Wt::WEnvironment& env)
{
  return new WtConnectThreeApplication(env);
}
//---------------------------------------------------------------------------
int main(int argc, char **argv)
{
  WtAutoConfig a(argc,argv,createApplication);
  WtAutoConfig::SaveDefaultStylesheet();
  return a.Run();
}
//---------------------------------------------------------------------------


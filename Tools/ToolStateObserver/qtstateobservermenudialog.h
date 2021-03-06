#ifndef QTSTATEOBSERVERMENUDIALOG_H
#define QTSTATEOBSERVERMENUDIALOG_H

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#include "qthideandshowdialog.h"

namespace Ui {
class QtStateObserverMenuDialog;
}

class QtStateObserverMenuDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtStateObserverMenuDialog(QWidget *parent = 0);
  ~QtStateObserverMenuDialog();

private slots:
  void on_button_start_clicked();
  void on_button_about_clicked();
  void on_button_quit_clicked();

private:
  Ui::QtStateObserverMenuDialog *ui;
};

#endif // QTSTATEOBSERVERMENUDIALOG_H

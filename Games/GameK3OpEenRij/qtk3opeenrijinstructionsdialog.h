#ifndef QTK3OPEENRIJINSTRUCTIONSDIALOG_H
#define QTK3OPEENRIJINSTRUCTIONSDIALOG_H

#include "qthideandshowdialog.h"

namespace Ui {
  class QtK3OpEenRijInstructionsDialog;
}

class QtK3OpEenRijInstructionsDialog : public QtHideAndShowDialog
{
  Q_OBJECT
  
public:
  explicit QtK3OpEenRijInstructionsDialog(QWidget *parent = 0);
  ~QtK3OpEenRijInstructionsDialog();
  
private:
  Ui::QtK3OpEenRijInstructionsDialog *ui;
};

#endif // QTK3OPEENRIJINSTRUCTIONSDIALOG_H

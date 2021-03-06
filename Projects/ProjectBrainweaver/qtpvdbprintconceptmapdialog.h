#ifndef QTPVDBPRINTCONCEPTMAPDIALOG_H
#define QTPVDBPRINTCONCEPTMAPDIALOG_H

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#include <boost/shared_ptr.hpp>

#include "pvdbfwd.h"
#include "qthideandshowdialog.h"

namespace Ui {
  class QtPvdbPrintConceptMapDialog;
}

///View the current work, optimized for humans
///This dialog will not be visible for humans at all in release
///QtPvdbPrintConceptMapDialog is optimized for printers
class QtPvdbPrintConceptMapDialog : public QtHideAndShowDialog
{
  Q_OBJECT
  
public:
  ///file be const, as the Display Concept map cannot deal with const pvdb::ConceptMap (yet?)
  explicit QtPvdbPrintConceptMapDialog(
    const boost::shared_ptr<pvdb::File>& file,
    QWidget *parent = 0);
  ~QtPvdbPrintConceptMapDialog();
  void Print();

protected:
  void keyPressEvent(QKeyEvent * event);
  void showEvent(QShowEvent *);

private slots:
  void on_button_print_clicked();

private:
  Ui::QtPvdbPrintConceptMapDialog *ui;

  ///m_file be const, as the Display Concept map cannot deal with const pvdb::ConceptMap (yet?)
  const boost::shared_ptr<pvdb::File> m_file;

  QtPvdbConceptMapDisplayWidget * const m_widget;

  const std::vector<QWidget *> CollectWidgets() const;

};

#endif // QTPVDBPRINTCONCEPTMAPDIALOG_H

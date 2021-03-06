#ifndef QTKALMANFILTERERMAINDIALOG_H
#define QTKALMANFILTERERMAINDIALOG_H

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorPperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <boost/shared_ptr.hpp>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/vector.hpp>

#include <QDialog>
#include <QTableWidget>

#include "qwt_plot.h"

///NEVER FORGET: Do never use forward declarations in header files parsed by MOC
#include "kalmanfilterexperiment.h"
#include "qthideandshowdialog.h"
#include "qtkalmanfilterexperimentdialog.h"
#include "qtkalmanfilterexperimentmodel.h"
#include "qtstandardkalmanfiltercalculationdialog.h"
#include "qtsteadystatekalmanfiltercalculationdialog.h"
#include "qtwhitenoisesystemparametersdialog.h"

#pragma GCC diagnostic pop


namespace Ui {
  class QtKalmanFiltererMainDialog;
}

class QtKalmanFiltererMainDialog : public QtHideAndShowDialog
{
  Q_OBJECT
  
public:
  explicit QtKalmanFiltererMainDialog(
    const boost::shared_ptr<QtKalmanFilterExperimentModel> model,
    QWidget *parent = 0);
  ~QtKalmanFiltererMainDialog();

  ///Get the dialog to set the experiment its parameters
  const QtKalmanFilterExperimentDialog * GetExperimentDialog() const { return m_experiment_dialog; }

  ///Set the checkbox to show the calculation
  void SetShowCalculation(const bool do_show);

  ///Set the checkbox to show the graphs
  void SetShowGraph(const bool do_show);

  ///Set the checkbox to show the statistics
  void SetShowStatistics(const bool do_show);

  ///Set the checkbox to show the table
  void SetShowTable(const bool do_show);

  ///Create a QtKalmanFiltererMainDialog
  static boost::shared_ptr<QtKalmanFiltererMainDialog> Create();

protected:
  void keyPressEvent(QKeyEvent * event);
  
private:
  Ui::QtKalmanFiltererMainDialog *ui;

  ///The dialog to set the experiment its parameters
  QtKalmanFilterExperimentDialog * const m_experiment_dialog;

  ///Contains the widgets that must be deleted at a new run
  ///these must be stored because deleting
  ///the layout that contains these does not work properly
  std::vector<boost::shared_ptr<QWidget> > m_to_delete_at_new_run;

  ///The model
  const boost::shared_ptr<QtKalmanFilterExperimentModel> m_model;

  ///Contains the plots, these must be stored because deleting
  ///the layout that contains these does not work properly
  std::vector<boost::shared_ptr<QwtPlot> > m_plots;


  static const std::vector<std::vector<double> > CreateData(
    const std::vector<boost::numeric::ublas::vector<double> >& a,
    const std::vector<boost::numeric::ublas::vector<double> >& b,
    const std::vector<boost::numeric::ublas::vector<double> >& c,
    const std::vector<boost::numeric::ublas::vector<double> >& d
    );

  const boost::shared_ptr<QtKalmanFilterCalculationDialog> CreateKalmanFilterCalculationDialog(
    const KalmanFilterType type) const;

  const std::vector<double> ExtractAverageSquaredError(
    const boost::shared_ptr<const KalmanFilterExperiment>& experiment);

  ///Called when a new context is set in m_model
  void OnNewContext(const std::string context);

  ///Show the results of an experiment in a calculation
  void ShowCalculation(const boost::shared_ptr<const KalmanFilterExperiment>& experiment);

  ///Show the results of an experiment in a graph
  void ShowGraph(const boost::shared_ptr<const KalmanFilterExperiment>& experiment);

  ///Show the results of an experiment its statistics
  void ShowStatistics(const boost::shared_ptr<const KalmanFilterExperiment>& experiment);

  ///Show the results of an experiment in a table
  void ShowTable(const boost::shared_ptr<const KalmanFilterExperiment>& experiment);

  #ifndef NDEBUG
  ///Test this class
  static void Test();
  #endif

private slots:
  void on_button_start_clicked();
  void on_button_save_graph_clicked();
  void on_tab_context_currentChanged(int index);
  void on_edit_context_textChanged();
};

#endif // QTKALMANFILTERERMAINDIALOG_H

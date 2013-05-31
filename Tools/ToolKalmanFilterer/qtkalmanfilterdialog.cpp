#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtkalmanfilterdialog.h"

#include <cassert>

#include <boost/lexical_cast.hpp>

#include <QTableWidgetItem>
#include <QVBoxLayout>

#include "matrix.h"
#include "qtmatrix.h"
#include "standardkalmanfilter.h"
#include "standardkalmanfilterfactory.h"
#include "steadystatekalmanfilter.h"
#include "kalmanfilterparameter.h"
#include "fixedlagsmootherkalmanfilter.h"
#include "steadystatekalmanfilterfactory.h"
#include "kalmanfilterexperimentparameter.h"
#include "trace.h"
#include "ui_qtkalmanfilterdialog.h"

QtKalmanFilterDialog::QtKalmanFilterDialog(
  const boost::shared_ptr<QtKalmanFilterExperimentModel> model,
  QWidget *parent)
  : QDialog(parent),
    ui(new Ui::QtKalmanFilterDialog),
    m_model(model)
{
  assert(m_model);

  ui->setupUi(this);

  //Create the map
  {
    const std::vector<KalmanFilterParameterType> v = this->GetParameterTypes();
    const std::size_t sz = v.size();
    for (std::size_t i=0; i!=sz; ++i)
    {
      assert(i < v.size());

      const KalmanFilterParameterType type = v[i];

      QtKalmanFiltererParameterDialog * const dialog
        = new QtKalmanFiltererParameterDialog(
          KalmanFilterParameter::ToName(type),
          KalmanFilterParameter::ToDescription(type),
          m_model->Find( KalmanFilterExperimentParameter::ConvertToKalmanFilterExperimentParameter(v[i]) )
        );
      assert(dialog);

      //Add to map
      m_parameters.insert(std::make_pair(type,dialog));

      //Add to dialog
      assert(this->layout());
      this->layout()->addWidget(dialog);

    }
    assert(boost::numeric_cast<int>(v.size()) == static_cast<int>(KalmanFilterParameterType::n_parameters)
      && "All parameters must be in");
  }

  this->setFocusPolicy(Qt::NoFocus);
  this->on_box_filter_type_currentIndexChanged(0);
  //assert(this->GetKalmanFilter() && "Can get an empty Kalman filter, with all sizes equal to zero");
}

QtKalmanFilterDialog::~QtKalmanFilterDialog()
{
  delete ui;
}

/*
bool QtKalmanFilterDialog::AreAllParametersValid() const
{
  const auto j = m_parameters.end();
  for (auto i = m_parameters.begin(); i!=j; ++i)
  {
    const KalmanFilterParameterType type = (*i).first;
    //Is the type present in the current type of Kalman filter?
    switch (this->GetKalmanFilterType())
    {
      case KalmanFilterType::standard:
        if (!StandardKalmanFilterParameters::HasParameterType(type)) continue;
        break;
      case KalmanFilterType::steady_state:
        if (!SteadyStateKalmanFilterParameters::HasParameterType(type)) continue;
        break;
      case KalmanFilterType::n_types:
        assert(!"Unimplemented KalmanFilterType");
        throw std::logic_error(__func__);
    }
  }
  return true;
}
*/

KalmanFilterType QtKalmanFilterDialog::GetKalmanFilterType() const
{
  switch (ui->box_filter_type->currentIndex())
  {
    case 0: return KalmanFilterType::standard;
    case 1: return KalmanFilterType::steady_state;
    case 2: return KalmanFilterType::fixed_lag_smoother;
    default: assert(!"Unimplemented ComboBox index");
      throw std::logic_error(__func__);
  }
}


const std::vector<KalmanFilterParameterType> QtKalmanFilterDialog::GetParameterTypes() const
{
  const std::vector<KalmanFilterParameterType> v
    =
    {
      KalmanFilterParameterType::initial_state_estimate,             //x
      KalmanFilterParameterType::initial_covariance_estimate,        //P
      KalmanFilterParameterType::state_transition,                   //A
      KalmanFilterParameterType::control,                            //B
      KalmanFilterParameterType::observation,                        //H
      KalmanFilterParameterType::estimated_optimal_kalman_gain,      //K
      KalmanFilterParameterType::estimated_process_noise_covariance, //Q
      KalmanFilterParameterType::estimated_measurement_noise         //R
    };
  assert(v.size() == KalmanFilterParameter::GetAll().size());
  return v;
}


void QtKalmanFilterDialog::SetKalmanFilterType(const KalmanFilterType new_type)
{
  switch (new_type)
  {
    case KalmanFilterType::standard: ui->box_filter_type->setCurrentIndex(0); break;
    case KalmanFilterType::steady_state: ui->box_filter_type->setCurrentIndex(1); break;
    case KalmanFilterType::fixed_lag_smoother: ui->box_filter_type->setCurrentIndex(2); break;
    case KalmanFilterType::n_types:
      assert(!"Unimplemented KalmanFilterType");
  }
  assert(this->GetKalmanFilterType() == new_type);
}

void QtKalmanFilterDialog::on_button_calculate_optimal_kalman_gain_steady_state_clicked()
{
  m_model->CalculateOptimalEstimatedKalmanGain();
}

void QtKalmanFilterDialog::on_box_filter_type_currentIndexChanged(int)
{

  //Update the GUI
  switch (this->GetKalmanFilterType())
  {
    case KalmanFilterType::standard:
    {
      const auto j = m_parameters.end();
      for (auto i = m_parameters.begin(); i!=j; ++i)
      {
        ((*i).second)->setVisible(StandardKalmanFilterParameters::HasParameterType((*i).first));
      }
      ui->box_estimated_lag->setVisible(false);
      ui->label_estimated_lag->setVisible(false);
      ui->button_calculate_optimal_kalman_gain_steady_state->setVisible(false);
    }
    break;
    case KalmanFilterType::steady_state:
    {
      const auto j = m_parameters.end();
      for (auto i = m_parameters.begin(); i!=j; ++i)
      {
        ((*i).second)->setVisible(SteadyStateKalmanFilterParameters::HasParameterType((*i).first));
      }
      ui->box_estimated_lag->setVisible(false);
      ui->label_estimated_lag->setVisible(false);
      ui->button_calculate_optimal_kalman_gain_steady_state->setVisible(true);
    }
    break;
    case KalmanFilterType::fixed_lag_smoother:
    {
      const auto j = m_parameters.end();
      for (auto i = m_parameters.begin(); i!=j; ++i)
      {
        ((*i).second)->setVisible(FixedLagSmootherKalmanFilterParameters::HasParameterType((*i).first));
      }
      ui->box_estimated_lag->setVisible(true);
      ui->label_estimated_lag->setVisible(true);
      ui->button_calculate_optimal_kalman_gain_steady_state->setVisible(false);
    }
    break;
    case KalmanFilterType::n_types:
      assert(!"Unimplemented Kalman filter type");
  }

  //Notify the model
  m_model->SetKalmanFilterType(this->GetKalmanFilterType());

  emit signal_kalman_filter_type_changed( this->GetKalmanFilterType() );
}
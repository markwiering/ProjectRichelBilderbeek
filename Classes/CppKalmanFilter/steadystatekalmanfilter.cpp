#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "steadystatekalmanfilter.h"

#include <boost/numeric/conversion/cast.hpp>

#include "matrix.h"
#include "trace.h"

SteadyStateKalmanFilter::SteadyStateKalmanFilter(
  const boost::shared_ptr<KalmanFilterCalculationElements>& calculation,
  const boost::shared_ptr<const KalmanFilterParameters>& parameters)
  : KalmanFilter(calculation,parameters),
    m_last_calculation(boost::dynamic_pointer_cast<SteadyStateKalmanFilterCalculationElements>(calculation)),
    m_parameters(dynamic_cast<const SteadyStateKalmanFilterParameters*>(parameters.get()))
{
  assert(m_last_calculation);
  assert(m_parameters);
  assert(this->GetType() == m_parameters->GetType());
  assert(this->GetType() == GetParameters()->GetType()
    && "Initialize each Kalman filter type with the right type of parameters");

  m_state_estimate = m_parameters->GetInitialStateEstimate();

  #ifndef NDEBUG
  //Check for correct dimensionality
  const auto sz = m_state_estimate.size();
  assert(m_parameters->GetControl().size1() == sz);
  assert(m_parameters->GetControl().size2() == sz);
  assert(m_parameters->GetEstimatedOptimalKalmanGain().size1() == sz);
  assert(m_parameters->GetEstimatedOptimalKalmanGain().size2() == sz);
  assert(m_parameters->GetObservation().size1() == sz);
  assert(m_parameters->GetObservation().size2() == sz);
  assert(m_parameters->GetStateTransition().size1() == sz);
  assert(m_parameters->GetStateTransition().size2() == sz);
  assert(m_state_estimate.size() == sz);
  #endif

  //Initialize the last calculation with null values
  //NEW 2013-05-23
  //m_last_calculation->SetMeasurement(
  //  boost::numeric::ublas::zero_vector<double>(m_state_estimate.size()));
  //m_last_calculation->SetPredictedState(m_parameters->GetInitialStateEstimate());
  //m_last_calculation->SetPreviousStateEstimate(m_parameters->GetInitialStateEstimate());
  //m_last_calculation->SetUpdatedState(m_parameters->GetInitialStateEstimate());
}

int SteadyStateKalmanFilter::GetStateSize() const
{
  const int sz = boost::numeric_cast<int>(m_state_estimate.size());
  return sz;
}

const std::string SteadyStateKalmanFilter::GetVersion()
{
  return "1.1";
}

const std::vector<std::string> SteadyStateKalmanFilter::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2013-05-01: version 1.0: initial version");
  v.push_back("2013-05-06: version 1.1: inherits from KalmanFilter");
  return v;
}

const boost::numeric::ublas::vector<double> SteadyStateKalmanFilter::PredictState(
  const boost::numeric::ublas::vector<double>& input) const
{
  const boost::numeric::ublas::matrix<double> term_a
    = m_parameters->GetStateTransition()
    - Matrix::Prod(
      m_parameters->GetEstimatedOptimalKalmanGain(),
      m_parameters->GetObservation()
    );

  //m_last_measured must be set before calling PredictState!
  assert(!m_last_calculation->GetMeasurement().empty());

  const boost::numeric::ublas::vector<double> state_prediction
    = Matrix::Prod(term_a,this->GetStateEstimate())
    + Matrix::Prod(m_parameters->GetControl(),input)
    + Matrix::Prod(m_parameters->GetEstimatedOptimalKalmanGain(),m_last_calculation->GetMeasurement());
  return state_prediction;
}

void SteadyStateKalmanFilter::SupplyMeasurementAndInput(
  const boost::numeric::ublas::vector<double>& measurements,
  const boost::numeric::ublas::vector<double>& input)
{
  
  assert(measurements.size() == input.size());

  //Store the calculation
  m_last_calculation->Clear();
  assert(!m_last_calculation->IsComplete());
  m_last_calculation->SetPreviousStateEstimate(this->GetStateEstimate());

  //m_last_calculation->SetMeasurement must be set before calling PredictState!
  m_last_calculation->SetMeasurement(measurements);

  // 1/1) State prediction
  const boost::numeric::ublas::vector<double> state_prediction = PredictState(input);
  m_state_estimate = state_prediction;

  //Store the calculation
  m_last_calculation->SetPredictedState(state_prediction);
  m_last_calculation->SetUpdatedState(GetStateEstimate());
  assert(m_last_calculation->IsComplete());
}


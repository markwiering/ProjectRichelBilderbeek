#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "steadystatekalmanfilterparameters.h"

#include <cassert>

#include "matrix.h"

SteadyStateKalmanFilterParameters::SteadyStateKalmanFilterParameters(
  const boost::numeric::ublas::matrix<double>& control,
  const boost::numeric::ublas::matrix<double>& estimated_optimal_kalman_gain,
  const boost::numeric::ublas::vector<double>& initial_state_estimate,
  const boost::numeric::ublas::matrix<double>& observation,
  const boost::numeric::ublas::matrix<double>& state_transition)
  : KalmanFilterParameters(control,initial_state_estimate,observation,state_transition),
    m_estimated_optimal_kalman_gain(estimated_optimal_kalman_gain)
{
  #ifndef NDEBUG
  //Check for correct dimensionality
  const std::size_t sz = GetInitialStateEstimate().size();
  //assert(sz >= 0); //Inevitable for std::size_t
  assert(GetEstimatedOptimalKalmanGain().size1() == sz);
  assert(GetEstimatedOptimalKalmanGain().size2() == sz);
  #endif
}

const boost::numeric::ublas::matrix<double> SteadyStateKalmanFilterParameters::CalculateOptimalKalmanGain(
  const boost::numeric::ublas::matrix<double>& initial_covariance,
  const boost::numeric::ublas::matrix<double>& measurement_noise,
  const boost::numeric::ublas::matrix<double>& observation,
  const boost::numeric::ublas::matrix<double>& state_transition)
{
  const boost::numeric::ublas::matrix<double>& a = state_transition;
  const boost::numeric::ublas::matrix<double>& c = observation;
  const boost::numeric::ublas::matrix<double>& p = initial_covariance;
  const boost::numeric::ublas::matrix<double>& r = measurement_noise;

  const boost::numeric::ublas::matrix<double> term_a
    = Matrix::MultiProd(a,p,boost::numeric::ublas::trans(c));
  if (Matrix::CalcDeterminant(term_a + r) == 0.0)
  {
    throw std::runtime_error("Optimal Kalman gain matrix is degenerate");
  }
  const boost::numeric::ublas::matrix<double> k
    = Matrix::Prod(term_a,Matrix::Inverse(term_a + r));

  return k;

}

const std::string SteadyStateKalmanFilterParameters::GetVersion()
{
  return "1.1";
}

const std::vector<std::string> SteadyStateKalmanFilterParameters::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2013-05-01: version 1.0: initial version");
  v.push_back("2013-05-03: version 1.1: inherit from KalmanFilterParameters");
  return v;
}

bool SteadyStateKalmanFilterParameters::HasParameterType(const KalmanFilterParameterType type)
{
  return
       type == KalmanFilterParameterType::control
    || type == KalmanFilterParameterType::estimated_optimal_kalman_gain
    || type == KalmanFilterParameterType::initial_state_estimate
    || type == KalmanFilterParameterType::observation
    || type == KalmanFilterParameterType::state_transition;
}

bool SteadyStateKalmanFilterParameters::IsAboutEqual(
  const SteadyStateKalmanFilterParameters& lhs,
  const SteadyStateKalmanFilterParameters& rhs)
{
  return
       Matrix::MatricesAreAboutEqual(lhs.GetControl(),rhs.GetControl())
    && Matrix::MatricesAreAboutEqual(lhs.GetEstimatedOptimalKalmanGain(),rhs.GetEstimatedOptimalKalmanGain())
    && Matrix::VectorsAreAboutEqual(lhs.GetInitialStateEstimate(),rhs.GetInitialStateEstimate())
    && Matrix::MatricesAreAboutEqual(lhs.GetObservation(),rhs.GetObservation())
    && Matrix::MatricesAreAboutEqual(lhs.GetStateTransition(),rhs.GetStateTransition());
}

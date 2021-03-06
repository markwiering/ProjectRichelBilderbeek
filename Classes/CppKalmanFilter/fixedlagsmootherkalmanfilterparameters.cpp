#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "fixedlagsmootherkalmanfilterparameters.h"

#include <cassert>

#include "standardkalmanfilterparameters.h"

FixedLagSmootherKalmanFilterParameters::FixedLagSmootherKalmanFilterParameters(
  const boost::shared_ptr<StandardKalmanFilterParameters>& standard_parameters,
  const int lag)
  : KalmanFilterParameters(
      standard_parameters->GetControl(),
      standard_parameters->GetInitialStateEstimate(),
      standard_parameters->GetObservation(),
      standard_parameters->GetStateTransition()),
    m_lag(lag),
    m_standard_parameters(standard_parameters)
{
  assert(lag >= 0);
  assert(m_standard_parameters);
}

bool FixedLagSmootherKalmanFilterParameters::HasParameterType(const KalmanFilterParameterType type)
{
  return StandardKalmanFilterParameters::HasParameterType(type);
}

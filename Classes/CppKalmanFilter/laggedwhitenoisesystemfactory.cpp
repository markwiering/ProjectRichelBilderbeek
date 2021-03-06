#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "laggedwhitenoisesystemfactory.h"

const boost::shared_ptr<LaggedWhiteNoiseSystem> LaggedWhiteNoiseSystemFactory::Create(
  const boost::numeric::ublas::matrix<double>& control,
  const boost::numeric::ublas::vector<double>& initial_state,
  const int lag,
  const boost::numeric::ublas::vector<double>& real_measurement_noise,
  const boost::numeric::ublas::vector<double>& real_process_noise,
  const boost::numeric::ublas::matrix<double>& state_transition)
{
  const boost::shared_ptr<const WhiteNoiseSystemParameters> parameters(
    new LaggedWhiteNoiseSystemParameters(
      control,
      initial_state,
      lag,
      real_measurement_noise,
      real_process_noise,
      state_transition));
  assert(parameters);

  const boost::shared_ptr<LaggedWhiteNoiseSystem> system(
    new LaggedWhiteNoiseSystem(parameters));
  assert(system);
  return system;
}

const boost::shared_ptr<LaggedWhiteNoiseSystem> LaggedWhiteNoiseSystemFactory::Create(
  const boost::shared_ptr<WhiteNoiseSystemParameters>& parameters)
{
  assert(parameters);
  assert(parameters->GetType() == WhiteNoiseSystemType::lagged);
  const boost::shared_ptr<LaggedWhiteNoiseSystemParameters> lagged_parameters
    = boost::dynamic_pointer_cast<LaggedWhiteNoiseSystemParameters>(parameters);
  assert(lagged_parameters);

  const boost::shared_ptr<LaggedWhiteNoiseSystem> my_system
    = Create(
      lagged_parameters->GetControl(),
      lagged_parameters->GetInitialState(),
      lagged_parameters->GetLag(),
      lagged_parameters->GetMeasurementNoise(),
      lagged_parameters->GetProcessNoise(),
      lagged_parameters->GetStateTransition());
  assert(my_system);
  return my_system;
}

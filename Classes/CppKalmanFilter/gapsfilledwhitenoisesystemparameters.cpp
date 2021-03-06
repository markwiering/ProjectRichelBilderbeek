#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "gapsfilledwhitenoisesystemparameters.h"

#include <cassert>

#include "standardwhitenoisesystemparameters.h"
#include "trace.h"

GapsFilledWhiteNoiseSystemParameters::GapsFilledWhiteNoiseSystemParameters(
    const boost::numeric::ublas::matrix<double>& control,
    const boost::numeric::ublas::vector<double>& initial_state,
    const boost::numeric::ublas::vector<int>& measurement_frequency,
    const boost::numeric::ublas::vector<double>& real_measurement_noise,
    const boost::numeric::ublas::vector<double>& real_process_noise,
    const boost::numeric::ublas::matrix<double>& state_transition)
  : WhiteNoiseSystemParameters(
      control,
      initial_state,
      real_measurement_noise,
      real_process_noise,
      state_transition
    ),
    m_measurement_frequency(measurement_frequency)
{
  #ifndef NDEBUG
  Test();
  assert(m_measurement_frequency.size() == initial_state.size());
  //Check measuring frequecies
  {
    const auto v = m_measurement_frequency;
    const std::size_t sz = v.size();
    for (std::size_t i=0; i!=sz; ++i)
    {
      const int x = v[i];
      if (x < 1)
      {
        TRACE(x);
        TRACE("BREAK");
      }
      assert(x >= 1 && "At least one out of one measurements is a real measurement");
    }
  }
  #endif
}

#ifndef NDEBUG
void GapsFilledWhiteNoiseSystemParameters::Test()
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  {

  }
}
#endif

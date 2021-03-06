#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "alphafilter.h"

#include <cassert>

AlphaFilter::AlphaFilter(
  const double alpha,
  const double dt)
  : m_alpha(alpha),
    m_dt(dt),
    m_output(0.0)
{
  //assert(m_alpha >= 0.0 && m_alpha <  1.0);
  //assert(m_beta  >= 0.0 && m_beta  <= 2.0); //beta > 1.0 amplifies noise
  //assert(4.0 - (2.0 * m_alpha - m_beta) > 0.0);
  assert(m_dt != 0.0);
}


void AlphaFilter::Update(const double measurement)
{
  const double difference = measurement - m_output;
  m_output += m_alpha * difference;
}

const std::string AlphaFilter::GetVersion()
{
  return "1.1";
}

const std::vector<std::string> AlphaFilter::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2013-05-25: version 1.0: initial version");
  v.push_back("2013-06-18: version 1.1: derive from FloatingPointStateObserver");
  return v;
}

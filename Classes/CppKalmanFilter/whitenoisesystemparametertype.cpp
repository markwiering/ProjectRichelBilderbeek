#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "whitenoisesystemparametertype.h"

#include <cassert>
#include <boost/numeric/conversion/cast.hpp>

bool operator<(const WhiteNoiseSystemParameterType lhs, const WhiteNoiseSystemParameterType rhs)
{
  //Must cast enum class to integer, because of a bug
  //in GCC version 4.4.0:
  //http://gcc.gnu.org/bugzilla/show_bug.cgi?id=38064
  return static_cast<int>(lhs) < static_cast<int>(rhs);
}

bool operator==(const WhiteNoiseSystemParameterType lhs, const WhiteNoiseSystemParameterType rhs)
{
  //Must cast enum class to integer, because of a bug
  //in GCC version 4.4.0:
  //http://gcc.gnu.org/bugzilla/show_bug.cgi?id=38064
  return static_cast<int>(lhs) == static_cast<int>(rhs);
}

bool operator!=(const WhiteNoiseSystemParameterType lhs, const WhiteNoiseSystemParameterType rhs)
{
  return !(lhs == rhs);
}

#ifndef WHITENOISESYSTEMTYPE_H
#define WHITENOISESYSTEMTYPE_H

#include <string>

enum class WhiteNoiseSystemType
{
  lagged,
  standard,
  n_types
};

bool operator==(const WhiteNoiseSystemType lhs, const WhiteNoiseSystemType rhs);
bool operator<(const WhiteNoiseSystemType lhs, const WhiteNoiseSystemType rhs);


#endif // WHITENOISESYSTEMTYPE_H

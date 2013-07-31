#include <cassert>
#include <string>
#include <boost/regex.hpp>

int main()
{
  const std::string str = "The zip code 1234AB is correct";
  const boost::regex regex("(\\d{4})()([A-Z]{2})");
  const std::string fix("($1) ($3)");
  const std::string s
    = boost::regex_replace(str, regex, fix,
        boost::match_default | boost::format_all);
  assert(s == "The zip code 1234 AB is correct");
}

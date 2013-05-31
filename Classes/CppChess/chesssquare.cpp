
#include <cassert>
#include <iostream>

#ifdef SADC_USE_THREADS
#include <thread>
#endif

#ifndef NDEBUG
#include <algorithm>
#include <vector>
#endif

#include <boost/lexical_cast.hpp>

#include "chesssquare.h"
#include "trace.h"

namespace Chess {

Square::Square(const Chess::File& x, const Chess::Rank& y)
  : m_file(x), m_rank(y)
{
  #ifndef NDEBUG
  Test();
  #endif
}

Square::Square(const std::string &s)
  : m_file(Chess::File(boost::lexical_cast<std::string>(s.at(0)))),
    m_rank(Chess::Rank(boost::lexical_cast<std::string>(s.at(1))))
{
  #ifndef NDEBUG
  Test();
  #endif
  if (s.empty()) throw std::logic_error("An empty string cannot be converted to a chess square");
  if (s.size() != 2) throw std::logic_error("An string to be converted to a chess square must consist of exactly two characters");
}

//Square::Square(const char * const s)
//  : m_x(Chess::File(s[0]),
//    m_y(Chess::Rank(boost::lexical_cast<int>(s[1])))
//{
//  assert(s);
//  assert(std::strlen(s) == 2);
//}

Chess::Color Square::GetColor() const
{
  return ((this->GetFile().ToInt() + this->GetRank().ToInt()) % 2 == 1 ? Color::white : Color::black);
}

const std::string Square::GetVersion()
{
  return "1.0";
}

const std::vector<std::string> Square::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("YYYY-MM-DD: version X.Y: [description]");
  v.push_back("2012-01-25: version 1.0: initial version");
  return v;
}

#ifndef NDEBUG
void Square::Test()
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  #ifdef SADC_USE_THREADS
  std::thread t(
    []
  #endif
    {
      Chess::File::Test();
      Chess::Rank::Test();

      FTRACE("Test Chess::Square operators and constructor");
      {
        Chess::Square s("a1");
        Chess::Square t("a1");
        Chess::Square u(t);
        Chess::Square v("a2");
        assert(IsEqual(s,t));
        assert(IsEqual(t,u));
        assert(!IsEqual(s,v));
        assert(!IsEqual(u,v));
      }

      {
        FTRACE("Test a1");
        Chess::Square s("a1");
        assert(s.GetFile().ToStr() == "a");
        assert(s.GetRank().ToStr() == std::string("1"));
        assert(s.GetFile().ToInt() == 0);
        assert(s.GetRank().ToInt() == 0);
        assert(s.GetColor() == Color::black);
      }
      {
        FTRACE("Test b1");
        Chess::Square s("b1");
        assert(s.GetFile().ToStr() == "b");
        assert(s.GetRank().ToStr() == std::string("1"));
        assert(s.GetFile().ToInt() == 1);
        assert(s.GetRank().ToInt() == 0);
        assert(s.GetColor() == Color::white);
      }
      {
        FTRACE("Test a2");
        Chess::Square s("a2");
        assert(s.GetFile().ToStr() == "a");
        assert(s.GetRank() == Chess::Rank(std::string("2")));
        assert(s.GetFile().ToInt() == 0);
        assert(s.GetRank().ToInt() == 1);
        assert(s.GetColor() == Color::white);
      }
      {
        FTRACE("Test d1");
        Chess::Square s("d1");
        assert(s.GetColor() == Color::white);
      }
      {
        FTRACE("Test d8");
        Chess::Square s("d8");
        assert(s.GetColor() == Color::black);
      }
      {
        FTRACE("Test g8");
        Chess::Square s("g8");
        assert(s.GetFile().ToStr() == "g");
        assert(s.GetRank() == Rank(std::string("8")));
        assert(s.GetFile().ToInt() == 6);
        assert(s.GetRank().ToInt() == 7);
      }
      {
        FTRACE("Test known-to-be-valid squares");
        const std::vector<std::string> v =
        {
          "a1", "a8", "h1", "h8", "d4"
        };
        std::for_each(v.begin(),v.end(),
          [](const std::string& s)
          {
            try
            {
              Chess::Square x(s);
            }
            catch (std::exception& e)
            {
              TRACE(s);
              TRACE(e.what());
              assert("Should not get here");
            }
          }
        );
      }

      {
        FTRACE("Test known-to-be-invalid squares");
        const std::vector<std::string> v =
        {
          "A1", "a9", "H8", "h9", "i1", "a", "A", "1", "9", "a10", "h10", "aa1", "a1a", "11", "aa"
        };
        std::for_each(v.begin(),v.end(),
          [](const std::string& s)
          {
            bool ok = false;
            try
            {
              Chess::Square x(s);
            }
            catch (std::exception& e)
            {
              //Ok!
              ok = true;
            }
            if (!ok)
            {
              TRACE(s);
              assert("Should not get here");
            }
          }
        );
      }
      FTRACE("Tested Chess::Square successfully");
    }
  #ifdef SADC_USE_THREADS
  );
  t.detach();
  #endif
}
#endif

const std::string Square::ToStr() const
{
  std::string s
    = boost::lexical_cast<std::string>(GetFile().ToStr())
    + boost::lexical_cast<std::string>(GetRank().ToStr());
  return s;
}

std::ostream& operator<<(std::ostream& os, const Square& s)
{
  os << s.ToStr();
  return os;
}

bool IsEqual(const Square& lhs, const Square& rhs)
{
  return lhs.GetFile() == rhs.GetFile()
    && lhs.GetRank() == rhs.GetRank();
}

} //~ namespace Chess

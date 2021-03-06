//---------------------------------------------------------------------------
/*
CodeToHtml, converts C++ code to HTML
Copyright (C) 2010-2013  Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program.If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ToolCodeToHtml.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "codetohtmlreplacements.h"

#include <algorithm>
#include <cassert>
#include <iostream>

#include "trace.h"

CodeToHtmlReplacements::CodeToHtmlReplacements(
  const std::vector<std::pair<std::string,std::string> >& replacements)
  : m_all_replacements(CreateAllReplacements(replacements))
{
  #ifndef NDEBUG
  {
    ///Warn the user for doublures in the input
    const auto end = replacements.end();
    for (auto i=replacements.begin();i!=end;++i)
    {
      for (auto j=replacements.begin();j!=end;++j)
      {
        if (i==j) continue;
        if ((*i).first == (*j).first)
        {
          std::cerr << "Element occurring twice: " << (*i).first << '\n';
        }
      }
    }
  }


  {
    ///Check against recurring replacements
    std::for_each(replacements.begin(),replacements.end(),
      [](const std::pair<std::string,std::string>& p)
      {
        if(!(
          std::search(p.second.begin(),p.second.end(),p.first.begin(),p.first.end())
          == p.second.end()))
        {
          TRACE("Recurring replacement detected:")
          TRACE(p.first);
          TRACE(p.second);
          TRACE("Add $ symbols in the second part, so that the first part is not a subsequence of it")
        }

        assert(
          std::search(p.second.begin(),p.second.end(),p.first.begin(),p.first.end())
          == p.second.end());
      }
    );
  }

  {
    ///Check agains doublures in the processed input
    const auto end = m_replacements.end();
    for (auto i=m_replacements.begin();i!=end;++i)
    {
      TRACE((*i).first);
      for (auto j=m_replacements.begin();j!=end;++j)
      {
        if (i==j) continue;
        if ((*i).first == (*j).first)
        {
          TRACE((*i).first);
        }
        assert((*i).first != (*j).first);
      }
    }
  }

  {
    ///Check nested processed input
    const auto end = m_replacements.end();
    for (auto i=m_replacements.begin();i!=end;++i)
    {
      const std::string s = (*i).second;
      //if (s.find("any")!=std::string::npos) { std::clog << "any_ found!\n"; }
      for (auto j=m_replacements.begin();j!=end;++j)
      {
        if (i==j) continue;
        const std::string t = (*j).first;
        //if (t == "any") { std::clog << "any found!\n"; }
        if (s.find(t) != std::string::npos)
        {
          std::cerr << "Error: "
            << s
            << " is nested by "
            << t
            << '\n';
        }
        assert(s.find(t) == std::string::npos);
      }
    }
  }

  #endif
}

const std::vector<std::pair<std::string,std::string> >
  CodeToHtmlReplacements::CreateAllReplacements(
    const std::vector<std::pair<std::string,std::string> >& replacements)
{
  std::vector<std::pair<std::string,std::string> > v;
  //Initial
  {
    std::vector<std::pair<std::string,std::string> > w
      = CreateInitialReplacements();
    std::copy(w.begin(),w.end(),std::back_inserter(v));
  }
  //Main
  {
    std::vector<std::pair<std::string,std::string> > w(replacements);

    //Sort to remove doublures
    std::sort(w.begin(),w.end());
    const auto new_end = std::unique(w.begin(),w.end());
    w.erase(new_end,w.end());

    //Sort from long strings to short, and alphabetically
    std::sort(w.begin(),w.end(),
      [](const std::pair<std::string,std::string>& lhs,const std::pair<std::string,std::string>& rhs)
      {
        if (lhs.first.size() > rhs.first.size()) return true;
        else if (lhs.first.size() < rhs.first.size()) return false;
        else
        {
          assert(lhs.first.size() == rhs.first.size());
          return lhs.first < rhs.first;
        }
      }
    );
    std::copy(w.begin(),w.end(),std::back_inserter(v));
    /*
    std::for_each(w.begin(),w.end(),
      [](const std::pair<std::string,std::string>& p)
      {
        TRACE(p.first);
      }
    );
    */
  }
  //End
  {
    std::vector<std::pair<std::string,std::string> > w
      = CreateEndReplacements();
    std::copy(w.begin(),w.end(),std::back_inserter(v));
  }
  return v;
}

const std::vector<std::pair<std::string,std::string> > CodeToHtmlReplacements::CreateEndReplacements()
{
  //C++11 initializer list
  return
  {
  //2
    { "  ","&nbsp;&nbsp;" },
  //Remove the dollars
    { "$","" }, //IMPORTANT: the $ is used to disrupt replaced words
  //Convert original ampersands and dollars back again
    { "[AMPERSAND]","&amp;" },
    { "[DOLLAR]","$" },
    { "[LESS_THAN]","&lt;" },
    { "[GREATER_THAN]","&gt;" }
  };
}

const std::vector<std::pair<std::string,std::string> > CodeToHtmlReplacements::CreateInitialReplacements()
{
  //C++11 initializer list
  return
  {
    //symbol replacements that will mess up the markup if placed in bottom
    //First convert ampersands and dollars
    { "&","[AMPERSAND]" },
    { "$","[DOLLAR]" },
    { "<","[LESS_THAN]" },
    { ">","[GREATER_THAN]" }
  };
}



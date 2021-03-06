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

#include <cassert>
#include <stdexcept>

#include "codetohtmlpagetype.h"

namespace c2h {

bool CanStrToPageType(const std::string& s)
{
  try
  {
    StrToPageType(s);
    return true;
  }
  catch (std::logic_error&)
  {
    return false;
  }
}

const std::string PageTypeToStr(const PageType t)
{
  switch (t)
  {
    case PageType::cpp: return "cpp";
    case PageType::text: return "text";
    case PageType::music: return "music";
    case PageType::tool: return "tool";
  }
  assert(!"Should not get here");
  throw std::logic_error("c2h::PageTypeToStr");
}

const std::vector<PageType> GetAllPageTypes()
{
  return
  {
    PageType::cpp,
    PageType::text,
    PageType::music,
    PageType::tool
  };
}

PageType StrToPageType(const std::string& s)
{
  if (s == "cpp") return PageType::cpp;
  if (s == "text") return PageType::cpp;
  if (s == "music") return PageType::cpp;
  if (s == "tool") return PageType::cpp;
  throw std::logic_error("Invalid string in StrToCodeToHtmlPageType");
}

} //~namespace CodeToHtml


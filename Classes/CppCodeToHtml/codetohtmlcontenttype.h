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
#ifndef CODETOHTMLCONTENTTYPE_H
#define CODETOHTMLCONTENTTYPE_H

#include <string>
#include <vector>

namespace c2h {

///The types of content
///text: .txt file
///cpp: .h or .hpp or .c or .cpp file
///pro: .pro file
///py: python file
///sh: .sh file
///code_snippet: file without an extension
///other: file with other extension
enum class ContentType { code_snippet, cpp, pro, py, sh, txt, other };

bool CanStrToContentType(const std::string& s);
const std::string ContentTypeToStr(const ContentType t);
const std::vector<ContentType> GetAllContentTypes();
ContentType StrToContentType(const std::string& s);

} //~namespace CodeToHtml

#endif // CODETOHTMLCONTENTTYPE_H

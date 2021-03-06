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
#ifndef CODETOHTML_H
#define CODETOHTML_H

#include <string>
#include <vector>

#include <boost/shared_ptr.hpp>

#include "codetohtmlcontenttype.h"
#include "codetohtmlpagetype.h"

///c2h contains the CodeToHtml functions
namespace c2h {
  #ifndef NDEBUG
  ///Test these functions
  void Test();
  #endif

  ///Convert a code snippet
  const std::vector<std::string> ConvertCodeSnippet(
    const std::vector<std::string>& code,
    const ContentType content_type);

  ///Convert a file
  const std::vector<std::string> ConvertFile(
    const std::string& filename,
    const ContentType content_type);

  ///Convert all file in a folder/directory, without adding header, technical info or footer
  const std::vector<std::string> ConvertFiles(
    const std::string& foldername);

  ///Convert a folder/directory with adding header, technical info or footer
  const std::vector<std::string> ConvertFolder(
    const std::string& foldername,
    const PageType page_type);

  ///Convert a .pro file
  const std::vector<std::string> ConvertProject(const std::string& filename);

  ///FileToVector reads a file and converts it to a std::vector<std::string>
  //From http://www.richelbilderbeek.nl/CppFileToVector.htm
  const std::vector<std::string> FileToVector(const std::string& filename);

  ///Filter files: only let .pro, .h, .hpp, . cpp, .c and .sh files pass
  const std::vector<std::string> FilterFiles(const std::vector<std::string>& files);

  //Returns the extension of a filename
  //From http://www.richelbilderbeek.nl/CppGetExtension.htm
  const std::string GetExtension(const std::string& filename);

  ///Obtain the basename of a file, e.g. '/Folder/temp.txt' -> 'temp'
  ///From http://www.richelbilderbeek.nl/CppGetFileBasename.htm
  const std::string GetFileBasename(const std::string& filename);

  //From http://www.richelbilderbeek.nl/CppGetFilesInFolder.htm
  const std::vector<std::string> GetFilesInFolder(const std::string& folder);

  const std::vector<std::string> GetFilesInFolder(
    const std::string& folder,
    const std::string& regex_str);

  ///Returns the path of a filename
  ///From http://www.richelbilderbeek.nl/CppGetPath.htm
  const std::string GetPath(const std::string& filename);

  #ifndef _WIN32
  ///Tests if the HTML is clean, this will be checked by the tool 'tidy'
  bool IsCleanHtml(const std::vector<std::string>& html);
  #endif

  ///Returns if the name is a folder name
  ///From http://www.richelbilderbeek.nl/CppIsFolder.htm
  bool IsFolder(const std::string& filename);

  ///Determines if a filename is a regular file
  ///From http://www.richelbilderbeek.nl/CppIsRegularFile.htm
  bool IsRegularFile(const std::string& filename);

  #ifndef _WIN32
  ///Check if the tool 'tidy' is installed
  ///If not, user should 'sudo-apt get install tidy'
  ///Or go to http://tidy.sourceforge.net
  bool IsTidyInstalled();
  #endif

  ///Sort files: .pro files first, then X.h, X.cpp, then .sh files
  const std::vector<std::string> SortFiles(std::vector<std::string> files);

  ///Obtain the sorted files in a folder
  const std::vector<std::string> GetSortedFilesInFolder(const std::string& folder);

} //~namespace c2h

#endif // CODETOHTML_H

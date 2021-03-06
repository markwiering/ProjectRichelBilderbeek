//---------------------------------------------------------------------------
/*
KTouchLectureCreator, create KTouch lecture for C++ programmers
Copyright (C) 2013 Richel Bilderbeek

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program. If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
//From http://www.richelbilderbeek.nl/ToolKTouchLectureCreator.htm
//---------------------------------------------------------------------------
#ifndef KTOUCHLECTURE_H
#define KTOUCHLECTURE_H

#include <string>
#include <vector>

#include "ktouchlevels.h"

struct KTouchLecture
{
  KTouchLecture();
  const std::vector<std::string> ToXml() const;

  private:
  const std::string m_comment;
  const std::string m_font_suggestion;
  const KTouchLevels m_levels;
  const std::string m_title;

  static const KTouchLevels CreateLevels();
};

#endif // KTOUCHLECTURE_H

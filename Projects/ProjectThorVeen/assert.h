//---------------------------------------------------------------------------
/*
  The Thor Veen Project, simulation to investigate honest signalling
  Copyright (C) 2006  Rich�l Bilderbeek

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/
//---------------------------------------------------------------------------
// From http://www.richelbilderbeek.nl
//---------------------------------------------------------------------------
#ifndef BilderbikkelAssertH
#define BilderbikkelAssertH
//---------------------------------------------------------------------------
#include <Dialogs.hpp>
//---------------------------------------------------------------------------
#ifdef NDEBUG
  #define Assert(x) ((void)0)
#else
  #define Assert(x) \
  if (! (x)) \
  { \
    ShowMessage("ERROR!! Assertion "+      \
                String (#x) +              \
                " failed\n on line " +     \
                (__LINE__) +               \
                " in the function " +     \
                (__FUNC__) +               \
                "\n in file " +            \
                (__FILE__)                 \
               );                          \
  }
#endif


#endif

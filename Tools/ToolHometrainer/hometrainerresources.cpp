//---------------------------------------------------------------------------
/*
Hometrainer, exercise and survey suite
Copyright (C) 2009-2013 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolHometrainer.htm
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
#include "hometrainerresources.h"

#include <cassert>
#include <iostream>

#include <boost/filesystem.hpp>

#include "trace.h"

//Must be #included after Wt header files
#include <QFile>

HometrainerResources::HometrainerResources()
{
  const std::vector<std::string> files
    =
    {
      GetQuestion(),
      GetQuestionMark(),
      GetWelcome(),
      "ToolHometrainerExerciseAdapter.jpg",
      "ToolHometrainerExerciseAuks.jpg",
      "ToolHometrainerExerciseBakMetFilters.jpg",
      "ToolHometrainerExerciseCdSpelerNumarck.jpg",
      "ToolHometrainerExerciseDcc.jpg",
      "ToolHometrainerExerciseDi.jpg",
      "ToolHometrainerExerciseDimmerpack.jpg",
      "ToolHometrainerExerciseDmxMannetjeConnector.jpg",
      "ToolHometrainerExerciseDmxMannetje.jpg",
      "ToolHometrainerExerciseDmxVrouwtjeConnector.jpg",
      "ToolHometrainerExerciseDmxVrouwtje.jpg",
      "ToolHometrainerExerciseEffect.jpg",
      "ToolHometrainerExerciseEuroMannetjeConnector.jpg",
      "ToolHometrainerExerciseEuroVrouwtje.jpg",
      "ToolHometrainerExerciseFilterboekje.jpg",
      "ToolHometrainerExerciseFilterhouder.jpg",
      "ToolHometrainerExerciseFilter.jpg",
      "ToolHometrainerExerciseFiltervellen.jpg",
      "ToolHometrainerExerciseFlightcase.jpg",
      "ToolHometrainerExerciseFresnel.jpg",
      "ToolHometrainerExerciseGeluidstafelAchterkantLinks.jpg",
      "ToolHometrainerExerciseGeluidstafelAchterkantRechts.jpg",
      "ToolHometrainerExerciseGeluidstafelAlesis.jpg",
      "ToolHometrainerExerciseGeluidstafelBovenkantMiddenboven.jpg",
      "ToolHometrainerExerciseGeluidstafelBovenkantMidden.jpg",
      "ToolHometrainerExerciseGeluidstafelBovenkantRechtsboven.jpg",
      "ToolHometrainerExerciseGeluidstafelBovenkantRechtsonder.jpg",
      "ToolHometrainerExerciseGeluidstafelYamaha.jpg",
      "ToolHometrainerExerciseGordijnhaak.jpg",
      "ToolHometrainerExerciseHaspel.jpg",
      "ToolHometrainerExerciseJackMannetjeMono.jpg",
      "ToolHometrainerExerciseJackVrouwtjeConnector.jpg",
      "ToolHometrainerExerciseJackVrouwtjeEnXlrVrouwtjeConnector.jpg",
      "ToolHometrainerExerciseKabeltester.jpg",
      "ToolHometrainerExerciseKrachtstroomMannetjeConnector.jpg",
      "ToolHometrainerExerciseKrachtstroomMannetje.jpg",
      "ToolHometrainerExerciseKrachtstroomVrouwtjeConnector.jpg",
      "ToolHometrainerExerciseLamp500W.jpg",
      "ToolHometrainerExerciseLichtplanDeBruiloften.jpg",
      "ToolHometrainerExerciseLichtplan.jpg",
      "ToolHometrainerExerciseLichttafel.jpg",
      "ToolHometrainerExerciseMdGrijs.jpg",
      "ToolHometrainerExerciseMdSpeler.jpg",
      "ToolHometrainerExerciseMdTransparent.jpg",
      "ToolHometrainerExerciseMicrofoonShureSm58.jpg",
      "ToolHometrainerExerciseMiniJackStereoVrouwJackStereoMan.jpg",
      "ToolHometrainerExerciseMonitorTorqueConnectors.jpg",
      "ToolHometrainerExerciseMultikabelMannetjeConnector.jpg",
      "ToolHometrainerExerciseMultikabelVrouwtjeConnector.jpg",
      "ToolHometrainerExerciseMultimeterMetex.jpg",
      "ToolHometrainerExerciseMultistekkerdoos.jpg",
      "ToolHometrainerExerciseOn.jpg",
      "ToolHometrainerExerciseOpwindstatief.jpg",
      "ToolHometrainerExercisePar.jpg",
      "ToolHometrainerExercisePc.jpg",
      "ToolHometrainerExercisePriklijst.jpg",
      "ToolHometrainerExerciseProfielspot.jpg",
      "ToolHometrainerExerciseRcf322aAchterkant.jpg",
      "ToolHometrainerExerciseRgbLamp.jpg",
      "ToolHometrainerExerciseSafety.jpg",
      "ToolHometrainerExerciseScartMannetje.jpg",
      "ToolHometrainerExerciseSchukoVrouwtjeConnector.jpg",
      "ToolHometrainerExerciseShureSm58.jpg",
      "ToolHometrainerExerciseSpanningsmeterFluke.jpg",
      "ToolHometrainerExerciseSpeakerEvent3000.jpg",
      "ToolHometrainerExerciseSpeakonVrouwSpeakonVrouw.jpg",
      "ToolHometrainerExerciseSpeakonVrouwtjeConnector.jpg",
      "ToolHometrainerExerciseSpringV2.jpg",
      "ToolHometrainerExerciseStandenplot.jpg",
      "ToolHometrainerExerciseStekkerdoos.jpg",
      "ToolHometrainerExerciseTbar.jpg",
      "ToolHometrainerExerciseTrussHaarspeld.jpg",
      "ToolHometrainerExerciseTruss.jpg",
      "ToolHometrainerExerciseTrussklem.jpg",
      "ToolHometrainerExerciseTrussPin.jpg",
      "ToolHometrainerExerciseTrussVerbindingsstuk.jpg",
      "ToolHometrainerExerciseTulpMannetje.jpg",
      "ToolHometrainerExerciseVerloopstukje.jpg",
      "ToolHometrainerExerciseVersterkerSamsonAchterkant.jpg",
      "ToolHometrainerExerciseVersterkerSamson.jpg",
      "ToolHometrainerExerciseVgaVrouwVgaVrouw.jpg",
      "ToolHometrainerExerciseVoetstatief.jpg",
      "ToolHometrainerExerciseWijkenArnhemGenummerd.bmp",
      "ToolHometrainerExerciseXlrMannetjeConnector.jpg",
      "ToolHometrainerExerciseXlrVrouwtje.jpg",
      "ToolHometrainerExerciseZekering.jpg"
  };
  std::for_each(files.begin(),files.end(),
    [](const std::string& s)
    {
      if (!boost::filesystem::exists(s))
      {
        const std::string filename = ":/images/" + s;
        QFile f(filename.c_str());
        f.copy(s.c_str());
        if (!boost::filesystem::exists(s)) { TRACE(s); }
        assert(boost::filesystem::exists(s));
      }
      if (!boost::filesystem::exists(s)) { TRACE(s); }
      assert(boost::filesystem::exists(s));
    }
  );

  {
    const std::vector<std::string> files
    =
    {
      GetExerciseClouds(),
      GetExerciseTest(),
      "ToolHometrainerExerciseClouds.txt",
      "ToolHometrainerExerciseTest.txt",
      "ToolHometrainerExerciseTtBasis.txt",
      "ToolHometrainerExerciseTtGeluid.txt",
      "ToolHometrainerExerciseTtLicht.txt",
      "ToolHometrainerExerciseWijkenArnhem.txt"
    };
    std::for_each(files.begin(),files.end(),
      [](const std::string& filename)
      {
        if (!(QFile::exists(filename.c_str())))
        {
          QFile f( (std::string(":/textfiles/") + filename).c_str() );
          f.copy(filename.c_str());
        }
        if (!boost::filesystem::exists(filename.c_str()))
        {
          std::cerr << "File not found: " << filename << '\n';
        }
        assert(boost::filesystem::exists(filename.c_str()));
      }
    );
  }
{
  const std::vector<std::string> files
  =
  {
    "ToolHometrainerManual.odt"
  };
  std::for_each(files.begin(),files.end(),
    [](const std::string& filename)
    {
      if (!(QFile::exists(filename.c_str())))
      {
        QFile f( (std::string(":/docs/") + filename).c_str() );
        f.copy(filename.c_str());
      }
      if (!boost::filesystem::exists(filename.c_str()))
      {
        std::cerr << "File not found: " << filename << '\n';
      }
      assert(boost::filesystem::exists(filename.c_str()));
    }
  );
}
}


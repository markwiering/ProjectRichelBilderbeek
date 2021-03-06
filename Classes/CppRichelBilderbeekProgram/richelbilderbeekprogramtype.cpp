//---------------------------------------------------------------------------
/*
RichelBilderbeek::ProgramType, enum for a program by Richel Bilderbeek
Copyright (C) 2013 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ProjectRichelBilderbeek.htm
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
#include "richelbilderbeekprogramtype.h"

#include <cassert>
#include "trace.h"
namespace RichelBilderbeek {

std::vector<ProgramType> GetAllProgramTypes()
{
  const std::vector<ProgramType> v =
  {
    ProgramType::asciiArter,
    ProgramType::barbaImage,
    ProgramType::beerWanter,
    ProgramType::bochum,
    ProgramType::boenken,
    ProgramType::chrisWiley,
    ProgramType::codeToHtml,
    ProgramType::connectThree,
    ProgramType::createGlossary,
    ProgramType::createQtProjectZipFile,
    ProgramType::createSitemap,
    ProgramType::crossPoll,
    ProgramType::dasWahreSchlagerfest,
    ProgramType::dotMatrix,
    ProgramType::encranger,
    ProgramType::filterOperationer,
    ProgramType::fryskLeareLieder,
    ProgramType::functionPlotter,
    ProgramType::gaborFilter,
    ProgramType::gnuplotInterface,
    ProgramType::grayCoder,
    ProgramType::gtst,
    ProgramType::histogramEqualizationer,
    ProgramType::hometrainer,
    ProgramType::imageRotater,
    ProgramType::k3OpEenRij,
    ProgramType::kalmanFilterer,
    ProgramType::keySender,
    ProgramType::kTouchLectureCreator,
    ProgramType::knokfighter,
    ProgramType::learyCircumplex,
    ProgramType::logisticGrowthSimulator,
    ProgramType::loose,
    ProgramType::mazeCreator,
    ProgramType::maziak,
    ProgramType::morpher,
    ProgramType::multiEncranger,
    ProgramType::muscaDomestica,
    ProgramType::musicTheory,
    ProgramType::ndsMake,
    ProgramType::pause,
    ProgramType::newickVector,
    ProgramType::paperRockScissors,
    ProgramType::perfectElasticCollision,
    ProgramType::picToCode,
    ProgramType::pixelator,
    ProgramType::pokeVolley,
    ProgramType::pylos,
    ProgramType::qmakeWatcher,
    ProgramType::quadraticSolver,
    ProgramType::randomCode,
    ProgramType::rasper,
    ProgramType::refrigeratorPuzzleSolver,
    ProgramType::regexTester,
    ProgramType::reversi,
    ProgramType::richelBilderbeekGallery,
    ProgramType::richelBilderbeekNlSitemapGenerator,
    ProgramType::rubiksClock,
    ProgramType::searchAndDestroyChess,
    ProgramType::secretMessage,
    ProgramType::simBrainiac,
    ProgramType::simImmuneResponse,
    ProgramType::simMysteryMachine,
    ProgramType::simplifyNewick,
    ProgramType::simStagecraft,
    ProgramType::soaSim,
    ProgramType::solvePuzzleX,
    ProgramType::spaceHarry,
    ProgramType::stateObserver,
    ProgramType::styleSheetSetter,
    ProgramType::surfacePlotter,
    ProgramType::testAbout,
    ProgramType::testBinaryNewickVector,
    //ProgramType::testBouncingBallsWidget,
    //ProgramType::testBouncingRectsWidget,
    ProgramType::testBroadcastServer,
    ProgramType::testChess,
    ProgramType::testDial,
    ProgramType::testEncranger,
    ProgramType::testEntrance,
    ProgramType::testExercise,
    ProgramType::testFunctionParser,
    //ProgramType::testGraphicsProxyWidget,
    //ProgramType::testGravityWidget,
    ProgramType::testGroupWidget,
    //ProgramType::testHugeVector,
    ProgramType::testLed,
    //ProgramType::testManyDigitNewick,
    ProgramType::testMultiVector,
    ProgramType::testNdsMake,
    ProgramType::testNeuralNet,
    //ProgramType::testNewick,
    //ProgramType::testNewickVector,
    ProgramType::testPrimeExpert,
    ProgramType::testPylos,
    ProgramType::testQrcFile,
    ProgramType::testQtArrowItems,
    ProgramType::testQtCreatorProFile,
    //ProgramType::testQtHideAndShowDialog,
    ProgramType::testQtKeyboardFriendlyGraphicsView,
    ProgramType::testQtModels,
    ProgramType::testQtRoundedEditRectItem,
    ProgramType::testQtRoundedRectItem,
    ProgramType::testQtRoundedTextRectItem,
    ProgramType::testQuestion,
    //ProgramType::testReversi,
    ProgramType::testSelectFile,
    ProgramType::testServerPusher,
    ProgramType::testShape,
    ProgramType::testShinyButton,
    ProgramType::testStopwatch,
    //ProgramType::testTextPositionWidget,
    ProgramType::testTicTacToe,
    ProgramType::testTimedServerPusher,
    ProgramType::testToggleButton,
    ProgramType::testTwoDigitNewick,
    ProgramType::thorVeen,
    ProgramType::thresholdFilterer,
    ProgramType::ticTacToe,
    ProgramType::ticTacToeLearner,
    ProgramType::ticTacToeValuer,
    ProgramType::timePoll,
    ProgramType::twoDigitNewick,
    ProgramType::ubuntuOneWatcher,
    ProgramType::visualAbc
  };
  #ifndef NDEBUG
  if (static_cast<int>(v.size()) != static_cast<int>(ProgramType::n_types))
  {
    TRACE(v.size());
    TRACE(static_cast<int>(ProgramType::n_types));
    TRACE("Copy the contents of ProgramType (except n_types) to above here");
  }
  #endif
  assert(static_cast<int>(v.size()) == static_cast<int>(ProgramType::n_types));
  return v;
}

} //~namespace RichelBilderbeek

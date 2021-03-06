//---------------------------------------------------------------------------
/*
Project Richel Bilderbeek, Richel Bilderbeek's work
Copyright (C) 2010-2013 Richel Bilderbeek

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
#include "richelbilderbeekmenudialog.h"

#include "asciiartermenudialog.h"
#include "codetohtmlmenudialog.h"
#include "connectthree.h"
#include "binarynewickvector.h"
#include "connectthreewidget.h"
#include "copy_if.h"
#include "counter.h"
#include "createqtprojectzipfilemenudialog.h"
#include "fuzzy_equal_to.h"
#include "dial.h"
#include "fixedlagsmootherkalmanfilter.h"
#include "fuzzy_equal_to.h"
#include "gaborfilter.h"
#include "gaborfilterwidget.h"
#include "kalmanfilter.h"
#include "laggedwhitenoisesystem.h"
#include "manydigitnewick.h"
#include "stateobservermenudialog.h"
#include "steadystatekalmanfilterparameters.h"
#include "steadystatekalmanfilter.h"
#include "multivector.h"
#include "newick.h"
#include "dialwidget.h"
#include "encranger.h"
#include "exercise.h"
#include "hometrainermenudialog.h"
#include "htmlpage.h"
#include "ipaddress.h"
#include "lazy_init.h"
#include "led.h"
#include "ledwidget.h"
#include "loopreader.h"
#include "matrix.h"
#include "multiplechoicequestiondialog.h"
#include "multiplechoicequestion.h"
#include "musicchord.h"
#include "musicnote.h"
#include "musicscale.h"
#include "mysterymachine.h"
#include "mysterymachinewidget.h"
#include "newickvector.h"
#include "openquestiondialog.h"
#include "openquestion.h"
#include "qrcfile.h"
#include "qtcreatorprofile.h"
#include "questiondialog.h"
#include "question.h"
#include "rainbow.h"
#include "randomcode.h"
#include "regextestermenudialog.h"
#include "richelbilderbeekprogram.h"
#include "richelbilderbeekprogramstatus.h"
#include "rubiksclockdial.h"
#include "rubiksclockdialwidget.h"
#include "rubiksclock.h"
#include "rubiksclockmenudialog.h"
#include "rubiksclockwidget.h"
#include "shape.h"
#include "shapewidget.h"
#include "shinybutton.h"
#include "pylosmenudialog.h"
#include "shinybuttonwidget.h"
#include "simmysterymachinemenudialog.h"
#include "stopwatch.h"
#include "testdialmenudialog.h"
#include "testencrangerdialog.h"
#include "testexercisemenudialog.h"
#include "testfunctionparsermenudialog.h"
#include "testledmenudialog.h"
#include "testnewickvectordialog.h"
#include "testqrcfilemenudialog.h"
#include "testqtarrowitemsmenudialog.h"
#include "testqtcreatorprofilemenudialog.h"
#include "richelbilderbeekprogram.h"
#include "sortedbinarynewickvector.h"
#include "alphafilter.h"
#include "alphabetafilter.h"
#include "alphabetagammafilter.h"
#include "multialphafilter.h"
#include "testquestionmenudialog.h"
#include "testshapemenudialog.h"
#include "testshinybuttonmenudialog.h"
#include "testtogglebuttonmenudialog.h"
#include "tictactoe.h"
#include "tictactoemenudialog.h"
#include "togglebutton.h"
#include "togglebuttonwidget.h"
#include "trace.h"
#include "twodigitnewick.h"

namespace RichelBilderbeek {

MenuDialog::MenuDialog()
  : m_programs(RichelBilderbeek::Program::GetAllPrograms())
{
  #ifndef NDEBUG
  std::for_each(m_programs.begin(), m_programs.end(),
    [](const boost::shared_ptr<Program>& p)
    {
      assert(p);
    }
  );
  #endif
}

const About MenuDialog::GetAbout()
{
  About a(
    "Richel Bilderbeek",
    "Project Richel Bilderbeek",
    "Richel Bilderbeek's work",
    "the 11th of July 2013",
    "2010-2013",
    "http://www.richelbilderbeek.nl/ProjectRichelBilderbeek.htm",
    GetVersion(),
    GetVersionHistory());
  a.AddLibrary("AsciiArter version: " + AsciiArterMenuDialog::GetVersion());
  a.AddLibrary("Big Integer Library (by Matt McCutchen) version: 2010.04.30");
  a.AddLibrary("BinaryNewickVector version: " + BinaryNewickVector::GetVersion());
  a.AddLibrary("CodeToHtml version: " + CodeToHtmlMenuDialog::GetVersion());
  a.AddLibrary("ConnectThree version: " + ConnectThree::GetVersion());
  a.AddLibrary("ConnectThreeWidget version: " + ConnectThreeWidget::GetVersion());
  a.AddLibrary("Copy_if version: " + Copy_if_version::GetVersion());
  a.AddLibrary("Counter version: " + Counter::GetVersion());
  a.AddLibrary("CreateQtProjectZipFile version: " + CreateQtProjectZipFile::MenuDialog::GetVersion());
  a.AddLibrary("Dial version: " + Dial::GetVersion());
  a.AddLibrary("DialWidget version: " + DialWidget::GetVersion());
  a.AddLibrary("Encranger version: " + Encranger::GetVersion());
  a.AddLibrary("Exercise version: " + Exercise::GetVersion());
  a.AddLibrary("FixedLagSmootherKalmanFilter version: " + FixedLagSmootherKalmanFilter::GetVersion());
  a.AddLibrary("Fuzzy_equal_to version: " + fuzzy_equal_to::GetVersion());
  a.AddLibrary("GaborFilter version: " + GaborFilter::GetVersion());
  a.AddLibrary("GaborFilterWidget version: " + GaborFilterWidget::GetVersion());
  a.AddLibrary("Hometrainer version: " + HometrainerMenuDialog::GetVersion());
  a.AddLibrary("HtmlPage version: " + HtmlPage::GetVersion());
  a.AddLibrary("IpAddress version: " + IpAddress::GetVersion());
  a.AddLibrary("KalmanFilter version: " + KalmanFilter::GetVersion());
  a.AddLibrary("LaggedWhiteNoiseSystem version: " + LaggedWhiteNoiseSystem::GetVersion());
  a.AddLibrary("Lazy_init version: " + Lazy_initVersion::GetVersion());
  a.AddLibrary("Led version: " + Led::GetVersion());
  a.AddLibrary("LedWidget version: " + LedWidget::GetVersion());
  a.AddLibrary("LoopReader version: " + LoopReader<int>::GetVersion());
  a.AddLibrary("ManyDigitNewick version: " + ManyDigitNewick::GetVersion());
  a.AddLibrary("Matrix version: " + Matrix::GetVersion());
  a.AddLibrary("Matrix version: " + Matrix::GetVersion());
  a.AddLibrary("MultipleChoiceQuestionDialog version: " + MultipleChoiceQuestionDialog::GetVersion());
  a.AddLibrary("MultipleChoiceQuestion version: " + MultipleChoiceQuestion::GetVersion());
  a.AddLibrary("MultipleVector version: " + MultiVector<int>::GetVersion());
  a.AddLibrary("Music::Chord version: " + Music::Chord::GetVersion());
  a.AddLibrary("Music::Note version: " + Music::Note::GetVersion());
  a.AddLibrary("Music::Scale version: " + Music::Scale::GetVersion());
  a.AddLibrary("MysteryMachine version: " + MysteryMachine::GetVersion());
  a.AddLibrary("MysteryMachineWidget version: " + MysteryMachineWidget::GetVersion());
  a.AddLibrary("Newick version: " + Newick::GetVersion());
  a.AddLibrary("NewickVector version: " + NewickVector::GetVersion());
  a.AddLibrary("OpenQuestionDialog version: " + OpenQuestionDialog::GetVersion());
  a.AddLibrary("OpenQuestion version: " + OpenQuestion::GetVersion());
  a.AddLibrary("Pylos version: " + PylosMenuDialog::GetVersion());
  a.AddLibrary("QtCreatorProFile version: " + QtCreatorProFile::GetVersion());
  a.AddLibrary("QrcFile version: " + QrcFile::GetVersion());
  a.AddLibrary("QuestionDialog version: " + QuestionDialog::GetVersion());
  a.AddLibrary("Question version: " + Question::GetVersion());
  a.AddLibrary("Rainbow version: " + Rainbow::GetVersion());
  a.AddLibrary("RandomCode version: " + RandomCode::GetVersion());
  a.AddLibrary("Rectangle version: " + Rect::GetVersion());
  a.AddLibrary("RegexTester version: " + RegexTesterMenuDialog::GetVersion());
  a.AddLibrary("RichelBilderbeekProgram version: " + RichelBilderbeek::Program::GetVersion());
  a.AddLibrary("RubiksClock (class) version: " + RubiksClock::GetVersion());
  a.AddLibrary("RubiksClockDialversion: " + RubiksClockDial::GetVersion());
  a.AddLibrary("RubiksClockDialWidget version: " + RubiksClockDialWidget::GetVersion());
  a.AddLibrary("RubiksClock (game) version: " + RubiksClockMenuDialog::GetVersion());
  a.AddLibrary("RubiksClockWidget version: " + RubiksClockWidget::GetVersion());
  a.AddLibrary("Shape version: " + Shape::GetVersion());
  a.AddLibrary("ShapeWidget version: " + ShapeWidget::GetVersion());
  a.AddLibrary("ShinyButton version: " + ShinyButton::GetVersion());
  a.AddLibrary("ShinyButtonWidget version: " + ShinyButtonWidget::GetVersion());
  a.AddLibrary("SimMysteryMachine version: " + SimMysteryMachineMenuDialog::GetVersion());
  a.AddLibrary("SortedBinaryNewickVector version: " + SortedBinaryNewickVector::GetVersion());
  a.AddLibrary("StandardKalmanFilterParameters version: " + StandardKalmanFilterParameters::GetVersion());
  a.AddLibrary("AlphaFilter version: " + AlphaFilter::GetVersion());
  a.AddLibrary("AlphaBetaFilter version: " + AlphaBetaFilter::GetVersion());
  a.AddLibrary("AlphaBetaGammaFilter version: " + AlphaBetaGammaFilter::GetVersion());
  a.AddLibrary("MultiAlphaFilter version: " + MultiAlphaFilter::GetVersion());
  a.AddLibrary("StateObserver version: " + StateObserverMenuDialog::GetVersion());
  a.AddLibrary("StandardKalmanFilter version: " + StandardKalmanFilter::GetVersion());
  a.AddLibrary("StandardWhiteNoiseSystemParameters version: " + StandardWhiteNoiseSystemParameters::GetVersion());
  a.AddLibrary("StandardWhiteNoiseSystem version: " + StandardWhiteNoiseSystem::GetVersion());
  a.AddLibrary("SteadyStateKalmanFilterParameters version: " + SteadyStateKalmanFilterParameters::GetVersion());
  a.AddLibrary("SteadyStateKalmanFilter version: " + SteadyStateKalmanFilter::GetVersion());
  a.AddLibrary("Stopwatch version: " + Stopwatch::GetVersion());
  a.AddLibrary("TestDial version: " + TestDialMenuDialog::GetVersion());
  a.AddLibrary("TestEncranger version: " + TestEncrangerDialog::GetVersion());
  a.AddLibrary("TestExercise version: " + TestExerciseMenuDialog::GetVersion());
  a.AddLibrary("TestFunctionParser version: " + TestFunctionParserMenuDialog::GetVersion());
  a.AddLibrary("TestLed version: " + TestLedMenuDialog::GetVersion());
  a.AddLibrary("TestNewickVector version: " + TestNewickVectorDialog::GetVersion());
  a.AddLibrary("TestProFile version: " + TestQtCreatorProFileMenuDialog::GetVersion());
  a.AddLibrary("TestQrcFile version: " + TestQrcFileMenuDialog::GetVersion());
  a.AddLibrary("TestQuestion version: " + TestQuestionMenuDialog::GetVersion());
  a.AddLibrary("TestShape version: " + TestShapeMenuDialog::GetVersion());
  a.AddLibrary("TestShinyButton version: " + TestShinyButtonMenuDialog::GetVersion());
  a.AddLibrary("TestToggleButton version: " + TestToggleButtonMenuDialog::GetVersion());
  //a.AddLibrary("TestTwoDigitNewick version: " + WtTestTwoDigitNewickDialog::GetVersion());
  a.AddLibrary("TicTacToe (game) version: " + TicTacToeMenuDialog::GetVersion());
  a.AddLibrary("TicTacToe version: " + TicTacToe::GetVersion());
  a.AddLibrary("ToggleButton version: " + ToggleButton::GetVersion());
  a.AddLibrary("ToggleButtonWidget version: " + ToggleButtonWidget::GetVersion());
  a.AddLibrary("Trace version: " + Trace::GetVersion());
  a.AddLibrary("Trace version: " + Trace::GetVersion());
  a.AddLibrary("TwoDigitNewick version: " + TwoDigitNewick::GetVersion());
  a.AddLibrary("Warp's FunctionParser version: 4.4.3");
  a.AddLibrary("WhiteNoiseSystem version: " + WhiteNoiseSystem::GetVersion());
  a.AddLibrary("Widget version: " + Widget::GetVersion());
  return a;
}

const std::string MenuDialog::GetVersion()
{
  return "1.09";
}

const std::vector<std::string> MenuDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2010-12-20: Version 0.1: web-application-only project called 'ProjectWtWebsite', initial setup with BeerWanter and Loose");
  v.push_back("2010-12-21: Version 0.2: added System button");
  v.push_back("2010-12-22: Version 0.3: added About button");
  v.push_back("2010-12-22: Version 0.4: added What's New button. Got BeerWanter to work minimally");
  v.push_back("2010-12-24: Version 0.5: added RandomCode");
  v.push_back("2011-01-07: Version 0.6: major architecture adjustment, added TicTacToe, temporarily removed BeerWanter, Loose and System");
  v.push_back("2011-01-09: Version 0.7: added title structure, added response of WtRichelBilderbeek's Close button, added ConnectThree beta");
  v.push_back("2011-01-10: Version 0.8: ConnectThree to alpha");
  v.push_back("2011-01-11: Version 0.9: ConnectThree to full version");
  v.push_back("2011-03-06: Version 0.10: added TestTwoDigitNewick");
  v.push_back("2011-03-09: Version 0.11: replaced TestTwoDigitNewick by TestNewick");
  v.push_back("2011-03-22: Version 0.12: added TestEncranger");
  v.push_back("2011-03-26: Version 0.13: replaced TestNewick by TestNewickVector");
  v.push_back("2011-03-27: Version 0.14: added TestAsciiArter");
  v.push_back("2011-04-13: Version 0.15: added TimePoll");
  v.push_back("2011-04-16: Version 0.16: major architectural change: use of Wt::WMenu and WtAutoConfig");
  v.push_back("2011-04-23: Version 0.17: new version of ConnectThree, added Bep to welcome page");
  v.push_back("2011-04-24: Version 0.18: fixed bug in ConnectThree, improved RandomCode");
  v.push_back("2011-04-25: Version 0.19: fixed bug in ConnectThree (again), removed Close buttons, fixed doublures in About information");
  v.push_back("2011-05-30: Version 0.20: removed TimePoll, added GTST");
  v.push_back("2011-06-11: Version 0.21: added TestTwoDigitNewick, TestDial, TestLed and TimePoll");
  v.push_back("2011-06-22: Version 0.22: added TestGroupWidget");
  v.push_back("2011-06-24: Version 0.23: added TestFunctionParser");
  v.push_back("2011-06-26: Version 0.24: use of WtSafeTimer");
  v.push_back("2011-06-30: Version 0.25: added TestQuestion, removed TimePoll");
  v.push_back("2011-07-02: Version 0.26: added TestSelectFileDialog");
  v.push_back("2011-07-16: Version 0.27: removed GTST and TimePoll, added TestShape");
  v.push_back("2011-07-26: Version 0.28: added TimePoll");
  v.push_back("2011-08-20: Version 0.29: added TestServerPusher and TestSTimederverPusher");
  v.push_back("2011-08-31: Version 0.30: improved TestAsciiArter, TestDial, TestEncranger, TestFunctionParser and RandomCode, added GTST and TestToggleButton");
  v.push_back("2011-09-08: Version 0.31: improved TestLed, TestGroupWidget, added RubiksClock");
  v.push_back("2011-09-16: Version 0.32: added CodeToHtml, added SimMysteryMachine, improved TestQuestion");
  v.push_back("2011-09-19: Version 0.33: added TestEntrance");
  v.push_back("2011-09-20: Version 0.34: restyled the main menu");
  v.push_back("2011-09-22: Version 0.35: added TestShinyButton, restyled the main menu");
  v.push_back("2011-10-02: Version 0.36: added TestExercise, restyled the main menu");
  v.push_back("2011-10-24: Version 0.37: added Hometrainer");
  v.push_back("2011-10-30: Version 0.38: conformized to newer GCC's C++0x implementation, improved Hometrainer, improved WtRichelBilderbeek code");
  v.push_back("2012-02-12: Version 1.00: renamed project to 'Project Richel Bilderbeek', first step to both a desktop and web application of this project");
  v.push_back("2012-07-29: Version 1.01: added many programs");
  v.push_back("2012-12-05: Version 1.02: added AsciiArter, CreateGlossary, MusicTheory, added About screen");
  v.push_back("2012-12-23: Version 1.03: added Rubik's Clock");
  v.push_back("2013-05-20: Version 1.04: added RegexTester, TestQuestion, TestQtArrowItems, TestQtModels");
  v.push_back("2013-05-22: Version 1.05: can crosscompile console and desktop version to Windows");
  v.push_back("2013-05-25: Version 1.06: scalable architecture, added placeholder dialogs in desktop version");
  v.push_back("2013-05-26: Version 1.07: changed the main menu, added StateObserver");
  v.push_back("2013-05-29: Version 1.08: added KalmanFilterer, added About button in desktop version");
  v.push_back("2013-07-11: Version 1.09: transition phase to Qt5, still supports Qt4");
  return v;
}

} //~namespace RichelBilderbeek


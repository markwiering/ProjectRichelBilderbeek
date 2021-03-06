//---------------------------------------------------------------------------
/*
RichelBilderbeek::Program, class for a program by Richel Bilderbeek
Copyright (C) 2012 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ProjectRichelBilderbeekProgram.htm
//---------------------------------------------------------------------------
#ifndef RICHELBILDERBEEKPROGRAM_H
#define RICHELBILDERBEEKPROGRAM_H

#include <string>

#include <boost/shared_ptr.hpp>

#include "richelbilderbeekprogramstatus.h"
#include "richelbilderbeekprogramtype.h"

namespace RichelBilderbeek {

///RichelBilderbeek::Program is the base class for program information
struct Program
{
  virtual ~Program() {}

  ///Create a std::vector with all different Program instances in it
  static const boost::shared_ptr<Program> CreateProgram(const ProgramType type);

  ///Create a std::vector with all different Program instances in it
  static const std::vector<boost::shared_ptr<Program> > GetAllPrograms();

  ///Get the filename of a console version screenshot
  virtual const std::string GetFilenameConsole() const = 0;

  ///Get the filename of a desktop platform-independent version screenshot
  virtual const std::string GetFilenameDesktop() const = 0;

  ///Get the filename of a desktop windows-only version screenshot
  virtual const std::string GetFilenameDesktopWindowsOnly() const = 0;

  ///Get the filename of a web application version screenshot
  virtual const std::string GetFilenameWeb() const = 0;

  ///The item its name, e.g. 'SimMysteryMachine'
  virtual const std::string GetName() const = 0;

  ///Status of the console-only version
  virtual ProgramStatus GetStatusConsole() const = 0;

  ///Status of the Windows-only desktop version
  virtual ProgramStatus GetStatusDesktopWindowsOnly() const = 0;

  ///Status of the platform-independent desktop version
  virtual ProgramStatus GetStatusDesktop() const = 0;

  ///Status of the web application version
  virtual ProgramStatus GetStatusWebApplication() const = 0;

  ///The program, e.g. 'RichelBilderbeekProgramType::boenken'
  virtual ProgramType GetType() const = 0;

  ///The type of program its name, e.g. 'Game'
  virtual const std::string GetTypeName() const = 0;

  ///The item its URL (at http://ww.richelbilderbeek.nl), e.g. 'ToolSimMysteryMachine.htm'
  virtual const std::string GetUrl() const = 0;

  ///Obtain the version of this class
  static const std::string GetVersion();

  ///Obtain the version history of this class
  static const std::vector<std::string> GetVersionHistory();

  private:
  ///Get the base of a filename
  const std::string GetFilenameBase() const;
};

///RichelBilderbeek::ProgramClass is the base class for all class demonstration programs
struct ProgramClass: public RichelBilderbeek::Program
{
  virtual ~ProgramClass() {}

  ///The type of program its name, e.g. 'game'
  const std::string GetTypeName() const { return "class"; }
};

struct ProgramGame: public RichelBilderbeek::Program
{
  virtual ~ProgramGame() {}

  ///The type of program its name, e.g. 'game'
  const std::string GetTypeName() const { return "game"; }
};

struct ProgramProject: public RichelBilderbeek::Program
{
  virtual ~ProgramProject() {}

  ///The type of program its name, e.g. 'game'
  const std::string GetTypeName() const { return "project"; }
};

struct ProgramTool: public RichelBilderbeek::Program
{
  virtual ~ProgramTool() {}

  ///The type of program its name, e.g. 'game'
  const std::string GetTypeName() const { return "tool"; }
};

struct ProgramGnuplotInterface: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return "CppGnuplotInterface.png"; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "GnuplotInterface"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::gnuplotInterface; }
  const std::string GetUrl() const { return "CppGnuplotInterface.htm"; }
};

struct ProgramGrayCoder: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolGrayCoder_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "GrayCoder"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::grayCoder; }
  const std::string GetUrl() const { return "GrayCoder.htm"; }
};

struct ProgramNdsMake: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Ndsmake"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::ndsMake; }
  const std::string GetUrl() const { return "CppNdsMake.htm"; }
};

struct ProgramTestBroadcastServer: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestBroadcastServer_1_0.png"; }
  const std::string GetName() const { return "TestBroadcastServer"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::n_a; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::n_a; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::n_a; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testBroadcastServer; }
  const std::string GetUrl() const { return "ToolTestBroadcastServer.htm"; }
};

struct ProgramTestChess: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestChess20120209.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestChess20120207.png"; }
  const std::string GetName() const { return "TestChess"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::wip; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::wip; }
  ProgramType GetType() const { return ProgramType::testChess; }
  const std::string GetUrl() const { return "ToolTestChess.htm"; }
};

struct ProgramTestDial: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestDial_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestDial_1_1.png"; }
  const std::string GetName() const { return "TestDial"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::n_a; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testDial; }
  const std::string GetUrl() const { return "ToolTestDial.htm"; }
};

struct ProgramTestEncranger: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestEncranger_2_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolTestEncranger_1_0.png"; }
  const std::string GetFilenameWeb() const { return "ToolTestEncranger_2_1.png"; }
  const std::string GetName() const { return "TestEncranger"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testEncranger; }
  const std::string GetUrl() const { return "ToolTestEncranger.htm"; }
};

struct ProgramTestEntrance: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestEntrance_1_0.png"; }
  const std::string GetName() const { return "TestEntrance"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::n_a; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::n_a; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::n_a; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testEntrance; }
  const std::string GetUrl() const { return "ToolTestEntrance.htm"; }
};

struct ProgramTestExercise: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestExercise_1_0.png"; }
  const std::string GetName() const { return "TestExercise"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::unk; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testExercise; }
  const std::string GetUrl() const { return "ToolTestExercise.htm"; }
};

struct ProgramTestFunctionParser: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestFunctionParser_2_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolTestFunctionParser_1_0.png"; }
  const std::string GetFilenameWeb() const { return "ToolTestFunctionParser_2_1.png"; }
  const std::string GetName() const { return "TestFunctionParser"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testFunctionParser; }
  const std::string GetUrl() const { return "ToolTestFunctionParser.htm"; }
};

struct ProgramTestGroupWidget: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestGroupWidget_1_0.png"; }
  const std::string GetName() const { return "TestGroupWidget"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testGroupWidget; }
  const std::string GetUrl() const { return "ToolTestGroupWidget.htm"; }
};

struct ProgramTestLed : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestLed_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestLed_1_1.png"; }
  const std::string GetName() const { return "TestLed"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testLed; }
  const std::string GetUrl() const { return "ToolTestLed.htm"; }
};

struct ProgramTestMultiVector : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestMultiVector"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testMultiVector; }
  const std::string GetUrl() const { return "ToolTestMultiVector.htm"; }
};

struct ProgramTestNdsMake : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestNdsmake_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestNdsmake"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testNdsMake; }
  const std::string GetUrl() const { return "ToolTestNdsmake.htm"; }
};

struct ProgramTestNeuralNet : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestNeuralNet_0_1.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestNeuralNet"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testNeuralNet; }
  const std::string GetUrl() const { return "ToolTestNeuralNet.htm"; }
};

struct ProgramTestPrimeExpert : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestPrimeExpert_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestPrimeExpert"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testPrimeExpert; }
  const std::string GetUrl() const { return "ToolTestPrimeExpert.htm"; }
};

struct ProgramTestPylos: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestPylos_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestPylos"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testPylos; }
  const std::string GetUrl() const { return "ToolTestPylos.htm"; }
};

struct ProgramTestQrcFile: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestQrcFile"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testQrcFile; }
  const std::string GetUrl() const { return "ToolTestQrcFile.htm"; }
};

struct ProgramTestQtArrowItems: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestQtArrowItems_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestQtArrowItems"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testQtArrowItems; }
  const std::string GetUrl() const { return "ToolTestQtArrowItems.htm"; }
};

struct ProgramTestQtCreatorProFile: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestQtCreatorProFile"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testQtCreatorProFile; }
  const std::string GetUrl() const { return "ToolTestQtCreatorProFile.htm"; }
};

struct ProgramTestQtKeyboardFriendlyGraphicsView: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestQtKeyboardFriendlyGraphicsView"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testQtKeyboardFriendlyGraphicsView; }
  const std::string GetUrl() const { return "ToolTestQtKeyboardFriendlyGraphicsView.htm"; }
};

struct ProgramTestQtModels : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestQtModels"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testQtModels; }
  const std::string GetUrl() const { return "ToolTestQtModels.htm"; }
};

struct ProgramTestQtRoundedEditRectItem : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestQtRoundedEditRectItem_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestQtRoundedEditRectItem"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testQtRoundedEditRectItem; }
  const std::string GetUrl() const { return "ToolTestQtRoundedEditRectItem.htm"; }
};

struct ProgramTestQtRoundedRectItem : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestQtRoundedRectItem_1_1.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestQtRoundedRectItem"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testQtRoundedRectItem; }
  const std::string GetUrl() const { return "ToolTestQtRoundedRectItem.htm"; }
};

struct ProgramTestQtRoundedTextRectItem : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestQtRoundedTextRectItem_1_1.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestQtRoundedTextRectItem"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testQtRoundedTextRectItem; }
  const std::string GetUrl() const { return "ToolTestQtRoundedTextRectItem.htm"; }
};

struct ProgramTestQuestion: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestQuestion_2_1.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestQuestion"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::unk; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testQuestion; }
  const std::string GetUrl() const { return "ToolTestQuestion.htm"; }
};

struct ProgramTestSelectFile: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestSelectFileDialog_1_1.png"; }
  const std::string GetName() const { return "TestSelectFile"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testSelectFile; }
  const std::string GetUrl() const { return "ToolTestSelectFile.htm"; }
};

struct ProgramTestServerPusher: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestServerPusher"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testServerPusher; }
  const std::string GetUrl() const { return "ToolTestServerPusher.htm"; }
};

struct ProgramTestShape: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestShape_1_0_desktop.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestShape_1_0_web.png"; }
  const std::string GetName() const { return "TestShape"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testShape; }
  const std::string GetUrl() const { return "ToolTestShape.htm"; }
};

struct ProgramTestShinyButton : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestShinyButton_2_0_desktop.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestShinyButton_2_0_web.png"; }
  const std::string GetName() const { return "TestShinyButton"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testShinyButton; }
  const std::string GetUrl() const { return "ToolTestShinyButton.htm"; }
};

struct ProgramTestStopwatch : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestStopwatch"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testStopwatch; }
  const std::string GetUrl() const { return "ToolTestStopwatch.htm"; }
};

struct ProgramTestTicTacToe: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestTicTacToe_1_1.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTestTicTacToe_1_2.png"; }
  const std::string GetName() const { return "TestTicTacToe"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testTicTacToe; }
  const std::string GetUrl() const { return "ToolTestTicTacToe.htm"; }
};

struct ProgramTestTimedServerPusher: public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestTimedServerPusher"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testTimedServerPusher; }
  const std::string GetUrl() const { return "ToolTestTimedServerPusher.htm"; }
};

struct ProgramTestToggleButton : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestToggleButton"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::testToggleButton; }
  const std::string GetUrl() const { return "ToolTestToggleButton.htm"; }
};

struct ProgramTestTwoDigitNewick : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestTwoDigitNewick_0_6.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestTwoDigitNewick"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testTwoDigitNewick; }
  const std::string GetUrl() const { return "ToolTestTwoDigitNewick.htm"; }
};

struct ProgramBeerWanter: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "GameBeerWanter5.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GameBeerWanter3.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "BeerWanter"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::beerWanter; }
  const std::string GetUrl() const { return "GameBeerWanter.htm"; }
};

struct ProgramBoenken: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "GameBoenken_3_1.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GameBoenken_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Boenken"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::boenken; }
  const std::string GetUrl() const { return "GameBoenken.htm"; }
};

struct ProgramConnectThree: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "GameConnectThree_5_2.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "GameConnectThree_6_0.png"; }
  const std::string GetName() const { return "ConnectThree"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::connectThree; }
  const std::string GetUrl() const { return "GameConnectThree.htm"; }
};

struct ProgramDasWahreSchlagerfest: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "GameDasWahreSchlagerfest_2_2.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GameDasWahreSchlagerfest_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Das Wahre Schlagerfest"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::dasWahreSchlagerfest; }
  const std::string GetUrl() const { return "GameDasWahreSchlagerfest.htm"; }
};

struct ProgramK3OpEenRij: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GameK3OpEenRij_4_0.png"; }
  const std::string GetFilenameWeb() const { return "GameK3OpEenRij_5_0.png"; }
  const std::string GetName() const { return "K3 Op Een Rij"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::k3OpEenRij; }
  const std::string GetUrl() const { return "GameK3OpEenRij.htm"; }
};

struct ProgramKalmanFilterer: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolKalmanFilterer_1_6.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolKalmanFilterer_1_4.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "KalmanFilterer"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::kalmanFilterer; }
  const std::string GetUrl() const { return "ToolKalmanFilterer.htm"; }
};

struct ProgramKeySender : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolKeySender_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "KeySender"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::keySender; }
  const std::string GetUrl() const { return "ToolKeySender.htm"; }
};

struct ProgramKnokfighter: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GameKnokfighter_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Knokfighter"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::knokfighter; }
  const std::string GetUrl() const { return "GameKnokfighter.htm"; }
};

struct ProgramKTouchLectureCreator : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "KTouchLectureCreator"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::kTouchLectureCreator; }
  const std::string GetUrl() const { return "ToolKTouchLectureCreator.htm"; }
};

struct ProgramLearyCircumplex : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolLearyCircumplex_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "LearyCircumplex"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::learyCircumplex; }
  const std::string GetUrl() const { return "ToolLearyCircumplex.htm"; }
};

struct ProgramLogisticGrowthSimulator : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolLogisticGrowthSimulator_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "LogisticGrowthSimulator"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::logisticGrowthSimulator; }
  const std::string GetUrl() const { return "ToolLogisticGrowthSimulator.htm"; }
};

struct ProgramLoose : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolLoose_2_0.png"; }
  const std::string GetName() const { return "LogisticGrowthSimulator"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::loose; }
  const std::string GetUrl() const { return "ToolLoose.htm"; }
};

struct ProgramMaziak: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "GameMaziak_1_3.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GameMaziak_2_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Maziak"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::maziak; }
  const std::string GetUrl() const { return "GameMaziak.htm"; }
};

struct ProgramMorpher : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolMorpher_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Morpher"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::morpher; }
  const std::string GetUrl() const { return "ToolMorpher.htm"; }
};

struct ProgramPokeVolley: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GamePokeVolley_2_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "PokeVolley"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::pokeVolley; }
  const std::string GetUrl() const { return "GamePokeVolley.htm"; }
};

struct ProgramPylos: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "GamePylos_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Pylos"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::pylos; }
  const std::string GetUrl() const { return "GamePylos.htm"; }
};

struct ProgramQmakeWatcher : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "QmakeWatcher"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::qmakeWatcher; }
  const std::string GetUrl() const { return "ToolQmakeWatcher.htm"; }
};

struct ProgramQuadraticSolver: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return "ToolQuadraticSolver_1_0.png"; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "QuadraticSolver"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::quadraticSolver; }
  const std::string GetUrl() const { return "ToolQuadraticSolver..htm"; }
};

struct ProgramReversi: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GameReversi_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Reversi"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::reversi; }
  const std::string GetUrl() const { return "GameReversi.htm"; }
};

struct ProgramRubiksClock: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "GameRubiksClockDesktop_2_2.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GameRubiksClock_1_0.png"; }
  const std::string GetFilenameWeb() const { return "GameRubiksClock_2_1.png"; }
  const std::string GetName() const { return "Rubik's Clock"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::rubiksClock; }
  const std::string GetUrl() const { return "GameRubiksClock.htm"; }
};

struct ProgramSearchAndDestroyChess: public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return "GameSearchAndDestroyChessConsole_1_0.png"; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GameSearchAndDestroyChess_2_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Search And Destroy Chess"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::searchAndDestroyChess; }
  const std::string GetUrl() const { return "GameSearchAndDestroyChess.htm"; }
};

struct ProgramSpaceHarry : public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "GameSpaceHarry_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Space Harry"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::spaceHarry; }
  const std::string GetUrl() const { return "GameSpaceHarry.htm"; }
};

struct ProgramStateObserver : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolStateObserver_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "StateObserver"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::stateObserver; }
  const std::string GetUrl() const { return "ToolStateObserver.htm"; }
};

struct ProgramStyleSheetSetter : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "StyleSheetSetter"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::styleSheetSetter; }
  const std::string GetUrl() const { return "ToolStyleSheetSetter.htm"; }
};

struct ProgramTicTacToe : public RichelBilderbeek::ProgramGame
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "GameTicTacToe_1_1.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "GameTicTacToe_1_4.png"; }
  const std::string GetName() const { return "TicTacToe"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::ticTacToe; }
  const std::string GetUrl() const { return "GameTicTacToe.htm"; }
};

struct ProgramTicTacToeLearner : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTicTacToeLearner_0_3.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TicTacToeLearner"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::ticTacToeLearner; }
  const std::string GetUrl() const { return "ToolTicTacToeLearner.htm"; }
};

struct ProgramTicTacToeValuer : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTicTacToeValuer_0_7.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TicTacToeValuer"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::ticTacToeValuer; }
  const std::string GetUrl() const { return "ToolTicTacToeValuer.htm"; }
};

struct ProgramBochum: public RichelBilderbeek::ProgramProject
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ProjectBochumGaborFiltersResults.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Project Bochum"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::n_a; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::bochum; }
  const std::string GetUrl() const { return "ProjectBochum.htm"; }
};

struct ProgramChrisWiley: public RichelBilderbeek::ProgramProject
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ProjectChrisWiley_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Project Chris Wiley"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::chrisWiley; }
  const std::string GetUrl() const { return "ProjectChrisWiley.htm"; }
};

struct ProgramCrossPoll: public RichelBilderbeek::ProgramProject
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ProjectCrossPoll3.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "CrossPoll"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::crossPoll; }
  const std::string GetUrl() const { return "ProjectCrossPoll.htm"; }
};

struct ProgramGtst: public RichelBilderbeek::ProgramProject
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ProjectGtst_1_2.png"; }
  const std::string GetName() const { return "GTST"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::gtst; }
  const std::string GetUrl() const { return "ProjectGtst.htm"; }
};

struct ProgramMuscaDomestica: public RichelBilderbeek::ProgramProject
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ProjectMuscaDomestica_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Project Musca Domestica"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::muscaDomestica; }
  const std::string GetUrl() const { return "ProjectMuscaDomestica.htm"; }
};

struct ProgramNewickVector: public RichelBilderbeek::ProgramProject
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "NewickVector"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::newickVector; }
  const std::string GetUrl() const { return "ProjectNewickVector.htm"; }
};

struct ProgramThorVeen: public RichelBilderbeek::ProgramProject
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ProjectThorVeen_0_9.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Project ThorVeen"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::thorVeen; }
  const std::string GetUrl() const { return "ProjectThorVeen.htm"; }
};

struct ProgramTwoDigitNewick : public RichelBilderbeek::ProgramProject
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TwoDigitNewick"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::twoDigitNewick; }
  const std::string GetUrl() const { return "ProjectTwoDigitNewick.htm"; }
};

struct ProgramUbuntuOneWatcher : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolUbuntuOneWatcher_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "UbuntuOneWatcher"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::ubuntuOneWatcher; }
  const std::string GetUrl() const { return "ToolUbuntuOneWatcher.htm"; }
};

struct ProgramAsciiArter: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolAsciiArter_5_1.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolAsciiArter_1_0.png"; }
  const std::string GetFilenameWeb() const { return "ToolTestAsciiArter_4_1.png"; }
  const std::string GetName() const { return "AsciiArter"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::asciiArter; }
  const std::string GetUrl() const { return "ToolAsciiArter.htm"; }
};

struct ProgramBarbaImage: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolBarbaImage_1_3.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "BarbaImage"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::barbaImage; }
  const std::string GetUrl() const { return "ToolBarbaImage.htm"; }
};

struct ProgramCodeToHtml: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolCodeToHtml_2_3.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolCodeToHtml_2_0.png"; }
  const std::string GetName() const { return "CodeToHtml"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::codeToHtml; }
  const std::string GetUrl() const { return "ToolCodeToHtml.htm"; }
};

struct ProgramCreateGlossary: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "CreateGlossary"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::createGlossary; }
  const std::string GetUrl() const { return "ToolCreateGlossary.htm"; }
};

struct ProgramCreateQtProjectZipFile: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolCreateQtProjectZipFile_1_3.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "CreateQtProjectZipFile"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::wip; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::createQtProjectZipFile; }
  const std::string GetUrl() const { return "ToolCreateQtProjectZipFile.htm"; }
};

struct ProgramCreateSitemap : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "CreateSitemap"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::createSitemap; }
  const std::string GetUrl() const { return "ToolCreateSitemap.htm"; }
};

struct ProgramDotMatrix: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolDotMatrix_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "DotMatrix"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::dotMatrix; }
  const std::string GetUrl() const { return "ToolDotMatrix.htm"; }
};

struct ProgramEncranger: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolEncranger_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Encranger"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::encranger; }
  const std::string GetUrl() const { return "ToolEncranger.htm"; }
};

struct ProgramFilterOperationer: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolFilterOperationer_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "FilterOperationer"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::filterOperationer; }
  const std::string GetUrl() const { return "ToolFilterOperationer.htm"; }
};

struct ProgramFryskLeareLieder: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolFryskLeareLieder_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "FryskLeareLieder"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::fryskLeareLieder; }
  const std::string GetUrl() const { return "ToolFryskLeareLieder.htm"; }
};

struct ProgramFunctionPlotter: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolFunctionPlotter_1_1.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "FunctionPlotter"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::functionPlotter; }
  const std::string GetUrl() const { return "ToolFunctionPlotter.htm"; }
};

struct ProgramGaborFilter: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolGaborFilter_2_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolGaborFilter_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "GaborFilter"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::gaborFilter; }
  const std::string GetUrl() const { return "ToolGaborFilter.htm"; }
};

struct ProgramHistogramEqualizationer: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolHistogramEqualizationer_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "HistogramEqualizationer"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::unk; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::histogramEqualizationer; }
  const std::string GetUrl() const { return "ToolHistogramEqualizationer.htm"; }
};

struct ProgramHometrainer: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolHometrainer_1_8.png"; }
  const std::string GetFilenameWeb() const { return "ToolHometrainer_2_0.png"; }
  const std::string GetName() const { return "Hometrainer"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::hometrainer; }
  const std::string GetUrl() const { return "ToolHometrainer.htm"; }
};

struct ProgramImageRotater: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolImageRotaterClx_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "ImageRotater"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::imageRotater; }
  const std::string GetUrl() const { return "ToolImageRotater.htm"; }
};

struct ProgramMazeCreator: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolMazeCreator_2_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolMazeCreator_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "MazeCreator"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::mazeCreator; }
  const std::string GetUrl() const { return "ToolMazeCreator.htm"; }
};

struct ProgramMultiEncranger: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolMultiEncranger_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "MultiEncranger"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::multiEncranger; }
  const std::string GetUrl() const { return "ToolMultiEncranger.htm"; }
};

struct ProgramMusicTheory : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolMusicTheory_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "MusicTheory"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::musicTheory; }
  const std::string GetUrl() const { return "ToolMusicTheory.htm"; }
};

struct ProgramPaperRockScissors : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolPaperRockScissors_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "PaperRockScissors"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::paperRockScissors; }
  const std::string GetUrl() const { return "ToolPaperRockScissors.htm"; }
};

struct ProgramPause : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Pause"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::pause; }
  const std::string GetUrl() const { return "ToolPause.htm"; }
};

struct ProgramPerfectElasticCollision: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolPerfectElasticCollision_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "PerfectElasticCollision"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::perfectElasticCollision; }
  const std::string GetUrl() const { return "ToolPerfectElasticCollision.htm"; }
};

struct ProgramPicToCode: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolPicToCode_1_2.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolPicToCode_1_3.png"; }
  const std::string GetName() const { return "PicToCode"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::picToCode; }
  const std::string GetUrl() const { return "ToolPicToCode.htm"; }
};

struct ProgramPixelator: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolPixelator_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "Pixelator"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::pixelator; }
  const std::string GetUrl() const { return "ToolPixelator.htm"; }
};

struct ProgramRandomCode: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolRandomCode_4_2.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolRandomCode_1_0.png"; }
  const std::string GetFilenameWeb() const { return "ToolRandomCode_3_0.png"; }
  const std::string GetName() const { return "RandomCode"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::randomCode; }
  const std::string GetUrl() const { return "ToolRandomCode.htm"; }
};

struct ProgramRasper: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolRasper_0_3.png"; }
  const std::string GetName() const { return "Rasper"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::rasper; }
  const std::string GetUrl() const { return "ToolRasper.htm"; }
};

struct ProgramRefrigeratorPuzzleSolver: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolRefrigeratorPuzzleSolver_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "RefrigeratorPuzzleSolver"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::refrigeratorPuzzleSolver; }
  const std::string GetUrl() const { return "ToolRefrigeratorPuzzleSolver.htm"; }
};



struct ProgramRegexTester: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolRegexTester_1_1.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "RegexTester"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::regexTester; }
  const std::string GetUrl() const { return "ToolRegexTester.htm"; }
};

struct ProgramRichelBilderbeekGallery : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolRichelBilderbeekGallery_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "RichelBilderbeekGallery"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::richelBilderbeekGallery; }
  const std::string GetUrl() const { return "ToolRichelBilderbeekGallery.htm"; }
};


struct ProgramRichelBilderbeekNlSitemapGenerator : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolRichelbilderbeekNlSitemapGenerator_2_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "RichelBilderbeekNlSitemapGenerator"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::richelBilderbeekNlSitemapGenerator; }
  const std::string GetUrl() const { return "ToolRichelBilderbeekNlSitemapGenerator.htm"; }
};

struct ProgramSecretMessage: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolSecretMessage_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "SecretMessage"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::secretMessage; }
  const std::string GetUrl() const { return "ToolSecretMessage.htm"; }
};

struct ProgramSimBrainiac: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolSimBrainiac_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "SimBrainiac"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::simBrainiac; }
  const std::string GetUrl() const { return "ToolSimBrainiac.htm"; }
};

struct ProgramSimImmuneResponse: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolSimImmuneResponse_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "SimImmuneResponse"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::simImmuneResponse; }
  const std::string GetUrl() const { return "ToolSimImmuneResponse.htm"; }
};

struct ProgramSimMysteryMachine : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolSimMysteryMachine_1_1_desktop.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolSimMysteryMachine_1_1_web.png"; }
  const std::string GetName() const { return "SimMysteryMachine"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::simMysteryMachine; }
  const std::string GetUrl() const { return "ToolSimMysteryMachine.htm"; }
};

struct ProgramSimplifyNewick : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolSimplifyNewick_1_2.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "SimplifyNewick"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::simplifyNewick; }
  const std::string GetUrl() const { return "ToolSimplifyNewick.htm"; }
};



struct ProgramSimStagecraft: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolSimStagecraft_1_1.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "SimStagecraft"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::simStagecraft; }
  const std::string GetUrl() const { return "ToolSimStagecraft.htm"; }
};

struct ProgramSoaSim: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolSoaSim_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "SoaSim"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::soaSim; }
  const std::string GetUrl() const { return "ToolSoaSim.htm"; }
};

struct ProgramSolvePuzzleX: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "SolvePuzzleX"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::solvePuzzleX; }
  const std::string GetUrl() const { return "ToolSolvePuzzleX.htm"; }
};

struct ProgramSurfacePlotter : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolSurfacePlotter_1_2.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "SurfacePlotter"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::surfacePlotter; }
  const std::string GetUrl() const { return "ToolSurfacePlotter.htm"; }
};

struct ProgramTestAbout : public RichelBilderbeek::ProgramClass
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestAbout"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testAbout; }
  const std::string GetUrl() const { return "ToolTestAbout.htm"; }
};

struct ProgramTestBinaryNewickVector : public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolTestBinaryNewickVector_1_5.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "TestBinaryNewickVector"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::testBinaryNewickVector; }
  const std::string GetUrl() const { return "ToolTestBinaryNewickVector.htm"; }
};

struct ProgramThresholdFilterer: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return "ToolThresholdFilterer_1_0.png"; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "ThresholdFilterer"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::thresholdFilterer; }
  const std::string GetUrl() const { return "ToolThresholdFilterer.htm"; }
};

struct ProgramTimePoll: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return ""; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return "ToolTimePoll_4_1.png"; }
  const std::string GetName() const { return "TimePoll"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::no; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::yes; }
  ProgramType GetType() const { return ProgramType::timePoll; }
  const std::string GetUrl() const { return "ToolTimePoll.htm"; }
};

struct ProgramVisualAbc: public RichelBilderbeek::ProgramTool
{
  const std::string GetFilenameConsole() const { return ""; }
  const std::string GetFilenameDesktop() const { return "ToolVisualAbc_1_0.png"; }
  const std::string GetFilenameDesktopWindowsOnly() const { return ""; }
  const std::string GetFilenameWeb() const { return ""; }
  const std::string GetName() const { return "VisualAbc"; }
  ProgramStatus GetStatusConsole() const { return ProgramStatus::no; }
  ProgramStatus GetStatusDesktopWindowsOnly() const { return ProgramStatus::nvr; }
  ProgramStatus GetStatusDesktop() const { return ProgramStatus::yes; }
  ProgramStatus GetStatusWebApplication() const { return ProgramStatus::no; }
  ProgramType GetType() const { return ProgramType::visualAbc; }
  const std::string GetUrl() const { return "ToolVisualAbc.htm"; }
};

std::ostream& operator<<(std::ostream& os, const Program * const p);
bool operator<(const Program& lhs, const Program& rhs);

} //~namespace RichelBilderbeek

#endif // RICHELBILDERBEEKPROGRAM_H

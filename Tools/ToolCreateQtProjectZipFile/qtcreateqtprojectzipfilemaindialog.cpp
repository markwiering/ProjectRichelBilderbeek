//---------------------------------------------------------------------------
/*
CreateQtProjectZipFile, tool to create a zip file from a Qt project
Copyright (C) 2012-2013 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolCreateQtProjectZipFile.htm
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
#include "qtcreateqtprojectzipfilemaindialog.h"

#include <boost/filesystem.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>

#include <QFileDialog>
#include <QKeyEvent>
#include <QListWidgetItem>
#include <QMessageBox>

#include "createqtprojectzipfilemenudialog.h"
#include "qtcreatorprofilezipscript.h"
#include "trace.h"
#include "ui_qtcreateqtprojectzipfilemaindialog.h"

QtCreateQtProjectZipFileMainDialog::QtCreateQtProjectZipFileMainDialog(QWidget *parent) :
  QtHideAndShowDialog(parent),
  ui(new Ui::QtCreateQtProjectZipFileMainDialog)
{
  ui->setupUi(this);
  #ifndef NDEBUG
  Test();
  #endif

  ui->lineEdit->setText("Tools/ToolCreateQtProjectZipFile");
}

QtCreateQtProjectZipFileMainDialog::~QtCreateQtProjectZipFileMainDialog()
{
  delete ui;
}

void QtCreateQtProjectZipFileMainDialog::CreateScript(const std::string source_folder)
{
  /*
  std::stringstream s;

  const std::vector<std::string> pro_filenames = GetProFilesInFolder(source_folder);

  std::vector<boost::shared_ptr<const QtCreatorProFileZipScript> > scripts;

  for (const std::string& pro_filename: pro_filenames)
  {
    const boost::shared_ptr<QtCreatorProFile> pro_file(
      new QtCreatorProFile(pro_filename));
    assert(pro_file);

    const boost::shared_ptr<QtCreatorProFileZipScript> script(
      new QtCreatorProFileZipScript(pro_file));
    assert(script);

    scripts.push_back(script);
  }


  const boost::shared_ptr<QtCreatorProFileZipScript> merged_script
    = QtCreatorProFileZipScript::Merge(scripts);
  if (!merged_script)
  {
    ui->text->setPlainText("Folder does not contain any .pro files");
  }
  else
  {
    s << *merged_script << '\n';
    ui->text->setPlainText( s.str().c_str() );
  }
  */
  ui->text->setPlainText(QtCreatorProFileZipScript::CreateScript(source_folder).c_str());
}


void QtCreateQtProjectZipFileMainDialog::keyPressEvent(QKeyEvent * event)
{
  if (event->key() == Qt::Key_Escape) { close(); return; }
}

void QtCreateQtProjectZipFileMainDialog::on_lineEdit_textChanged(const QString &arg1)
{
  const std::string source_folder = "../../" + arg1.toStdString();

  if (!boost::filesystem::exists(source_folder))
  {
    const std::string text = "Folder '" + source_folder + std::string("' does not exist.");
    ui->text->setPlainText(text.c_str());
    return;
  }
  CreateScript(source_folder);
}

#ifndef NDEBUG
void QtCreateQtProjectZipFileMainDialog::Test()
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  //Test basic functions on this project with going two folders down
  const std::vector<std::string> pro_filenames
    =
    {
      "../../Tools/ToolCreateQtProjectZipFile/ToolCreateQtProjectZipFileDesktop.pro",
      "../../Tools/ToolCodeToHtml/ToolCodeToHtmlDesktop.pro",
      "../../Tools/ToolKalmanFilterer/ToolKalmanFiltererDesktop.pro",
      "../../Projects/ProjectRichelBilderbeek/ProjectRichelBilderbeekDesktop.pro"
    };
  const int n_tests = std::count_if(
    pro_filenames.begin(), pro_filenames.end(),
      [](const std::string& filename)
      { return boost::filesystem::is_regular_file(filename); }
    );
  const std::string s = "Testing "
    + boost::lexical_cast<std::string>(n_tests)
    + " / "
    + boost::lexical_cast<std::string>(pro_filenames.size());
  TRACE(s);

  for (const std::string& pro_filename: pro_filenames)
  {
    if (!boost::filesystem::is_regular_file(pro_filename)) continue;
    const boost::shared_ptr<const QtCreatorProFile> pro_file(
      new QtCreatorProFile(pro_filename));
    assert(pro_file);

    const boost::shared_ptr<const QtCreatorProFileZipScript> script(
      new QtCreatorProFileZipScript(pro_file));

    std::stringstream s;
    s << *script;
    assert(!s.str().empty());
  }
}
#endif


//---------------------------------------------------------------------------
/*
RichelbilderbeekNlSitemapGenerator, generates the richelbilderbeek.nl sitemap
Copyright (C) 2010-2012 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolRichelbilderbeekNlSitemapGenerator.htm
//---------------------------------------------------------------------------
#ifndef SITEMAPGENERATORMAINDIALOG_H
#define SITEMAPGENERATORMAINDIALOG_H

#include "qthideandshowdialog.h"

namespace Ui {
  class QtSitemapGeneratorMainDialog;
}

class QtSitemapGeneratorMainDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtSitemapGeneratorMainDialog(QWidget *parent = 0);
  ~QtSitemapGeneratorMainDialog();

protected:
  void changeEvent(QEvent *e);
  void keyPressEvent(QKeyEvent * e);

private:
  Ui::QtSitemapGeneratorMainDialog *ui;

private slots:
  void on_button_start_clicked();

  static const std::vector<std::string> AddHeader(const std::vector<std::string>& files);

  static const std::vector<std::string> CreateConfigXml(
    const std::string& local_website_path,
    const std::string& urllist_path);

  //From http://www.richelbilderbeek.nl/CppFileExists.htm
  //bool FileExists(const std::string& filename);

  //From http://www.richelbilderbeek.nl/CppFileToVector.htm
  static const std::vector<std::string> FileToVector(const std::string& fileName);

  //From http://www.richelbilderbeek.nl/CppGetCurrentFolder.htm
  static const std::string GetCurrentFolder();

  //From http://www.richelbilderbeek.nl/CppGetCurrentFolder.htm
  static const std::string GetCurrentFolder(const std::string& s);

  //From http://www.richelbilderbeek.nl/CppGetFilesInFolder.htm
  static const std::vector<std::string> GetFilesInFolder(const std::string& folder);

  //From http://www.richelbilderbeek.nl/CppGetHtmlFilesInFolder.htm
  static const std::vector<std::string> GetHtmlFilesInFolder(const std::string& folder);

  //From http://www.richelbilderbeek.nl/CppGetDateIso8601.htm
  static const std::string GetDateIso8601();

  //From http://www.richelbilderbeek.nl/CppGetPath.htm
  static const std::string GetPath(const std::string& filename);

};

#endif // SITEMAPGENERATORMAINDIALOG_H

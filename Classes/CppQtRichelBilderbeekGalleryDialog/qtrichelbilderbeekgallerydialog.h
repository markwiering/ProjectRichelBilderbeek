//---------------------------------------------------------------------------
/*
QtRichelBilderbeekGalleryDialog, gallery of Richel Bilderbeek's work
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
//From http://www.richelbilderbeek.nl/CppQtRichelBilderbeekGalleryDialog.htm
//---------------------------------------------------------------------------
#ifndef QTRICHELBILDERBEEKGALLERYDIALOG_H
#define QTRICHELBILDERBEEKGALLERYDIALOG_H

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

#include <vector>

#include <boost/shared_ptr.hpp>

#include "qthideandshowdialog.h"

struct QModelIndex;
namespace RichelBilderbeek { struct Program; }
namespace Ui { class QtRichelBilderbeekGalleryDialog; }

class QtRichelBilderbeekGalleryDialog : public QtHideAndShowDialog
{
  Q_OBJECT

public:
  explicit QtRichelBilderbeekGalleryDialog(QWidget *parent = 0);
  ~QtRichelBilderbeekGalleryDialog();

  ///Obtain the version of this class
  static const std::string GetVersion();

  ///Obtain the version history of this class
  static const std::vector<std::string> GetVersionHistory();

protected:
  void keyPressEvent(QKeyEvent* e);


private slots:
  void on_table_clicked(const QModelIndex &index);

  void on_table_cellEntered(int row, int column);

  void on_table_entered(const QModelIndex &index);

private:
  Ui::QtRichelBilderbeekGalleryDialog *ui;
  const std::vector<boost::shared_ptr<RichelBilderbeek::Program> > m_programs;

  ///Show the screenshot requested by the item in [col,row]
  void ShowScreenshot(const int col, const int row);
};

#endif // QTRICHELBILDERBEEKGALLERYDIALOG_H


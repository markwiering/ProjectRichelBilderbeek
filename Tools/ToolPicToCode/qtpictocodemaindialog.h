//---------------------------------------------------------------------------
/*
PicToCode, tool to convert a picture to C++ code
Copyright (C) 2010-2011 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolPicToCode.htm
//---------------------------------------------------------------------------
#ifndef QTPICTOCODEDIALOG_H
#define QTPICTOCODEDIALOG_H
//---------------------------------------------------------------------------
#include <string>
//---------------------------------------------------------------------------
#include <QDialog>
//---------------------------------------------------------------------------
namespace Ui {
  class QtPicToCodeMainDialog;
}
//---------------------------------------------------------------------------
struct QImage;
#include "pictocodemaindialog.h"
//---------------------------------------------------------------------------
class QtPicToCodeMainDialog : public QDialog
{
  Q_OBJECT

public:
  explicit QtPicToCodeMainDialog(QWidget *parent = 0);
  ~QtPicToCodeMainDialog();

protected:
  void changeEvent(QEvent *e);

private:
  Ui::QtPicToCodeMainDialog *ui;

private slots:
  void on_button_convert_clicked();
  void on_button_select_file_clicked();

public:
  static const PicToCodeMainDialog::YxImage ImageToImage(const QImage& image);

  const std::vector<std::string>
    PicToNdsCode(const QImage& image) const;
  const std::vector<std::string>
    PicToQtCode(const QImage& image) const;
};
//---------------------------------------------------------------------------

#endif // QTPICTOCODEDIALOG_H

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
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtrichelbilderbeekgallerydialog.h"

#include <cassert>

#include <QDesktopWidget>
#include <QIcon>
#include <QKeyEvent>
#include <QMouseEvent>

#include <boost/shared_ptr.hpp>

#include "qtrichelbilderbeekgalleryresources.h"
#include "richelbilderbeekprogram.h"
#include "richelbilderbeekprogramstatus.h"
#include "trace.h"
#include "ui_qtrichelbilderbeekgallerydialog.h"

struct QtGalleryItem : public QTableWidgetItem
{

  QtGalleryItem(const QIcon &icon, const QString &text)
    : QTableWidgetItem(icon,text)
  {
    this->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  }
  QtGalleryItem(const QString &text)
    : QTableWidgetItem(text)
  {
    this->setFlags(Qt::ItemIsEnabled | Qt::ItemIsSelectable);
  }
  protected:


};


QtRichelBilderbeekGalleryDialog::QtRichelBilderbeekGalleryDialog(QWidget *parent) :
  QtHideAndShowDialog(parent),
  ui(new Ui::QtRichelBilderbeekGalleryDialog),
  m_programs(RichelBilderbeek::Program::GetAllPrograms())
{
  ui->setupUi(this);

  RichelBilderbeek::QtResources r;
  const int n = static_cast<int>(m_programs.size());
  ui->table->setColumnCount(5);
  ui->table->setRowCount(n + 1);
  {
    QtGalleryItem * const item = new QtGalleryItem(QIcon(r.GetCl().c_str()),QString());
    item->setToolTip("Command line");
    ui->table->setItem(0,1,item);
  }
  {
    QtGalleryItem * const item = new QtGalleryItem(QIcon(r.GetWindows().c_str()),QString());
    item->setToolTip("Windows-only desktop ");
    ui->table->setItem(0,2,item);
  }
  {
    QtGalleryItem * const item = new QtGalleryItem(QIcon(r.GetDesktop().c_str()),QString());
    item->setToolTip("Desktop");
    ui->table->setItem(0,3,item);
  }
  {
    QtGalleryItem * const item = new QtGalleryItem(QIcon(r.GetWeb().c_str()),QString());
    item->setToolTip("Web application");
    ui->table->setItem(0,4,item);
  }

  for (int row=0; row!=n; ++row)
  {
    {
      QtGalleryItem * const item = new QtGalleryItem(m_programs[row]->GetName().c_str());
      ui->table->setItem(row+1,0,item);
    }
    for (int col=0; col!=4; ++col)
    {
      RichelBilderbeek::ProgramStatus p =  RichelBilderbeek::ProgramStatus::unk;
      switch (col)
      {
        case 0: p = m_programs[row]->GetStatusConsole(); break;
        case 1: p = m_programs[row]->GetStatusDesktopWindowsOnly(); break;
        case 2: p = m_programs[row]->GetStatusDesktop(); break;
        case 3: p = m_programs[row]->GetStatusWebApplication(); break;
      }
      std::string s;
      switch (p)
      {
        case RichelBilderbeek::ProgramStatus::yes: s = r.GetGreen(); break;
        case RichelBilderbeek::ProgramStatus::no: s = r.GetRed(); break;
        case RichelBilderbeek::ProgramStatus::nvr: s = r.GetBlack(); break;
        case RichelBilderbeek::ProgramStatus::n_a: s = r.GetBlack(); break;
        case RichelBilderbeek::ProgramStatus::wip: s = r.GetYellow(); break;
        case RichelBilderbeek::ProgramStatus::tbd: s = r.GetOrange(); break;
        case RichelBilderbeek::ProgramStatus::unk: s = r.GetBlack(); break;
      }
      {
        QtGalleryItem * const item = new QtGalleryItem(QIcon(s.c_str()),QString());
        item->setToolTip(RichelBilderbeek::ProgramStatusToStr(p).c_str());
        ui->table->setItem(row+1,col+1,item);
      }
    }
  }

  //Set all row heights
  {
    const int n_rows = ui->table->rowCount();
    const int row_height = 18;
    for (int i=0; i!=n_rows; ++i)
    {
      ui->table->setRowHeight(i,row_height);
    }
  }
  //Set all column widths
  {
    const int n_cols = ui->table->columnCount();
    const int col_width = 18;
    const int first_col_width = 200;
    ui->table->setColumnWidth(0,first_col_width);
    for (int i=1; i!=n_cols; ++i)
    {
      ui->table->setColumnWidth(i,col_width);
    }
    ui->table->setMaximumWidth(first_col_width + (n_cols * col_width));
    ui->table->setMinimumWidth(first_col_width + (n_cols * col_width));
  }


  {
    //Put the maximized dialog in the screen center
    const QRect screen = QApplication::desktop()->screenGeometry();
    const int width = screen.width() - 64;
    const int height = screen.height() - 128;
    this->setGeometry(0,0,width,height);
    this->move( screen.center() - this->rect().center() );
    this->setMaximumHeight(height);
    this->setMaximumWidth(width);
  }
}

QtRichelBilderbeekGalleryDialog::~QtRichelBilderbeekGalleryDialog()
{
  delete ui;
}

const std::string QtRichelBilderbeekGalleryDialog::GetVersion()
{
  return "1.1";
}

const std::vector<std::string> QtRichelBilderbeekGalleryDialog::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2012-02-19: version 1.0: initial version of QtAboutDialog");
  v.push_back("2012-12-25: version 1.1: inherits from QtHideAndShowDialog, added keyPressEvent");
  return v;
}

void QtRichelBilderbeekGalleryDialog::keyPressEvent(QKeyEvent* e)
{
  if (e->key()  == Qt::Key_Escape) close();
}

void QtRichelBilderbeekGalleryDialog::on_table_clicked(const QModelIndex &index)
{
  const int row = index.row();
  if (row - 1 < 0 || row - 1 >= static_cast<int>(m_programs.size())) return;

  const int col = index.column();
  ShowScreenshot(col,row);
}

void QtRichelBilderbeekGalleryDialog::on_table_cellEntered(int row, int column)
{
  ShowScreenshot(column,row);
}

void QtRichelBilderbeekGalleryDialog::ShowScreenshot(const int col, const int row)
{
  const boost::shared_ptr<RichelBilderbeek::Program>& p = m_programs[row - 1];
  std::string filename;
  switch (col)
  {
    case 0: break;
    case 1: filename = p->GetFilenameConsole(); break;
    case 2: filename = p->GetFilenameDesktopWindowsOnly(); break;
    case 3: filename = p->GetFilenameDesktop(); break;
    case 4: filename = p->GetFilenameWeb(); break;
  }
  ui->image->setPixmap(QPixmap(filename.c_str()));

  //Put the dialog in the screen center
  const QRect screen = QApplication::desktop()->screenGeometry();
  this->move( screen.center() - this->rect().center() );
}

void QtRichelBilderbeekGalleryDialog::on_table_entered(const QModelIndex &index)
{
  const int row = index.row();
  if (row - 1 < 0 || row - 1 >= static_cast<int>(m_programs.size())) return;
  const int col = index.column();
  ShowScreenshot(col,row);
}

//---------------------------------------------------------------------------
/*
TestPylos, tool to test the Pylos classes
Copyright (C) 2010-2012 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTestPylos.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qttestpylosrandomplaydialog.h"

#include <boost/lexical_cast.hpp>
//---------------------------------------------------------------------------
#include "pylosboard.h"
#include "pylosgame.h"
#include "ui_qttestpylosrandomplaydialog.h"
//---------------------------------------------------------------------------
QtTestPylosRandomPlayDialog::QtTestPylosRandomPlayDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtTestPylosRandomPlayDialog)
{
  ui->setupUi(this);
}
//---------------------------------------------------------------------------
QtTestPylosRandomPlayDialog::~QtTestPylosRandomPlayDialog()
{
  delete ui;
}
//---------------------------------------------------------------------------
void QtTestPylosRandomPlayDialog::on_button_start_clicked()
{
  const boost::shared_ptr<Pylos::Board> board =  (ui->radio_advanced->isChecked()
    ? Pylos::Board::CreateAdvancedBoard()
    : Pylos::Board::CreateBasicBoard() );

  int won1 = 0;
  int won2 = 0;

  ui->bar_progress->setValue(0);
  ui->bar_won_player1->setValue(0);

  const int max = boost::lexical_cast<int>(ui->edit_n_games->text().toStdString());

  for (int i=0; i!=max; ++i)
  {
    const Pylos::Winner winner = Pylos::Game::PlayRandomGame(board);
    if (winner == Pylos::Winner::player1) ++won1; else ++won2;
    ui->bar_progress->setValue(i);
    ui->bar_won_player1->setValue(
      static_cast<int>(
      100.0 * static_cast<double>(won1) / static_cast<double>(i) ) );
  }

  ui->bar_progress->setValue(max);
}
//---------------------------------------------------------------------------
void QtTestPylosRandomPlayDialog::on_edit_n_games_textChanged(const QString &arg1)
{
  try
  {
    boost::lexical_cast<int>(arg1.toStdString());
  }
  catch (boost::bad_lexical_cast&)
  {
    ui->button_start->setEnabled(false);
    return;
  }
  ui->bar_progress->setMaximum(boost::lexical_cast<int>(arg1.toStdString()));
  ui->button_start->setEnabled(true);
}
//---------------------------------------------------------------------------

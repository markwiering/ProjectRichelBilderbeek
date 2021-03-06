//---------------------------------------------------------------------------
/*
TestChess, program to test my chess classes
Copyright (C) 2012 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTestChess.htm
//---------------------------------------------------------------------------
#include "chessboard.h"
#include "chessboardwidget.h"
#include "chessmove.h"
#include "qttestchessgamedialog.h"
//#include "testchessmaindialog.h"
#include "ui_qttestchessgamedialog.h"
//---------------------------------------------------------------------------
#define NO_QTGAMEWIDGET_YET
//---------------------------------------------------------------------------
QtTestChessGameDialog::QtTestChessGameDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtTestChessGameDialog)
{
  ui->setupUi(this);

  #ifndef NO_QTGAMEWIDGET_YET
  ui->chessgame_widget->m_signal_changed.connect(
    boost::bind(
      &QtTestChessGameDialog::OnChessboardChanged,
      this));
  #endif

  OnChessboardChanged();
}
//---------------------------------------------------------------------------
QtTestChessGameDialog::~QtTestChessGameDialog()
{
  delete ui;
}
//---------------------------------------------------------------------------
void QtTestChessGameDialog::OnChessboardChanged()
{
  #ifndef NO_QTGAMEWIDGET_YET
  const std::vector<Chess::Move> v = ui->chessgame_widget->GetWidget()->GetBoard()->GetMoves();
  ui->list_moves->clear();
  std::for_each(v.begin(),v.end(),
    [&ui](const Chess::Move& m)
    {
      ui->list_moves->addItem(m.GetStr().c_str());
    }
  );

  ui->edit_status->clear();
  const std::string s = std::string("Active player: ") +
    Chess::ColorToStr(ui->chessgame_widget->GetWidget()->GetBoard()->GetActivePlayer());
  ui->edit_status->appendPlainText(s.c_str());
  #endif
}
//---------------------------------------------------------------------------
void QtTestChessGameDialog::on_list_moves_doubleClicked(const QModelIndex &index)
{
  const std::string move_str = ui->list_moves->item(index.row())->text().toStdString();
  const std::string s
    = std::string("Doing move ") + move_str;
  ui->edit_status->appendPlainText(s.c_str());
  #ifndef NO_QTGAMEWIDGET_YET
  ui->chessgame_widget->GetWidget()->DoMove(move_str);
  OnChessboardChanged();
  #endif
}
//---------------------------------------------------------------------------

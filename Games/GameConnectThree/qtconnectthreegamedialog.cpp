//---------------------------------------------------------------------------
/*
GameConnectThree, connect-three game
Copyright (C) 2010-2013 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/GameConnectThree.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorPperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "qtconnectthreegamedialog.h"
#pragma GCC diagnostic pop

#include <QDesktopWidget>
#include <QTimer>

#include "connectthree.h"
#include "connectthreewidget.h"
#include "connectthreeresources.h"
#include "ui_qtconnectthreegamedialog.h"
#include "qtconnectthreegamedialog.h"
#include "qtconnectthreewidget.h"
#include "qtshowwinnerdialog.h"

QtConnectThreeGameDialog::QtConnectThreeGameDialog(
  const boost::shared_ptr<const ConnectThreeResources> resources,
  QWidget *parent,
  const std::bitset<3>& is_player_human)
  : QDialog(parent, Qt::Window),
    ui(new Ui::QtConnectThreeGameDialog),
    m_board(
      new QtConnectThreeWidget(
        resources,
        nullptr,is_player_human,16,8)),
    m_is_player_human(is_player_human),
    m_resources(resources)
{
  ui->setupUi(this);

  //Add board widget
  {
    assert(!ui->widget->layout());
    QLayout * const mylayout = new QVBoxLayout;
    mylayout->addWidget(m_board.get());
    ui->widget->setLayout(mylayout);
  }

  QObject::connect(ui->button_quit,SIGNAL(clicked()),
    this,SLOT(close()));

  m_board->m_signal_valid_move.connect(
    boost::bind(
      &QtConnectThreeGameDialog::OnValidMove,
      this));

  //Put the dialog in the screen center
  const QRect screen = QApplication::desktop()->screenGeometry();
  this->move( screen.center() - this->rect().center() );

  ui->button_quit->setText(resources->GetQuitText().c_str());

  OnValidMove(); //Draw screen
}

QtConnectThreeGameDialog::~QtConnectThreeGameDialog()
{
  delete ui;
}

void QtConnectThreeGameDialog::DoComputerTurn()
{
  this->m_board->DoComputerTurn();
  OnValidMove();
}

///OnValidMove is called after a valid move. The game
///is either terminated, or the next player can do
///his/her move.
void QtConnectThreeGameDialog::OnValidMove()
{
  if (m_board->GetWinner() == ConnectThree::no_player)
  {
    const int active_player = m_board->GetActivePlayer();
    switch(active_player)
    {
      case ConnectThree::player1:
        ui->label_player1->setPixmap(QPixmap(m_resources->GetPlayersFilenames()[0].c_str()));
        ui->label_player2->setPixmap(QPixmap(m_resources->GetPlayersGreyFilenames()[1].c_str()));
        ui->label_player3->setPixmap(QPixmap(m_resources->GetPlayersGreyFilenames()[2].c_str()));
        break;
      case ConnectThree::player2:
        ui->label_player1->setPixmap(QPixmap(m_resources->GetPlayersGreyFilenames()[0].c_str()));
        ui->label_player2->setPixmap(QPixmap(m_resources->GetPlayersFilenames()[1].c_str()));
        ui->label_player3->setPixmap(QPixmap(m_resources->GetPlayersGreyFilenames()[2].c_str()));
        break;
      case ConnectThree::player3:
        ui->label_player1->setPixmap(QPixmap(m_resources->GetPlayersGreyFilenames()[0].c_str()));
        ui->label_player2->setPixmap(QPixmap(m_resources->GetPlayersGreyFilenames()[1].c_str()));
        ui->label_player3->setPixmap(QPixmap(m_resources->GetPlayersFilenames()[2].c_str()));
        break;
      default:
        assert(!"Should not get here");
        throw std::logic_error("Known value of GetCurrentPlayer in WtConnectThreeGameDialog::OnValidMove");
    }
    if (this->m_board->IsComputerTurn())
    {
      //Do a computer turn after a second
      QTimer::singleShot(100,
        this, SLOT(DoComputerTurn()));
    }

    return;
  }
  //There is a winner, or the screen is full
  {
    std::string filename;
    switch(m_board->GetWinner())
    {
        case ConnectThree::player1  : filename = m_resources->GetPlayersFilenames()[0]; break;
        case ConnectThree::player2  : filename = m_resources->GetPlayersFilenames()[1]; break;
        case ConnectThree::player3  : filename = m_resources->GetPlayersFilenames()[2]; break;
        case ConnectThree::no_player: filename = m_resources->GetEmptyFilename(); break;
        default:
          assert(!"Should not get here");
          throw std::logic_error("Known value of GetCurrentPlayer in WtConnectThreeGameDialog::OnValidMove");
    }
    QtShowWinnerDialog d(filename,m_resources->GetWinnerText());
    d.setStyleSheet(this->styleSheet());
    d.setWindowIcon(this->windowIcon());

    //this->hide();
    d.exec();
  }
  this->close();
}


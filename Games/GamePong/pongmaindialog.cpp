#include <cmath>
#include <QBrush>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QKeyEvent>
#include <QTimer>
#include <QVBoxLayout>

#include "pongmaindialog.h"
#include "ui_pongmaindialog.h"

PongMainDialog::PongMainDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::PongMainDialog),
  m_background(new PongBackground),
  m_ball(new PongBall),
  m_players( { new PongPlayer, new PongPlayer } )
{
  ui->setupUi(this);
  const int w = this->width();
  const int h = this->height();

  //Start by creating a scene
  QGraphicsScene * const scene(new QGraphicsScene(this));

  //Connect a view to display the scene
  QGraphicsView * const view(new QGraphicsView(scene));
  view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  view->setGeometry(0,0,w,h);
  view->setFocusPolicy(Qt::NoFocus);

  //Add the view to the UI
  ui->layout->addWidget(view);

  //Add background
  scene->addItem(m_background);
  m_background->SetGeometry(w,h);

  //Add ball
  scene->addItem(m_ball);
  m_ball->SetArenaRect(w,h);

  //Add players
  m_players[0]->setRect(0,(h / 2)-64,32,128);
  m_players[1]->setRect(w-32,(h / 2)-64,32,128);
  std::for_each(m_players.begin(),m_players.end(),
    [scene](PongPlayer * const player)
    {
      scene->addItem(player);
    }
  );

  //Create a timer to call 'advance' on all sprites
  QTimer * const timer(new QTimer(this));
  timer->connect(timer, SIGNAL(timeout()), scene, SLOT(advance()));
  timer->start(20);
}

PongMainDialog::~PongMainDialog()
{
  delete ui;
}

void PongMainDialog::keyPressEvent(QKeyEvent * e)
{
  int player = -1;
  double dy = 0.0;
  switch (e->key())
  {
    case Qt::Key_Up  : player = 0; dy = -1.0; break;
    case Qt::Key_Down: player = 0; dy =  1.0; break;
    case Qt::Key_W   : player = 1; dy = -1.0; break;
    case Qt::Key_S   : player = 1; dy =  1.0; break;
    default: return;
  }
  assert(player >= 0 && player < static_cast<int>(m_players.size()));
  m_players[player]->SetDy(dy);
}

void PongMainDialog::resizeEvent(QResizeEvent *)
{
  m_background->SetGeometry(this->width(),this->height());
  m_ball->SetArenaRect(this->width(),this->height());
}

//---------------------------------------------------------------------------
/*
Boenken. A multiplayer soccer/billiards game.
Copyright (C) 2007-2012 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/GameBoenken.htm
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
#include "boenkengame.h"

#include <boost/foreach.hpp>

#include <QPainter>

#include "boenkenarenasettings.h"
#include "boenkensprite.h"
#include "boenkenspriteball.h"
#include "boenkenspritemoving.h"
#include "boenkenspritenonmoving.h"
#include "boenkenspriteplayer.h"


namespace Boenken {

Game::Game(
  const ArenaSettings& arena_settings,
  const Controls& controls,
  std::vector<boost::shared_ptr<SpritePlayer   > > players,
  std::vector<boost::shared_ptr<SpriteBall     > > balls,
  std::vector<boost::shared_ptr<SpriteNonMoving> > obstacles)
  : m_players(players),
    m_balls(balls),
    m_obstacles(obstacles),
    m_moving_sprites(CollectMovingSprites(players,balls)),
    m_sprites(CollectSprites(players,balls,obstacles)),
    m_arena_settings(arena_settings),
    m_controls(controls)
{
  #ifndef NDEBUG
  Test();
  #endif
  ///Reset the score to 0-0
  SpriteBall::ResetScore();

  ///Set the friction
  SpriteMoving::SetFriction(m_arena_settings.friction);

  ///Set the arena size for the Sprites
  Sprite::setArenaSize(this->getWidth(),this->getHeight());

  ///Keep the right goal posts at the right side
  ///Assume this is done!
  assert(m_obstacles.size() >= 4
    && "There must be at least four goal posts");
  //m_obstacles[2]->setX(width - m_obstacles[2]->m_size);
  //m_obstacles[3]->setX(width - m_obstacles[3]->m_size);

  ///Set the goal area
  assert(m_obstacles.size() >= 4
    && "There must be at least four goal posts");
  const double goal_y_top    = m_obstacles[0]->getY();
  const double goal_y_bottom = m_obstacles[1]->getY();
  assert(goal_y_top <= goal_y_bottom);
  SpriteBall::SetGoalPoles(goal_y_top,goal_y_bottom);
}

const std::vector<SpriteMoving*> Game::CollectMovingSprites(
  std::vector<boost::shared_ptr<SpritePlayer> > players,
  std::vector<boost::shared_ptr<SpriteBall  > > balls)
{
  std::vector<SpriteMoving*> v;
  BOOST_FOREACH(boost::shared_ptr<SpritePlayer> i,players)
  {
    assert(i);
    SpriteMoving * const s = i.get();
    assert(s);
    v.push_back(s);
  }
  BOOST_FOREACH(boost::shared_ptr<SpriteBall> i,balls)
  {
    assert(i);
    SpriteMoving * const s = i.get();
    assert(s);
    v.push_back(s);
  }
  return v;
}

const std::vector<Sprite*> Game::CollectSprites(
  std::vector<boost::shared_ptr<SpritePlayer   > > players,
  std::vector<boost::shared_ptr<SpriteBall     > > balls,
  std::vector<boost::shared_ptr<SpriteNonMoving> > obstacles)
{
  std::vector<Sprite*> v;
  BOOST_FOREACH(boost::shared_ptr<SpritePlayer> i,players)
  {
    assert(i);
    Sprite * const s = i.get();
    assert(s);
    v.push_back(s);
  }
  BOOST_FOREACH(boost::shared_ptr<SpriteBall> i,balls)
  {
    assert(i);
    Sprite * const s = i.get();
    assert(s);
    v.push_back(s);
  }
  BOOST_FOREACH(boost::shared_ptr<SpriteNonMoving> i,obstacles)
  {
    assert(i);
    Sprite * const s = i.get();
    assert(s);
    v.push_back(s);
  }
  return v;
}

void Game::drawPlayers(QPainter& painter) const
{
  BOOST_FOREACH(const Sprite * const s,m_sprites)
  {
    s->Draw(painter);
  }
}

int Game::getHeight() const
{
  return m_arena_settings.height();
}

const std::pair<int,int> Game::GetScore() const
{
  return SpriteBall::GetScore();
}

int Game::getWidth() const
{
  return m_arena_settings.width();
}


void Game::pressKey(const int key)
{
  const std::size_t n_players = m_controls.m_names.size();
  for (std::size_t i=0; i!=n_players; ++i)
  {
    if (key == m_controls.m_keys_accel[i]) m_players[i]->Accelerate();
    if (key == m_controls.m_keys_turn[i] ) m_players[i]->TurnRight();
  }
  switch (key)
  {
    ///F1 is the debugging key
    ///F2 is the debugging key, after which there is a quit
    case Qt::Key_F1:
    case Qt::Key_F2:
    {
      //std::clog << "Player coordinats:\n";
      //BOOST_FOREACH(boost::shared_ptr<SpritePlayer>& s,m_players)
      {
        //std::clog << s.get() << ": (" << s->getX() << "," << s->getY() << ")\n";
      }
      //std::clog << "Ball coordinats:\n";
      //BOOST_FOREACH(boost::shared_ptr<SpriteBall>& s,m_balls)
      {
        //std::clog << s.get() << ": (" << s->getX() << "," << s->getY() << ")\n";
      }
      //std::clog << "Moving sprite coordinats (must match above):\n";
      //BOOST_FOREACH(SpriteMoving * s,m_moving_sprites)
      {
        //std::clog << s << ": (" << s->getX() << "," << s->getY() << ")\n";
      }
    }
  }
  if (key == Qt::Key_F2) std::exit(1);
}

void Game::Test()
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  {
    const boost::shared_ptr<SpritePlayer> p(new SpritePlayer(
      0.0,0.0,0.0,8,0,0,0));
    assert(p);
  }
  {
    const boost::shared_ptr<SpriteBall> p(new SpriteBall(0.0,0.0));
    assert(p);
  }
  {
    const boost::shared_ptr<SpriteNonMoving> p(new SpriteNonMoving(0.0,0.0));
    assert(p);
  }
  {
    ArenaSettings arena_settings;
    const Controls controls;
  }
}

///Moves all sprites
void Game::tick()
{
  ///Move all moving sprites
  BOOST_FOREACH(SpriteMoving* const s,m_moving_sprites)
  {
    assert(s);
    s->Move();
  }

  ///Check all moving sprite collisions with moving sprites
  {
    BOOST_FOREACH(SpriteMoving* const s1,m_moving_sprites)
    {
      BOOST_FOREACH(SpriteMoving* const s2,m_moving_sprites)
      {
        assert(s1);
        assert(s2);
        if (s1 <= s2) continue;
        SpritePlayer::Collision(s1,s2);
      }
    }
  }

  ///Check all moving sprite collisions with non-moving sprites
  {
    BOOST_FOREACH(boost::shared_ptr<SpriteNonMoving>& s1,m_obstacles)
    {
      BOOST_FOREACH(SpriteMoving* const s2,m_moving_sprites)
      {
        SpriteNonMoving::Collision(s1.get(),s2);
      }
    }
  }
}

} //~namespace Boenken {


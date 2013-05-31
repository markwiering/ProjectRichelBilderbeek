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
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "boenkensprite.h"

#include <cassert>
#include <cmath>

//Terrible #define, but my crosscompiler cannot find the definition of M_PI in cmath.h :-(
#ifndef M_PI
# define M_PI		3.14159265358979323846	/* pi */
#endif

#include <boost/numeric/conversion/cast.hpp>

#include <QBitmap>
#include <QImage>
#include <QPainter>
#include <QPixmap>

namespace Boenken {

///The maximum x coordinat a Sprite can have
int Sprite::m_maxx = 320;

///The maximum y coordinat a Sprite can have
int Sprite::m_maxy = 200;

Sprite::Sprite(
  const double x,
  const double y,
  const int size,
  const unsigned char r,
  const unsigned char g,
  const unsigned char b)
  : m_size(size),
    m_pixmap(DrawGlobe(size,size,r,g,b)),
    m_x(x),
    m_y(y)
{
  #ifndef NDEBUG
  Test();
  #endif
}

QRect Sprite::rect() const
{
  return QRect(m_x,m_y,m_size,m_size);
}

const QPixmap& Sprite::pixmap() const
{
  return m_pixmap;
}

void Sprite::Draw(QPainter& painter) const
{
  //Draw the globe
  painter.drawPixmap(this->rect(),this->pixmap());
}

const std::string Sprite::GetVersion()
{
  return "1.1";
}

const std::vector<std::string> Sprite::GetVersionHistory()
{
  return
  {
    "2010-xx-xx: version 1.0: initial version",
    "2013-04-30: added testing, fixed bug in GetAngle"
  };
}


void Sprite::setArenaSize(const int width, const int height)
{
  m_maxx = width;
  m_maxy = height;
}

#ifndef NDEBUG
void Sprite::Test()
{
  {
    static bool is_tested = false;
    if (is_tested) return;
    is_tested = true;
  }
  //Test GetAngle
  {
    const double angle =  GetAngle(0.0,-1.0); //North
    const double expected = 0.0 * M_PI;
    assert(std::abs(angle-expected) < 0.01);
  }
  {
    const double angle =  GetAngle(1.0,-1.0); //North-East
    const double expected = 0.25 * M_PI;
    assert(std::abs(angle-expected) < 0.01);
  }
  {
    const double angle =  GetAngle(1.0,0.0); //East
    const double expected = 0.5 * M_PI;
    assert(std::abs(angle-expected) < 0.01);
  }
  {
    const double angle =  GetAngle(1.0,1.0); //South-East
    const double expected = 0.75 * M_PI;
    assert(std::abs(angle-expected) < 0.01);
  }
  {
    const double angle =  GetAngle(0.0,1.0); //South
    const double expected = 1.0 * M_PI;
    assert(std::abs(angle-expected) < 0.01);
  }
  {
    const double angle =  GetAngle(-1.0,1.0); //South-West
    const double expected = 1.25 * M_PI;
    assert(std::abs(angle-expected) < 0.01);
  }
  {
    const double angle =  GetAngle(-1.0,0.0); //West
    const double expected = 1.5 * M_PI;
    assert(std::abs(angle-expected) < 0.01);
  }
  {
    const double angle =  GetAngle(-1.0,-1.0); //North-West
    const double expected = 1.75 * M_PI;
    assert(std::abs(angle-expected) < 0.01);
  }
}
#endif

//From http://www.richelbilderbeek.nl/CppDrawGlobe.htm
QPixmap Sprite::DrawGlobe(
  const int width,
  const int height,
  const unsigned char r,
  const unsigned char g,
  const unsigned char b)
{
  QPixmap pixmap(width,height);
  QImage image = pixmap.toImage();
  assert(width != 0);
  assert(image.bytesPerLine() / width == 4
    && "Assume there are 4 bytes per pixel");

  const double r_max = boost::numeric_cast<double>(r);
  const double g_max = boost::numeric_cast<double>(g);
  const double b_max = boost::numeric_cast<double>(b);
  const double midX = boost::numeric_cast<double>(width ) / 2.0;
  const double midY = boost::numeric_cast<double>(height) / 2.0;
  const double max_dist = std::min(midX,midY);

  for (int y=0; y!=height; ++y)
  {

    unsigned char * const line
      = static_cast<unsigned char *>(image.scanLine(y));
    const double y_d = boost::numeric_cast<double>(y);
    for (int x=0; x!=width; ++x)
    {
      const double x_d = boost::numeric_cast<double>(x);
      const double dist
        = std::sqrt(
            ((x_d - midX) * (x_d - midX))
          + ((y_d - midY) * (y_d - midY)) );
      if (dist <= max_dist)
      {
        const double rel_dist = dist / max_dist;
        const int r_here = rel_dist * r_max;
        const int g_here = rel_dist * g_max;
        const int b_here = rel_dist * b_max;
        assert( r_here >= 0);
        assert( r_here < 256);
        assert( g_here >= 0);
        assert( g_here < 256);
        assert( b_here >= 0);
        assert( b_here < 256);
        line[x*4+3] = 255; //Alpha value
        line[x*4+2] = r_here; //Red
        line[x*4+1] = g_here; //Green
        line[x*4+0] = b_here; //Blue
      }
      else
      {
        line[x*4+3] = 0; //Alpha value
        line[x*4+2] = 0; //Red
        line[x*4+1] = 0; //Green
        line[x*4+0] = 0; //Blue
      }
    }
  }
  pixmap = pixmap.fromImage(image);

  //Add transparency
  const QBitmap mask = pixmap.createMaskFromColor(QColor(0,0,0,0).rgb());
  pixmap.setMask(mask);

  return pixmap;
}

double Sprite::GetAngle(const double dx, const double dy)
{
  return M_PI - std::atan2(dx,dy);
}

//From http://www.richelbilderbeek.nl/CppDoPerfectElasticCollision.htm
void Sprite::DoPerfectElasticCollision(
  const double angleCollision,
  double& angle1,
  double& speed1,
  double& angle2,
  double& speed2)
{
  //The length of the impulse of player 1 (assumes both players have equal mass!)
  const double A = speed1;
  //The length of the impulse of player 2 (assumes both players have equal mass!)
  const double E = speed2;
  //The angles between the two globes
  const double c = angleCollision;
  //The angle between c and the impulse direction of player 1
  const double a = c - angle1;
  //The angle between c and the impulse direction of player 2
  const double b = c + M_PI - angle2;

  //Seperate the impulses to their impulses paralel and othoganal the angle of collision
  //The length of the impulse of player 1 parallel to the collision
  const double B = A * std::cos(a);
  //The length of the impulse of player 1 orthogonal to the collision
  const double C = A * std::sin(a);
  //The length of the impulse of player 2 parallel to the collision
  const double F = E * std::cos(b);
  //The length of the impulse of player 2 orthogonal to the collision
  const double G = E * std::sin(b);

  //Seperate the impulses in X and Y directions
  const double BdX = B *  std::sin(c + (0.0 * M_PI));
  const double BdY = B * -std::cos(c + (0.0 * M_PI));
  const double CdX = C *  std::sin(c + (1.5 * M_PI));
  const double CdY = C * -std::cos(c + (1.5 * M_PI));
  const double FdX = F *  std::sin(c + (1.0 * M_PI));
  const double FdY = F * -std::cos(c + (1.0 * M_PI));
  const double GdX = G *  std::sin(c + (0.5 * M_PI));
  const double GdY = G * -std::cos(c + (0.5 * M_PI));

  //The resulting impulses
  //The resulting impulse of player 1 in the X direction
  const double DdX = CdX + FdX;
  //The resulting impulse of player 1 in the Y direction
  const double DdY = CdY + FdY;
  //The resulting impulse of player 2 in the X direction
  const double HdX = BdX + GdX;
  //The resulting impulse of player 2 in the Y direction
  const double HdY = BdY + GdY;

  //Write the final results
  angle1 = GetAngle(DdX, DdY);
  angle2 = GetAngle(HdX, HdY);
  speed1 = std::sqrt( (DdX * DdX) + (DdY * DdY) ); //Pythagoras
  speed2 = std::sqrt( (HdX * HdX) + (HdY * HdY) ); //Pythagoras
}


} //~namespace Boenken


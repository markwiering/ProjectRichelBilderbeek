//---------------------------------------------------------------------------
/*
TestPylos, tool to test Pylos class
Copyright (C) 2010 Richel Bilderbeek

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
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtpylossprites.h"

#include <cassert>

#include <boost/numeric/conversion/cast.hpp>

#include <QBitmap>

#include "pylosmove.h"

namespace Pylos {

QtSprites::QtSprites(
  const int board_width,
  const int board_height,
  const boost::array<int,6> &colors)
  : m_board_width(board_width),
    m_board_height(board_height),
    m_colors(colors)
{
  GenerateSprites();
}

void QtSprites::GenerateSprites()
{
  m_sprite_board_bottom
    = DrawBoardBottom(m_board_width,m_board_height,64,64,64);
  const int width  = m_board_width  / 4;
  const int height = m_board_height / 4;

  m_sprite_board_hole
    = DrawInvertedGlobe(width,height,64,64,64);
  m_sprite_player1
    = DrawGlobe(width,height,m_colors[0],m_colors[1],m_colors[2]);
  m_sprite_player2
    = DrawGlobe(width,height,m_colors[3],m_colors[4],m_colors[5]);
  m_sprite_player1_select
    = DrawSelector(width,height,m_colors[0],m_colors[1],m_colors[2]);
  m_sprite_player2_select
    = DrawSelector(width,height,m_colors[3],m_colors[4],m_colors[5]);
  m_sprite_player1_remove
    = DrawRemover(width,height,m_colors[0],m_colors[1],m_colors[2]);
  m_sprite_player2_remove
    = DrawRemover(width,height,m_colors[3],m_colors[4],m_colors[5]);
}

const QPixmap& QtSprites::Get(
  const Type sprite) const
{
  switch (sprite)
  {
    case Type::player1: return m_sprite_player1;
    case Type::player2: return m_sprite_player2;
    case Type::player1_select : return m_sprite_player1_select;
    case Type::player2_select : return m_sprite_player2_select;
    case Type::player1_remove : return m_sprite_player1_remove;
    case Type::player2_remove : return m_sprite_player2_remove;
    case Type::board_bottom   : return m_sprite_board_bottom;
    case Type::board_hole     : return m_sprite_board_hole;
  }
  assert(!"Should not get here");
  throw std::logic_error("QtSprites::Get");
}

const std::string QtSprites::GetVersion()
{
  return "2.0";
}

const std::vector<std::string> QtSprites::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2012-05-28: version 2.0: initial release version");
  return v;
}

void QtSprites::SetBoardSize(const int board_width, const int board_height)
{
  m_board_width  = board_width;
  m_board_height = board_height;
  GenerateSprites();
}

///SetColorScheme sets the color scheme of the Sprites.
///This redraws all the sprites.
void QtSprites::SetColorScheme(const boost::array<int,6> colors)
{
  m_colors = colors;
  GenerateSprites();
}

QPixmap DrawBoardBottom(
  const int width,
  const int height,
  const unsigned char r,
  const unsigned char g,
  const unsigned char b)
{
  QPixmap pixmap(width,height);
  Paint(pixmap,r,g,b);
  return pixmap;
}

///From http://www.richelbilderbeek.nl/CppDrawGlobe.htm
QPixmap DrawGlobe(
  const int width,
  const int height,
  const unsigned char r,
  const unsigned char g,
  const unsigned char b)
{
  QPixmap pixmap(width,height);
  QImage image = pixmap.toImage();

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
        line[x*4+2] = (r_here == 0 ? 1: r_here); //Red
        line[x*4+1] = (g_here == 0 ? 1: g_here); //Green
        line[x*4+0] = (b_here == 0 ? 1: b_here); //Blue
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

///From http://www.richelbilderbeek.nl/CppDrawInvertedGlobe.htm
QPixmap DrawInvertedGlobe(
  const int width,
  const int height,
  const unsigned char r,
  const unsigned char g,
  const unsigned char b)
{
  QPixmap pixmap(width,height);
  QImage image = pixmap.toImage();

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
        const int r_here = r_max - (rel_dist * r_max);
        const int g_here = g_max - (rel_dist * g_max);
        const int b_here = b_max - (rel_dist * b_max);
        assert( r_here >= 0);
        assert( r_here < 256);
        assert( g_here >= 0);
        assert( g_here < 256);
        assert( b_here >= 0);
        assert( b_here < 256);
        line[x*4+3] = 255; //Alpha value
        line[x*4+2] = (r_here == 0 ? 1: r_here); //Red
        line[x*4+1] = (g_here == 0 ? 1: g_here); //Green
        line[x*4+0] = (b_here == 0 ? 1: b_here); //Blue
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

QPixmap DrawRemover(
  const int width,
  const int height,
  const unsigned char r,
  const unsigned char g,
  const unsigned char b)
{
  //Faded out globe
  QPixmap pixmap(width,height);
  QImage image = pixmap.toImage();

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
        const int r_here = 127 + ((rel_dist * r_max) / 2);
        const int g_here = 127 + ((rel_dist * g_max) / 2);
        const int b_here = 127 + ((rel_dist * b_max) / 2);
        assert( r_here >= 0);
        assert( r_here < 256);
        assert( g_here >= 0);
        assert( g_here < 256);
        assert( b_here >= 0);
        assert( b_here < 256);
        line[x*4+3] = 255; //Alpha value
        line[x*4+2] = (r_here == 0 ? 1: r_here); //Red
        line[x*4+1] = (g_here == 0 ? 1: g_here); //Green
        line[x*4+0] = (b_here == 0 ? 1: b_here); //Blue
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

QPixmap DrawSelector(
  const int width,
  const int height,
  const unsigned char r,
  const unsigned char g,
  const unsigned char b)
{
  QPixmap pixmap(width,height);
  QImage image = pixmap.toImage();

  assert(image.bytesPerLine() / width == 4
    && "Assume there are 4 bytes per pixel");

  const double r_max = boost::numeric_cast<double>(r);
  const double g_max = boost::numeric_cast<double>(g);
  const double b_max = boost::numeric_cast<double>(b);
  const double midX = boost::numeric_cast<double>(width ) / 2.0;
  const double midY = boost::numeric_cast<double>(height) / 2.0;
  const double max_dist = std::min(midX,midY);
  const double min_dist = 0.8 * max_dist;

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
      if (dist >= min_dist && dist <= max_dist)
      {
        const double rel_dist = (dist - min_dist) / (max_dist - min_dist);
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
        line[x*4+2] = (r_here == 0 ? 1: r_here); //Red
        line[x*4+1] = (g_here == 0 ? 1: g_here); //Green
        line[x*4+0] = (b_here == 0 ? 1: b_here); //Blue
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

const boost::array<int,6> GetBlackWhiteColors()
{
  boost::array<int,6> v;
  v[0] = 255; v[1] = 255; v[2] = 255;
  v[3] =  96; v[4] =  96; v[5] =  96;
  return v;
}

const boost::array<int,6> GetDefaultColors()
{
  return GetRedBlueColors();
}

const boost::array<int,6> GetRedBlueColors()
{
  boost::array<int,6> v;
  v[0] = 255; v[1] =   0; v[2] =   0;
  v[3] =   0; v[4] =   0; v[5] = 255;
  return v;
}

//From http://www.richelbilderbeek.nl/CppPaint.htm
void Paint(
  QPixmap& pixmap,
  const unsigned char r,
  const unsigned char g,
  const unsigned char b,
  const unsigned char a) //Opaque
{
  const int width = pixmap.width();
  const int height = pixmap.height();

  QImage image = pixmap.toImage();

  assert(image.bytesPerLine() / width == 4
    && "Assume there are 4 bytes per pixel");

  for (int y=0; y!=height; ++y)
  {
    unsigned char * const line
      = static_cast<unsigned char *>(image.scanLine(y));
    for (int x=0; x!=width; ++x)
    {
      line[x*4+3] = a; //Alpha value
      line[x*4+2] = r; //Red
      line[x*4+1] = g; //Green
      line[x*4+0] = b; //Blue
    }
  }
  pixmap = pixmap.fromImage(image);
}

} //~namespace Pylos


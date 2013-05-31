//---------------------------------------------------------------------------
/*
BeerWanter. A simple game.
Copyright (C) 2005-2012 Richel Bilderbeek

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
//From hhtp://www.richelbilderbeek.nl/GameBeerWanter.htm
//---------------------------------------------------------------------------
#ifndef BEERWANTERMAINDIALOG_H
#define BEERWANTERMAINDIALOG_H
//---------------------------------------------------------------------------
#include <string>
#include <vector>
//---------------------------------------------------------------------------
///BeerWanterMainDialog contains the logic behind the game BeerWanter
struct BeerWanterMainDialog
{
  BeerWanterMainDialog(
    int screen_width,
    int screen_height,
    int sprite_width,
    int sprite_height,
    int window_width,
    int window_height);
  bool Click();
  bool ClickWilBeSuccess() const;
  int GetCursorX() const { return m_cursor_x; }
  int GetCursorY() const { return m_cursor_y; }
  int GetLevel() const { return m_level; }
  int GetSpriteX() const { return m_sprite_x; }
  int GetSpriteY() const { return m_sprite_y; }
  int GetSpriteHeight() const { return m_sprite_height; }
  int GetSpriteWidth()  const { return m_sprite_width ; }
  int GetWindowHeight() const { return m_window_height; }
  const std::string GetWindowTitle() const;
  int GetWindowWidth()  const { return m_window_width ; }
  int GetWindowX() const { return m_window_x; }
  int GetWindowY() const { return m_window_y; }
  void SetArenaSize(const int width, const int height);
  void SetCursorPos(const int x, const int y);
  void SetSpriteSize(const int width, const int height);
  void ShakeCursor();
  void ShakeWindow();
  void Tick();

  private:
  int m_cursor_x;
  int m_cursor_y;
  int m_level;
  const int m_screen_height;
  const int m_screen_width;
  int m_sprite_x;
  int m_sprite_y;
  const int m_sprite_height;
  const int m_sprite_width;
  const int m_window_height;
  const int m_window_width;
  int m_window_x;
  int m_window_y;

  int GetRandomCursorShake() const;
  int GetRandomWindowShake() const;
};
//---------------------------------------------------------------------------
///From http://www.richelbilderbeek.nl/CppIntToStr.htm
const std::string IntToStr(const int x);
//---------------------------------------------------------------------------
#endif // BEERWANTERMAINDIALOG_H
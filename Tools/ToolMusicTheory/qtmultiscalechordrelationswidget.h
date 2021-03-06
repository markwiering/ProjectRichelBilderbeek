//---------------------------------------------------------------------------
/*
MusicTheory, tool for visualizing my music theory
Copyright (C)  2012  Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolMusicTheory.htm
//---------------------------------------------------------------------------
#ifndef QTMULTISCALECHORDRELATIONSWIDGET_H
#define QTMULTISCALECHORDRELATIONSWIDGET_H

#include <boost/shared_ptr.hpp>
#include <QGraphicsView>
struct QGraphicsScene;
namespace Music { struct ChordVertex; struct Chord; }

struct QtMultiScaleChordRelationsWidget : public QGraphicsView
{
  QtMultiScaleChordRelationsWidget(QWidget *parent = 0);

  ///Obtain this class its version number
  static const std::string GetVersion();

  ///Obtain this class its version history
  static const std::vector<std::string> GetVersionHistory();

  ///Set the two collections of chords
  void SetChords(
    std::vector<boost::shared_ptr<Music::Chord> >& chords1,
    std::vector<boost::shared_ptr<Music::Chord> >& chords2);

  void resizeEvent(QResizeEvent *event);

  private:
  QGraphicsScene * const m_scene;
};

#endif // QTMULTISCALECHORDRELATIONSWIDGET_H

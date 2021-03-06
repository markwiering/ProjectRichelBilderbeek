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
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtmultiscalechordrelationswidget.h"


#include <cmath>

#include <QGraphicsScene>
#include <QPainterPath>
#include <QPen>
#include "qtchordvertex.h"
#include "qtchordedge.h"
#include "musicchord.h"

QtMultiScaleChordRelationsWidget::QtMultiScaleChordRelationsWidget(QWidget *parent)
 : QGraphicsView(parent),
   m_scene(new QGraphicsScene(this))
{
  this->setScene(m_scene); //Obligatory

  //Turn off the scrollbars, as they look ugly
  this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
  this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

const std::string QtMultiScaleChordRelationsWidget::GetVersion()
{
  return "1.1";
}

const std::vector<std::string> QtMultiScaleChordRelationsWidget::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2012-08-17: version 1.0: initial version");
  v.push_back("2013-07-25: version 1.1: transition to Qt5");
  return v;
}


void QtMultiScaleChordRelationsWidget::resizeEvent(QResizeEvent *)
{
  m_scene->setSceneRect(this->rect());
}

void QtMultiScaleChordRelationsWidget::SetChords(
  std::vector<boost::shared_ptr<Music::Chord> >& chords1,
  std::vector<boost::shared_ptr<Music::Chord> >& chords2)
{
  m_scene->clear();

  //Collect all chords
  std::vector<boost::shared_ptr<Music::Chord> > chords(chords1.begin(),chords1.end());
  std::copy_if(chords2.begin(),chords2.end(),std::back_inserter(chords),
    [chords](boost::shared_ptr<Music::Chord>& chord)
    {
      return 0 == std::count_if(chords.begin(),chords.end(),
        [chord](const boost::shared_ptr<Music::Chord>& another_chord)
        {
          return chord->ToStr() == another_chord->ToStr();
        }
      );
    }
  );
  //assert(chords.size() == chords1.size() + chords2.size());

  std::vector<QtChordVertex * > qt_chords;

  //Create QtChords and add them to the scene
  std::transform(chords.begin(),chords.end(),
    std::back_inserter(qt_chords),
    [this,chords1,chords2](boost::shared_ptr<Music::Chord>& chord)
    {
      //m_scene will delete these QtChords
      QtChordVertex * const qt_chord = new QtChordVertex(chord,0);
      m_scene->addItem(qt_chord);
      const int cnt1 = std::count_if(chords1.begin(),chords1.end(),
        [chord](const boost::shared_ptr<Music::Chord>& another_chord)
        {
          return chord->ToStr() == another_chord->ToStr();
        }
      );
      const int cnt2 = std::count_if(chords2.begin(),chords2.end(),
        [chord](const boost::shared_ptr<Music::Chord>& another_chord)
        {
          return chord->ToStr() == another_chord->ToStr();
        }
      );
      assert(cnt1 + cnt2 > 0);
      qt_chord->SetColor(cnt1 + cnt2 == 2
        ? Qt::yellow
        : (cnt1 ? Qt::red : Qt::green));
      //qt_chord->SetColor
      return qt_chord;
      //m_scene->addItem(qt_chord);
    }
  );
  //Position the qt_chords
  {
    //Circumference must be 64 * SQRT(2) * sz,
    //So ray must be circumference / 2 * M_PI
    const std::size_t sz = qt_chords.size();
    //const double ray = 2.0 * 64.0 * std::sqrt(2.0) * static_cast<double>(sz) / (2.0 * M_PI);
    const double ray = 0.4 * static_cast<double>(std::min(this->width(),this->height()));
    const double d_angle = 2.0 * M_PI / static_cast<double>(sz);
    for (std::size_t i = 0; i!=sz; ++i)
    {
      const double angle = static_cast<double>(i) * d_angle;
      const double x = (0.5*static_cast<double>(this->width())) + (std::sin(angle)*ray);
      const double y = (0.5*static_cast<double>(this->height())) - (std::cos(angle)*ray);
      qt_chords[i]->setPos(x,y);
    }
  }

  //Create the edges based on the number of identical notes
  const std::size_t sz = chords.size();
  for (std::size_t i = 0; i!=sz; ++i)
  {
    //The indices of the notes
    const boost::shared_ptr<Music::Chord> x = chords[i];
    for (std::size_t j = i+1; j!=sz; ++j)
    {
      assert(j < sz);
      const boost::shared_ptr<Music::Chord> y = chords[j];
      const int same = Music::Chord::CountSameNotes(x,y);
      if (same)
      {
        QtChordEdge * const edge = new QtChordEdge(0);
        m_scene->addItem(edge);
        QPen pen;
        pen.setWidth(same * same);
        edge->setPen(pen);
        edge->setZValue(-1.0);
        edge->setLine(
          qt_chords[i]->pos().x(),
          qt_chords[i]->pos().y(),
          qt_chords[j]->pos().x(),
          qt_chords[j]->pos().y()
        );
      }
    }
  }
}

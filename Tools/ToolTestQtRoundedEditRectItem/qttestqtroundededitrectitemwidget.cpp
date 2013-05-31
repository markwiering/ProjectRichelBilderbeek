#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qttestqtroundededitrectitemwidget.h"

#include <cassert>
#include <cmath>
#include <iostream>
#include <boost/lexical_cast.hpp>
#include <QFontDialog>
#include <QGraphicsScene>
#include <QGraphicsSimpleTextItem>
#include <QIcon>
#include <QKeyEvent>
#include <QGraphicsSimpleTextItem>
#include <QPen>
#include "about.h"
#include "qtaboutdialog.h"
#include "qtroundededitrectitem.h"
#include "testqtroundededitrectitemmenudialog.h"

#ifndef NDEBUG
#include "qtroundedtextrectitem.h"
#endif

QtTestQtRoundedEditRectItemWidget::QtTestQtRoundedEditRectItemWidget(QWidget *parent)
  : QtKeyboardFriendlyGraphicsView(parent)
{
  //Display with default font
  this->Display(QtRoundedEditRectItem().GetFont());
}

void QtTestQtRoundedEditRectItemWidget::Display(const QFont& font)
{
  scene()->clear();

  //Add texts
  {
    const std::vector<std::string> v
      =
      {
        "F1: change font",
        "Space: set focus to random item",
        "Arrow keys: move focus",
        "Shift + arrow keys: move item"
        //"F2: edit item"
      };
    const int sz = boost::numeric_cast<int>(v.size());
    for (int i=0; i!=sz; ++i)
    {
      QGraphicsSimpleTextItem * const item = new QGraphicsSimpleTextItem(v[i].c_str());
      const double w = item->boundingRect().width();
      const double h = item->boundingRect().height();
      const double y = -100.0 + (static_cast<double>(i - (sz/2)) * 20.0);
      item->setPos(-0.5 * w,(-0.5 * h) + y);
      scene()->addItem(item);
    }
  }
  const int n_cols = 10;
  const int n_rows = 26 * 2; //Twice the number of chars in the alphabet
  double x = 0.0;
  for (int col=0; col!=n_cols; ++col)
  {
    double y = 0.0;
    double max_width = 0.0;
    for (int row=0; row!=n_rows; ++row)
    {
      QtRoundedEditRectItem * const item = new QtRoundedEditRectItem;
      item->SetFont(font);
      const char c = (row / 26 ? 'A' : 'a') + (row % 26);
      const std::string s
        = std::string(1 + col,c)
        + std::string(" ")
        + boost::lexical_cast<std::string>(c);
      item->SetText( std::vector<std::string>(1 + col,s) );
      item->setPos(x,y);
      item->SetFocusPen(QPen(QColor(255,0,0),3.0));
      scene()->addItem(item);

      y += item->boundingRect().height() + 2.0;
      max_width = std::max(max_width,item->boundingRect().width());
    }
    x += max_width + 6.0;
  }

}

void QtTestQtRoundedEditRectItemWidget::keyPressEvent(QKeyEvent *event)
{

  switch (event->key())
  {
    case Qt::Key_F1:
    {
      bool ok;
      static QFont font = QtRoundedEditRectItem().GetFont();
      const QFont new_font = QFontDialog::getFont(&ok, font, this);
      if (ok) { font = new_font; Display(font); }
    }
    return;
  }
  QtKeyboardFriendlyGraphicsView::keyPressEvent(event);
}
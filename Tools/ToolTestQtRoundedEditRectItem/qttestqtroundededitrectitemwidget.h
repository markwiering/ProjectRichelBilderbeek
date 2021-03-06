#ifndef QTTESTQTROUNDEDEDITRECTITEMWIDGETWIDGET_H
#define QTTESTQTROUNDEDEDITRECTITEMWIDGETWIDGET_H

#include "qtkeyboardfriendlygraphicsview.h"

struct QFont;

///The widget holding the items
struct QtTestQtRoundedEditRectItemWidget : public QtKeyboardFriendlyGraphicsView
{
  QtTestQtRoundedEditRectItemWidget(QWidget *parent = 0);

  void keyPressEvent(QKeyEvent *event);

private:
  ///Display a font
  void Display(const QFont& font);
};

#endif // QTTESTQTROUNDEDEDITRECTITEMWIDGETWIDGET_H

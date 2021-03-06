//---------------------------------------------------------------------------
/*
QtDialWidget, Qt class for displaying a DialWidget
Copyright (C) 2011 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/CppQtDialWidget.htm
//---------------------------------------------------------------------------
#ifndef QTDIALWIDGET_H
#define QTDIALWIDGET_H

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

#include <string>
#include <vector>

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include <boost/scoped_ptr.hpp>
#include <boost/signals2.hpp>
#pragma GCC diagnostic pop

#include <QWidget>

#include "dial.h" //For MOC
#include "dialwidget.h" //For MOC

///QtDialWidget manages and displays a Dial
class QtDialWidget : public QWidget
{
  Q_OBJECT
public:
  explicit QtDialWidget(QWidget *parent = 0);
  void mousePressEvent(QMouseEvent *);
  void paintEvent(QPaintEvent *);
  void resizeEvent(QResizeEvent *);

  ///Draw a dial from a Dial
  static void DrawDial(
    QPainter& painter,
    const int left, const int top,
    const int width, const int height,
    const Dial * const dial);

  ///Draw a dial from a DialWidget
  static void DrawDial(
    QPainter& painter,
    const DialWidget * const widget);

  DialWidget * GetWidget() { return m_widget.get(); }
  const DialWidget * GetWidget() const { return m_widget.get(); }

private:
  boost::scoped_ptr<DialWidget> m_widget;

  void OnDialChanged();

public:
  static const std::string GetVersion();
  static const std::vector<std::string> GetVersionHistory();
};

#endif // QTDIALWIDGET_H


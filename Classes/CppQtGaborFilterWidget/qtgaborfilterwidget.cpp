
/*
QtGaborFilterWidget, Qt widget for displaying the GaborFilter class
Copyright (C) 2011-2012 Richel Bilderbeek

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

//From http://www.richelbilderbeek.nl/CppQtGaborFilterWidget.htm

#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtgaborfilterwidget.h"

#include <cassert>
#include <iostream>

#include <boost/math/constants/constants.hpp>
#include <boost/numeric/conversion/cast.hpp>

#include <QPainter>

#include "gaborfilter.h"
//#include "trace.h"

QtGaborFilterWidget::QtGaborFilterWidget(
  QWidget *parent,
  const double intensity,
  const unsigned char red,
  const unsigned char green,
  const unsigned char blue)
  : QWidget(parent),
    m_widget(new GaborFilterWidget(intensity,red,green,blue))
{
  assert(m_widget);
  m_widget->GetGaborFilter()->m_signal_changed.connect(
    boost::bind(
      &QtGaborFilterWidget::repaint,
      this));

  m_widget->m_signal_geometry_changed.connect(
    boost::bind(
      &QtGaborFilterWidget::OnResize,
      this));

  #ifdef __STRICT_ANSI__
  const double pi = boost::math::constants::pi<double>();
  #else
  const double pi = M_PI;
  #endif
  this->GetWidget()->GetGaborFilter()->SetAngle(pi * 2.0 / 16.0);
  this->GetWidget()->GetGaborFilter()->SetFrequency(16.0);
  this->GetWidget()->GetGaborFilter()->SetSigma(this->GetWidget()->GetGaborFilter()->SuggestSigma(
    2.0,2.0));

}

void QtGaborFilterWidget::DrawGaborFilter(
    QPainter& painter,
    const int left, const int top,
    const int width, const int height,
    const GaborFilter * const gaborfilter)
{
  QImage image(width,height,QImage::Format::Format_RGB32);
  const double midx = static_cast<double>(left + width ) / 2.0;
  const double midy = static_cast<double>(top  + height) / 2.0;
  const double max = gaborfilter->GetMax();
  for (int y=0; y!=height; ++y)
  {
    for (int x=0; x!=width; ++x)
    {
      ///Transform the pixels coordinat system to [-1,1] for both x and y
      const double xco = (static_cast<double>(x) - midx)/midx;
      const double yco = (static_cast<double>(y) - midy)/midy;
      const double greyness = gaborfilter->GaborFunction(xco,yco);
      const int grey_int = 128.0 + ((greyness / max) * 126.0);
      const int grey_in_range = (grey_int < 0 ? 0 : (grey_int > 255 ? 255 : grey_int));
      const unsigned char grey = static_cast<unsigned char>(grey_in_range);
      image.setPixel(QPoint(x,y),qRgb(grey,grey,grey));
    }
  }
  painter.drawPixmap(left,top,width,height,QPixmap::fromImage(image));
}

void QtGaborFilterWidget::DrawGaborFilter(
  QPainter& painter,
  const GaborFilterWidget * const widget)
{
  DrawGaborFilter(
    painter,
    widget->GetGeometry().GetX(),
    widget->GetGeometry().GetY(),
    widget->GetGeometry().GetWidth(),
    widget->GetGeometry().GetHeight(),
    widget->GetGaborFilter());
}

const std::string QtGaborFilterWidget::GetVersion()
{
  return "1.0";
}

const std::vector<std::string> QtGaborFilterWidget::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2012-07-07: Version 1.0: initial version");
  return v;
}

///OnResize is calgaborfilter when the geometry of the GaborFilterWidget is changed
void QtGaborFilterWidget::OnResize()
{
  this->setGeometry(
    this->GetWidget()->GetGeometry().GetX(),
    this->GetWidget()->GetGeometry().GetY(),
    this->GetWidget()->GetGeometry().GetWidth(),
    this->GetWidget()->GetGeometry().GetHeight());
  this->repaint();
}

void QtGaborFilterWidget::paintEvent(QPaintEvent *)
{
  QPainter p(this);
  DrawGaborFilter(p,m_widget.get());
}

void QtGaborFilterWidget::resizeEvent(QResizeEvent *)
{
  QRect r = this->geometry();
  this->GetWidget()->SetGeometry(Rect(r.x(),r.y(),r.width(),r.height()));
}


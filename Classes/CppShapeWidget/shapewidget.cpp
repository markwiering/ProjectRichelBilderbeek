#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorUnableToFindNumericLiteralOperatorOperatorQ.htm
#if !(__GNUC__ >= 4 && __GNUC_MINOR__ >= 8)
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedefs"
#include "shapewidget.h"

#include <cassert>
#include <cmath>

#include <boost/numeric/conversion/cast.hpp>

#include "shape.h"
#include "rectangle.h"
//#include "trace.h"

#pragma GCC diagnostic pop

ShapeWidget::ShapeWidget(
  const int n_corners,
  const double rotation,
  const int x,
  const int y,
  const int width,
  const int height,
  const unsigned char red,
  const unsigned char green,
  const unsigned char blue)
  : m_shape(new Shape(n_corners,rotation,red,green,blue))
{
  this->SetGeometry(Rect(x,y,width,height));
}

///Make a deep copy of ShapeWidget
ShapeWidget * ShapeWidget::Clone() const
{
  ShapeWidget * const w = new ShapeWidget(
    this->GetShape()->GetNumberOfCorners(),
    this->GetShape()->GetRotation(),
    this->GetGeometry().GetX(),
    this->GetGeometry().GetY(),
    this->GetGeometry().GetWidth(),
    this->GetGeometry().GetHeight(),
    this->GetShape()->GetRed(),
    this->GetShape()->GetGreen(),
    this->GetShape()->GetBlue());
  assert(*w == *this);
  return w;
}

const std::string ShapeWidget::GetVersion()
{
  return "2.0";
}

const std::vector<std::string> ShapeWidget::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2011-07-13: Version 1.0: initial version");
  v.push_back("2011-07-18: Version 1.1: removed useless methods");
  v.push_back("2011-08-08: Version 2.0: conformized architecture to MysteryMachineWidget");
  return v;
}

bool operator==(const ShapeWidget& lhs,const ShapeWidget& rhs)
{
  return  lhs.GetGeometry() ==  rhs.GetGeometry()
    &&   *lhs.GetShape()    == *rhs.GetShape();
}


//---------------------------------------------------------------------------
/*
GaborFilter, tool to demonstrate Gabor filtering
Copyright (C) 2012  Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolGaborFilter.htm
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
#include "qttoolgaborfiltermaindialog.h"

#include <boost/lexical_cast.hpp>
#include <boost/math/constants/constants.hpp>

#include "ui_qttoolgaborfiltermaindialog.h"

QtToolGaborFilterMainDialog::QtToolGaborFilterMainDialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::QtToolGaborFilterMainDialog)
{
  ui->setupUi(this);
  this->on_dial_angle_sliderMoved(ui->dial_angle->value());
  this->on_slider_frequency_sliderMoved(ui->slider_frequency->value());
  this->on_slider_sigma_sliderMoved(ui->slider_sigma->value());
}

QtToolGaborFilterMainDialog::~QtToolGaborFilterMainDialog()
{
  delete ui;
}

void QtToolGaborFilterMainDialog::on_dial_angle_sliderMoved(int position)
{
  #ifdef __STRICT_ANSI__
  const double pi = boost::math::constants::pi<double>();
  #else
  const double pi = M_PI;
  #endif

  const double angle = 2.0 * pi * static_cast<double>(position)
    / static_cast<double>(ui->dial_angle->maximum());
  ui->gaborfilterwidget->GetWidget()->GetGaborFilter()->SetAngle(angle);
  const std::string s = boost::lexical_cast<std::string>(angle);
  ui->label_angle->setText(s.substr(0,4).c_str());
}

void QtToolGaborFilterMainDialog::on_slider_frequency_sliderMoved(int position)
{
  const double frequency = 64.0 * static_cast<double>(position) / static_cast<double>(ui->slider_frequency->maximum());
  ui->gaborfilterwidget->GetWidget()->GetGaborFilter()->SetFrequency(frequency);
  const std::string s = boost::lexical_cast<std::string>(frequency);
  ui->label_frequency->setText(s.substr(0,4).c_str());

}

void QtToolGaborFilterMainDialog::on_slider_sigma_sliderMoved(int position)
{
  const double suggest = ui->gaborfilterwidget->GetWidget()->GetGaborFilter()->SuggestSigma(2.0,2.0);
  const double sigma = 2.0 * suggest * static_cast<double>(position) / static_cast<double>(ui->slider_sigma->maximum());
  ui->gaborfilterwidget->GetWidget()->GetGaborFilter()->SetSigma(sigma);
  const std::string s = boost::lexical_cast<std::string>(sigma);
  ui->label_sigma->setText(s.substr(0,4).c_str());

}

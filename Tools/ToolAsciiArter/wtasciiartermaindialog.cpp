//---------------------------------------------------------------------------
/*
TestAsciiArter, tool to test the AsciiArter class
Copyright (C) 2006-2011 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/ToolTestAsciiArter.htm
//---------------------------------------------------------------------------
#include <boost/filesystem.hpp>
#include <boost/foreach.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/numeric/conversion/cast.hpp>
//---------------------------------------------------------------------------
#include <Wt/WBreak>
#include <Wt/WFileUpload>
#include <Wt/WGroupBox>
#include <Wt/WImage>
#include <Wt/WLabel>
#include <Wt/WLineEdit>
#include <Wt/WMenu>
#include <Wt/WPushButton>
#include <Wt/WStackedWidget>
#include <Wt/WTextArea>
//---------------------------------------------------------------------------
#include <QFile>
#include <QtGui/QImage>
//---------------------------------------------------------------------------
#include "about.h"
#include "asciiarter.h"
#include "asciiartermaindialog.h"
#include "asciiartermenudialog.h"
#include "wtaboutdialog.h"
#include "wtautoconfig.h"
#include "wtasciiartermaindialog.h"
//---------------------------------------------------------------------------
WtAsciiArterMainDialog::Ui::Ui()
  : m_edit_width(new Wt::WLineEdit),
    m_fileupload(new Wt::WFileUpload),
    m_text(new Wt::WTextArea)
{

}
//---------------------------------------------------------------------------
WtAsciiArterMainDialog::WtAsciiArterMainDialog()
  : m_dialog(new AsciiArterMainDialog)
{
  //Create resources
  {
    std::vector<std::string> image_names;
    image_names.push_back("ToolAsciiArterWelcome.png");

    BOOST_FOREACH(const std::string& filename,image_names)
    {
      if (!(QFile::exists(filename.c_str())))
      {
        QFile f( (std::string(":/images/") + filename).c_str() );
        f.copy(filename.c_str());
      }
      if (!QFile::exists(filename.c_str()))
      {
        std::cerr << "File not found: " + filename + '\n';
      }
      assert(QFile::exists(filename.c_str()));
    }
  }

  this->setContentAlignment(Wt::AlignCenter);
  m_dialog->SetWidth(79);

  this->clear();
  //Title
  {
    Wt::WLabel * const title = new Wt::WLabel("AsciiArter");
    title->setStyleClass("title");
    this->addWidget(title);
  }
  this->addWidget(new Wt::WBreak);
  //Menu
  {
    Wt::WStackedWidget * const contents = new Wt::WStackedWidget;
    Wt::WMenu * const menu = new Wt::WMenu(contents,Wt::Horizontal);
    menu->setStyleClass("menu");
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Welcome",
        CreateNewWelcomeDialog());
      menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "Start",
        CreateNewMainDialog());
      menu->addItem(item);
    }
    {
      Wt::WMenuItem * const item = new Wt::WMenuItem(
        "About",
        CreateNewAboutDialog());
      menu->addItem(item);
    }
    //Display menu on top
    this->addWidget(menu);
    this->addWidget(new Wt::WBreak);
    //Display contents below menu
    this->addWidget(contents);
  }

  this->addWidget(new Wt::WBreak);

  assert(ui.m_edit_width);
  assert(ui.m_text);
}
//---------------------------------------------------------------------------
Wt::WWidget * WtAsciiArterMainDialog::CreateNewAboutDialog() const
{
  About a = AsciiArterMenuDialog::GetAbout();
  a.AddLibrary("WtAutoConfig version: " + WtAutoConfig::GetVersion());
  WtAboutDialog * const d = new WtAboutDialog(a,false);
  return d;
}
//---------------------------------------------------------------------------
Wt::WWidget * WtAsciiArterMainDialog::CreateNewMainDialog()
{
  Wt::WContainerWidget * dialog = new Wt::WContainerWidget;
  //File upload
  {
    assert(ui.m_fileupload);

    //Upload automatically when the user entered a file
    ui.m_fileupload->changed().connect(
      ui.m_fileupload,
      &Wt::WFileUpload::upload);

    //Call WtTextUploadDialog::on_upload_done when file is uploaded
    ui.m_fileupload->uploaded().connect(
      this,
      &WtAsciiArterMainDialog::OnUploadDone);
    dialog->addWidget(ui.m_fileupload);
  }
  dialog->addWidget(new Wt::WBreak);
  dialog->addWidget(new Wt::WBreak);
  //Width edit
  {
    assert(ui.m_edit_width);
    ui.m_edit_width->setText(
      boost::lexical_cast<std::string>(m_dialog->GetWidth()));
    //Respond to if user presses enter
    ui.m_edit_width->enterPressed().connect(
      this, &WtAsciiArterMainDialog::OnEditWidthChange);
    dialog->addWidget(ui.m_edit_width);
  }
  //Convert button
  {
    Wt::WPushButton * const button = new Wt::WPushButton("Convert");
    button->clicked().connect(
      this, &WtAsciiArterMainDialog::OnConvertClick);
    dialog->addWidget(button);
  }
  dialog->addWidget(new Wt::WBreak);
  dialog->addWidget(new Wt::WBreak);
  //text
  {
    assert(ui.m_text);
    ui.m_text->setMinimumSize(600,600);
    dialog->addWidget(ui.m_text);
  }
  return dialog;
}
//---------------------------------------------------------------------------
Wt::WWidget * WtAsciiArterMainDialog::CreateNewWelcomeDialog() const
{
  Wt::WContainerWidget * dialog = new Wt::WContainerWidget;
  dialog->setContentAlignment(Wt::AlignCenter);
  dialog->addWidget(new Wt::WBreak);
  new Wt::WLabel("Welcome to AsciiArter",dialog);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  new Wt::WLabel("AsciiArter is a tool to convert images to ascii art.",dialog);
  new Wt::WBreak(dialog);
  new Wt::WBreak(dialog);
  Wt::WGroupBox * const box = new Wt::WGroupBox("Explanation",dialog);
  box->addWidget(new Wt::WImage("ToolAsciiArterWelcome.png"));
  return dialog;
}
//---------------------------------------------------------------------------
void WtAsciiArterMainDialog::OnAnyChange()
{
  if (m_dialog->CanConvert())
  {
    m_dialog->Convert();
    std::vector<std::string> v = m_dialog->GetAsciiArt();
    Wt::WString ws;
    BOOST_FOREACH(const std::string& s,v)
    {
      ws += s.c_str();
      ws += "\n";
    }
    ui.m_text->setText(ws);
  }
}
//---------------------------------------------------------------------------
void WtAsciiArterMainDialog::OnConvertClick()
{
  OnEditWidthChange();
}
//---------------------------------------------------------------------------
void WtAsciiArterMainDialog::OnEditWidthChange()
{
  try
  {
    const std::string s = ui.m_edit_width->text().toUTF8();
    const int i = boost::lexical_cast<int>(s);
    m_dialog->SetWidth(i);
  }
  catch(boost::bad_lexical_cast&)
  {
    //No problem
  }

  OnAnyChange();
}
//---------------------------------------------------------------------------
void WtAsciiArterMainDialog::OnUploadDone()
{
  const std::string filename = ui.m_fileupload->spoolFileName();
  assert(boost::filesystem::exists(filename));
  const std::vector<std::vector<double> > v
    = ConvertToGreyYx(filename);
  assert(!v.empty());
  m_dialog->SetImage(v);
  OnAnyChange();
}
//---------------------------------------------------------------------------
//Returns a Y-X-ordered std::vector of greynesses.
const std::vector<std::vector<double> >
  WtAsciiArterMainDialog::ConvertToGreyYx(const std::string& filename)
{
  assert(boost::filesystem::exists(filename));
  const QImage * const i = new QImage(filename.c_str());
  const int maxy = i->height();
  const int maxx = i->width();
  const int n_bytes = i->bytesPerLine() / maxx;

  std::vector<std::vector<double> > v;
  for (int y=0; y!=maxy; ++y)
  {
    v.push_back(std::vector<double>());
    const unsigned char * const line = i->scanLine(y);
    for (int x=0; x!=maxx; ++x)
    {
      int sum = 0;
      for (int byte=0; byte!=n_bytes; ++byte)
      {
        sum += line[(x * n_bytes) + byte];
      }
      const double greyness
        = (boost::numeric_cast<double>(sum)
        / boost::numeric_cast<double>(n_bytes))
        / 256.0;
      assert(greyness >= 0.0);
      assert(greyness <= 1.0);
      v.back().push_back(greyness);
    }
  }
  return v;
}
//---------------------------------------------------------------------------
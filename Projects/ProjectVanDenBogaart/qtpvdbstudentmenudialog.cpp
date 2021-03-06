#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtpvdbstudentmenudialog.h"

#include <cassert>

#include <QKeyEvent>
#include <QFileDialog>

#include "pvdbfile.h"
//#include "pvdbmenudialog.h"
#include "qtpvdbaboutdialog.h"
#include "qtpvdbstudentstartcompletedialog.h"
#include "trace.h"
#include "ui_qtpvdbstudentmenudialog.h"

QtPvdbStudentMenuDialog::QtPvdbStudentMenuDialog(const boost::shared_ptr<pvdb::File> file, QWidget* parent)
  : QtHideAndShowDialog(parent),
    ui(new Ui::QtPvdbStudentMenuDialog),
    m_file(file)
{
  ui->setupUi(this);
  assert(m_file);
  if (!m_file->GetStudentName().empty())
  {
    SetName(m_file->GetStudentName());
  }
  on_edit_name_textChanged(ui->edit_name->text());
}

QtPvdbStudentMenuDialog::~QtPvdbStudentMenuDialog()
{
  delete ui;
}

const std::string QtPvdbStudentMenuDialog::GetName() const
{
  return ui->edit_name->text().toStdString();
}

void QtPvdbStudentMenuDialog::keyPressEvent(QKeyEvent* e)
{
  if (e->key()  == Qt::Key_Escape) { close(); return; }
  if ((e->modifiers() & Qt::ControlModifier) && e->key() == Qt::Key_S) { on_button_save_clicked(); return; }
  QDialog::keyPressEvent(e);
}

void QtPvdbStudentMenuDialog::on_button_about_clicked()
{
  const auto d(QtPvdbAboutDialog::Get());
  this->hide();
  d->exec();
  this->show();
}

void QtPvdbStudentMenuDialog::on_button_quit_clicked()
{
  close();
}

void QtPvdbStudentMenuDialog::on_button_start_clicked()
{
  m_file->SetStudentName(ui->edit_name->text().toStdString());
  QtPvdbStudentStartCompleteDialog d(m_file);
  this->ShowChild(&d);
}

void QtPvdbStudentMenuDialog::on_edit_name_textChanged(const QString &arg1)
{
  //Enable start button when student has entered at least two characters
  assert(ui->edit_name->text() == arg1);
  if (arg1.size() > 1)
  {
    ui->button_start->setEnabled(true);
  }
  else
  {
    ui->button_start->setEnabled(false);
  }
}

void QtPvdbStudentMenuDialog::on_button_save_clicked()
{
  const std::string filter_str = std::string("*.") + pvdb::File::GetFilenameExtension();
  const std::string filename_raw = QFileDialog::getSaveFileName(0,"Sla de concept map op",
    QString(),
    filter_str.c_str()).toStdString();
  if (!filename_raw.empty())
  {
    const std::string filename
      =  (filename_raw.size() < pvdb::File::GetFilenameExtension().size()
        || filename_raw.substr( filename_raw.size() - 3, 3 ) != pvdb::File::GetFilenameExtension()
       ? filename_raw + std::string(".") + pvdb::File::GetFilenameExtension()
       : filename_raw);
    assert(filename.size() > 3
      && filename.substr( filename.size() - 3, 3 ) == pvdb::File::GetFilenameExtension()
      && "File must have correct file extension name");
    Save(filename);
  }
}

void QtPvdbStudentMenuDialog::Save(const std::string& filename) const
{
  m_file->SetStudentName(ui->edit_name->text().toStdString());

  assert(filename.size() > 3
    && filename.substr( filename.size() - 3, 3 ) == pvdb::File::GetFilenameExtension()
    && "File must have correct file extension name");
  m_file->Save(filename);
  //{ const std::string debug_str = "File saved as " + filename; TRACE(debug_str); }
}

void QtPvdbStudentMenuDialog::SetName(const std::string& name)
{
  ui->edit_name->setText(name.c_str());
}

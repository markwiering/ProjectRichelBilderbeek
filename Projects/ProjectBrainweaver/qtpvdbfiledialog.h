#ifndef QTPVDBFILEDIALOG_H
#define QTPVDBFILEDIALOG_H

#include <boost/shared_ptr.hpp>

struct QFileDialog;

namespace pvdb {

struct QtFileDialog
{
  ///Create a QFileDialog to open Brainweaver files with
  static const boost::shared_ptr<QFileDialog> GetOpenFileDialog();

  ///Create a QFileDialog to save Brainweaver files with
  static const boost::shared_ptr<QFileDialog> GetSaveFileDialog();
};

} //~namespace pvdb

#endif // QTPVDBFILEDIALOG_H

//---------------------------------------------------------------------------
/*
QtModel, my classes derived from QAbstractTableModel
Copyright (C) 2013 Richel Bilderbeek

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
//From http://www.richelbilderbeek.nl/CppQtModel.htm
//---------------------------------------------------------------------------
#ifdef _WIN32
//See http://www.richelbilderbeek.nl/CppCompileErrorSwprintfHasNotBeenDeclared.htm
#undef __STRICT_ANSI__
#endif

//#include own header file as first substantive line of code, from:
// * John Lakos. Large-Scale C++ Software Design. 1996. ISBN: 0-201-63362-0. Section 3.2, page 110
#include "qtublasmatrixdoublemodel.h"

#include <numeric>
#include <cassert>
#include <boost/lexical_cast.hpp>

#include "matrix.h"
#include "trace.h"

QtUblasMatrixDoubleModel::QtUblasMatrixDoubleModel(QObject *parent)
  : QAbstractTableModel(parent)
{

}

int QtUblasMatrixDoubleModel::columnCount(const QModelIndex &) const
{
  return m_data.size2();
}

QVariant QtUblasMatrixDoubleModel::data(const QModelIndex &index, int role) const
{
  //Removing this line will cause checkboxes to appear
  if (role != Qt::EditRole && role != Qt::DisplayRole) return QVariant();

  assert(index.isValid());

  const int row = index.row();
  const int col = index.column();
  assert(row < boost::numeric_cast<int>(m_data.size1()));
  assert(col < boost::numeric_cast<int>(m_data.size2()));

  #ifdef RETURN_DOUBLE_723465978463059835
  return m_data(row,col);
  #else
  //Convert to string, otherwise the number digits behind the comma
  //will be set to 2, e.g. 0.01
  const std::string s = boost::lexical_cast<std::string>(m_data(row,col));
  return QString(s.c_str());
  #endif
}

Qt::ItemFlags QtUblasMatrixDoubleModel::flags(const QModelIndex &) const
{
  return
    Qt::ItemIsSelectable
  | Qt::ItemIsEditable
  | Qt::ItemIsDragEnabled
  | Qt::ItemIsDropEnabled
  | Qt::ItemIsEnabled;
}

const std::string QtUblasMatrixDoubleModel::GetVersion()
{
  return "1.2";
}

const std::vector<std::string> QtUblasMatrixDoubleModel::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("2013-05-15: version 1.0: initial version");
  v.push_back("2013-05-21: version 1.1: added columns and rows are initialized with zeroes");
  v.push_back("2013-05-23: version 1.2: allow an infine amount of digits behind the comma");
  return v;
}

QVariant QtUblasMatrixDoubleModel::headerData(int section, Qt::Orientation orientation, int role) const
{
  //Removing this line will cause checkboxes to appear
  if (role != Qt::EditRole && role != Qt::DisplayRole) return QVariant();

  if (orientation == Qt::Horizontal)
  {
    //No idea why this happens
    if (!(section < boost::numeric_cast<int>(m_header_horizontal_text.size())))
    {
      return QVariant();
    }

    assert(section < boost::numeric_cast<int>(m_header_horizontal_text.size()));
    return QString( m_header_horizontal_text[section].c_str() );
  }
  else
  {
    assert(orientation == Qt::Vertical);
    //No idea why this happens
    if (!(section < boost::numeric_cast<int>(m_header_vertical_text.size())))
    {
      return QVariant();
    }

    assert(section < boost::numeric_cast<int>(m_header_vertical_text.size()));
    return QString( m_header_vertical_text[section].c_str() );
  }
}

bool QtUblasMatrixDoubleModel::insertColumns(int col, int count, const QModelIndex &parent)
{
  //Must be called before the real operation
  this->beginInsertColumns(parent,col,col+count-1);

  //The real operation: resize the m_data
  assert(m_data.size2() == m_header_horizontal_text.size());

  const int new_size = m_data.size2() + count;

  #ifdef USE_NAIVE_APPROACH_785768676876547
  //The drawback of this naive approach is that new cells are uninitialized
  m_data.resize(m_data.size1(),new_size);
  #else
  boost::numeric::ublas::matrix<double> new_data = boost::numeric::ublas::zero_matrix<double>(m_data.size1(),new_size);
  const int n_rows = boost::numeric_cast<int>(m_data.size1());
  const int n_cols = boost::numeric_cast<int>(m_data.size2());
  for (int y = 0; y != n_rows; ++y)
  {
    for (int x = 0; x != n_cols; ++x)
    {
      assert(y < boost::numeric_cast<int>(new_data.size1()));
      assert(x < boost::numeric_cast<int>(new_data.size2()));
      assert(y < boost::numeric_cast<int>(m_data.size1()));
      assert(x < boost::numeric_cast<int>(m_data.size2()));
      new_data(y,x) = m_data(y,x);
    }
  }
  m_data = new_data;
  #endif

  m_header_horizontal_text.resize(new_size,"");

  assert(m_data.size2() == m_header_horizontal_text.size());

  //Must be called in the end
  this->endInsertColumns();

  //It worked!
  return true;
}

bool QtUblasMatrixDoubleModel::insertRows(int row, int count, const QModelIndex &parent)
{
  //Must be called before the real operation
  this->beginInsertRows(parent,row,row+count-1);

  //The real operation: resize the m_data
  assert(m_data.size1() == m_header_vertical_text.size());

  const int new_size = m_data.size1() + count;

  #ifdef USE_NAIVE_APPROACH_785768676876547
  //The drawback of this naive approach is that new cells are uninitialized
  m_data.resize(new_size,m_data.size2());
  #else
  boost::numeric::ublas::matrix<double> new_data = boost::numeric::ublas::zero_matrix<double>(new_size,m_data.size2());
  const int n_rows = boost::numeric_cast<int>(m_data.size1());
  const int n_cols = boost::numeric_cast<int>(m_data.size2());
  for (int y = 0; y != n_rows; ++y)
  {
    for (int x = 0; x != n_cols; ++x)
    {
      assert(y < boost::numeric_cast<int>(new_data.size1()));
      assert(x < boost::numeric_cast<int>(new_data.size2()));
      assert(y < boost::numeric_cast<int>(m_data.size1()));
      assert(x < boost::numeric_cast<int>(m_data.size2()));
      new_data(y,x) = m_data(y,x);
    }
  }
  m_data = new_data;
  #endif

  m_header_vertical_text.resize(new_size);

  assert(m_data.size1() == m_header_vertical_text.size());

  //Must be called in the end
  this->endInsertRows();

  //It worked!
  return true;
}

bool QtUblasMatrixDoubleModel::removeColumns(int col, int count, const QModelIndex &parent)
{
  //Must be called before the real operation
  this->beginRemoveColumns(parent,col,col+count-1);

  //The real operation: resize the m_data
  assert(m_data.size2() == m_header_horizontal_text.size());

  const int new_size = m_data.size2() - count;
  m_data.resize(m_data.size1(),new_size);
  m_header_horizontal_text.resize(new_size);

  assert(m_data.size2() == m_header_horizontal_text.size());

  //Must be called in the end
  this->endRemoveColumns();

  //It worked!
  return true;
}

bool QtUblasMatrixDoubleModel::removeRows(int row, int count, const QModelIndex &parent)
{
  //Must be called before the real operation
  this->beginRemoveRows(parent,row,row+count-1);

  //The real operation: resize the m_data
  assert(m_data.size1() == m_header_vertical_text.size());

  const int new_size = m_data.size1() - count;
  m_data.resize(new_size,m_data.size2());
  m_header_vertical_text.resize(new_size);

  assert(m_data.size1() == m_header_vertical_text.size());

  //Must be called in the end
  this->endRemoveRows();

  //It worked!
  return true;
}

int QtUblasMatrixDoubleModel::rowCount(const QModelIndex &) const
{
  return m_data.size1();
}

bool QtUblasMatrixDoubleModel::setData(const QModelIndex &index, const QVariant &value, int /* role */)
{
  const int row = index.row();
  const int col = index.column();
  assert(row < boost::numeric_cast<int>(m_data.size1()));
  assert(col < boost::numeric_cast<int>(m_data.size2()));
  m_data(row,col) = value.toDouble();
  ///This line below is needed to let multiple views synchronize
  emit dataChanged(index,index);

  //Editing succeeded!
  return true;
}

void QtUblasMatrixDoubleModel::SetHeaderData(
  const std::vector<std::string>& horizontal_header_text,
  const std::vector<std::string>& vertical_header_text)
{
  if (m_header_horizontal_text != horizontal_header_text)
  {
    const int new_size = boost::numeric_cast<int>(horizontal_header_text.size());
    const int cur_size = this->columnCount();
    if (cur_size < new_size)
    {
      //Insert some rows in the raw data
      this->insertColumns(cur_size,new_size - cur_size,QModelIndex());

      //If you forget this line, the view displays a different number of rows than m_data has
      emit layoutChanged();
    }
    else if (cur_size > new_size)
    {
      //Remove some rows from the raw data
      this->removeColumns(cur_size,cur_size - new_size,QModelIndex());

      //If you forget this line, the view displays a different number of rows than m_data has
      emit layoutChanged();
    }

    assert(this->columnCount() == boost::numeric_cast<int>(horizontal_header_text.size()));

    m_header_horizontal_text = horizontal_header_text;

    emit headerDataChanged(Qt::Horizontal,0,new_size);
  }

  if (m_header_vertical_text != vertical_header_text)
  {
    const int new_size = boost::numeric_cast<int>(vertical_header_text.size());
    const int cur_size = this->rowCount();
    if (cur_size < new_size)
    {
      //Insert some rows in the raw data
      this->insertRows(cur_size,new_size - cur_size,QModelIndex());

      //If you forget this line, the view displays a different number of rows than m_data has
      emit layoutChanged();
    }
    else if (cur_size > new_size)
    {
      //Remove some rows from the raw data
      this->removeRows(cur_size,cur_size - new_size,QModelIndex());

      //If you forget this line, the view displays a different number of rows than m_data has
      emit layoutChanged();
    }

    assert(this->rowCount() == boost::numeric_cast<int>(vertical_header_text.size()));

    m_header_vertical_text = vertical_header_text;

    emit headerDataChanged(Qt::Vertical,0,new_size);
  }

  assert(this->columnCount() == boost::numeric_cast<int>(this->m_data.size2()));
  assert(this->columnCount() == boost::numeric_cast<int>(m_header_horizontal_text.size()));
  assert(this->rowCount() == boost::numeric_cast<int>(this->m_data.size1()));
  assert(this->rowCount() == boost::numeric_cast<int>(m_header_vertical_text.size()));
}

bool QtUblasMatrixDoubleModel::setHeaderData(int section, Qt::Orientation orientation, const QVariant &value, int /*role*/)
{
  if (orientation == Qt::Horizontal)
  {
    assert(section < boost::numeric_cast<int>(m_header_horizontal_text.size()));
    assert(m_header_horizontal_text[section] != value.toString().toStdString());
    m_header_horizontal_text[section] = value.toString().toStdString();
    ///This line below is needed to let multiple views synchronize
    emit headerDataChanged(orientation,section,section);
    //Editing succeeded!
    return true;
  }
  else
  {
    assert(orientation == Qt::Vertical);
    assert(section < boost::numeric_cast<int>(m_header_vertical_text.size()));
    assert(m_header_vertical_text[section] != value.toString().toStdString());
    m_header_vertical_text[section] = value.toString().toStdString();
    ///This line below is needed to let multiple views synchronize
    emit headerDataChanged(orientation,section,section);
    //Editing succeeded!
    return true;
  }
}

void QtUblasMatrixDoubleModel::SetRawData(const boost::numeric::ublas::matrix<double>& data)
{
  if (!Matrix::MatricesAreEqual(m_data,data))
  {
    //Check for row count
    {
      const int new_row_count = boost::numeric_cast<int>(data.size1());
      const int cur_row_count = this->rowCount();
      if (cur_row_count < new_row_count)
      {
        //Insert some rows in the raw data
        this->insertRows(cur_row_count,new_row_count - cur_row_count,QModelIndex());

        //If you forget this line, the view displays a different number of rows than m_data has
        emit layoutChanged();
      }
      else if (cur_row_count > new_row_count)
      {
        //Remove some rows from the raw data
        this->removeRows(cur_row_count,cur_row_count - new_row_count,QModelIndex());

        //If you forget this line, the view displays a different number of rows than m_data has
        emit layoutChanged();
      }
      assert(this->rowCount() == boost::numeric_cast<int>(data.size1()));
    }
    //Check for column count
    {
      const int new_col_count = boost::numeric_cast<int>(data.size2());
      const int cur_col_count = this->columnCount();
      if (cur_col_count < new_col_count)
      {
        //Insert some rows in the raw data
        this->insertColumns(cur_col_count,new_col_count - cur_col_count,QModelIndex());

        //If you forget this line, the view displays a different number of rows than m_data has
        emit layoutChanged();
      }
      else if (cur_col_count > new_col_count)
      {
        //Remove some rows from the raw data
        this->removeColumns(cur_col_count,cur_col_count - new_col_count,QModelIndex());

        //If you forget this line, the view displays a different number of rows than m_data has
        emit layoutChanged();
      }
      assert(this->columnCount() == boost::numeric_cast<int>(data.size2()));
    }

    assert(m_data.size1() == data.size1());
    assert(m_data.size2() == data.size2());

    m_data = data;
    const QModelIndex top_left = this->index(0,0);
    const QModelIndex bottom_right = this->index(rowCount(), columnCount());
    emit dataChanged(top_left,bottom_right);
  }

  assert(this->columnCount() == boost::numeric_cast<int>(this->m_data.size2()));
  assert(this->columnCount() == boost::numeric_cast<int>(m_header_horizontal_text.size()));
  assert(this->rowCount() == boost::numeric_cast<int>(this->m_data.size1()));
  assert(this->rowCount() == boost::numeric_cast<int>(m_header_vertical_text.size()));
}
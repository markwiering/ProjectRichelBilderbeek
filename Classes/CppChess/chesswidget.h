#ifndef CHESSWIDGET_H
#define CHESSWIDGET_H

#include <boost/shared_ptr.hpp>

//#include "chessboard.h"
#include "chessfwd.h"
#include "widget.h"
struct Rect;

namespace Chess {

///Chess::ChessWidget is a Widget to interact with a Chess class:
///Where the Chess::Board is very picky about valid moves,
///the Chess::ChessWidget enables simple interaction with it
///Note the name, which is to prevent conflict with the Widget class
struct ChessWidget : public ::Widget
{
  enum class Key { up, down, left, right, select };

  ///Emit this signal when the chessboard changes
  mutable boost::signals2::signal<void ()> m_signal_graphic_changed;

  ChessWidget(const Rect& geometry);

  //Base classes must have a public destructor:
  //Herb Sutter, Andrei Alexandrescu. C++ coding standards:
  //101 rules, guidelines, and best practices.
  //ISBN: 0-32-111358-6. Item 50: 'Make base class destructors
  //public and virtual, or protected and nonvirtual'.
  virtual ~ChessWidget();

  ///Can do a move?
  virtual bool CanDoMove(const Chess::Square& from, const Chess::Square& to) const = 0;

  ///Respond to a click
  ///Note: originally, this method was called Click, but it conflicted with Click(const Square&) :-(
  void ClickPixel(const int x, const int y);

  ///Do a move
  virtual void DoMove(const Chess::Square& from, const Chess::Square& to) = 0;

  ///Obtain the SquareSelector
  boost::scoped_ptr<Chess::SquareSelector>& GetSelector() { return m_selector; }

  ///Obtain the SquareSelector
  const boost::scoped_ptr<Chess::SquareSelector>& GetSelector() const { return m_selector; }

  ///Obtain the version of this class
  static const std::string GetVersion();

  ///Obtain the version history of this class
  static const std::vector<std::string> GetVersionHistory();

  ///Respond to a key being pressed
  void PressKey(const Chess::ChessWidget::Key key);

  ///Test this class
  static void Test();

  ///The Selector (a cursor and possibly a selected square)
  boost::scoped_ptr<Chess::SquareSelector> m_selector;

  ///Respond to a click, transformed click coordinats to a square
  virtual void Click(const Chess::Square& square) = 0;

  ///OnChanged is called when the BoardWidget is changed and needs a repaint.
  ///BoardWidget requests for a repaint by emitting m_signal_board_changed
  void OnChanged() const;

  friend void boost::checked_delete<>(ChessWidget* x);
};

} //~ namespace Chess

#endif // CHESSWIDGET_H

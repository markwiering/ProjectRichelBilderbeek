#include "chessboardfactory.h"

#include <algorithm>
#include <cassert>
#include <numeric>

#include "chessboard.h"
#include "chesspiecefactory.h"

namespace Chess {

boost::shared_ptr<Chess::Board> BoardFactory::Create(const Chess::Board::Pieces& pieces)
{
  boost::shared_ptr<Chess::Board> p(new Chess::Board(pieces));
  assert(p);
  return p;
}

boost::shared_ptr<Chess::Board> BoardFactory::DeepCopy(const Board& board)
{
  const Chess::Board::ConstPieces original = board.GetPieces();
  Chess::Board::Pieces pieces;
  std::transform(original.begin(),original.end(),
    std::inserter(pieces,pieces.begin()),
    [](const Chess::Board::ConstPiecePtr& piece)
    {
      assert(piece);
      Chess::Board::PiecePtr p = PieceFactory::DeepCopy(*piece);
      assert(p);
      return p;
    }
  );
  boost::shared_ptr<Chess::Board> b(Create(pieces));
  assert(b);
  return b;
}


} //~namespace Chess

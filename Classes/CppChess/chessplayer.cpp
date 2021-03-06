
#include <cassert>
#include <stdexcept>

#include "chessplayer.h"

namespace Chess {

const std::string PlayerToStr(const Player player)
{
  switch (player)
  {
    case Player::black: return "black";
    case Player::white: return "white";
  }
  assert(!"Unknown Player in PlayerToStr");
  throw std::logic_error("Unknown Player in PlayerToStr");
}

} //~ namespace Chess



#include <cassert>
#include <stdexcept>

#include <boost/lexical_cast.hpp>
#include <boost/regex.hpp>

#include "chesscastling.h"
#include "chessmove.h"
#include "chessmoves.h"
#include "chesspiece.h"
#include "chesspiecefactory.h"
#include "chesssquarefactory.h"
#include "chessscore.h"
#include "trace.h"

namespace Chess {

Move::Move(const std::string& s)
  : m_from(ParseFrom(s)),
    m_is_capture(ParseIsCapture(s)),
    m_is_castling(ParseIsCastling(s)),
    m_is_check(ParseIsCheck(s)),
    m_is_checkmate(ParseIsCheckmate(s)),
    m_is_en_passant(ParseIsEnPassant(s)),
    m_is_promotion(ParseIsPromotion(s)),
    m_piece(ParsePiece(s)),
    m_piece_promotion(ParsePiecePromotion(s)),
    m_score(ParseScore(s)),
    m_str(s),
    m_to(ParseTo(s))
{
  #ifndef NDEBUG
  Test();
  #endif

  if (s.empty()) throw std::logic_error("std::string to parse is empty");
  if (!m_to && !m_is_castling && (!m_score))
  {
    const std::string error = "Chess::Move::Move exception: m_to not initialized for non-castling non-score move " + s;
    throw std::logic_error(error.c_str());
  }
  if (!m_piece && !m_is_castling && !m_score)
  {
    const std::string error = "Chess::Move::Move exception: m_piece not initialized for non-castling non-score move " + s;
    throw std::logic_error(error.c_str());
  }

  if (m_is_en_passant && !m_is_capture) throw std::logic_error("Chess::Move::Move exception: every en passant capture is a capture");

  if (boost::regex_search(s,boost::regex("e.p.")) && !m_is_en_passant)
  {
    const std::string error = "Chess::Move::Move exception: move is an invalid en passant move: " + s;
    throw std::logic_error(error.c_str());
  }

  if (m_piece)
  {
    if (m_is_castling)
    {
      throw std::logic_error("Chess::Move::Move exception: m_piece cannot be initialized in a castling move");
    }
    if (m_score) throw std::logic_error("Chess::Move::Move exception: m_piece cannot be initialized in a score move");
    const bool valid = m_piece->CanDoMove(*this);
    if (!valid)
    {
      const std::string t = "Move " + s + " invalid for " + m_piece->GetName();
      throw std::logic_error(t.c_str());
    }
  }
}

const std::vector<std::string> Move::GetRegexMatches(
  const std::string& s,
  const boost::regex& r)
{
  std::vector<std::string> v;

  std::string::const_iterator start = s.begin();
  const std::string::const_iterator end = s.end();
  boost::match_results<std::string::const_iterator> what;
  boost::match_flag_type flags = boost::match_default;
  while(boost::regex_search(start, end, what, r, flags))
  {
    const std::string x = what.str();
    v.push_back(x);
    start = what[0].second;
    flags |= boost::match_prev_avail;
    flags |= boost::match_not_bob;
  }
  return v;
}

const std::string Move::GetVersion()
{
  return "1.0";
}

const std::vector<std::string> Move::GetVersionHistory()
{
  std::vector<std::string> v;
  v.push_back("YYYY-MM-DD: version X.Y: [description]");
  v.push_back("2012-01-25: version 1.0: initial version");
  return v;
}

bool Move::IsCastling() const
{
  assert(!m_is_castling || CanStrToCastling(m_str));
  return m_is_castling;
}

const boost::shared_ptr<Chess::Square> Move::ParseFrom(const std::string& s)
{
  boost::shared_ptr<Chess::Square> square;
  const std::vector<std::string> v = GetRegexMatches(s,boost::regex("[a-h][1-8]"));
  #ifndef NDEBUG
  if (!(v.size() <= 2)) { TRACE(s); }
  #endif
  assert(v.size() <= 2);
  if (v.size() == 2)
  {
    square = SquareFactory::Create(v[0]);
    //square.reset(new Square(v[0]));
  }
  return square;
}

bool Move::ParseIsCapture(const std::string& s)
{
  //if (s.empty()) throw std::logic_error("Move::ParseIsCapture exception: move must not be empty");
  //return boost::regex_match(s,boost::regex("[a-h]\\d?x.*"));
  return boost::regex_match(s,boost::regex("(B|K|N|Q|R)?([a-h])?([1-8])?x[a-h][1-8](e.p.)?(\\+|\\#)?"));
}

bool Move::ParseIsCastling(const std::string& s)
{
  return CanStrToCastling(s);

  //return s == "0-0" || s == "O-O" || s == "O-O+" || s == "0-0-0" || s == "O-O-O"|| s == "O-O-O+";
}

bool Move::ParseIsCheck(const std::string& s)
{
  if (s.empty()) throw std::logic_error("Move::IsCheck(const std::string& s) exception: move must not be empty");
  return s[s.size() - 1] == '+';
}

bool Move::ParseIsCheckmate(const std::string& s)
{
  if (s.empty()) throw std::logic_error("Move::IsCheckmate(const std::string& s) exception: move must not be empty");
  return s[s.size() - 1] == '#';
}

bool Move::ParseIsEnPassant(const std::string& s)
{
  if (!boost::regex_match(s,boost::regex("([a-h][4-5])x[a-h][3-6]e.p.(\\+|\\#)?"))) return false;
  const boost::shared_ptr<Chess::Square> from = ParseFrom(s);
  const boost::shared_ptr<Chess::Square> to = ParseTo(s);
  assert(from);
  assert(to);
  if (std::abs(from->GetFile().ToInt() - to->GetFile().ToInt()) != 1) return false;
  if (std::abs(from->GetRank().ToInt() - to->GetRank().ToInt()) != 1) return false;
  if (from->GetRank() == Chess::Rank("5") && to->GetRank() == Chess::Rank("6")) return true;
  if (from->GetRank() == Chess::Rank("4") && to->GetRank() == Chess::Rank("3")) return true;
  return false;
}

bool Move::ParseIsPromotion(const std::string& s)
{
  return boost::regex_match(s,boost::regex("([a-h][1-8](x|\\s)?)?[a-h][1|8][B|N|Q|R](\\+|\\#)?"));
}

const boost::shared_ptr<Chess::Piece> Move::ParsePiece(const std::string& s)
{
  if (s.empty()) throw std::logic_error("Move::ParsePiece exception: move must not be empty");
  const boost::shared_ptr<Chess::Piece> p = PieceFactory::CreateFromMove(s);
  assert(p);
  return p;
}

const boost::shared_ptr<Chess::Piece> Move::ParsePiecePromotion(const std::string& s)
{
  if (s.empty()) throw std::logic_error("Move::ParsePiece exception: move must not be empty");
  const boost::shared_ptr<Chess::Piece> p = PieceFactory::CreateFromPromotion(s);
  assert(p);
  return p;
}

const boost::shared_ptr<Chess::Score> Move::ParseScore(const std::string& s)
{
  boost::shared_ptr<Chess::Score> p;
  try
  {
    Chess::Score * const ptr = new Chess::Score(s);
    p.reset(ptr);
  }
  catch (std::exception& e)
  {
    //Move is not a Score, no problem
  }
  return p;
}

const boost::shared_ptr<Chess::Square> Move::ParseTo(const std::string& s)
{
  boost::shared_ptr<Chess::Square> square;
  const std::vector<std::string> v = GetRegexMatches(s,boost::regex("[a-h][1-8]"));
  if (!v.empty())
  {
    assert(v.size() <= 2);
    const std::string t = v[ v.size() - 1];
    square = SquareFactory::Create(t);
    assert(square);
  }
  return square;
}

const std::string Move::ToStr() const
{
  std::string s;
  if (m_piece)
  {
    if (!dynamic_cast<PiecePawn*>(m_piece.get()))
    {
      s += m_piece->GetNameChar();
    }
    if (m_from)
    {
      s += m_from->ToStr();
    }
    else
    {
      s += "??";
    }
    if (m_is_capture)
    {
      s += "x";
    }
    else
    {
      s += " ";
    }
    if (m_to)
    {
      s += m_to->ToStr();
    }
    else
    {
      s += "??";
    }
  }
  if (m_is_castling) s += m_str;
  if (m_is_check) s+= "+";
  if (m_is_checkmate) s+= "#";
  if (m_is_en_passant) s+= "e.p.";
  if (m_is_promotion) s+= "(promotion)";
  if (m_piece_promotion) s+= m_piece_promotion->GetNameChar();
  if (m_score) s+= m_score->ToStr();
  return s;
}

bool operator==(const Move& lhs, const Move& rhs)
{
  if (static_cast<bool>(lhs.m_from) != static_cast<bool>(rhs.m_from)) return false;
  if (lhs.m_from)
  {
    assert(rhs.m_from);
    if (!IsEqual(*lhs.m_from,*rhs.m_from)) return false;
  }
  if (lhs.m_is_capture  != rhs.m_is_capture) return false;
  if (lhs.m_is_castling != rhs.m_is_castling) return false;
  if (lhs.m_is_check != rhs.m_is_check) return false;
  if (lhs.m_is_checkmate != rhs.m_is_checkmate) return false;
  if (lhs.m_is_en_passant != rhs.m_is_en_passant) return false;
  if (lhs.m_is_promotion != rhs.m_is_promotion) return false;
  if (static_cast<bool>(lhs.m_piece) != static_cast<bool>(rhs.m_piece)) return false;
  if (lhs.m_piece)
  {
    assert(rhs.m_piece);
    if (!IsEqual(*lhs.m_piece,*rhs.m_piece)) return false;
  }

  if (static_cast<bool>(lhs.m_piece_promotion) != static_cast<bool>(rhs.m_piece_promotion)) return false;
  if (lhs.m_piece_promotion)
  {
    assert(rhs.m_piece_promotion);
    if (!IsEqual(*lhs.m_piece_promotion,*rhs.m_piece_promotion)) return false;
  }

  if (static_cast<bool>(lhs.m_score) != static_cast<bool>(rhs.m_score)) return false;
  if (lhs.m_piece_promotion)
  {
    assert(rhs.m_score);
    if (*lhs.m_score!= *rhs.m_score) return false;
  }

  return true;
}

bool operator!=(const Move& lhs, const Move& rhs)
{
  return !(lhs == rhs);
}

std::ostream& operator<<(std::ostream& os,const Move& m)
{
  os << m.GetStr();
  return os;
}

} //~ namespace Chess

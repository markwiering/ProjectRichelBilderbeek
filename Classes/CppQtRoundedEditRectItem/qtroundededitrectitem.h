#ifndef QTROUNDEDEDITRECTITEM_H
#define QTROUNDEDEDITRECTITEM_H

#include <string>
#include <vector>
#include <boost/signals2.hpp>
#include <QFont>
#include "qtroundedrectitem.h"

///A QtRoundedRectTextItem displaying multiple lines of text
struct QtRoundedEditRectItem : public QtRoundedRectItem
{
  struct Padding
  {
    Padding(const double any_top = 0.0, const double any_right = 0.0, const double any_bottom = 0.0, const double any_left = 0.0)
      : bottom(any_bottom), left(any_left), right(any_right), top(any_top) {}
    double bottom;
    double left;
    double right;
    double top;
  };

  QtRoundedEditRectItem(
    const std::vector<std::string>& text = { "..." },
    const Padding& padding = Padding(),
    const QFont& font = QFont("monospace",9),
    QGraphicsItem* parent = 0,
    QGraphicsScene* scene = 0);

  virtual ~QtRoundedEditRectItem() {}

  ///Get the font by which the text is drawn
  const QFont& GetFont() const { return m_font; }

  ///Obtain the version of this class
  static const std::string GetVersion();

  ///Obtain the version history of this class
  static const std::vector<std::string> GetVersionHistory();

  ///Set the font by which the text is drawn
  void SetFont(const QFont& font);

  ///Set the padding between text and rectangle
  void SetPadding(const Padding& padding);

  ///Set the text displayed
  virtual void SetText(const std::vector<std::string>& text);

  ///Called when the user wants to edit the text
  boost::signals2::signal<void(QtRoundedEditRectItem*)> m_signal_item_requests_edit;

protected:
  virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
  virtual void keyPressEvent(QKeyEvent* event);

private:

  ///The font by which the text is drawn
  QFont m_font;

  ///Set the padding between text and rectangle
  Padding m_padding;

  ///The text displayed
  std::vector<std::string> m_text;

  ///Set the padding around text, so the text will be centered
  static const Padding m_text_padding;

  ///Obtain the unpadded text rectangle for a single line
  ///Note: even this rectangle is enlarged by a pixel in both dimensions, so the text will be drawn in full
  const QRectF GetTextRect(const std::string& s) const;

  ///Obtain the unpadded text rectangle for the whole text
  ///Note: even this rectangle is enlarged by a pixel in both dimensions, so the text will be drawn in full
  const QRectF GetTextRect(const std::vector<std::string>& text) const;

  ///Obtain the padded text rectangle for a single line
  const QRectF GetPaddedTextRect(const std::string& s) const;
};

#endif // QTROUNDEDEDITRECTITEM_H
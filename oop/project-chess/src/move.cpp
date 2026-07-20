#include "move.h"

Move::Move(int fromRow, int fromCol, int toRow, int toCol, char pieceMoved, bool wasWhite, char pieceCaptured) : m_fromRow(fromRow), m_fromCol(fromCol), m_toRow(toRow), m_toCol(toCol), m_pieceMoved(pieceMoved), m_pieceCaptured(pieceCaptured), m_wasWhite(wasWhite), m_isCastling(false), m_isEnPassant(false), m_isPawnPromotion(false), m_promotedTo('Q') {}

int Move::getFromRow() const { return m_fromRow; }
int Move::getFromCol() const { return m_fromCol; }
int Move::getToRow() const { return m_toRow; }
int Move::getToCol() const { return m_toCol; }
char Move::getPieceMoved() const { return m_pieceMoved; }
char Move::getPieceCaptured() const { return m_pieceCaptured; }
bool Move::wasWhite() const { return m_wasWhite; }

bool Move::isCastling() const { return m_isCastling; }
bool Move::isEnPassant() const { return m_isEnPassant; }
bool Move::isPawnPromotion() const { return m_isPawnPromotion; }
char Move::getPromotedTo() const { return m_promotedTo; }

void Move::setPawnPromotion(bool value, char piece) {
    m_isPawnPromotion = value;
    m_promotedTo = piece;
}
void Move::setCastling(bool value) { m_isCastling = value; }
void Move::setEnPassant(bool value) { m_isEnPassant = value; }

bool Move::wasCapture() const { return m_pieceCaptured != '\0'; }
bool Move::wasPawnMove() const { return m_pieceMoved == 'P'; }
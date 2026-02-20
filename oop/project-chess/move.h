#pragma once
#include "main.h"

class Move {
private:
    int m_fromRow;
    int m_fromCol;
    int m_toRow;
    int m_toCol;
    char m_pieceMoved; // 'P', 'R', 'N', 'B', 'Q', 'K'
    char m_pieceCaptured; // '\0' if no capture
    bool m_wasWhite;

    //special move flags
    bool m_isCastling;
    bool m_isEnPassant;
    bool m_isPawnPromotion;
    char m_promotedTo;
public:
    Move(int fromRow = 0, int fromCol = 0, int toRow = 0, int toCol = 0, char pieceMoved = '\0', bool wasWhite = true, char pieceCaptured = '\0');

    int getFromRow() const;
    int getFromCol() const;
    int getToRow() const;
    int getToCol() const;
    char getPieceMoved() const;
    char getPieceCaptured() const;
    bool wasWhite() const;

    bool isCastling() const;
    bool isEnPassant() const;
    bool isPawnPromotion() const;
    char getPromotedTo() const;

    void setPawnPromotion(bool value, char piece);
    void setCastling(bool value);
    void setEnPassant(bool value);

    bool wasCapture() const;
    bool wasPawnMove() const;
};
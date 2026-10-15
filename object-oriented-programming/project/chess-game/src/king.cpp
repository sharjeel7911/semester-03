#include "king.h"
#include "board.h"

King::King(bool isWhite, int row, int col) : Piece(isWhite, row, col) {}

const char* King::getSymbol() const {
    return m_isWhite ? "wK" : "bK";
}

bool King::isValidMove(int toRow, int toCol, Board* board) const {
    int rowDiff = abs(toRow - m_row);
    int colDiff = abs(toCol - m_col);

    if (rowDiff > 1 || colDiff > 1) return false;
    if (rowDiff == 0 && colDiff == 0) return false; //can't stay in same place

    //check destination square
    Square* target = board->getSquare(toRow, toCol);
    if (!target) return false;

    //can move to empty square or capture enemy piece
    if (target->isEmpty()) return true;
    return target->getPiece()->isWhite() != m_isWhite; //can capture enemy
}
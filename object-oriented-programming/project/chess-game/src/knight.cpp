#include "knight.h"
#include "board.h"

Knight::Knight(bool isWhite, int row, int col) : Piece(isWhite, row, col) {}

const char* Knight::getSymbol() const {
    return m_isWhite ? "wN" : "bN"; 
}

bool Knight::isValidMove(int toRow, int toCol, Board* board) const {
    int rowDiff = abs(toRow - m_row);
    int colDiff = abs(toCol - m_col);

    bool isLShape = (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);

    if (!isLShape) return false;

    //check destination square
    Square* target = board->getSquare(toRow, toCol);
    if (!target) return false;

    //can move to empty square or capture enemy piece
    if (target->isEmpty()) return true;
    return target->getPiece()->isWhite() != m_isWhite; //can capture enemy
}
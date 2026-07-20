#include "rook.h"
#include "board.h"

Rook::Rook(bool isWhite, int row, int col) : Piece(isWhite, row, col) {}


const char* Rook::getSymbol() const {
    return m_isWhite ? "wR" : "bR";
}

bool Rook::isValidMove(int toRow, int toCol, Board* board) const {
    if (m_row != toRow && m_col != toCol) return false;

    //check if path is clear
    int rowStep = (toRow > m_row) ? 1 : (toRow < m_row) ? -1 : 0;
    int colStep = (toCol > m_col) ? 1 : (toCol < m_col) ? -1 : 0;

    int currentRow = m_row + rowStep;
    int currentCol = m_col + colStep;

    //check all squares between start and destination
    while (currentRow != toRow || currentCol != toCol) {
        Square* sq = board->getSquare(currentRow, currentCol);
        if (!sq || !sq->isEmpty()) return false; //path blocked
        currentRow += rowStep;
        currentCol += colStep;
    }

    //check destination square
    Square* target = board->getSquare(toRow, toCol);
    if (!target) return false;

    //can move to empty square or capture enemy piece
    if (target->isEmpty()) return true;
    return target->getPiece()->isWhite() != m_isWhite;
}
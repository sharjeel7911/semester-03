#include "bishop.h"
#include "board.h"

Bishop::Bishop(bool isWhite, int row, int col) : Piece(isWhite, row, col) {}

const char* Bishop::getSymbol() const {
    return m_isWhite ? "wB" : "bB";
}

bool Bishop::isValidMove(int toRow, int toCol, Board* board) const {
	int rowDiff = abs(toRow - m_row);
	int colDiff = abs(toCol - m_col); 

    if (rowDiff != colDiff) return false;

    //check if path is clear
    int rowStep = (toRow > m_row) ? 1 : -1;
    int colStep = (toCol > m_col) ? 1 : -1;

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
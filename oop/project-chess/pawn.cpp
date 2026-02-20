#include "pawn.h"
#include "board.h"

Pawn::Pawn(bool isWhite, int row, int col) : Piece(isWhite, row, col) {}

const char* Pawn::getSymbol() const {
    return m_isWhite ? "wP" : "bP"; 
}

bool Pawn::isValidMove(int toRow, int toCol, Board* board) const {
    int rowDiff = toRow - m_row;
    int colDiff = abs(toCol - m_col);

    //white pawns move up (+1), black pawns move down (-1)
    int direction = m_isWhite ? 1 : -1;

    //move forward one square 
    if (colDiff == 0 && rowDiff == direction) {
        Square* target = board->getSquare(toRow, toCol);
        return target && target->isEmpty();
    }

    //move forward two squares from starting position
    if (colDiff == 0 && rowDiff == 2 * direction) {
        int startRow = m_isWhite ? 1 : 6;
        if (m_row == startRow) {
            Square* target = board->getSquare(toRow, toCol);
            Square* inBetween = board->getSquare(m_row + direction, m_col);
            return target && target->isEmpty() && inBetween && inBetween->isEmpty();
        }
    }

    //capture diagonally
    if (colDiff == 1 && rowDiff == direction) {
        Square* target = board->getSquare(toRow, toCol);
        if (target && !target->isEmpty()) {
            return target->getPiece()->isWhite() != m_isWhite; //enemy piece
        }

		//check for en passant
        if (target && target->isEmpty()) {
            //check if this is a valid en passant capture
            Move* lastMove = board->getLastMove();
            if (lastMove && lastMove->wasPawnMove()) {
                int moveDistance = abs(lastMove->getToRow() - lastMove->getFromRow());
                if (moveDistance == 2) {
                    //enemy pawn moved 2 squares and is next to us
                    if (lastMove->getToRow() == m_row && lastMove->getToCol() == toCol) {
                        return true; //valid en passant
                    }
                }
            }
        }

    }
    return false;
}

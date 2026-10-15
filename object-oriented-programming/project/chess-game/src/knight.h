#pragma once
#include "piece.h"

class Board;

class Knight : public Piece {
public:
    Knight(bool isWhite, int row, int col);
    const char* getSymbol() const override; //decides the symbol based on color
	bool isValidMove(int toRow, int toCol, Board* board) const override; //checks if the move is valid for knight
};
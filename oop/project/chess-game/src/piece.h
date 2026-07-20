#pragma once
#include "main.h"

class Board;

//forward declared in square.h
class Piece {
protected:
    bool m_isWhite;
    int m_row;
    int m_col;
public:
    Piece(bool isWhite, int row, int col); //constructor
	virtual ~Piece(); //virtual destructor

	bool isWhite() const; //check color of the piece
	virtual const char* getSymbol() const = 0; //get symbol of the piece
	virtual bool isValidMove(int toRow, int toCol, Board* board) const = 0; //check if move is valid

    int getRow() const;
    int getCol() const;

	void setPosition(int row, int col); //set position of the piece
};  
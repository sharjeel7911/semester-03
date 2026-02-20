#pragma once
#include "main.h"

class Piece; 

class Square {
private:
	int m_row;
	int m_col;
	Piece* m_piece;
public:
	Square(int row = 0, int col = 0, Piece* piece = nullptr); //constructor

	void setPosition(int, int); //set row and column

	void setPiece(Piece*); //set piece on the square
	Piece* getPiece() const; //get piece on the square

	int getRow() const;
	int getCol() const;

	bool isEmpty() const; //check if square is empty
	void clearPiece(); //doesn't delete the piece but make m_piece nullptr
};
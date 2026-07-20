#include "piece.h"

Piece::Piece(bool isWhite, int row, int col) : m_isWhite(isWhite), m_row(row), m_col(col) {}

Piece::~Piece() {}

bool Piece::isWhite() const { 
	return m_isWhite; 
}

int Piece::getRow() const {
    return m_row;
}

int Piece::getCol() const {
    return m_col;
}

void Piece::setPosition(int row, int col) {
    m_row = row;
    m_col = col;
}

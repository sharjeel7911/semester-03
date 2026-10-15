#include "square.h"

Square::Square(int row, int col, Piece* piece) : m_row(row), m_col(col), m_piece(piece) {}

void Square::setPosition(int row, int col) {
	m_row = row;
	m_col = col;
}

void Square::setPiece(Piece* piece) {
	m_piece = piece;
}

Piece* Square::getPiece() const {
	return m_piece;
}

int Square::getRow() const {
	return m_row;
}

int Square::getCol() const {
	return m_col;
}

bool Square::isEmpty() const {
	return m_piece == nullptr;
}

void Square::clearPiece() {
	m_piece = nullptr;
}
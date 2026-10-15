#pragma once
#include "main.h"
#include "mystack.h"
#include "square.h"
#include "piece.h"
#include "pawn.h"
#include "knight.h"
#include "bishop.h"
#include "rook.h"
#include "queen.h"
#include "king.h"  
#include "move.h"

class Board {
private:
	Square m_squares[8][8]; //8 x 8 array of squares
	Piece* m_pieces[32]; //total 32 pieces
	int m_pieceCount;
	bool m_whiteTurn;
	int m_halfMoveClock;
	int m_positionHashes[500];  //store position hashes
	int m_hashCount;
	MyStack<Move> m_moveHistory; //store move history
	MyStack<int> m_halfMoveClockHistory; //store move history of white king

	//private helper methods
	Piece* findKing(bool isWhite) const; //return pointer to king of given color
	bool isSquareUnderAttack(int row, int col, bool byWhite); //check if square is attacked by given color
	bool wouldExposeKingToCheck(int fromRow, int fromCol, int toRow, int toCol); //check if moving piece(king included) would expose king to check
	bool hasAnyValidMoves(bool isWhite); //check if player of given color has any valid moves

	void promotePawn(int row, int col, char promoteTo); //for promoting pawn

	bool canCastle(bool isWhite, bool isKingside); //check if castling possible
	void executeCastle(bool isWhite, bool isKingside); //do castle
	bool canEnPassant(int pawnRow, int pawnCol, int targetCol); //check if en passant possible

	int calculatePositionHash();
public:
	Board(); //constructor
	~Board(); //destructor

	void initialize(); //initialize the board with squares
	void setupPieces(); //set up the pieces on the board

	Square* getSquare(int, int); //return pointer to square at given row and column
	void displayBoard() const; //display the board on console

	bool movePiece(int fromRow, int fromCol, int toRow, int toCol); //move piece from one square to another
	bool isWhiteTurn() const; //check if it's white's turn
	void removePieceFromArray(Piece* piece); //remove piece from m_pieces array

	bool isKingInCheck(bool isWhite); //check if the king of given color is in check
	bool isCheckmate(bool isWhite); //check if the player of given color is in checkmate
	bool isStalemate(bool isWhite); //check if the player of given color is in stalemate

	bool isFiftyMoveDraw() const; //check for fifty-move rule draw
	bool isThreefoldRepetition(); //check for threefold repetition draw
	bool isInsufficientMaterial() const; //check for insufficient material draw

	void recordMove(const Move& move); //record a move in move history
	Move* getLastMove(); //get the last move made
	int getMoveCount() const; //get number of moves made
	bool hasKingMoved(bool isWhite) const; //check if king has moved
	bool hasRookMoved(bool isWhite, bool isKingside) const; //check if rook has moved

	bool undoLastMove(bool checkPlayerOwnership);
};
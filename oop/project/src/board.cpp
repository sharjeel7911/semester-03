#include "board.h"

//private helper methods

Piece* Board::findKing(bool isWhite) const {
    for (int i = 0; i < m_pieceCount; i++) {
        if (m_pieces[i]->isWhite() == isWhite) {
            //check if it's a King by checking its symbol
            const char* symbol = m_pieces[i]->getSymbol();
            if (symbol[1] == 'K') { //"wK" or "bK"
                return m_pieces[i];
            }
        }
    }
    return nullptr;
}

bool Board::isSquareUnderAttack(int row, int col, bool byWhite) {
    //check all opponent pieces to see if they can attack this square
    for (int i = 0; i < m_pieceCount; i++) {
        Piece* piece = m_pieces[i];
        if (piece->isWhite() == byWhite) {
            //this piece is the attacking color
            if (piece->isValidMove(row, col, this)) {
                return true;
            }
        }
    }
    return false;
}

bool Board::wouldExposeKingToCheck(int fromRow, int fromCol, int toRow, int toCol) {
    Square* from = getSquare(fromRow, fromCol);
    Square* to = getSquare(toRow, toCol);

    if (!from || !to) return true;

    Piece* movingPiece = from->getPiece();
    Piece* capturedPiece = to->getPiece();
    bool isWhite = movingPiece->isWhite();

    //temporarily remove captured piece from piece array
    int capturedPieceIndex = -1;
    if (capturedPiece) {
        for (int i = 0; i < m_pieceCount; i++) {
            if (m_pieces[i] == capturedPiece) {
                capturedPieceIndex = i;
                // Shift array left to temporarily remove it
                for (int j = i; j < m_pieceCount - 1; j++) {
                    m_pieces[j] = m_pieces[j + 1];
                }
                m_pieceCount--;
                break;
            }
        }
    }

    //temporarily make the move
    to->setPiece(movingPiece);
    from->clearPiece();
    movingPiece->setPosition(toRow, toCol);

    //check if king is in check after this move
    bool inCheck = isKingInCheck(isWhite);

    //undo the move
    from->setPiece(movingPiece);
    to->setPiece(capturedPiece);
    movingPiece->setPosition(fromRow, fromCol);

    //restore captured piece to array
    if (capturedPiece && capturedPieceIndex != -1) {
        //shift array right to make space
        for (int j = m_pieceCount; j > capturedPieceIndex; j--) {
            m_pieces[j] = m_pieces[j - 1];
        }
        m_pieces[capturedPieceIndex] = capturedPiece;
        m_pieceCount++;
    }
    return inCheck;
}

bool Board::hasAnyValidMoves(bool isWhite) {
    //try all pieces of this color
    for (int i = 0; i < m_pieceCount; i++) {
        Piece* piece = m_pieces[i];
        if (piece->isWhite() != isWhite) continue;

        int fromRow = piece->getRow();
        int fromCol = piece->getCol();

        //try all possible destination squares
        for (int toRow = 0; toRow < 8; toRow++) {
            for (int toCol = 0; toCol < 8; toCol++) {
                //check if piece can move there
                if (piece->isValidMove(toRow, toCol, this)) {
                    //check if move would expose king
                    if (!wouldExposeKingToCheck(fromRow, fromCol, toRow, toCol)) {
                        return true; //found a valid move
                    }
                }
            }
        }
    }
    return false; //no valid moves found
}

void Board::promotePawn(int row, int col, char promoteTo) {
    Square* square = getSquare(row, col);
    if (!square || square->isEmpty()) return;

    Piece* pawn = square->getPiece();
    bool isWhite = pawn->isWhite();

    //remove old pawn
    removePieceFromArray(pawn);
    delete pawn;
    square->clearPiece();

    //create new piece based on choice
    Piece* newPiece = nullptr;

    switch (promoteTo) {
    case 'Q':
        newPiece = new Queen(isWhite, row, col);
        break;
    case 'R':
        newPiece = new Rook(isWhite, row, col);
        break;
    case 'B':
        newPiece = new Bishop(isWhite, row, col);
        break;
    case 'N':
        newPiece = new Knight(isWhite, row, col);
        break;
    default:
        newPiece = new Queen(isWhite, row, col); //default to Queen
    }

    //add new piece to board
    m_pieces[m_pieceCount] = newPiece;
    m_pieceCount++;
    square->setPiece(newPiece);
}

bool Board::canCastle(bool isWhite, bool isKingside) {
    //check if king and rook has moved
    if (hasKingMoved(isWhite)) return false;
    if (hasRookMoved(isWhite, isKingside)) return false;

    int row = isWhite ? 0 : 7;
    int kingCol = 4;
    int rookCol = isKingside ? 7 : 0;

	//check if king is in check by any opposing piece
    if (isKingInCheck(isWhite)) return false;

    //check squares between king and rook are empty
    if (isKingside) {
        //kingside: check f and g files (columns 5 and 6)
        if (!getSquare(row, 5)->isEmpty()) return false;
        if (!getSquare(row, 6)->isEmpty()) return false;

        //check king doesn't pass through check (f file)
        if (isSquareUnderAttack(row, 5, !isWhite)) return false;
        //check king doesn't land in check (g file)
        if (isSquareUnderAttack(row, 6, !isWhite)) return false;
    }
    else {
        //queenside: check b, c, d files (columns 1, 2, 3)
        if (!getSquare(row, 1)->isEmpty()) return false;
        if (!getSquare(row, 2)->isEmpty()) return false;
        if (!getSquare(row, 3)->isEmpty()) return false;

        //check king doesn't pass through check (d file)
        if (isSquareUnderAttack(row, 3, !isWhite)) return false;
        //check king doesn't land in check (c file)
        if (isSquareUnderAttack(row, 2, !isWhite)) return false;
    }
    return true;
}

void Board::executeCastle(bool isWhite, bool isKingside) {
    int row = isWhite ? 0 : 7;
    int kingCol = 4;
    int rookCol = isKingside ? 7 : 0;
    int newKingCol = isKingside ? 6 : 2;
    int newRookCol = isKingside ? 5 : 3;

    //get king and rook
    Square* kingSquare = getSquare(row, kingCol);
    Square* rookSquare = getSquare(row, rookCol);

    Piece* king = kingSquare->getPiece();
    Piece* rook = rookSquare->getPiece();

    //move king
    Square* newKingSquare = getSquare(row, newKingCol);
    newKingSquare->setPiece(king);
    kingSquare->clearPiece();
    king->setPosition(row, newKingCol);

    //move rook
    Square* newRookSquare = getSquare(row, newRookCol);
    newRookSquare->setPiece(rook);
    rookSquare->clearPiece();
    rook->setPosition(row, newRookCol);

    //create and record move
    Move move(row, kingCol, row, newKingCol, 'K', isWhite, '\0');
    move.setCastling(true);
    recordMove(move);
    cout << "Castled " << (isKingside ? "kingside" : "queenside") << "!" << endl;
}

bool Board::canEnPassant(int pawnRow, int pawnCol, int targetCol) {
    //get last move
    Move* lastMove = getLastMove();
    if (!lastMove) return false;

    //last move must be a pawn move
    if (!lastMove->wasPawnMove()) return false;

    //last move must be a 2-square advance
    int moveDistance = abs(lastMove->getToRow() - lastMove->getFromRow());
    if (moveDistance != 2) return false;

    //enemy pawn must be next to our pawn (same row, adjacent column)
    if (lastMove->getToRow() != pawnRow) return false;
    if (lastMove->getToCol() != targetCol) return false;

    //our pawn must be on correct row (row 4 for white, row 3 for black)
    Square* ourSquare = getSquare(pawnRow, pawnCol);
    if (!ourSquare || ourSquare->isEmpty()) return false;

    Piece* ourPawn = ourSquare->getPiece();
    bool isWhite = ourPawn->isWhite();
    int correctRow = isWhite ? 4 : 3; //white pawns en passant from row 4, black from row 3

    if (pawnRow != correctRow) return false;
    return true;
}

int Board::calculatePositionHash() {
    int hash = 0;

    //hash all pieces on the board
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Square* sq = getSquare(row, col);
            if (!sq->isEmpty()) {
                Piece* piece = sq->getPiece();
                char symbol = piece->getSymbol()[1];  // P, R, N, B, Q, K
                bool isWhite = piece->isWhite();

                //create unique value for this piece at this position
                int pieceValue = (symbol - 'A') + (isWhite ? 100 : 200);
                int positionValue = row * 8 + col;
                hash += pieceValue * positionValue;
            }
        }
    }

    //include whose turn it is
    hash += m_whiteTurn ? 1000000 : 2000000;

    if (!hasKingMoved(true) && !hasRookMoved(true, true))  hash += 1 << 20;  //white kingside
    if (!hasKingMoved(true) && !hasRookMoved(true, false)) hash += 1 << 21; //white queenside
    if (!hasKingMoved(false) && !hasRookMoved(false, true)) hash += 1 << 22; //black kingside
    if (!hasKingMoved(false) && !hasRookMoved(false, false)) hash += 1 << 23; //black queenside

    //include en passant possibility (column only, 0-7; -1 if not possible)
    Move* lastMove = getLastMove();
    int enPassantCol = -1; // default: no en passant
    if (lastMove && lastMove->wasPawnMove()) {
        int moveDistance = abs(lastMove->getToRow() - lastMove->getFromRow());
        if (moveDistance == 2) { // two-square pawn move
            enPassantCol = lastMove->getToCol();
        }
    }
    if (enPassantCol >= 0) {
        hash += (enPassantCol + 1) << 24; //shift so it doesn't collide with other bits
    }
    return hash;
}

//public methods

Board::Board() {
    m_pieceCount = 0;
    m_whiteTurn = true;
    m_halfMoveClock = 0;
	m_hashCount = 0;
    initialize();
}

Board::~Board() {
    for (int i = 0; i < m_pieceCount; i++) {
        delete m_pieces[i];
        m_pieces[i] = nullptr;
    }
}

void Board::initialize() {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            m_squares[i][j].setPosition(i, j);
            m_squares[i][j].clearPiece(); //no piece on current square at initialization
        }
    }
    setupPieces();
}

void Board::setupPieces() {
    m_pieceCount = 0;

    //white pieces

    for (int i = 0; i < 8; i++) {
        m_pieces[m_pieceCount] = new Pawn(true, 1, i);
        m_squares[1][i].setPiece(m_pieces[m_pieceCount++]);
    }

    m_pieces[m_pieceCount] = new Rook(true, 0, 0);
    m_squares[0][0].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Knight(true, 0, 1);
    m_squares[0][1].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Bishop(true, 0, 2);
    m_squares[0][2].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Queen(true, 0, 3);
    m_squares[0][3].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new King(true, 0, 4);
    m_squares[0][4].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Bishop(true, 0, 5);
    m_squares[0][5].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Knight(true, 0, 6);
    m_squares[0][6].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Rook(true, 0, 7);
    m_squares[0][7].setPiece(m_pieces[m_pieceCount++]);

    //black pieces

    for (int i = 0; i < 8; i++) {
        m_pieces[m_pieceCount] = new Pawn(false, 6, i);
        m_squares[6][i].setPiece(m_pieces[m_pieceCount++]);
    }

    m_pieces[m_pieceCount] = new Rook(false, 7, 0);
    m_squares[7][0].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Knight(false, 7, 1);
    m_squares[7][1].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Bishop(false, 7, 2);
    m_squares[7][2].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Queen(false, 7, 3);
    m_squares[7][3].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new King(false, 7, 4);
    m_squares[7][4].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Bishop(false, 7, 5);
    m_squares[7][5].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Knight(false, 7, 6);
    m_squares[7][6].setPiece(m_pieces[m_pieceCount++]);

    m_pieces[m_pieceCount] = new Rook(false, 7, 7);
    m_squares[7][7].setPiece(m_pieces[m_pieceCount++]);
}

Square* Board::getSquare(int row, int col) {
    if (row >= 0 && row < 8 && col >= 0 && col < 8) return &m_squares[row][col];
    return nullptr;
}

void Board::displayBoard() const {
    cout << "                             Sharjeel's Chess" << endl << endl;

    for (int r = 7; r >= 0; r--) {
        cout << "        ";
        for (int c = 0; c < 8; c++) {
            cout << "+------";
        }
        cout << "+" << endl;

        //row with pieces
        cout << "    " << r + 1 << "   ";
        for (int c = 0; c < 8; c++) {
            cout << "|  ";
            const Square* sq = &m_squares[r][c];
            if (sq->isEmpty()) cout << "  ";
            else cout << sq->getPiece()->getSymbol();
            cout << "  ";
        }
        cout << "|" << endl;
    }
    cout << "        ";
    for (int c = 0; c < 8; c++) {
        cout << "+------";
    }
    cout << "+" << endl;
    cout << "           a      b      c      d      e      f      g      h" << endl;
}

bool Board::isWhiteTurn() const {
    return m_whiteTurn;
}

bool Board::movePiece(int fromRow, int fromCol, int toRow, int toCol) {
    Square* from = getSquare(fromRow, fromCol);
    Square* to = getSquare(toRow, toCol);

    //validation
    if (!from || !to) return false;
    if (from->isEmpty()) return false;

    Piece* piece = from->getPiece();

    //check correct player's turn
    if (piece->isWhite() != m_whiteTurn) return false;
    
	//handle castling
    char pieceType = piece->getSymbol()[1];
    if (pieceType == 'K') {
        int colDiff = toCol - fromCol;

        //king moves 2 squares = castling attempt
        if (abs(colDiff) == 2) {
            bool isKingside = (colDiff > 0); //moving right = kingside

            if (canCastle(piece->isWhite(), isKingside)) {
                executeCastle(piece->isWhite(), isKingside);
                if (m_halfMoveClock < 500) {
					m_halfMoveClockHistory.push(m_halfMoveClock++);
				} //push half-move clock before castling 

                m_whiteTurn = !m_whiteTurn;
                if (m_hashCount < 500) m_positionHashes[m_hashCount++] = calculatePositionHash();
                return true;
            }
            else return false;  //invalid castle
        }
    }

    //check if move is valid for this piece
    if (!piece->isValidMove(toRow, toCol, this)) return false;

    if (wouldExposeKingToCheck(fromRow, fromCol, toRow, toCol)) {
        return false; //can't make a move that exposes your king
    }

    pieceType = piece->getSymbol()[1]; //extract 'P', 'R', 'N', 'B', 'Q', 'K'
    char capturedType = '\0';

	//handle en passant
    bool isEnPassant = false;
    if (pieceType == 'P') {
        int colDiff = abs(toCol - fromCol);
        if (colDiff == 1 && to->isEmpty()) {
            //diagonal move to empty square = en passant
            if (canEnPassant(fromRow, fromCol, toCol)) {
                isEnPassant = true;

                //remove the captured pawn (it's on same row as attacking pawn)
                Square* capturedPawnSquare = getSquare(fromRow, toCol);
                if (capturedPawnSquare && !capturedPawnSquare->isEmpty()) {
                    Piece* capturedPawn = capturedPawnSquare->getPiece();
                    capturedType = 'P';
                    removePieceFromArray(capturedPawn);
                    delete capturedPawn;
                    capturedPawnSquare->clearPiece();
                }
            }
        }
    }

    //handle capture
    if (!to->isEmpty() && !isEnPassant) {
        capturedType = to->getPiece()->getSymbol()[1];
        Piece* captured = to->getPiece();
        removePieceFromArray(captured);
        delete captured;
    }

	//prepare move record
    Move move(fromRow, fromCol, toRow, toCol, pieceType, piece->isWhite(), capturedType);

	//mark en passant in move record
    if (isEnPassant) {
        move.setEnPassant(true);
    }

    //executing move
    to->setPiece(piece);
    from->clearPiece();
    piece->setPosition(toRow, toCol);

	//handle pawn promotion
    if (pieceType == 'P') {
        bool isWhite = piece->isWhite();
        int promotionRow = isWhite ? 7 : 0;  //white promotes at row 7, Black at row 0

        if (toRow == promotionRow) {
            //pawn reached the end - ask for promotion
            char promoteTo;
            while (true) {
                clearScreen();
                cout << "\n        +-----------------------------------+" << endl;
                cout << "        |          PAWN PROMOTION!          |" << endl;
                cout << "        +-----------------------------------+" << endl;
                cout << "             Choose piece to promote to:" << endl;
                cout << "                     Q - Queen" << endl;
                cout << "                     R - Rook" << endl;
                cout << "                     B - Bishop" << endl;
                cout << "                     N - Knight" << endl;
                cout << "             Enter choice (Q/R/B/N): ";

                cin >> promoteTo;
                cin.ignore(); //clear newline from input buffer

                //convert to uppercase
                if (promoteTo >= 'a' && promoteTo <= 'z') {
                    promoteTo = promoteTo - 'a' + 'A';
                }

                //validate input
                if (promoteTo == 'Q' || promoteTo == 'R' || promoteTo == 'B' || promoteTo == 'N') {
                    break; 
                }
                cout << "Invalid choice! Please enter Q, R, B, or N.\n";
            }

            // Perform promotion
            promotePawn(toRow, toCol, promoteTo);

            // Mark move as promotion
            move.setPawnPromotion(true, promoteTo);
            cout << "Pawn promoted to " << promoteTo << "!" << endl;
        }
    }

	//record the move by pushing it onto the move history stack
    recordMove(move);

	//record half-move clock history
    if (m_halfMoveClock < 500) m_halfMoveClockHistory.push(m_halfMoveClock);

	//update half-move clock
    if (pieceType == 'P' || capturedType != '\0') m_halfMoveClock = 0;  //reset counter
    else m_halfMoveClock++; //increment counter
    
    //switch turns for next move
    m_whiteTurn = !m_whiteTurn;

	//record position hash for threefold repetition
    if (m_hashCount < 500) m_positionHashes[m_hashCount++] = calculatePositionHash();
    return true;
}

void Board::removePieceFromArray(Piece* piece) {
    for (int i = 0; i < m_pieceCount; i++) {
        if (m_pieces[i] == piece) {
            //shift remaining pieces left
            for (int j = i; j < m_pieceCount - 1; j++) m_pieces[j] = m_pieces[j + 1];
            m_pieceCount--;
            break;
        }
    }
}

bool Board::isKingInCheck(bool isWhite) {
    Piece* king = findKing(isWhite);
    if (!king) return false; //no king found (it shouldn't happen)

    int kingRow = king->getRow();
    int kingCol = king->getCol();

    //check if any opponent piece can attack the king's position
    return isSquareUnderAttack(kingRow, kingCol, !isWhite);
}

bool Board::isCheckmate(bool isWhite) {
    if (!isKingInCheck(isWhite)) return false;
    return !hasAnyValidMoves(isWhite);
}

bool Board::isStalemate(bool isWhite) {
    if (isKingInCheck(isWhite)) return false;
    return !hasAnyValidMoves(isWhite);
}

bool Board::isFiftyMoveDraw() const {
    //50 full moves = 100 half-moves(one half-move per player turn)
    return m_halfMoveClock >= 100;
}

bool Board::isThreefoldRepetition() {
    int currentHash = calculatePositionHash();
    int count = 0;

    //count how many times this position has occurred
    for (int i = 0; i < m_hashCount; i++) {
        if (m_positionHashes[i] == currentHash) {
            count++;
        }
    }

    //if position occurred 3 or more times, it's a draw
    return count == 3;
}

bool Board::isInsufficientMaterial() const {
    //count pieces for each side
    int whiteKnights = 0, blackKnights = 0;
    int whiteBishops = 0, blackBishops = 0;
    int whiteOthers = 0, blackOthers = 0;  //queens, rooks, pawns

    //track bishop square colors (true = light square, false = dark square)
    bool whiteBishopOnLight = false, whiteBishopOnDark = false;
    bool blackBishopOnLight = false, blackBishopOnDark = false;

    for (int i = 0; i < m_pieceCount; i++) {
        Piece* piece = m_pieces[i];
        char symbol = piece->getSymbol()[1];
        bool isWhite = piece->isWhite();

        if (symbol == 'K') continue; //skip kings

        if (symbol == 'N') {
            if (isWhite) whiteKnights++;
            else blackKnights++;
        }
        else if (symbol == 'B') {
            int row = piece->getRow();
            int col = piece->getCol();
            //square is light if (row + col) is even, dark if odd
            bool isLightSquare = ((row + col) % 2 == 0);

            if (isWhite) {
                whiteBishops++;
                if (isLightSquare) whiteBishopOnLight = true;
                else whiteBishopOnDark = true;
            }
            else {
                blackBishops++;
                if (isLightSquare) blackBishopOnLight = true;
                else blackBishopOnDark = true;
            }
        }
        else {
            // pawn, rook, or queen - these can ALWAYS deliver checkmate
            if (isWhite) whiteOthers++;
            else blackOthers++;
        }
    }

    //if either side has pawns, rooks, or queens → sufficient material
    if (whiteOthers > 0 || blackOthers > 0) return false;

    //total minor pieces (knights + bishops) for each side
    int whiteMinor = whiteKnights + whiteBishops;
    int blackMinor = blackKnights + blackBishops;

    // ====================================================
    // INSUFFICIENT MATERIAL CASES (cannot force checkmate)
    // ====================================================

    // 1. King vs King
    if (whiteMinor == 0 && blackMinor == 0) { return true; }

    // 2. King + Knight vs King
    if ((whiteKnights == 1 && whiteMinor == 1 && blackMinor == 0) || (blackKnights == 1 && blackMinor == 1 && whiteMinor == 0)) { return true; }

    // 3. King + Bishop vs King
    if ((whiteBishops == 1 && whiteMinor == 1 && blackMinor == 0) || (blackBishops == 1 && blackMinor == 1 && whiteMinor == 0)) { return true; }

    // 4. King + Bishop vs King + Bishop (SAME color squares)
    if (whiteBishops == 1 && blackBishops == 1 && whiteMinor == 1 && blackMinor == 1) {
        //check if both bishops are on same color squares {draw}
        bool whiteBishopColor = whiteBishopOnLight;  // true = light, false = dark
        bool blackBishopColor = blackBishopOnLight;  // true = light, false = dark

        if (whiteBishopColor == blackBishopColor) {
            return true;  
        }
        //if bishops on opposite colors, checkmate IS possible → sufficient material
    }
    return false;  
}

void Board::recordMove(const Move& move) {
    m_moveHistory.push(move);
}

Move* Board::getLastMove() {
    if (m_moveHistory.isEmpty())
        return nullptr;
    return &m_moveHistory.peek();
}

int Board::getMoveCount() const {
    return m_moveHistory.size();
}

bool Board::hasKingMoved(bool isWhite) const {
    //check all moves in history
    for (int i = 0; i < m_moveHistory.size(); i++) {
        const Move& move = m_moveHistory[i];
        if (move.getPieceMoved() == 'K' && move.wasWhite() == isWhite) {
            return true;  //king has moved before
        }
    }
    return false;  //king never moved
}

bool Board::hasRookMoved(bool isWhite, bool isKingside) const {
    // rookCol: 0 = queenside (a-file), 7 = kingside (h-file)
    int rookRow = isWhite ? 0 : 7;
    int rookCol = isKingside ? 7 : 0; // Kingside = h-file (7), Queenside = a-file (0)

    for (int i = 0; i < m_moveHistory.size(); i++) {
        const Move& move = m_moveHistory[i];
        if (move.getPieceMoved() == 'R' && move.wasWhite() == isWhite) {
            if (move.getFromRow() == rookRow && move.getFromCol() == rookCol) {
                return true;  //this specific rook has moved
            }
        }
    }
	return false; //rook hasn't moved
}

bool Board::undoLastMove(bool checkPlayerOwnership) {
    if (m_moveHistory.isEmpty()) {
        cout << "        No moves to undo!" << endl;
        return false;
    }

    //pop the last move
    Move lastMove = m_moveHistory.pop();

    //if checking ownership, verify it's the current player's last move
    if (checkPlayerOwnership) {
        bool currentPlayerIsWhite = !m_whiteTurn; //turn has already switched
        if (lastMove.wasWhite() != currentPlayerIsWhite) {
            //put move back if undo is illegal
            m_moveHistory.push(lastMove);
            cout << "        You can only undo your own move!" << endl;
            return false;
        }
    }

    int fromRow = lastMove.getFromRow();
    int fromCol = lastMove.getFromCol();
    int toRow = lastMove.getToRow();
    int toCol = lastMove.getToCol();
    char pieceMoved = lastMove.getPieceMoved();
    bool wasWhite = lastMove.wasWhite();
    char capturedType = lastMove.getPieceCaptured();

    Square* from = getSquare(fromRow, fromCol);
    Square* to = getSquare(toRow, toCol);

    //handle castling undo
    if (lastMove.isCastling()) {
        int row = wasWhite ? 0 : 7;
        bool isKingside = (toCol > fromCol);

        if (isKingside) {
            Piece* king = getSquare(row, 6)->getPiece();
            Piece* rook = getSquare(row, 5)->getPiece();

            getSquare(row, 4)->setPiece(king);
            getSquare(row, 6)->clearPiece();
            king->setPosition(row, 4);

            getSquare(row, 7)->setPiece(rook);
            getSquare(row, 5)->clearPiece();
            rook->setPosition(row, 7);
        }
        else {
            Piece* king = getSquare(row, 2)->getPiece();
            Piece* rook = getSquare(row, 3)->getPiece();

            getSquare(row, 4)->setPiece(king);
            getSquare(row, 2)->clearPiece();
            king->setPosition(row, 4);

            getSquare(row, 0)->setPiece(rook);
            getSquare(row, 3)->clearPiece();
            rook->setPosition(row, 0);
        }

        //switch turn back
        m_whiteTurn = !m_whiteTurn;

        //restore half-move clock
        if (!m_halfMoveClockHistory.isEmpty()) m_halfMoveClock = m_halfMoveClockHistory.pop();

        //remove position hash
        if (m_hashCount > 0) m_hashCount--;
        return true;
    }

    //handle pawn promotion undo
    if (lastMove.isPawnPromotion()) {
        Piece* promotedPiece = to->getPiece();
        removePieceFromArray(promotedPiece);
        delete promotedPiece;

        Piece* pawn = new Pawn(wasWhite, toRow, toCol);
        m_pieces[m_pieceCount] = pawn;
        m_pieceCount++;
        to->setPiece(pawn);

        from->setPiece(pawn);
        to->clearPiece();
        pawn->setPosition(fromRow, fromCol);
    }
    //regular move undo
    else {
        Piece* piece = to->getPiece();
        from->setPiece(piece);
        to->clearPiece();
        piece->setPosition(fromRow, fromCol);
    }

    //restore captured piece
    if (lastMove.wasCapture()) {
        int captureRow = toRow;
        int captureCol = toCol;

        if (lastMove.isEnPassant()) {
            captureRow = fromRow;
        }

        Piece* captured = nullptr;

        switch (capturedType) {
        case 'P': captured = new Pawn(!wasWhite, captureRow, captureCol); break;
        case 'R': captured = new Rook(!wasWhite, captureRow, captureCol); break;
        case 'N': captured = new Knight(!wasWhite, captureRow, captureCol); break;
        case 'B': captured = new Bishop(!wasWhite, captureRow, captureCol); break;
        case 'Q': captured = new Queen(!wasWhite, captureRow, captureCol); break;
        case 'K': captured = new King(!wasWhite, captureRow, captureCol); break;
        }

        if (captured) {
            m_pieces[m_pieceCount++] = captured;
            getSquare(captureRow, captureCol)->setPiece(captured);
        }
    }

    //switch turn back
    m_whiteTurn = !m_whiteTurn;

    //restore half-move clock
    if (!m_halfMoveClockHistory.isEmpty()) m_halfMoveClock = m_halfMoveClockHistory.pop();

    //remove position hash
    if (m_hashCount > 0) m_hashCount--;
    return true;
}
#include "gameflow.h"

void GameFlow::gameLoop() {
    Board* board = new Board();
    clearScreen();
    board->displayBoard();

    string fromPos = "";
    bool offerDraw = false;
    while (true) {
        bool currentPlayerIsWhite = board->isWhiteTurn(); //track current player

        //check for game over conditions
        if (board->isCheckmate(currentPlayerIsWhite)) {
            cout << "\n        +------------------------------+" << endl;
            cout << "        |          CHECKMATE!          |" << endl;
            cout << "        |  " << (currentPlayerIsWhite ? "   Black" : "   White") << " wins the game!     |" << endl;
            cout << "        +------------------------------+" << endl;
            break;
        }

        if (board->isStalemate(currentPlayerIsWhite)) {
            cout << "\n        +------------------------+" << endl;
            cout << "        |       STALEMATE!       |" << endl;
            cout << "        |     Game is drawn!     |" << endl;
            cout << "        +------------------------+" << endl;
            break;
        }

        //check for 50-move rule draw
        if (board->isFiftyMoveDraw()) {
            cout << "\n        +------------------------------------+" << endl;
            cout << "        |        DRAW - 50 MOVE RULE!        |" << endl;
            cout << "        |     No capture or pawn move in     |" << endl;
            cout << "        |             50 moves!              |" << endl;
            cout << "        +------------------------------------+" << endl;
            break;
        }

        //check for threefold repetition
        if (board->isThreefoldRepetition()) {
            cout << "\n        +----------------------------------------+" << endl;
            cout << "        |      DRAW - THREEFOLD REPETITION!      |" << endl;
            cout << "        |     Same position occurred 3 times     |" << endl;
            cout << "        +----------------------------------------+" << endl;
            break;
        }

        //check for insufficient material
        if (board->isInsufficientMaterial()) {
            cout << "\n        +---------------------------------------+" << endl;
            cout << "        |     DRAW - INSUFFICIENT MATERIAL!     |" << endl;
            cout << "        |      Neither side can checkmate       |" << endl;
            cout << "        +---------------------------------------+" << endl;
            break;
        }

        //display check warning
        if (board->isKingInCheck(currentPlayerIsWhite)) {
            cout << "\n        WARNING: " << (currentPlayerIsWhite ? "White" : "Black") << " King is in CHECK! \n" << endl;
        }

        cout << "\n" << (currentPlayerIsWhite ? "        White" : "        Black") << "'s turn" << endl;

        if (fromPos == "") {
            //show draw offer 
            if (offerDraw) {
                cout << "\n        >>> " << (currentPlayerIsWhite ? "Black" : "White") << " offers a DRAW! <<<" << endl;
                cout << "        Accept draw? (y/n): ";
                char response;
                cin >> response;
                cin.ignore();

                if (response == 'y' || response == 'Y') {
                    cout << "\n        +--------------------------------+" << endl;
                    cout << "        |      DRAW - BY AGREEMENT!      |" << endl;
                    cout << "        |     Players agreed to draw     |" << endl;
                    cout << "        +--------------------------------+" << endl;
                    break;
                }
                else {
                    cout << "        Draw offer declined. Game continues." << endl;
                    offerDraw = false;
                }
            }

            cout << "        Select piece (e.g., e2), 'draw', or 'quit': ";
            getline(cin, fromPos);

            if (fromPos == "quit") break;



            //offer draw
            if (fromPos == "draw") {
                offerDraw = true;
                fromPos = "";
                continue;
            }

            //validate format
            if (fromPos.length() < 2) {
                cout << "        Invalid format! Use format: e2" << endl;
                fromPos = "";
                continue;
            }

            int fromCol = fromPos[0] - 'a';
            int fromRow = fromPos[1] - '1';

            if (fromCol < 0 || fromCol > 7 || fromRow < 0 || fromRow > 7) {
                cout << "        Invalid coordinates! Use a-h and 1-8->" << endl;
                fromPos = "";
                continue;
            }

            Square* sq = board->getSquare(fromRow, fromCol);
            if (!sq || sq->isEmpty()) {
                cout << "        No piece at that position!" << endl;
                fromPos = "";
                continue;
            }

            if (sq->getPiece()->isWhite() != currentPlayerIsWhite) {
                cout << "        That's not your piece!" << endl;
                fromPos = "";
                continue;
            }

            cout << "        Selected: " << fromPos << endl;
            continue;
        }

        cout << "        Move to (e.g., e4) or 'cancel': ";
        string toPos;
        getline(cin, toPos);

        if (toPos == "cancel") {
            cout << "        Move cancelled." << endl;
            fromPos = "";
            continue;
        }

        if (toPos.length() < 2) {
            cout << "        Invalid format!" << endl;
            continue;
        }

        int fromCol = fromPos[0] - 'a';
        int fromRow = fromPos[1] - '1';

        int toCol = toPos[0] - 'a';
        int toRow = toPos[1] - '1';

        if (toCol < 0 || toCol > 7 || toRow < 0 || toRow > 7) {
            cout << "        Invalid coordinates!" << endl;
            continue;
        }

        if (board->movePiece(fromRow, fromCol, toRow, toCol)) {
            clearScreen();
            board->displayBoard();

            //clear draw offer after successful move
            offerDraw = false;

            cout << "\n        Move successful: " << fromPos << " to " << toPos << endl;

            //check if opponent is in check after this move
            if (board->isKingInCheck(!currentPlayerIsWhite)) {
                cout << "        CHECK! " << (!currentPlayerIsWhite ? "White" : "Black") << " King is under attack! " << endl;
            }

            if (board->isCheckmate(!currentPlayerIsWhite) || board->isStalemate(!currentPlayerIsWhite) || board->isFiftyMoveDraw() || board->isInsufficientMaterial() || board->isThreefoldRepetition()) {
                fromPos = "";
                continue;
            }

            //undo last move option
            cout << "\n        Do you want to UNDO this move? (y/n): ";
            char undoResponse;
            cin >> undoResponse;
            cin.ignore();

            if (undoResponse == 'y' || undoResponse == 'Y') {
                //undo the move
                if (board->undoLastMove(false)) {
                    clearScreen();
                    board->displayBoard();
                    cout << "\n        Move has been undone!" << endl;
                }
            }
            fromPos = "";

        }
        else {
            //invalid move
            cout << "        Invalid move! ";
            if (board->isKingInCheck(currentPlayerIsWhite)) {
                cout << "         must move out of check!" << endl;
            }
            else cout << "        Try again." << endl;
        }

    }
    delete board;
}
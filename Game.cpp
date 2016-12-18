//
// Created by konzy on 12/17/2016.
//

#include "Game.h"
#include "AI.h"
#include "MinMaxNode.h"

Game::Game(const vector<char> &board, int currentPlayer) : board(board), currentPlayer(currentPlayer) {}

const int Game::checkWin() const {
    if ((board[0] == board[1] && board[1] == board[2]) ||
        (board[3] == board[4] && board[4] == board[5]) ||
        (board[6] == board[7] && board[7] == board[8]) ||
        (board[0] == board[3] && board[3] == board[6]) ||
        (board[1] == board[4] && board[4] == board[7]) ||
        (board[2] == board[5] && board[5] == board[8]) ||
        (board[0] == board[4] && board[4] == board[8]) ||
        (board[2] == board[4] && board[4] == board[6])) {
        return WIN;
    }

    else if (board[0] != '1' && board[1] != '2' && board[2] != '3'&&
             board[3] != '4' && board[4] != '5' && board[5] != '6'&&
             board[6] != '7' && board[7] != '8' && board[8] != '9') {
        return DRAW;
    }

    return CONTINUE;
}

void Game::drawBoard() {
    cout << endl << endl << " Get Ready to Play Tic Tac Toe " << endl << endl;

    cout << "Player 1 (X)  -  Player 2 (O)" << endl << endl;

    cout << "       |       |       " << endl;

    cout << "      " << board[0] << "|      " << board[1] << "|     " << board[2] << endl;

    cout << "_______|_______|________" << endl;
    cout << "       |       |        " << endl;

    cout << "      " << board[3] << "|      " << board[4] << "|     " << board[5] << endl;

    cout << "_______|_______|________" << endl;
    cout << "       |       |        " << endl;

    cout << "      " << board[6] << "|      " << board[7] << "|     " << board[8] << endl;

    cout << "       |       |        " << endl << endl;
}

void Game::runGame() {

    do {
        int boxNumber;
        drawBoard();
        do{
            cout << "Player" << currentPlayer << ", enter a number to mark_x_o: ";
            cin >> boxNumber;
        } while(!isValidMove(boxNumber));
        board[boxNumber - 1] = 'X';

        MinMaxNode minMaxNode(*this);
        minMaxNode.getValue();
        int cpuMove = minMaxNode.bestMove();

        board[cpuMove] = 'O';

    }while (checkWin() == CONTINUE);

    drawBoard();

    if (checkWin() == WIN)
        cout << "~~~Player " << --currentPlayer << "Won";
    else
        cout << "~~~Game Draw!";

    cin.ignore();
    cin.get();
}

bool Game::isValidMove(int move) {
    return board[move - 1] != 'O' && board[move - 1] != 'X';
}

void Game::changePlayers() {
    currentPlayer = currentPlayer % 2 ? 2 : 1;
}

//int Game::aiMove() {
//    AI ai();
//    return ai.minimax();
//
//}

char Game::currentPlayerSymbol() {
    return currentPlayer == 1 ? 'X' : 'O';
}

const vector<char> &Game::getBoard() const {
    return board;
}

int Game::getCurrentPlayer() const {
    return currentPlayer;
}

int Game::aiMove() {
    return 0;
}

Game::Game(const Game &rhs) {
    if (this != &rhs) {
        this->board = rhs.board;
        this->currentPlayer = rhs.currentPlayer;
    }
}

void Game::setBoard(const vector<char> &board) {
    Game::board = board;
}

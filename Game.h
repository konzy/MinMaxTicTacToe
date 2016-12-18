//
// Created by konzy on 12/17/2016.
//

#ifndef KONZMANB1FINALPROJECT_GAME_H
#define KONZMANB1FINALPROJECT_GAME_H

#define WIN 1
#define DRAW 0
#define CONTINUE -1

#define HUMAN 1
#define CPU 2

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Game {
private:
    vector<char> board;
    int currentPlayer;
public:
    Game(const vector<char> &board, int currentPlayer);
    Game(const Game &rhs);
    const int checkWin() const;
    void drawBoard();
    void runGame();
    bool isValidMove(int);
    void changePlayers();
    char currentPlayerSymbol();
    void setBoard(const vector<char> &board);
    const vector<char> &getBoard() const;
    int getCurrentPlayer() const;
};


#endif //KONZMANB1FINALPROJECT_GAME_H

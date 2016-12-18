/*
 * Simple Tic Tac Toe Game.
 * Compile : g++ TicTacToe.cpp
 * Run : ./a.out
 * taken originally from https://github.com/tapasweni-pathak/Games/blob/master/TicTacToe.cpp
 *
 * Modified to use minimax ai
 */

#include <iostream>
#include "AI.h"
#include "Game.h"
using namespace std;

vector<char> board = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main()
{
	Game game(board, 1);
    game.runGame();
	return 0;
}


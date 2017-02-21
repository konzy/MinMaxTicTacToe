//
// Created by konzy on 12/18/2016.
//

#include "MinMaxNode.h"

MinMaxNode::MinMaxNode(const Game &gameBoard, MinMaxNode *parent, int move) : gameBoard(gameBoard), parent(parent), move(move) {

    if (gameBoard.getCurrentPlayer() == HUMAN) {
        value = 1000;
    } else {
        value = -1000;
    }

    createTree(gameBoard);
}

void MinMaxNode::createTree(Game gameBoard) {
    //Tree creation
    if (gameBoard.checkWin() == CONTINUE) {

        for (int move = 0; move < 9; ++move) {
            Game tempBoard(gameBoard);
            tempBoard.changePlayers();
            char currentBoxValue = gameBoard.getBoard()[move];
            if (currentBoxValue != 'X' && currentBoxValue != 'O') {
                vector<char> tempCharBoard = tempBoard.getBoard();
                tempCharBoard[move] = tempBoard.currentPlayerSymbol();
                tempBoard.setBoard(tempCharBoard);
                MinMaxNode node(tempBoard, this, move);
                possibleMoves.push_back(node);
            }
        }

        if (gameBoard.getCurrentPlayer() == CPU) {
            for (auto it = begin(possibleMoves); it < end(possibleMoves); ++it) {
                value = max(it.base()->value - 1, value);
            }
        } else {
            for (auto it = begin(possibleMoves); it < end(possibleMoves); ++it) {
                value = min(it.base()->value + 1, value);
            }
        }
    } else { // WIN, LOSE, or DRAW -- we are at the leaf node
        if (gameBoard.getCurrentPlayer() == CPU) {
            value = gameBoard.checkWin() * 10;
        } else {
            value = -gameBoard.checkWin() * 10;
        }
    }

}

int MinMaxNode::bestMove() {
    int result = -1000;
    int bestValue = -1000;
    for (auto it = begin(possibleMoves); it < end(possibleMoves); ++it) {
        if (it.base()->value > bestValue) {
            result = it.base()->move;
            bestValue = it.base()->value;
        }
    }
    return result;
}

int MinMaxNode::getValue() const {
    return value;
}

MinMaxNode::MinMaxNode(const Game &gameBoard) : gameBoard(gameBoard) {
    createTree(gameBoard);
}





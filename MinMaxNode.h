//
// Created by konzy on 12/18/2016.
//

#ifndef KONZMANB1FINALPROJECT_MINMAXNODE_H
#define KONZMANB1FINALPROJECT_MINMAXNODE_H
#include <vector>
#include "Game.h"

using namespace std;

class MinMaxNode {
    private:
    vector<MinMaxNode> possibleMoves;
    Game gameBoard;
    int value = 0;
    MinMaxNode *parent;
    int move;
public:
    int getValue() const;

    void setValue(int value);

public:
    MinMaxNode(const Game &gameBoard, MinMaxNode *parent, int move);

    MinMaxNode(const Game &gameBoard);

    void createTree(Game gameBoard);

    int bestMove();
};


#endif //KONZMANB1FINALPROJECT_MINMAXNODE_H

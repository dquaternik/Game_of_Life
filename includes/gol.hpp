#ifndef h_GOL_h
#define h_GOL_h

#include "cells.hpp"

#include <vector>

class GolBoard
{
private:
    Board board;
    BoardPos alive;
    BoardPos nextAlive;
    unsigned int maxX;
    unsigned int maxY;

public:
    void readInput();
    void updateBoard();
    void printOutput();

private:
    int getIndex( int x, int y );
    void checkNeighbors( BoardPos pos, bool enable );
    void updateCells();
};

#endif
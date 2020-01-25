#ifndef h_GOL_h
#define h_GOL_h

#include "cells.hpp"

#include <vector>

class GolBoard
{
private:
    std::vector< Cell > board;
    std::vector< CellPos > alive;
    std::vector< CellPos > nextAlive;
    unsigned int maxX;
    unsigned int maxY;

public:
    void readInput();
    void updateBoard();
    void printOutput();

private:
    int getIndex( int x, int y );
    void checkNeighbors( std::vector< CellPos > pos, bool enable );
    void updateCells();
};

#endif
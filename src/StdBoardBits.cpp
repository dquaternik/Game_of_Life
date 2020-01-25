#include "StdBoardBits.hpp"

#include "cells.hpp"

void BoardBit::fixPosIndex( int buffer, int maxX, BoardPosList* posList )
{
    for(auto it = posList->begin(); it != posList->end(); it++ )
    {
        // fix position
        it->posX = it->posX + buffer;
        it->posY = it->posY + buffer;
        it->index = it->posY*maxX + it->posX; // fix the index based on buffer
    }
}

Board StdBoardBits::setupBitBoard( BoardPosList liveList, int minx, int miny )
{
    Board board( minx*miny );

    for( auto it = liveList.begin(); it != liveList.end(); ++it )
    {
        board[it->index].live = true;
    }

    return board;
}

BoardBit StdBoardBits::StillLife::block()
{
    StdBoardBits stdBrdBits;
    BoardBit out( 2, 2, 4 );

    CellPos one( 0, 0, 0 );
    CellPos two( 0, 1, 1 );
    CellPos three( 1, 0, 2 );
    CellPos four( 1, 1, 3 );
    out.bitPosLiveList.push_back( one );
    out.bitPosLiveList.push_back( two );
    out.bitPosLiveList.push_back( three );
    out.bitPosLiveList.push_back( four );

    out.bitBoard = stdBrdBits.setupBitBoard( out.bitPosLiveList, 2, 2 );

    return out;
}
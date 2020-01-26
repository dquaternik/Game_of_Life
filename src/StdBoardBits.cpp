#include "StdBoardBits.hpp"

#include "cells.hpp"

void BoardBit::fixPosIndex( int xbuffer, int ybuffer, int maxX, BoardPosList* posList )
{
    for(auto it = posList->begin(); it != posList->end(); it++ )
    {
        // fix position
        it->posX = it->posX + xbuffer;
        it->posY = it->posY + ybuffer;
        it->index = it->posY*maxX + it->posX; // fix the index based on buffer
    }
}

Board StdBoardBits::setupBoard( BoardPosList liveList, int minx, int miny )
{
    Board board;
    board.resize( minx*miny );

    for( auto it = liveList.begin(); it != liveList.end(); ++it )
    {
        board[it->index].live = true;
    }

    return board;
}

BoardBit StdBoardBits::StillLife::block()
{

    /*
        x x
        x x
    */
    StdBoardBits stdBrdBits;
    BoardBit block( 2, 2, 4 );

    block.bitPosLiveList.push_back( CellPos( 0, 0, 0 ) );
    block.bitPosLiveList.push_back( CellPos( 0, 1, 1 ) );
    block.bitPosLiveList.push_back( CellPos( 1, 0, 2 ) );
    block.bitPosLiveList.push_back( CellPos( 1, 1, 3 ) );

    block.bitBoard = stdBrdBits.setupBoard( block.bitPosLiveList, 2, 2 );

    return block;
}

BoardBit StdBoardBits::StillLife::beehive()
{
    /*
        . x x .
        x . . x
        . x x . 
    */
    StdBoardBits stdBrdBits;
    BoardBit beehive( 4, 3, 12 );

    beehive.bitPosLiveList.push_back( CellPos( 0, 1, 1 ) );
    beehive.bitPosLiveList.push_back( CellPos( 1, 0, 4 ) );
    beehive.bitPosLiveList.push_back( CellPos( 1, 2, 6 ) );
    beehive.bitPosLiveList.push_back( CellPos( 2, 0, 7 ) );
    beehive.bitPosLiveList.push_back( CellPos( 2, 2, 9 ) );
    beehive.bitPosLiveList.push_back( CellPos( 3, 1, 11 ) );

    beehive.bitBoard = stdBrdBits.setupBoard( beehive.bitPosLiveList, 4, 3 );

    return beehive;
}

BoardBit StdBoardBits::StillLife::loaf()
{
    /*
    . x x . 
    x . . x
    . x . x
    . . x .
    */
    StdBoardBits stdBrdBits;
    BoardBit loaf( 4, 4, 16 );

    loaf.bitPosLiveList.push_back( CellPos( 1, 0, 1 ) );
    loaf.bitPosLiveList.push_back( CellPos( 2, 0, 2 ) );
    loaf.bitPosLiveList.push_back( CellPos( 0, 1, 4 ) );
    loaf.bitPosLiveList.push_back( CellPos( 3, 1, 7 ) );
    loaf.bitPosLiveList.push_back( CellPos( 1, 2, 9 ) );
    loaf.bitPosLiveList.push_back( CellPos( 3, 2, 11 ) );
    loaf.bitPosLiveList.push_back( CellPos( 2, 3, 14 ) );

    loaf.bitBoard = stdBrdBits.setupBoard( loaf.bitPosLiveList, 4, 4 );

    return loaf;
}

BoardBit StdBoardBits::StillLife::boat()
{
    /*
    x x . 
    x . x 
    . x . 
    */
    StdBoardBits stdBrdBits;
    BoardBit boat( 3, 3, 9 );

    boat.bitPosLiveList.push_back( CellPos( 0, 0, 0 ) );
    boat.bitPosLiveList.push_back( CellPos( 1, 0, 1 ) );
    boat.bitPosLiveList.push_back( CellPos( 0, 1, 3 ) );
    boat.bitPosLiveList.push_back( CellPos( 2, 1, 5 ) );
    boat.bitPosLiveList.push_back( CellPos( 1, 2, 7 ) );

    boat.bitBoard = stdBrdBits.setupBoard( boat.bitPosLiveList, 3, 3 );

    return boat;
}

BoardBit StdBoardBits::StillLife::tub()
{
    /*
    . x . 
    x . x 
    . x . 
    */
    StdBoardBits stdBrdBits;
    BoardBit tub( 3, 3, 9 );

    tub.bitPosLiveList.push_back( CellPos( 1, 0, 1 ) );
    tub.bitPosLiveList.push_back( CellPos( 0, 1, 3 ) );
    tub.bitPosLiveList.push_back( CellPos( 2, 1, 5 ) );
    tub.bitPosLiveList.push_back( CellPos( 1, 2, 7 ) );

    tub.bitBoard = stdBrdBits.setupBoard( tub.bitPosLiveList, 3, 3 );

    return tub;
}

BoardBit StdBoardBits::Oscillators::blinker()
{
    /*
    . x .
    . x . 
    . x . 
    */
    StdBoardBits stdBrdBits;
    BoardBit blinker( 3, 3, 9 );

    blinker.bitPosLiveList.push_back( CellPos( 1, 0, 1 ) );
    blinker.bitPosLiveList.push_back( CellPos( 1, 1, 4 ) );
    blinker.bitPosLiveList.push_back( CellPos( 1, 2, 7 ) );

    blinker.bitBoard = stdBrdBits.setupBoard( blinker.bitPosLiveList, 3, 3 );

    return blinker;
}

BoardBit StdBoardBits::Oscillators::toad()
{
    /*
    . . x . 
    x . . x 
    x . . x 
    . x . . 
    */
    StdBoardBits stdBrdBits;
    BoardBit toad( 4, 4, 16 );

    toad.bitPosLiveList.push_back( CellPos( 2, 0, 2 ) );
    toad.bitPosLiveList.push_back( CellPos( 0, 1, 4 ) );
    toad.bitPosLiveList.push_back( CellPos( 3, 1, 7 ) );
    toad.bitPosLiveList.push_back( CellPos( 0, 2, 8 ) );
    toad.bitPosLiveList.push_back( CellPos( 3, 2, 11 ) );
    toad.bitPosLiveList.push_back( CellPos( 1, 3, 13 ) );

    toad.bitBoard = stdBrdBits.setupBoard( toad.bitPosLiveList, 4, 4 );

    return toad;
}

BoardBit StdBoardBits::Oscillators::beacon()
{
    /*
    x x . . 
    x . . . 
    . . . x 
    . . x x 
    */
    StdBoardBits stdBrdBits;
    BoardBit beacon( 4, 4, 16 );

    beacon.bitPosLiveList.push_back( CellPos( 0, 0, 0 ) );
    beacon.bitPosLiveList.push_back( CellPos( 1, 0, 1 ) );
    beacon.bitPosLiveList.push_back( CellPos( 0, 1, 4 ) );
    beacon.bitPosLiveList.push_back( CellPos( 3, 2, 11 ) );
    beacon.bitPosLiveList.push_back( CellPos( 2, 3, 14 ) );
    beacon.bitPosLiveList.push_back( CellPos( 3, 3, 15 ) );

    beacon.bitBoard = stdBrdBits.setupBoard( beacon.bitPosLiveList, 4, 4 );

    return beacon;

}

BoardBit StdBoardBits::Oscillators::pulsar()
{
    /* Needs at least one buffer
     x
     0 1 2 3 4 5 6 7 8 9 101112
 y0  . . x x x . . . x x x . . 
  1  . . . . . . . . . . . . . 
  2  x . . . . x . x . . . . x 
  3  x . . . . x . x . . . . x  
  4  x . . . . x . x . . . . x
  5  . . x x x . . . x x x . .
  6  . . . . . . . . . . . . . 
  7  . . x x x . . . x x x . .
  8  x . . . . x . x . . . . x 
  9  x . . . . x . x . . . . x  
  0  x . . . . x . x . . . . x
  1  . . . . . . . . . . . . . 
  2  . . x x x . . . x x x . .
    */
    StdBoardBits stdBrdBits;
    BoardBit pulsar( 13, 13, 169 );

    // upper left
    pulsar.bitPosLiveList.push_back( CellPos( 2, 0, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 3, 0, 3 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 4, 0, 4 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 0, 2, 26 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 5, 2, 31 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 0, 3, 39 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 5, 3, 44 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 0, 4, 52 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 5, 4, 57 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 2, 5, 67 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 3, 5, 68 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 4, 5, 69 ) );

    // upper right
    pulsar.bitPosLiveList.push_back( CellPos( 8, 0, 8 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 9, 0, 9 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 10, 0, 10 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 7, 2, 33 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 12, 2, 38 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 7, 3, 46 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 12, 3, 51 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 7, 4, 59 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 12, 4, 64 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 8, 5, 73 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 9, 5, 74 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 10, 5, 75 ) );

    // lower left
    pulsar.bitPosLiveList.push_back( CellPos( 2, 7, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 3, 7, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 4, 7, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 0, 9, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 5, 9, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 0, 10, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 5, 10, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 0, 11, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 5, 11, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 2, 12, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 3, 12, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 4, 12, 2 ) );

    // lower right
    pulsar.bitPosLiveList.push_back( CellPos( 8, 7, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 9, 7, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 10, 7, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 7, 9, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 12, 9, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 7, 10, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 12, 10, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 7, 11, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 12, 11, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 8, 12, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 9, 12, 2 ) );
    pulsar.bitPosLiveList.push_back( CellPos( 10, 12, 2 ) );   

    pulsar.bitBoard = stdBrdBits.setupBoard( pulsar.bitPosLiveList, 13, 13 );

    return pulsar;
}

BoardBit StdBoardBits::Oscillators::pentadecathalon()
{
    /* Lots of buffer needed
    . . x . . . . x . . 
    x x . x x x x . x x 
    . . x . . . . x . . 
    */
    StdBoardBits stdBrdBits;
    BoardBit pentadecathalon( 10, 3, 30 );

    pentadecathalon.bitPosLiveList.push_back( CellPos( 2, 0, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 7, 0, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 0, 1, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 1, 1, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 3, 1, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 4, 1, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 5, 1, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 6, 1, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 8, 1, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 9, 1, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 2, 2, 2 ) );
    pentadecathalon.bitPosLiveList.push_back( CellPos( 7, 2, 2 ) );

    pentadecathalon.bitBoard = stdBrdBits.setupBoard( pentadecathalon.bitPosLiveList, 10, 3 );

    return pentadecathalon;
    
}

BoardBit StdBoardBits::Spaceships::glider()
{
    StdBoardBits stdBrdBits;
    BoardBit glider( 4, 4, 16 );

    return glider;
}

BoardBit StdBoardBits::Spaceships::lwss()
{
    StdBoardBits stdBrdBits;
    BoardBit lwss( 4, 4, 16 );

    return lwss;
}

BoardBit StdBoardBits::Spaceships::mwss()
{
    StdBoardBits stdBrdBits;
    BoardBit mwss( 4, 4, 16 );

    return mwss;
}

BoardBit StdBoardBits::Spaceships::hwss()
{
    StdBoardBits stdBrdBits;
    BoardBit hwss( 4, 4, 16 );

    return hwss;
}

BoardBit StdBoardBits::Methuselahs::rpent()
{
    StdBoardBits stdBrdBits;
    BoardBit rpent( 4, 4, 16 );

    return rpent;
}

BoardBit StdBoardBits::Methuselahs::diehard()
{
    StdBoardBits stdBrdBits;
    BoardBit diehard( 4, 4, 16 );

    return diehard;
}

BoardBit StdBoardBits::Methuselahs::acorn()
{
    StdBoardBits stdBrdBits;
    BoardBit acorn( 4, 4, 16 );

    return acorn;
}

BoardBit StdBoardBits::GliderGun::gosper()
{
    StdBoardBits stdBrdBits;
    BoardBit gosper( 4, 4, 16 );

    return gosper;
}

BoardBit StdBoardBits::GliderGun::simkin()
{
    StdBoardBits stdBrdBits;
    BoardBit simkin( 4, 4, 16 );

    return simkin;
}

BoardBit StdBoardBits::InfiniteGrowth::ten_cell()
{
    StdBoardBits stdBrdBits;
    BoardBit ten_cell( 4, 4, 16 );

    return ten_cell;
}

BoardBit StdBoardBits::InfiniteGrowth::five_by_five()
{
    StdBoardBits stdBrdBits;
    BoardBit five_by_five( 4, 4, 16 );

    return five_by_five;
}

BoardBit StdBoardBits::InfiniteGrowth::one_high()
{
    StdBoardBits stdBrdBits;
    BoardBit one_high( 4, 4, 16 );

    return one_high;
}
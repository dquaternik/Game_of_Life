#include "StdBoardBits.hpp"

#include "cells.hpp"

#include <string>

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

void StdBoardBits::setupBoard( std::string input, BoardBit* out, int xmin, int ymin )
{   
    out->bitBoard.resize( xmin*ymin );
    int count = 0;

    for( std::string::iterator it = input.begin(); it != input.end(); ++it )
    {
        if( *it == 'x')
        {
            out->bitBoard[count].live = true;
            out->bitPosLiveList.push_back( CellPos( count%xmin, getPos(count, xmin), count ) );

            count++;
        }
        else if( *it == '.' )
        {
            out->bitBoard[count].live = false;
            count++;
        }
    }
}

BoardBit StdBoardBits::StillLife::block()
{
    /*
    x x 
    x x 
    */
    std::string input = "x x x x";
    StdBoardBits stdBrdBits;
    BoardBit out( 2, 2, 4 );

    stdBrdBits.setupBoard( input, &out, 2, 2 );

    return out;
}


BoardBit StdBoardBits::StillLife::beehive()
{
    /*
        . x x .
        x . . x
        . x x . 
    */
    std::string input = ". x x . x . . x . x x .";
    StdBoardBits stdBrdBits;
    BoardBit out( 4, 3, 12 );

    stdBrdBits.setupBoard( input, &out, 4, 3 );

    return out;
}

BoardBit StdBoardBits::StillLife::loaf()
{
    /*
    . x x . 
    x . . x
    . x . x
    . . x .
    */
    std::string input = ". x x . x . . x . x . x . . x .";
    StdBoardBits stdBrdBits;
    BoardBit out( 4, 4, 16 );

    stdBrdBits.setupBoard( input, &out, 4, 4 );

    return out;
}

BoardBit StdBoardBits::StillLife::boat()
{
    /*
    x x . 
    x . x 
    . x . 
    */
    std::string input = "x x . x . x . x . ";
    StdBoardBits stdBrdBits;
    BoardBit out( 3, 3, 9 );

    stdBrdBits.setupBoard( input, &out, 3, 3 );

    return out;
}

BoardBit StdBoardBits::StillLife::tub()
{
    /*
    . x . 
    x . x 
    . x . 
    */
    std::string input = ". x . x . x . x . ";
    StdBoardBits stdBrdBits;
    BoardBit out( 3, 3, 9 );

    stdBrdBits.setupBoard( input, &out, 3, 3 );

    return out;
}

BoardBit StdBoardBits::Oscillators::blinker()
{
    /*
    . x .
    . x . 
    . x . 
    */
    std::string input = ". x . . x . . x . ";    
    StdBoardBits stdBrdBits;
    BoardBit out( 3, 3, 9 );

    stdBrdBits.setupBoard( input, &out, 3, 3 );

    return out;
}

BoardBit StdBoardBits::Oscillators::toad()
{
    /*
    . . x . 
    x . . x 
    x . . x 
    . x . . 
    */
    std::string input = ". . x . x . . x x . . x . x . . ";    
    StdBoardBits stdBrdBits;
    BoardBit out( 4, 4, 16 );

    stdBrdBits.setupBoard( input, &out, 4, 4 );

    return out;
}

BoardBit StdBoardBits::Oscillators::beacon()
{
    /*
    x x . . 
    x . . . 
    . . . x 
    . . x x 
    */
    std::string input = "x x . . x . . . . . . x . . x x ";
    StdBoardBits stdBrdBits;
    BoardBit out( 4, 4, 16 );

    stdBrdBits.setupBoard( input, &out, 4, 4 );

    return out;

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
    std::string input = ". . x x x . . . x x x . . . . . . . . . . . . . . . x . . . . x . x . . . . x x . . . . x . x . . . . x x . . . . x . x . . . . x . . x x x . . . x x x . . . . . . . . . . . . . . . . . x x x . . . x x x . . x . . . . x . x . . . . x x . . . . x . x . . . . x x . . . . x . x . . . . x . . . . . . . . . . . . . . . x x x . . . x x x . . ";
    StdBoardBits stdBrdBits;
    BoardBit out( 13, 13, 169 ); 

    stdBrdBits.setupBoard( input, &out, 13, 13 );

    return out;
}

BoardBit StdBoardBits::Oscillators::pentadecathalon()
{
    /* Lots of buffer needed
    . . x . . . . x . . 
    x x . x x x x . x x 
    . . x . . . . x . . 
    */
    std::string input = ". . x . . . . x . . x x . x x x x . x x . . x . . . . x . . ";
    StdBoardBits stdBrdBits;
    BoardBit out( 10, 3, 30 );

    stdBrdBits.setupBoard( input, &out, 10, 3 );

    return out;
    
}

BoardBit StdBoardBits::Spaceships::glider()
{
    /*
    . . x
    x . x
    . x x
    */
    std::string input = ". . x x . x . x x";
    StdBoardBits stdBrdBits;
    BoardBit out( 3, 3, 9 );
    
    stdBrdBits.setupBoard( input, &out, 3, 3 );

    return out;
}

BoardBit StdBoardBits::Spaceships::lwss()
{
    /*
    . x . . x 
    x . . . . 
    x . . . x
    x x x x . 
    */
    std::string input = ". x . . x x . . . . x . . . x x x x x . ";    
    StdBoardBits stdBrdBits;
    BoardBit out( 5, 4, 20 );

    stdBrdBits.setupBoard( input, &out, 5, 4 );

    return out;
}

BoardBit StdBoardBits::Spaceships::mwss()
{
    /*
    . . . x . . 
    . x . . . x 
    x . . . . . 
    x . . . . x 
    x x x x x . 
    */
    std::string input = ". . . x . . . x . . . x x . . . . . x . . . . x x x x x x . ";
    StdBoardBits stdBrdBits;
    BoardBit out( 6, 5, 30 );

    stdBrdBits.setupBoard( input, &out, 6, 5 );

    return out;
}

BoardBit StdBoardBits::Spaceships::hwss()
{
    /*
    . . . x x . . 
    . x . . . . x
    x . . . . . . 
    x . . . . . x 
    x x x x x x . 
    */
    std::string input = ". . . x x . . . x . . . . x x . . . . . . x . . . . . x x x x x x x . ";
    StdBoardBits stdBrdBits;
    BoardBit out( 7, 5, 35 );

    stdBrdBits.setupBoard( input, &out, 7, 5 );

    return out;
}

BoardBit StdBoardBits::Methuselahs::rpent()
{
    /*
    . x x 
    x x . 
    . x . 
    */
    std::string input = ". x x x x . . x . ";
    StdBoardBits stdBrdBits;
    BoardBit out( 3, 3, 9 );

    stdBrdBits.setupBoard( input, &out, 3, 3 );

    return out;
}

BoardBit StdBoardBits::Methuselahs::diehard()
{
    /*
    . . . . . . x . 
    x x . . . . . . 
    . x . . . x x x 
    */
    std::string input = ". . . . . . x . x x . . . . . . . x . . . x x x ";
    StdBoardBits stdBrdBits;
    BoardBit out( 8, 3, 24 );

    stdBrdBits.setupBoard( input, &out, 8, 3 );

    return out;
}

BoardBit StdBoardBits::Methuselahs::acorn()
{
    /*
    . x . . . . . 
    . . . x . . . 
    x x . . x x x 
    */
    std::string input = ". x . . . . . . . . x . . . x x . . x x x ";
    StdBoardBits stdBrdBits;
    BoardBit out( 7, 3, 21 );

    stdBrdBits.setupBoard( input, &out, 7, 3 );

    return out;
}

BoardBit StdBoardBits::GliderGun::gosper()
{
    /*
     x
     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6
y0  . . . . . . . . . . . . . . . . . . . . . . . . . x . . . . . . . . . . . 
 1  . . . . . . . . . . . . . . . . . . . . . . . x . x . . . . . . . . . . . 
 2  . . . . . . . . . . . . . x x . . . . . . x x . . . . . . . . . . . x x . 
 3  . . . . . . . . . . . . x . . . x . . . . x x . . . . . . . . . . . x x . 
 4  . x x . . . . . . . . x . . . . . x . . . x x . . . . . . . . . . . . . . 
 5  . x x . . . . . . . . x . . . x . x x . . . . x . x . . . . . . . . . . . 
 6  . . . . . . . . . . . x . . . . . x . . . . . . . x . . . . . . . . . . . 
 7  . . . . . . . . . . . . x . . . x . . . . . . . . . . . . . . . . . . . . 
 8  . . . . . . . . . . . . . x x . . . . . . . . . . . . . . . . . . . . . . 
    */
    std::string input = ". . . . . . . . . . . . . . . . . . . . . . . . . x . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . x . x . . . . . . . . . . . . . . . . . . . . . . . . x x . . . . . . x x . . . . . . . . . . . x x . . . . . . . . . . . . . x . . . x . . . . x x . . . . . . . . . . . x x . . x x . . . . . . . . x . . . . . x . . . x x . . . . . . . . . . . . . . . x x . . . . . . . . x . . . x . x x . . . . x . x . . . . . . . . . . . . . . . . . . . . . . x . . . . . x . . . . . . . x . . . . . . . . . . . . . . . . . . . . . . . x . . . x . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . x x . . . . . . . . . . . . . . . . . . . . . . ";
    StdBoardBits stdBrdBits;
    BoardBit out( 37, 8, 296 );

    stdBrdBits.setupBoard( input, &out, 37, 8 );

    return out;
}

BoardBit StdBoardBits::GliderGun::simkin()
{
    /*
     x
     0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4 5 6 7 8 9 0 1 2 3 4
y0   . x x . . . . . x x . . . . . . . . . . . . . . . . . . . . . . . . .
 1   . x x . . . . . x x . . . . . . . . . . . . . . . . . . . . . . . . . 
 2   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
 3   . . . . . x x . . . . . . . . . . . . . . . . . . . . . . . . . . . .  
 4   . . . . . x x . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
 5   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
 6   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
 7   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
 8   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
 9   . . . . . . . . . . . . . . . . . . . . . . . x x . x x . . . . . . . 
10   . . . . . . . . . . . . . . . . . . . . . . x . . . . . x . . . . . .  
11   . . . . . . . . . . . . . . . . . . . . . . x . . . . . . x . . x x .
12   . . . . . . . . . . . . . . . . . . . . . . x x x . . . x . . . x x .
13   . . . . . . . . . . . . . . . . . . . . . . . . . . . x . . . . . . .
14   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
15   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
16   . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . 
17   . . . . . . . . . . . . . . . . . . . . . x x . . . . . . . . . . . .
18   . . . . . . . . . . . . . . . . . . . . . x . . . . . . . . . . . . . 
19   . . . . . . . . . . . . . . . . . . . . . . x x x . . . . . . . . . . 
20   . . . . . . . . . . . . . . . . . . . . . . . . x . . . . . . . . . .
    */
    std::string input = ". x x . . . . . x x . . . . . . . . . . . . . . . . . . . . . . . . .. x x . . . . . x x . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . x x . . . . . . . . . . . . . . . . . . . . . . . . . . . .  . . . . . x x . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . x x . x x . . . . . . . . . . . . . . . . . . . . . . . . . . . . . x . . . . . x . . . . . .  . . . . . . . . . . . . . . . . . . . . . . x . . . . . . x . . x x .. . . . . . . . . . . . . . . . . . . . . . x x x . . . x . . . x x .. . . . . . . . . . . . . . . . . . . . . . . . . . . x . . . . . . .. . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . x x . . . . . . . . . . . .. . . . . . . . . . . . . . . . . . . . . x . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . x x x . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . . x . . . . . . . . . . ";
    StdBoardBits stdBrdBits;
    BoardBit out( 35, 20, 700 );

    stdBrdBits.setupBoard( input, &out, 35, 20 );

    return out;
}

BoardBit StdBoardBits::InfiniteGrowth::ten_cell()
{
    /*
    . . . . . . x . 
    . . . . x . x x 
    . . . . x . x . 
    . . . . x . . . 
    . . . x . . . . 
    . x . x . . . . 
    */
    std::string input = ". . . . . . x . . . . . x . x x . . . . x . x . . . . . x . . . . . . x . . . . . x . x . . . . ";
    StdBoardBits stdBrdBits;
    BoardBit out( 8, 6, 48 );

    stdBrdBits.setupBoard( input, &out, 8, 6 );

    return out;
}

BoardBit StdBoardBits::InfiniteGrowth::five_by_five()
{
    /*
    x x x . x 
    x . . . . 
    . . . x x 
    . x x . x 
    x . x . x 
    */
    std::string input = "x x x . x x . . . . . . . x x . x x . x x . x . x ";
    StdBoardBits stdBrdBits;
    BoardBit out( 5, 5, 25 );

    stdBrdBits.setupBoard( input, &out, 5, 5 );

    return out;
}

BoardBit StdBoardBits::InfiniteGrowth::one_high()
{
    // x x x x x x x . x x x x x . . . x x x . . . . . . x x x x x x x . x x x x x 
    std::string input = "x x x x x x x . x x x x x . . . x x x . . . . . . x x x x x x x . x x x x x ";
    StdBoardBits stdBrdBits;
    BoardBit out( 39, 1, 39 );

    stdBrdBits.setupBoard( input, &out, 39, 1 );

    return out;
}
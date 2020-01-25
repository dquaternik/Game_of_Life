#ifndef h_STDBOARDBITS_h
#define h_STDBOARDBITS_h

#include "cells.hpp"

class BoardBit
{
public:
    BoardBit ();
    BoardBit( int minx = 0, int miny = 0, int size = 0 )
            : minx( minx )
            , miny( miny )
            , size( size )
            {};
    ~BoardBit() {};

    void fixPosIndex( int buffer, int maxX, BoardPosList* posList );

    Board bitBoard;
    BoardPosList bitPosLiveList;
    int minx;
    int miny;
    int size;
};

class StdBoardBits
{
public:

    Board setupBitBoard( BoardPosList liveList, int minx, int miny );
    

    class StillLife
    {
    public:
        BoardBit block();
        BoardBit beehive();
        BoardBit loaf();
        BoardBit board();
        BoardBit tub();
    };

    class Oscillators
    {
    public:
        BoardBit blinker();
        BoardBit toad();
        BoardBit beacon();
        BoardBit pulsar();
        BoardBit pentadecathalon();
    };

    class Spaceships
    {
    public:
        BoardBit glider();
        BoardBit lwss();
        BoardBit mwss();
        BoardBit hwss();
    };

    class Methuselahs
    {
    public:
        BoardBit rpent();
        BoardBit diehard();
        BoardBit acorn();
    };

    class GliderGun
    {
    public:
        BoardBit gosper();
        BoardBit simkin();
    };

    class InfiniteGrowth
    {
    public:
        BoardBit ten_cell();
        BoardBit five_by_five();
        BoardBit one_high();
    };
};

#endif
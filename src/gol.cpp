#include "gol.hpp"

#include "cells.hpp"
#include "StdBoardBits.hpp"

#include <iostream>
#include <fstream>
#include <string>

// Public
void GolBoard::readInputProt()
{
    StdBoardBits::StillLife stillLife;
    StdBoardBits::Spaceships spaceships;
    StdBoardBits::Oscillators oscillators;
    StdBoardBits::Methuselahs methuselas;
    StdBoardBits::InfiniteGrowth infGrowth;
    StdBoardBits::GliderGun guns;

    // reads from StdBoardBits library to create a board
    BoardBit bit = stillLife.block();
    int buffer = 2; 

    // setup board size based on minx of input + buffer
    maxX = buffer*2 + bit.minx;
    maxY = buffer*2 + bit.miny;

    // fix the index and resize board
    bit.fixPosIndex( buffer, maxX, &bit.bitPosLiveList );
    board.resize( maxX*maxY );

    for( auto it = bit.bitPosLiveList.begin(); it != bit.bitPosLiveList.end(); it++ )
    {
        board[it->index].live = true;
    }

    alive.insert( alive.end(), bit.bitPosLiveList.begin(), bit.bitPosLiveList.end() );
}

void GolBoard::readInput()
{
    // Takes a file in and reads the input into game board
    std::ifstream inputfile;
    std::string output;
    inputfile.open("conwayInput.txt", std::ios::in);
    
    if( !inputfile.is_open() )
    {
        std::cout << "Error bad file!" << std::endl;
        return;
    }

    int xcount = 0;
    int ycount = 0;
    maxX = 0;
    maxY = 0;

    // Read a line and parse through it
    while( std::getline(inputfile, output) )
    {
        for( auto i = output.begin(); i != output.end(); i++ )
        {
            if( *i == '.' )
            {
                Cell extra(false);
                board.push_back(extra); // create dead cell and push to board
                xcount++; // since the input has spaces, increment x only when a valid character found
            } 
            else if( *i == 'x' )
            {
                Cell extra(true);
                board.push_back(extra); // create a live cell and push to board
                CellPos extraPos( xcount, ycount, getIndex( xcount, ycount ) );
                alive.push_back( extraPos ); // add live cell location to list of cells to update
                xcount++;
            }
        }
        if( xcount > maxX ) maxX = xcount;
        xcount = 0;
        ycount++;
    }

    // once xcount finalized, update the index of the position list
    for( auto it = alive.begin(); it != alive.end(); ++it )
    {
        it->index = getIndex( it->posX, it->posY );
    }
    maxY = ycount;
}

void GolBoard::updateBoard()
{
    checkNeighbors( alive, true );
    updateCells();
}

void GolBoard::updateCells()
{
    // iterate through board and update entirety
    for( auto it = board.begin(); it != board.end(); it++ )
    {
        it->update();
    }

    alive.clear();
    alive = nextAlive;
    nextAlive.clear();
}

void GolBoard::printOutput()
{
    int count = 0;
    // iterate through the board and print to console
    for( auto i = board.begin(); i != board.end(); i++ )
    {
        if( i->live ) std::cout << "x ";
        else std::cout << ". ";
        count++;
        if( count == maxX )
        {
            count = 0;
            std::cout << std::endl;
        }

    }
    std::cout << std::endl;

}

// Private
int GolBoard::getIndex( int x, int y )
{
    // find index based on maxX
    return y*maxX+x;
}

// Searches through list of alive cells, checking the dead neighbors along the way to see if they will
// come to life. Only will check each cell once
void GolBoard::checkNeighbors( BoardPosList pos, bool enable )
{
    Cell *cut;
    int liveCount = 0;

    for(auto it = pos.begin(); it != pos.end(); it++ )
    {
        int cutIndex = it->index;
        int i = it->posY;
        int j = it->posX;
        BoardPosList deadPos;
        cut = &board[cutIndex];

        for( int k = -1; k < 2; k++ )
        {
            for( int l = -1; l < 2; l++ )
            {

                int index, truei, truej; 
                if( i == 0 && k == -1 ) truei = maxY-1;
                else if( i == maxY-1 && k == 1) truei = 0;
                else truei = i+k;

                if( j == 0 && l == -1 ) truej = maxX-1;
                else if( j == maxX-1 && l == 1) truej = 0;
                else truej = j+l;

                index = getIndex( truej, truei );
                if( board[index].live && cut != &board[index] ) liveCount++;
                else if( enable && !board[index].live && cut != &board[index] && !board[index].checked )
                {
                    board[index].checked = true;
                    CellPos extraPos( truej, truei, index );
                    deadPos.push_back( extraPos );
                }
            }
        }

        if( liveCount == 3 )
        {
            board[cutIndex].nextLive = true;
            CellPos extraPos( j, i, cutIndex );
            nextAlive.push_back( extraPos );
        }
        else if( liveCount < 2 || liveCount > 3 )
        {
            board[cutIndex].nextLive = false;
        }
        else
        {
            board[cutIndex].nextLive = board[cutIndex].live;
            if( board[cutIndex].live )
            {
                CellPos extraPos( j, i, cutIndex );
                nextAlive.push_back( extraPos );
            }
        }
        liveCount = 0;

        if( enable && deadPos.size() > 0 ) 
        {
            checkNeighbors( deadPos, false );
            deadPos.clear();
        }
    }
}
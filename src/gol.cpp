#include "gol.hpp"

#include <iostream>
#include <fstream>
#include <string>

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

    while( std::getline(inputfile, output) )
    {
        for( auto i = output.begin(); i != output.end(); i++ )
        {
            if( *i == '.' )
            {
                Cell extra(false);
                board.push_back(extra);
            } 
            else if( *i == 'x' )
            {
                Cell extra(true);
                board.push_back(extra);
                AlivePos extraPos( xcount, ycount );
                alive.push_back( extraPos );
            }
            xcount++;
        }
        if( xcount > maxX ) maxX = xcount/2;
        xcount = 0;
        ycount++;
    }
    maxY = ycount;
}

void GolBoard::updateBoard()
{
    Cell *cut;
    int liveCount = 0;
    int uk, dk, ll, rl;

    for(int i = 0; i < maxY; i++ )
    {
        for(int j = 0; j < maxX; j++ )
        {
            cut = &board[i*maxX+j];

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

                    index = (truei)*maxX+(truej);
                    if( board[index].isLive() && cut != &board[index] ) liveCount++;
                }
            }

            if( liveCount == 3 )
            {
                board[i*maxX+j].nextUpdate( true );
            }
            else if( liveCount < 2 || liveCount > 3 )
            {
                board[i*maxX+j].nextUpdate( false );
            }
            else
            {
                board[i*maxX+j].nextUpdate(board[i*maxX+j].isLive());
            }
            

            liveCount = 0;

        }
    }
}

void GolBoard::updateCells()
{
    for( auto i = board.begin(); i != board.end(); i++ )
    {
        i->update();
    }
}

void GolBoard::printOutput()
{
    int count = 0;
    for( auto i = board.begin(); i != board.end(); i++ )
    {
        if( i->isLive() ) std::cout << "x ";
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
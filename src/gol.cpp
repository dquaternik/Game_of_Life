#include "gol.hpp"

#include <iostream>
#include <fstream>
#include <string>

int GolBoard::getIndex( int x, int y )
{
    return y*maxX+x;
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
                CellPos extraPos( xcount, ycount, getIndex( xcount, ycount ) );
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

    for(int i = 0; i < maxY; i++ )
    {
        for(int j = 0; j < maxX; j++ )
        {
            int cutIndex = getIndex( j, i );
            std::vector< CellPos > deadPos;
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
                    if( board[index].live && cut != &board[index] )
                    {
                        liveCount++;
                    } 
                    else if( !board[index].live && cut != &board[index] && !board[index].checked )
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
            }
            else if( liveCount < 2 || liveCount > 3 )
            {
                board[cutIndex].nextLive = false;
            }
            else
            {
                board[cutIndex].nextLive = board[cutIndex].live;
            }

            liveCount = 0;

            if( deadPos.size() > 0 ) 
            {
                checkNeighbors( deadPos, false );
                deadPos.clear();
            }
        }
    }
}

void GolBoard::updateCells()
{
    for( auto i = board.begin(); i != board.end(); i++ )
    {
        i->update();
    }

    alive.clear();
    alive = nextAlive;
    nextAlive.clear();
}

void GolBoard::printOutput()
{
    int count = 0;
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

void GolBoard::checkNeighbors( std::vector< CellPos > pos, bool enable )
{
    Cell *cut;
    int liveCount = 0;

    for(auto it = pos.begin(); it != pos.end(); it++ )
    {
        int cutIndex = it->index;
        int i = it->posY;
        int j = it->posX;
        std::vector< CellPos > deadPos;
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
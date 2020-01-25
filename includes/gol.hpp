#include <vector>

class Cell
{
public:
    Cell( bool live = false ) : live( live ){};
    ~Cell(){};

    void nextUpdate( bool live )
    {
        nextLive = live;
    }
    
    void update()
    {
        live = nextLive;
        nextLive = false;
    }

    bool isLive() { return live; }

protected:
    bool live;
    bool nextLive;

};

class CellPos
{
public:
    CellPos( int posX = 0, int posY = 0, int index = 0 )
    : posX( posX )
    , posY( posY )
    , index( index )
    {};
    ~CellPos(){};

    int posX;
    int posY;
    int index;
};

class GolBoard
{
private:
    std::vector< Cell > board;
    std::vector< CellPos > alive;
    unsigned int maxX;
    unsigned int maxY;

public:
    void readInput();
    void updateBoard();
    void updateCells();
    void printOutput();

private:
    int getIndex( int x, int y );

};
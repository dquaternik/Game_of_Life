#include <vector>

class Cell
{
public:
    Cell( bool live = false ) 
        : live( live )
        , nextLive( false ) 
        , checked( false )
        {};
    ~Cell(){};
    
    void update()
    {
        live = nextLive;
        nextLive = false;
        checked = false;
    }

    bool checked;
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
    std::vector< CellPos > nextAlive;
    unsigned int maxX;
    unsigned int maxY;

public:
    void readInput();
    void updateBoard();
    void updateCells();
    void printOutput();

private:
    int getIndex( int x, int y );
    void checkNeighbors( std::vector< CellPos > pos, bool enable );

};
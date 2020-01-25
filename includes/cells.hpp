#ifndef h_CELLS_h
#define h_CELLS_h

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

#endif
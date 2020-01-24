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

class GolBoard
{
private:
    std::vector< Cell > board;
    unsigned int maxX;
    unsigned int maxY;

public:
    void readInput();
    void updateBoard();
    void updateCells();
    void printOutput();

};
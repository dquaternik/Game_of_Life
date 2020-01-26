#include "gol.hpp"
#include <chrono>
#include <thread>

int main()
{

    GolBoard golBoard;

    golBoard.readInput();
    golBoard.printOutput();

    while(1)
    {
        golBoard.updateBoard();
        golBoard.printOutput();
        std::chrono::milliseconds dura(300);
        std::this_thread::sleep_for( dura );
    }


    return 0;

}
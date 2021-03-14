// My Includes
#include "include/gameboard.hpp"

// Indludes
    // None.

// Defines
    // None.

int main(int argc, char *argv[])
{
    std::cout << "Blackjack program" << "\n\n";
    
    // Create the game board
    GameBoard GB{};

    // Game loop
    while( GB.Play() )
    {}

    std::cout << "----- Exiting Blackjack program -----" << "\n";

    return 0;
}

#include <iostream>

#include "include/coins.hpp"
#include "include/constants.hpp"
#include "include/cardvalue.hpp"
#include "include/deck.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Blackjack program" << "\n";
    std::cout << "Test : UINT_MAX from Class Coins : " << Coins::maxValue() << "\n";    // 4 294 967 295

    for(int i(CARD_VALUE_MIN); i <= CARD_VALUE_MAX; ++i) {
        std::cout << "Card Value : " << i << "\n";
    }

    
    unsigned int nbCardToStart = 2;
    std::unique_ptr<Deck> d = std::make_unique<Deck>(nbCardToStart);

    return 0;
}

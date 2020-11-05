#include <iostream>

#include "include/coins.hpp"
#include "include/constants.hpp"
#include "include/cardvalue.hpp"
#include "include/gameentitydeck.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Blackjack program" << "\n";
    std::cout << "Test : UINT_MAX from Class Coins : " << Coins::maxValue() << "\n";    // 4 294 967 295

    for(int i(CARD_VALUE_MIN); i <= CARD_VALUE_MAX; ++i) {
        std::cout << "Card Value : " << i << "\n";
    }

    GameEntityDeck ged{};
    ged.Give_a_Card();
    unsigned int nbCardToStart = 2;
    Deck d{nbCardToStart};
    Card card{ged.Give_a_Card()};
    d.Add_a_Card(card);

    return 0;
}

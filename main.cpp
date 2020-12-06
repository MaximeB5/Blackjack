// My Includes
#include "include/cardvalue.hpp"
#include "include/coins.hpp"
#include "include/constants.hpp"
#include "include/deck.hpp"
#include "include/humanplayer.hpp"


int main(int argc, char *argv[])
{
    std::cout << "Blackjack program" << "\n";
    std::cout << "Test : UINT_MAX from Class Coins : " << Coins::maxValue() << "\n";    // 4 294 967 295

    for(int i(CARD_VALUE_MIN); i <= CARD_VALUE_MAX; ++i) {
        std::cout << "Card Value : " << i << "\n";
    }

    
    unsigned int nbCardToStart = 2;
    std::unique_ptr<Deck> d = std::make_unique<Deck>(nbCardToStart);
    std::unique_ptr<Deck> dd = std::make_unique<Deck>(2);

    
    std::cout << "\n\n Test unique ptr == nullptr\n";
    
    auto gameDeck = std::make_shared<Deck>(DeckSpecification::DefaultDeck);
    std::unique_ptr<HumanPlayer> uPlayer; // to be tested for the GameBoard

    if(uPlayer == nullptr) 
        std::cout << "\t\t uPlayer == nullptr\n";

    std::cout << "Test 2\n";
    uPlayer = std::make_unique<HumanPlayer>(PlayerTag{Name{"PlayerName"}}, gameDeck, 20);
    
    if(uPlayer == nullptr) 
        std::cout << "\t\t uPlayer still == nullptr\n";
    else
        std::cout << "\t\t uPlayer allocated well\n";

    return 0;
}

// My Includes
#include "include/cardvalue.hpp"
#include "include/coins.hpp"
#include "include/constants.hpp"
#include "include/deck.hpp"
#include "include/humanplayer.hpp"
#include "include/templates.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Blackjack program" << "\n";

    // Test 1
    std::cout << "Test : UINT_MAX from Class Coins : " << Coins::maxValue() << "\n";    // 4 294 967 295

    // Test 2
    for(int i(CARD_VALUE_MIN); i <= CARD_VALUE_MAX; ++i) {
        std::cout << "Card Value : " << i << "\n";
    }

    // Test  3
    unsigned int nbCardToStart = 2;
    std::unique_ptr<Deck> d = std::make_unique<Deck>(nbCardToStart);
    std::unique_ptr<Deck> dd = std::make_unique<Deck>(2);

    // Test 4
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

    uPlayer.reset();
    uPlayer = std::make_unique<HumanPlayer>(PlayerTag{Name{"PlayerName2"}}, gameDeck, 20);
    if(uPlayer == nullptr) 
        std::cout << "\t\t uPlayer failed to reset\n";
    else
        std::cout << "\t\t uPlayer allocated PlayerName2 well after a reseto of the unique ptr\n";

    // Test 5
    CardValue cardVal  = CardValue::Queen;
    auto val = toUnderlyingType(cardVal);
    if(val == 12) 
        std::cout << "cardVal == 12 works\n";
    else
        std::cout << "cardVal == 12 does not work\n";
    
    return 0;    
}

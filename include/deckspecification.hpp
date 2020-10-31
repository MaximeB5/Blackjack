#ifndef DECKSPECIFICATION_H
#define DECKSPECIFICATION_H

/**
 * @brief enum class DeckSpecification : int
 * It contains the type of Deck that can be created by the Deck class.
 * If we want to create special game modes, we only have to add it here, and then specify it in the Deck constructor.
 * 
 */
enum class DeckSpecification : int {
    // Default deck.
    DefaultDeck = 0,

    // John Cena deck, it's a default deck with 4 Cards John Cena that makes all player win vs the casino dealer.
    // Players get their bet multiplicated by the number of hits that John Cena gives to the bank.
    // The minimum limit of hits is 3. There is no max limit of hits.
    JohnCena    = 1
};

#endif // DECKSPECIFICATION_H
#ifndef DECKSPECIFICATION_H
#define DECKSPECIFICATION_H

/**
 * @brief enum class DeckSpecification : int
 * It contains the type of Deck that can be created by the Deck class.
 * If we want to create special game modes, we only have to add it here, and then specify it in the Deck constructor.
 * 
 */
enum class DeckSpecification : int {
    DefaultDeck = 0
};

#endif // DECKSPECIFICATION_H
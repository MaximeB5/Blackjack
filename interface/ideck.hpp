#ifndef IDECK_H
#define IDECK_H

// My Includes
#include "../include/deckspecification.hpp"
#include "../include/card.hpp"

/**
 * Class IDeck
 */
class IDeck
{
public:
    // Constructors
        // None, this is an interface.

    // Destructor - virtual for interface.
    virtual ~IDeck() {}

    // UI Methods
    virtual void Shuffle(void) noexcept                                                                     = 0;
    virtual Card Give_a_Card(void)                                                                          = 0;
    virtual void Create_a_new_Deck(DeckSpecification deckspecification = DeckSpecification::DefaultDeck)    = 0;

protected:
    // None.

private:
    // None.
};

#endif // IDECK_H

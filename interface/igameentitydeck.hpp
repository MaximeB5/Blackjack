#ifndef IGAMEENTITYDECK_H
#define IGAMEENTITYDECK_H

// My Includes
#include "../include/deckspecification.hpp"
#include "../include/card.hpp"

/**
 * Class IGameEntityDeck
 */
class IGameEntityDeck
{
public:
    // Constructors
        // None, this is an interface.

    // Destructor - virtual for interface.
    virtual ~IGameEntityDeck() {}

    // UI Methods
    virtual void Add_a_Card(const Card& card) noexcept = 0;

protected:
    // None.

private:
    // None.
};

#endif // IGAMEENTITYDECK_H

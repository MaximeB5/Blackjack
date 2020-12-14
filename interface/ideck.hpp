#ifndef IDECK_H
#define IDECK_H

// My Includes
#include "../include/deckspecification.hpp"
#include "../include/card.hpp"

// Includes
#include <vector>
#include <string>

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
    virtual Card                     Give_a_Card            (void)                                                                          = 0;
    virtual void                     Drop_a_Specific_Card   (Card& card)                                                                    = 0;
    virtual void                     Add_a_Card             (const Card& card)                                                     noexcept = 0;
    virtual void                     Shuffle                (void)                                                                 noexcept = 0;
    virtual void                     Create_a_new_Deck      (DeckSpecification deckspecification = DeckSpecification::DefaultDeck)          = 0;
    virtual void                     Reset                  (void)                                                                 noexcept = 0;
    virtual std::vector<std::string> GetDeck                (void)                                                           const noexcept = 0;
    virtual unsigned int             GetNumberOfCards       (void)                                                           const noexcept = 0;
    virtual std::vector<int>         GetCardValuesOfTheDeck (DeckSpecification deckSpec = DeckSpecification::DefaultDeck)    const noexcept = 0;

protected:
    // None.

private:
    // None.
};

#endif // IDECK_H

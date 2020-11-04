#ifndef GAMEENTITYDECK_H
#define GAMEENTITYDECK_H

// My Includes
#include "deck.hpp"
#include "../interface/igameentitydeck.hpp"

// Includes
    // None for the moment.

class GameEntityDeck : public Deck, public IGameEntityDeck
{
// Attributes
private:
    const unsigned int NUMBER_OF_CARDS_AT_START = 2;

// Methods
public:
    // Constructors
    explicit GameEntityDeck();    

    // Destructor
    virtual ~GameEntityDeck();

    // UI
    // Inheritance from IDeck
        // The implementation of Give_a_Card() in the base Deck is sufficient. No need to override it here.

    // Inheritance from IGameEntityDeck
    void Add_a_Card(const Card& card) noexcept override;

private:
    // Inheritance from IDeck - private because not needed in the public UI
    /**
     * @brief Shuffle
     * Inherited method from IDeck that is inherited by Deck. Set as private with empty implementation because we don't need it.
     * 
     */
    void Shuffle(void)                                                                           noexcept override {}

    /**
     * @brief Create_a_new_Deck
     * Inherited method from IDeck that is inherited by Deck. Set as private with empty implementation because we don't need it.
     * 
     * @param deckspecification 
     */
    void Create_a_new_Deck(DeckSpecification deckspecification = DeckSpecification::DefaultDeck)          override {}

};

#endif // GAMEENTITYDECK_H
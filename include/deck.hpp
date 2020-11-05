#ifndef DECK_H
#define DECK_H

// My Includes
#include "../interface/ideck.hpp"
#include "deckspecification.hpp"
#include "card.hpp"
#include "constants.hpp"

// Includes
#include <vector>

/**
 * @brief Class Deck
 * It represents the deck of cards of the game.
 * It contains a data structure std::vector which contains the cards.
 * 
 */
class Deck : public IDeck
{
// Attributes
protected:
    std::vector<std::unique_ptr<Card> > _deck;

// Methods
public:
    // Constructors
    explicit Deck(DeckSpecification deckspecification = DeckSpecification::DefaultDeck);    // For the class that will holds the Deck
    explicit Deck(unsigned int numberOfCardToReserve = NUMBER_OF_CARDS_AT_START);           // For player hands

    // Destructor
    virtual ~Deck();

    // UI
    // Inheritance from IDeck
    Card Give_a_Card(void)                                                                                override;
    void Add_a_Card(const Card& card)                                                            noexcept override;
    void Shuffle(void)                                                                           noexcept override;
    void Create_a_new_Deck(DeckSpecification deckspecification = DeckSpecification::DefaultDeck)          override;
    void Reset(void)                                                                             noexcept override;
    
    /**
     * @brief Get the Deck object
     * Deleted method.
     * 
     * @return std::vector<Card> 
     */
    std::vector<Card> getDeck(void) const noexcept = delete;

    /**
     * @brief Set the Deck object
     * Deleted method.
     * 
     */
    void setDeck(std::vector<Card>) noexcept       = delete;

private:
    void createDefaultDeck(void)    noexcept;
};

#endif // DECK_H
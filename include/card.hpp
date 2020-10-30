#ifndef CARD_H
#define CARD_H


// My Includes
#include "cardvalue.hpp"
#include "cardcolor.hpp"
#include "cardsymbol.hpp"

// Includes
#include "memory"   // std::unique_ptr<T>

/**
 * @brief Class Card
 * It represents a card of the deck.
 * It is composed by a CardValue, a CardColor and a CardSymbol.
 * A card needs those three data to be created.
 * 
 */
class Card
{
// Attributes
private:
    std::unique_ptr<CardValue>  _cardValue;
    std::unique_ptr<CardColor>  _cardColor;
    std::unique_ptr<CardSymbol> _cardSymbol;

// Methods
public:
    // Constructors
    explicit Card(CardValue cardvalue, CardColor cardcolor, CardSymbol cardsymbol);

    // Destructor
    ~Card();

    // UI
    /**
     * @brief Get the Card Value object
     * 
     * @return CardValue 
     */
    CardValue  getCardValue()   const noexcept { return *_cardValue;  }

    /**
     * @brief Get the Card Color object
     * 
     * @return CardColor 
     */
    CardColor  getCardColor()   const noexcept { return *_cardColor;  }

    /**
     * @brief Get the Card Symbol object
     * 
     * @return CardSymbol 
     */
    CardSymbol getCardSymbol()  const noexcept { return *_cardSymbol; }

    /**
     * @brief Set the Card Value object
     * Deleted method.
     * 
     */
    void setCardValue()  = delete;

    /**
     * @brief Set the Card Color object
     * Deleted method.
     * 
     */
    void setCardColor()  = delete;

    /**
     * @brief Set the Card Symbol object
     * Deleted method.
     * 
     */
    void setCardSymbol() = delete;

protected:
    // None for the moment.

private:
    // None for the moment.
};

#endif // CARD_H
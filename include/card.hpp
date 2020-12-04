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
 * It is composed by a CardColor, a CardSymbol and a CardValue.
 * A card needs those three data to be created.
 * 
 */
class Card
{
// Attributes
private:
    std::unique_ptr<CardColor>  _cardColor;
    std::unique_ptr<CardSymbol> _cardSymbol;
    std::unique_ptr<CardValue>  _cardValue;


// Methods
public:
    // Constructors
    explicit Card(CardColor cardcolor, CardSymbol cardsymbol, CardValue cardvalue);
    explicit Card(const Card& card);
    explicit Card(Card&& card);

    // Destructor
    ~Card();

    // Operators
    /**
     * @brief Card& operator=( const Card& card )
     * 
     * @param card 
     * @return Card& 
     */
    Card& operator=( const Card& card )
    {
        _cardColor.reset ( new CardColor ( *card._cardColor  ) );
        _cardSymbol.reset( new CardSymbol( *card._cardSymbol ) );
        _cardValue.reset ( new CardValue ( *card._cardValue  ) );
        return *this;
    }

    /**
     * @brief Card& operator=( Card&& card )
     * 
     * @param card 
     * @return Card& 
     */
    Card& operator=( Card&& card )
    {
        _cardColor  = std::move( card._cardColor  );
        _cardSymbol = std::move( card._cardSymbol );
        _cardValue  = std::move( card._cardValue  );
        return *this;
    }

    // UI
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
     * @brief Get the Card Value object
     * 
     * @return CardValue 
     */
    CardValue  getCardValue()   const noexcept { return *_cardValue;  }

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

    /**
     * @brief Set the Card Value object
     * Deleted method.
     * 
     */
    void setCardValue()  = delete;

protected:
    // None for the moment.

private:
    // None for the moment.
};

#endif // CARD_H
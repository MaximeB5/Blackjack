// My Includes
#include "../include/card.hpp"

// Includes
    // None for the moment.


/**
 * @brief Construct a new Card:: Card object
 * Make unique the unique ptr class members _cardColor and _cardSymbol, _cardValue.
 * 
 * @param cardcolor 
 * @param cardsymbol 
 * @param cardvalue 
 */
Card::Card(CardColor cardcolor, CardSymbol cardsymbol, CardValue cardvalue)
: _cardColor ( std::make_unique<CardColor> ( cardcolor  ))
, _cardSymbol( std::make_unique<CardSymbol>( cardsymbol ))
, _cardValue ( std::make_unique<CardValue> ( cardvalue  )) {}


/**
 * @brief Construct a new Card:: Card object
 * Copy constructor.
 * 
 * @param card 
 */
Card::Card(const Card& card)
: _cardColor ( new CardColor  ( *card._cardColor  ) )
, _cardSymbol( new CardSymbol ( *card._cardSymbol ) )
, _cardValue ( new CardValue  ( *card._cardValue  ) ) {}


/**
 * @brief Construct a new Card:: Card object
 * Move constructor.
 * 
 * @param card 
 */
Card::Card( Card&& card )
: _cardColor  ( std::move( card._cardColor  ))
, _cardSymbol ( std::move( card._cardSymbol ))
, _cardValue  ( std::move( card._cardValue  )) {}


/**
 * @brief Destroy the Card:: Card object
 * 
 */
Card::~Card() {}
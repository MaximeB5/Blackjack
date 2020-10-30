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
: _cardColor(std::make_unique<CardColor>(cardcolor))
, _cardSymbol(std::make_unique<CardSymbol>(cardsymbol))
, _cardValue(std::make_unique<CardValue>(cardvalue)) {}

/**
 * @brief Destroy the Card:: Card object
 * 
 */
Card::~Card() {}
// My Includes
#include "../include/card.hpp"

// Includes
    // None for the moment.

/**
 * @brief Construct a new Card:: Card object
 * Make unique the unique ptr class members _cardValue, _cardColor and _cardSymbol.
 * 
 * @param cardvalue 
 * @param cardcolor 
 * @param cardsymbol 
 */
Card::Card(CardValue cardvalue, CardColor cardcolor, CardSymbol cardsymbol)
: _cardValue(std::make_unique<CardValue>(cardvalue))
, _cardColor(std::make_unique<CardColor>(cardcolor))
, _cardSymbol(std::make_unique<CardSymbol>(cardsymbol)) {}

/**
 * @brief Destroy the Card:: Card object
 * 
 */
Card::~Card() {}
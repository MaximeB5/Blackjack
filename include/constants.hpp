#ifndef CONSTANTS_H
#define CONSTANTS_H

/**
 * @brief Constants.hpp file
 * It contains all constants used in the project Blackjack, such as the index of the enum classes.
 * 
 */
// Card Color
const int   CARD_COLOR_MIN          = 0;
const int   CARD_COLOR_MAX          = 1;

// Card Value
const int   CARD_VALUE_MIN          = 1;
const int   CARD_VALUE_MAX          = 13;

// Card Symbol
const int   CARD_SYMBOL_MIN         = 0;
const int   CARD_SYMBOL_MAX         = 3;
const int   CARD_SYMBOL_RED_MIN     = 0;
const int   CARD_SYMBOL_RED_MAX     = 1;
const int   CARD_SYMBOL_BLACK_MIN   = 2;
const int   CARD_SYMBOL_BLACK_MAX   = 3;

// Deck
const unsigned int NUMBER_OF_CARDS_DEFAULT_DECK = 52;

// Game Entities - Deck
const unsigned int NUMBER_OF_CARDS_AT_START = 2;

// The Blackjack game itself
const unsigned int NUMBER_OF_PLAYERS_MAX = 4;
const unsigned int NUMBER_OF_PLAYERS_MIN = 1;

#endif // CONSTANTS_H
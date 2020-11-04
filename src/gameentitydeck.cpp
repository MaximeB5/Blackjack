// My Includes
#include "../include/gameentitydeck.hpp"

// Includes
    // None for the moment.

/**
 * @brief Construct a new Game Entity Deck:: Game Entity Deck object
 * 
 */
GameEntityDeck::GameEntityDeck() {
    // Being given a game will start with the same minimal amount of card, by default, we can so reserve this size before it is really needed.
    this->_deck.reserve(NUMBER_OF_CARDS_AT_START);
}

/**
 * @brief Destroy the Game Entity Deck:: Game Entity Deck object
 * 
 */
GameEntityDeck::~GameEntityDeck() {
}

/**
 * @brief 
 * 
 */
void GameEntityDeck::Add_a_Card(const Card& card) noexcept {
    this->_deck.push_back( std::make_unique<Card>(card) );
}
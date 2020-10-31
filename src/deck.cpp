// My Includes
#include "../include/deck.hpp"
#include "../include/deckexception.hpp"
#include "../include/constants.hpp"

// Includes
#include <algorithm>    // std::shuffle
#include <random>       // std::random_device ; std::default_random_engine
#include <iostream>     // std::cerr

/**
 * @brief Construct a new Deck:: Deck object
 * The deckspecification param has the default value DeckSpecification::DefaultDeck.
 * If we want to create special game modes, we only have to add it in the DeckSpecification enum class, and then specify it here.
 * 
 * If the deckspecification doesn't exist, a DeckException is thrown by Deck::Create_a_new_Deck.
 * On the v1.1 of the project, it writes the error on std::cerr.
 * On the v1.2 of the project, it writes the error in the log system.
 * It then creates a default deck by calling Deck::createDefaultDeck which is noexcept
 * 
 * @param deckspecification 
 */
Deck::Deck(DeckSpecification deckspecification) {
    try
    {
        this->Create_a_new_Deck(deckspecification);
    }
    catch(const DeckException& DE)
    {
        std::cerr << DE.what() << '\n'; // v1.1 of the project ; v1.2 -> using log system instead
        this->createDefaultDeck();
    }
}

/**
 * @brief Destroy the Deck:: Deck object
 * 
 */
Deck::~Deck() {}

/**
 * @brief Shuffle the deck
 * UI method.
 * 
 */
void Deck::Shuffle(void) noexcept {
    auto randomDevice   = std::random_device{}; 
    auto rng            = std::default_random_engine{ randomDevice() };

    std::shuffle(std::begin(this->_deck), std::end(this->_deck), rng);
}


/**
 * @brief Give the card on top of the deck
 * UI method.
 * 
 */
Card Deck::Give_a_Card(void) {
    Card card{ *this->_deck.back() };
    this->_deck.pop_back();

    return Card{card};
}


/**
 * @brief Create a new deck accordingly to the deckspecification param
 * UI method.
 * 
 * @param deckspecification 
 * @throw DeckException if the deckspecification doesn't exist
 */
void Deck::Create_a_new_Deck(DeckSpecification deckspecification) {
    if(deckspecification == DeckSpecification::DefaultDeck)
        this->createDefaultDeck();

    else throw new DeckException{"Error in \"Deck::Create_a_new_Deck\" : The DeckSpecification asked by the user doesn't exist."};
}

/**
 * @brief addCard
 * It adds a card to the deck, if the deck is full, it removes the last card and replaces it by the new one.
 * 
 * @param card 
 */
void Deck::addCard(Card card) noexcept {
    if(this->_deck.size() == this->_deck.max_size()) {
        this->_deck.pop_back();
    }

    this->_deck.push_back( std::make_unique<Card>(card) );
}

/**
 * @brief createDefaultDeck
 * It creates a default deck with 4 cards of each, including 2 of each color and 1 of each symbol.
 * 
 */
void Deck::createDefaultDeck(void) noexcept {
    // Create the deck
    for(int i(CARD_VALUE_MIN); i <= CARD_VALUE_MAX; ++i) {
        this->addCard( Card{CardColor::Red,   CardSymbol::Heart,  static_cast<CardValue>(i)} );
        this->addCard( Card{CardColor::Red,   CardSymbol::Tile,   static_cast<CardValue>(i)} );
        this->addCard( Card{CardColor::Black, CardSymbol::Clover, static_cast<CardValue>(i)} );
        this->addCard( Card{CardColor::Black, CardSymbol::Pike,   static_cast<CardValue>(i)} );
    }

    // Then shuffle it
    this->Shuffle();
}

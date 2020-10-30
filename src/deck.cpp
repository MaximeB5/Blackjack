// My Includes
#include "../include/deck.hpp"
#include "../include/deckexception.hpp"

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

    std::shuffle(std::begin(_deck), std::end(_deck), rng);
}


/**
 * @brief Give the card on top of the deck
 * UI method.
 * 
 */
Card Deck::Give_a_Card(void) {
    Card card{ this->_deck.back() };
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

    else throw new DeckException("Error in \"Deck::Create_a_new_Deck\" : The DeckSpecification asked by the user doesn't exist.");
}



void Deck::createDefaultDeck(void) noexcept {
    // Create the deck here
    throw new DeckException("Error in \"Deck::createDefaultDeck\" : THE METHOD ISN'T FULLY IMPLEMENTED");

    // Then shuffle it
    this->Shuffle();
}

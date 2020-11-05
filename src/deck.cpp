// My Includes
#include "../include/deck.hpp"
#include "../include/deckexception.hpp"
#include "../include/constants.hpp"

// Includes
#include <algorithm>    // std::shuffle
#include <random>       // std::random_device ; std::default_random_engine

// Debug
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
 * @brief Construct a new Deck:: Deck object
 * 
 * @param numberOfCardToReserve 
 */
Deck::Deck(unsigned int numberOfCardToReserve) {
    this->_deck.reserve(NUMBER_OF_CARDS_AT_START);
}

/**
 * @brief Destroy the Deck:: Deck object
 * 
 */
Deck::~Deck() {}

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
 * @brief Drop_a_Specific_Card
 * Drop the specified card if it exists, else throw.
 * 
 * @param card 
 * @throw DeckException if the card doesn't exist
 */
void Deck::Drop_a_Specific_Card(Card& card) {
    ///*
    for(auto it = this->_deck.begin(); it != this->_deck.end(); ++it) {
        if(     it->get()->getCardColor() == card.getCardColor()
            &&  it->get()->getCardSymbol() == card.getCardSymbol()
            &&  it->get()->getCardValue() == card.getCardValue()    ) {
            this->_deck.erase(it);
            return;
        }
    }
    
    throw new DeckException{"Error in \"Deck::Drop_a_Specific_Card\" : The specified card doesn't exist."};
    //*/
    /*
    auto iterator = std::find_if(
                                std::begin(this->_deck), 
                                std::end(this->_deck), 
                                [card](auto &element) { return element.get() == card; }
                                );

    if(iterator != this->_deck.end())
        this->_deck.erase(iterator);
    else throw new DeckException{"Error in \"Deck::Drop_a_Specific_Card\" : The specified card doesn't exist."};
    */
}

/**
 * @brief Add_a_Card
 * It adds a card to the deck, if the deck is full, it removes the last card and replaces it by the new one.
 * 
 * @param card 
 */
void Deck::Add_a_Card(const Card& card) noexcept {
    if(this->_deck.size() == this->_deck.max_size()) {
        this->_deck.pop_back();
    }

    this->_deck.push_back( std::make_unique<Card>(card) );
}

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

void Deck::Reset(void) noexcept {
    this->_deck.clear();
}

/**
 * @brief createDefaultDeck
 * It creates a default deck with 4 cards of each, including 2 of each color and 1 of each symbol.
 * 
 */
void Deck::createDefaultDeck(void) noexcept {
    // Create the deck
    for(int i(CARD_VALUE_MIN); i <= CARD_VALUE_MAX; ++i) {
        this->Add_a_Card( Card{CardColor::Red,   CardSymbol::Heart,  static_cast<CardValue>(i)} );
        this->Add_a_Card( Card{CardColor::Red,   CardSymbol::Tile,   static_cast<CardValue>(i)} );
        this->Add_a_Card( Card{CardColor::Black, CardSymbol::Clover, static_cast<CardValue>(i)} );
        this->Add_a_Card( Card{CardColor::Black, CardSymbol::Pike,   static_cast<CardValue>(i)} );
    }

    // Then shuffle it
    this->Shuffle();
}

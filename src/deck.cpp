// My Includes
#include "../include/deck.hpp"
#include "../include/deckexception.hpp"
#include "../include/constants.hpp"
#include "../include/magic_enum.hpp"

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
    catch(...) 
    {
        std::cerr << "Deck::Deck(DeckSpecification deckspecification) thrown an unknown exception" << '\n'; // v1.1 of the project ; v1.2 -> using log system instead
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
    std::scoped_lock<std::mutex> lock(this->_mutex);

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
    std::scoped_lock<std::mutex> lock(this->_mutex);
    
    for(auto it = this->_deck.begin(); it != this->_deck.end(); ++it) {
        if(     it->get()->getCardColor() == card.getCardColor()
            &&  it->get()->getCardSymbol() == card.getCardSymbol()
            &&  it->get()->getCardValue() == card.getCardValue()    ) {
            this->_deck.erase(it);
            return;
        }
    }
    
    throw DeckException{"Error in \"Deck::Drop_a_Specific_Card\" : The specified card doesn't exist."};
}


/**
 * @brief Add_a_Card
 * It adds a card to the deck, if the deck is full, it removes the last card and replaces it by the new one.
 * 
 * @param card 
 */
void Deck::Add_a_Card(const Card& card) noexcept {
    std::scoped_lock<std::mutex> lock(this->_mutex);

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
 * Careful ! This method doesn't clear the previous deck ! It has to be done manually !
 * UI method.
 * 
 * @param deckspecification 
 * @throw DeckException if the deckspecification doesn't exist
 */
void Deck::Create_a_new_Deck(DeckSpecification deckspecification) {
    if(deckspecification == DeckSpecification::DefaultDeck)
        this->createDefaultDeck();

    else throw DeckException{"Error in \"Deck::Create_a_new_Deck\" : The DeckSpecification asked by the user doesn't exist."};
}


/**
 * @brief Reset the deck by clearing it
 * 
 */
void Deck::Reset(void) noexcept {
    this->_deck.clear();
}


/**
 * @brief Get the content of the deck in a vector of strings where each string (i.e. index) represents a card.
 * If the deck is empty, the returned vector will be empty as well.
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> Deck::GetDeck(void) const noexcept {
    std::vector<std::string> v;

    // If the deck is empty
    if(this->_deck.empty())
        return v;

    // If the deck has at least 1 card
    for(auto it = this->_deck.begin(); it != this->_deck.end(); ++it)
    {
        Card c{ *it->get() };
        auto card_color  = magic_enum::enum_name<CardColor> (c.getCardColor() );
        auto card_symbol = magic_enum::enum_name<CardSymbol>(c.getCardSymbol());
        auto card_value  = magic_enum::enum_name<CardValue> (c.getCardValue() );

        std::string card{card_color};   card.append(" ");
        card.append(card_symbol);       card.append(" ");
        card.append(card_value);
        
        v.push_back(card);
    }

    return v;
}


/**
 * @brief GetNumberOfCards
 * 
 * @return unsigned int 
 */
unsigned int Deck::GetNumberOfCards(void) const noexcept {
    return this->_deck.size();
}


/**
 * @brief createDefaultDeck
 * It creates a default deck with 4 cards of each, including 2 of each color and 1 of each symbol.
 * Careful ! This method doesn't clear the previous deck ! It has to be done manually !
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
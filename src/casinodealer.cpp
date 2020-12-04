// My Includes
#include "../include/casinodealer.hpp"
#include "../include/deckexception.hpp"

// Includes
    // None for the moment.

// Debug
#include<iostream>


/**
 * @brief Construct a new Casino Dealer:: Casino Dealer object
 * 
 * @param name 
 */
CasinoDealer::CasinoDealer(std::shared_ptr<Deck> gameDeck, const Name& name) : _name(name) {
    // RAII
    this->Init();

    this->initGameDeck(gameDeck);
}


/**
 * @brief Destroy the Casino Dealer:: Casino Dealer object
 * 
 */
CasinoDealer::~CasinoDealer()
{
    // RAII
    this->Release();
}


/**
 * @brief RAII method Init
 * 
 */
void CasinoDealer::Init() {
    this->_playerHand = std::make_unique<Deck>(NUMBER_OF_CARDS_AT_START);
}


/**
 * @brief RAII method Release
 * 
 */
void CasinoDealer::Release() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
}


/**
 * @brief overriden method from IGameEntity
 * It takes a card from the game deck and place it in the player hand.
 * 
 */
void CasinoDealer::Pick_a_Card() {
    this->_playerHand->Add_a_Card( this->_deck->Give_a_Card() );
}


/**
 * @brief overriden method from IGameEntity
 * 
 */
void CasinoDealer::Skip_Turn() {
    this->setBooleanMembers(true);
}


/**
 * @brief overriden method from IGameEntity
 * 
 */
void CasinoDealer::Turn_is_Over() {
    this->setBooleanMembers(false, true);
}


/**
 * @brief initGameDeck
 * 
 * @param gameDeck 
 */
void CasinoDealer::initGameDeck(std::shared_ptr<Deck> gameDeck) {
    this->_deck = gameDeck;
}


/**
 * @brief set the boolean flags
 * 
 * @param skip 
 */
void CasinoDealer::setBooleanMembers(bool skip, bool endTurn) {
    this->_wantsToSkip       = skip;
    this->_wantsToEndHisTurn = endTurn;
}


/**
 * @brief dropCard
 * 
 * @param card 
 */
void CasinoDealer::dropCard(Card& card) noexcept {
    try
    {
        this->_playerHand->Drop_a_Specific_Card(card);
    }
    catch(const DeckException& de)
    {
        std::cerr << de.what() << '\n'; // v1.1 of the project ; v1.2 -> using log system instead
    }
    catch(...) 
    {
        std::cerr << "CasinoDealer::dropCard thrown an unknown exception" << '\n'; // v1.1 of the project ; v1.2 -> using log system instead
    }
}


/**
 * @brief addCard
 * 
 * @param card 
 */
void CasinoDealer::addCard(Card& card) noexcept {
    this->_playerHand->Add_a_Card(card);
}
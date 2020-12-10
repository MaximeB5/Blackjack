// My Includes
#include "../include/casinodealer.hpp"
#include "../include/deckexception.hpp"
#include "../include/magic_enum.hpp"

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
void CasinoDealer::Turn_is_Over() {
    this->setBooleanMembers(true);
}


/**
 * @brief Play method overriden from IPlay_CasinoDealer
 * This describes a whole and full turn of the CasinoDealer.
 * It has to be repeated, through a while loop for example, as many times as necessary by an external object, the GameBoard, that will handle the CasinoDealer.
 * It sets the flags and returns the hand value.
 * The CasinoDealer max hand value to get a card from the game deck is 17. This value is fixed in constants.hpp by CASINO_DEALER_HAND_VALUE_LIMIT.
 * As long as his hand is under this value, the CasinoDealer plays. Else, it stops and returns the current hand value.
 * 
 * @return unsigned int 
 */
unsigned int CasinoDealer::Play() noexcept {
    // The first two picks in order to know if it's a blackjack or not
    this->Pick_a_Card();
    this->Pick_a_Card();

    auto cards = this->_deck->GetDeck();  

    // if it's a Blackjack
    if(this->isBlackjack( cards[0], cards[1] ))
        return BLACKJACK_ACE_VALUE;
    
    // Keep playing
    auto handValue{0U};

    // Calculate the current handValue (careful with As)
        // TODO

    do {
        // TODO
    } while(handValue <= CASINO_DEALER_HAND_VALUE_LIMIT);

    return handValue;
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
 * @param endTurn 
 */
void CasinoDealer::setBooleanMembers(bool endTurn) {
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


/**
 * @brief based on the 2 cards passed, return true if it's a Blackjack, else false
 * 
 * @param card1 
 * @param card2 
 * @return true 
 * @return false 
 */
bool CasinoDealer::isBlackjack(const std::string& card1, const std::string& card2) const noexcept {
    // If card1 is an As and card2 == 10 or similar
    if(card1.find(magic_enum::enum_name<CardValue>(CardValue::As)) != std::string::npos
        &&
        (
                card2.find(magic_enum::enum_name<CardValue>(CardValue::Ten)) != std::string::npos
            ||
                card2.find(magic_enum::enum_name<CardValue>(CardValue::Jack)) != std::string::npos
            ||
                card2.find(magic_enum::enum_name<CardValue>(CardValue::Queen)) != std::string::npos
            ||
                card2.find(magic_enum::enum_name<CardValue>(CardValue::King)) != std::string::npos
        )
    )
    return true;

    // If card2 is an As and card1 == 10 or similar
    if(card2.find(magic_enum::enum_name<CardValue>(CardValue::As)) != std::string::npos
        &&
        (
                card1.find(magic_enum::enum_name<CardValue>(CardValue::Ten)) != std::string::npos
            ||
                card1.find(magic_enum::enum_name<CardValue>(CardValue::Jack)) != std::string::npos
            ||
                card1.find(magic_enum::enum_name<CardValue>(CardValue::Queen)) != std::string::npos
            ||
                card1.find(magic_enum::enum_name<CardValue>(CardValue::King)) != std::string::npos
        )
    )
    return true;

    // It wasn't a Blackjack
    return false;
}
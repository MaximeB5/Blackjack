// My Includes
#include "../include/humanplayer.hpp"
#include "../include/deckexception.hpp"

// Includes
    // None for the moment.

// Debug
#include<iostream>

// Static members initialization
unsigned int HumanPlayer::MetaData::Total_of_Players_in_Game = 0;
unsigned int HumanPlayer::MetaData::Total_of_Coins_in_Game   = 0;

/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param playerTag 
 */
HumanPlayer::HumanPlayer(const PlayerTag& playerTag)
: _playerTag(playerTag), _wallet(Coins(0)) {
    // RAII
    this->Init();
}

/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param name 
 */

HumanPlayer::HumanPlayer(const Name& name)
: _playerTag(name), _wallet(Coins(0)) {
    // RAII
    this->Init();
}

/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param title 
 * @param name 
 */

HumanPlayer::HumanPlayer(const Title& title, const Name& name)
: _playerTag(title, name), _wallet(Coins(0)) {
    // RAII
    this->Init();
}

/**
 * @brief Destroy the Human Player:: Human Player object
 * 
 */
HumanPlayer::~HumanPlayer()
{
    this->Release();
}

/**
 * @brief RAII method Init
 * 
 */
void HumanPlayer::Init() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug

    // -- Work on progress --
    this->_isReadyToPlay    = false;
    this->_wantsToLeave     = false;

    // MetaData
    this->_MetaData.Total_of_Players_in_Game++;
    this->_MetaData.Total_of_Coins_in_Game += this->_wallet.getCoins();
}

/**
 * @brief RAII method Release
 * 
 */
void HumanPlayer::Release() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug

    // MetaData
    this->_MetaData.Total_of_Players_in_Game--;
    this->_MetaData.Total_of_Coins_in_Game -= this->_wallet.getCoins();
}

/**
 * @brief overriden method from IGameEntity
 * 
 */
void HumanPlayer::Pick_a_Card() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
}

/**
 * @brief overriden method from IGameEntity
 * 
 */
void HumanPlayer::Skip_Turn() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
}

/**
 * @brief overriden method from IPlayer
 * 
 */
void HumanPlayer::Ready_to_Play() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
}

/**
 * @brief overriden method from IPlayer
 * 
 */
void HumanPlayer::Quit_Game() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
}

/**
 * @brief getCoinsOfWallet
 * 
 * @return unsigned int 
 */
unsigned int HumanPlayer::getCoinsOfWallet() const noexcept{
    return this->_wallet.getCoins();
}

/**
 * @brief addCoinsToWallet
 * 
 * @param value 
 */
void HumanPlayer::addCoinsToWallet(unsigned int value) noexcept{
    this->_wallet.addCoins(value);
}

/**
 * @brief setCoinsOfWallet
 * 
 * @param value 
 */
void HumanPlayer::setCoinsOfWallet(unsigned int value) noexcept{
    this->_wallet.setCoins(value);
}

/**
 * @brief dropCard
 * 
 * @param card 
 */
void HumanPlayer::dropCard(Card& card) noexcept {
    try
    {
        this->_playerHand->Drop_a_Specific_Card(card);
    }
    catch(const DeckException& de)
    {
        std::cerr << de.what() << '\n'; // v1.1 of the project ; v1.2 -> using log system instead
    }
}

/**
 * @brief addCard
 * 
 * @param card 
 */
void HumanPlayer::addCard(Card& card)  noexcept {
    this->_playerHand->Add_a_Card(card);
}
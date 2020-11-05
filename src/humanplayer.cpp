// My Includes
#include "../include/humanplayer.hpp"

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
}

/**
 * @brief addCoinsToWallet
 * 
 */
void HumanPlayer::addCoinsToWallet() noexcept{
}

/**
 * @brief setCoinsOfWallet
 * 
 */
void HumanPlayer::setCoinsOfWallet() noexcept{
}

/**
 * @brief dropCard
 * 
 * @param card 
 */
void HumanPlayer::dropCard(Card& card) noexcept {
}

/**
 * @brief addCard
 * 
 * @param card 
 */
void HumanPlayer::addCard(Card& card)  noexcept {
}
// My Includes
#include "../include/humanplayer.hpp"

// Includes
    // None for the moment.

// Debug
#include<iostream>

/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param playerTag 
 */
HumanPlayer::HumanPlayer(const PlayerTag& playerTag) : _playerTag(playerTag) {
    //this->_playerTag = playerTag;

    // RAII
    this->Init();
}

/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param name 
 */
/*
HumanPlayer::HumanPlayer(const Name& name) {
    //this->_playerTag = PlayerTag(name);

    // RAII
    this->Init();
}*/

/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param title 
 * @param name 
 */
/*
HumanPlayer::HumanPlayer(const Title& title, const Name& name) {

    // RAII
    this->Init();
}*/

/**
 * @brief Destroy the Human Player:: Human Player object
 * 
 */
HumanPlayer::~HumanPlayer()
{
    // TODO
}

/**
 * @brief RAII method Init
 * 
 */
void HumanPlayer::Init() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
}

/**
 * @brief RAII method Release
 * 
 */
void HumanPlayer::Release() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
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
// My Includes
#include "../include/casinodealer.hpp"

// Includes
    // None for the moment.

// Debug
#include<iostream>

/**
 * @brief Construct a new Casino Dealer:: Casino Dealer object
 * 
 * @param name 
 */
CasinoDealer::CasinoDealer(const Name& name) : _name(name) {
    // RAII
    this->Init();
}

/**
 * @brief Destroy the Casino Dealer:: Casino Dealer object
 * 
 */
CasinoDealer::~CasinoDealer()
{
    // TODO
}

/**
 * @brief RAII method Init
 * 
 */
void CasinoDealer::Init() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
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
 * 
 */
void CasinoDealer::Pick_a_Card() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
}

/**
 * @brief overriden method from IGameEntity
 * 
 */
void CasinoDealer::Skip_Turn() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
}
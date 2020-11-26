// My Includes
#include "../include/score.hpp"

// Includes
#include <bits/stdc++.h>    // INT_MAX = 2 147 483 647 ; INT_MIN = - 2 147 483 648 ; UINT_MAX = 4 294 967 295

// Debug
#include<iostream>

/**
 * @brief Construct a new Score:: Score object
 * 
 */
Score::Score() {
    // RAII
    this->Init();
}

/**
 * @brief Destroy the Score object
 * 
 */
Score::~Score() {}


/**
 * @brief RAII method Init
 * 
 */
void Score::Init() {
    this->_score                 = 0;
    this->_gamesWon              = 0;
    this->_gamesLost             = 0;
    this->_numberOfWinsInARow    = 0;
    this->_numberOfDefeatsInARow = 0;
}

/**
 * @brief RAII method Release
 * 
 */
void Score::Release() {
    // TODO
    std::cout << "You're here : " << __FUNCTION__ << "\n";  // Debug
}

/**
 * @brief Increase_Win
 * Add 1 to _gamesWon and _numberOfWinsInARow, increase the score, reset _numberOfDefeatsInARow
 * 
 */
void Score::Increase_Win() noexcept {
    // Add 1 to _gamesWon
    if(this->_gamesWon < UINT_MAX)
        ++this->_gamesWon;

    // Increase the score
    if((this->_score + ((1 * _numberOfWinsInARow) + 1)) < INT_MAX)
        this->_score += ((1 * _numberOfWinsInARow) + 1); // min value added = 1

    // Add 1 to _numberOfWinsInARow
    if(this->_numberOfWinsInARow < UINT_MAX)
        ++this->_numberOfWinsInARow;

    // Reset _numberOfDefeatsInARow
    if(this->_numberOfDefeatsInARow > 0)
        this->_numberOfDefeatsInARow = 0;
}

/**
 * @brief Increase_Defeat
 * Add 1 to _gamesLost and _numberOfDefeatsInARow, decrease the score, reset _numberOfWinsInARow
 * 
 */
void Score::Increase_Defeat() noexcept {
    // Add 1 to _gamesLost
    if(this->_gamesLost < UINT_MAX)
        ++this->_gamesLost;

    // Decrease the score
    if((this->_score - ((1 * static_cast<int>(_numberOfDefeatsInARow)) + 1)) > INT_MIN) // cast due to int (_score) vs unsigned int (_numberOfDefeatsInARow) so we have no warning
        this->_score -= _numberOfDefeatsInARow; // min value added = 0, the decrease is slower than the increase so the player can think he's good

    // Add 1 to _numberOfDefeatsInARow
    if(this->_numberOfDefeatsInARow < UINT_MAX)
        ++this->_numberOfDefeatsInARow;

    // Reset _numberOfWinsInARow
    if(this->_numberOfWinsInARow > 0)
        this->_numberOfWinsInARow = 0;
}

/**
 * @brief Reset all stats to 0
 * 
 */
void Score::Reset_Stats() noexcept {
    this->_score                 = 0;
    this->_gamesWon              = 0;
    this->_gamesLost             = 0;
    this->_numberOfWinsInARow    = 0;
    this->_numberOfDefeatsInARow = 0;
}

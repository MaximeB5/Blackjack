// My Includes
#include "../include/gameboard.hpp"

// Indludes
    // None for the moment.

/**
 * @brief Construct a new Game Board:: Game Board object
 * 
 */
GameBoard::GameBoard()
{
    // TODO
}

/**
 * @brief Destroy the Game Board:: Game Board object
 * 
 */
GameBoard::~GameBoard()
{
    // TODO
}

void GameBoard::SetGameMode(void) const noexcept {
    // TODO
}

void GameBoard::Add_New_Player(void) noexcept {
    // TODO
}

void GameBoard::Remove_Player(void) noexcept {
    // TODO
}

void GameBoard::Add_Coins_To_Player(HumanPlayer& player) noexcept {
    // TODO
}

void GameBoard::Set_Coins_To_Player(HumanPlayer& player) noexcept  {
    // TODO
}

void GameBoard::Remove_Coins_To_Player(HumanPlayer& player) noexcept {
    // TODO
}

int GameBoard::Get_Score(const HumanPlayer& player) const noexcept {
    return player.getScoreObject().getScore();
}

void GameBoard::Reset_GameDeck(DeckSpecification deckspecification) noexcept  {
    // TODO
}

std::vector<std::string> GameBoard::GetDeck(void) const noexcept {
    return this->_gameDeck->GetDeck();
}
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


/**
 * @brief Set the game mode
 * 
 */
void GameBoard::SetGameMode(void) const noexcept {
    // TODO
}


/**
 * @brief Add a new player to the game board
 * 
 */
void GameBoard::Add_New_Player(void) noexcept {
    // TODO
}


/**
 * @brief Remove a player from the game board
 * 
 */
void GameBoard::Remove_Player(void) noexcept {
    // TODO
}


/**
 * @brief Add coins to a player
 * 
 * @param player 
 */
void GameBoard::Add_Coins_To_Player(HumanPlayer& player) noexcept {
    // TODO
}


/**
 * @brief Set an amout of coins to a player
 * 
 * @param player 
 */
void GameBoard::Set_Coins_To_Player(HumanPlayer& player) noexcept  {
    // TODO
}


/**
 * @brief Remove coins to a player
 * 
 * @param player 
 */
void GameBoard::Remove_Coins_To_Player(HumanPlayer& player) noexcept {
    // TODO
}


/**
 * @brief Increase the score of a player
 * 
 * @param player 
 */
void GameBoard::Increase_Score(HumanPlayer& player) noexcept {
    // TODO
}


/**
 * @brief Decrease the score of a player
 * 
 * @param player 
 */
void GameBoard::Decrease_Score(HumanPlayer& player) noexcept {
    // TODO
}


/**
 * @brief Get the score of a player
 * 
 * @param player 
 * @return int 
 */
int GameBoard::Get_Score(const HumanPlayer& player) const noexcept {
    return player.getScoreObject().getScore();
}


/**
 * @brief Get the score object of a player
 * 
 * @param player 
 * @return Score
 */
Score GameBoard::Get_ScoreObject(const HumanPlayer& player) const noexcept {
    return player.getScoreObject();
}


/**
 * @brief Reset the game deck by clearing it and then building a new one according to the deck specification required
 * 
 * @param deckspecification 
 */
void GameBoard::Reset_GameDeck(DeckSpecification deckspecification) noexcept  {
    // TODO
}


/**
 * @brief get a vector of string where each string represents a card of the deck
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> GameBoard::GetDeck(void) const noexcept {
    return this->_gameDeck->GetDeck();
}
// My Includes
#include "../include/gameboard.hpp"

// Indludes
#include <thread>
#include <utility>  // std::pair


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


/**
 * @brief Play method
 * This describes a whole and full turn of the game Blackjack
 * It has to be repeated, through a while loop for example, as many times as necessary by an external object that will handle the GameBoard.
 * 
 */
void GameBoard::Play(void) noexcept  {
    // If the min number of players isn't reached, ask to remove some to make space for new ones
    // If the max number of players isn't reached, ask to add new ones until it is
    this->checkPlayers();
    
    // Create a thread for each HumanPlayer that isn't nullptr (= for each player ingame), bool = wantsToQuitFlag
    using ThreadUPtr  = std::unique_ptr<std::thread>;
    using ThreadArray = std::array<ThreadUPtr, 4>;
    ThreadArray player_threads;

    for(unsigned int i{0}; i < this->_players.size(); ++i) {
        if(this->_players[i] == nullptr) {
            player_threads[i] = nullptr;
        }
        else {
            player_threads[i] = std::make_unique<ThreadUPtr>(this->_players[i]->Play(), /* some arguments including the returned value*/);
        }
    }

    // Join all threads and get their hand value as well as the bet they made
    for(const auto& t : player_threads) {
        if(t != nullptr) {
            t->join();
        }
    }

    std::array<std::pair<unsigned int, unsigned int>, 4> playerHandsAndBets;    // first = playerHand's value, second = player's bet
    
        // TODO with std::future or other stuff, let's see this part later

    // Now, it's the turn of the CasinoDealer to play
    unsigned int casinoDealerHandValue = this->_casinoDealer->Play(/* some arguments*/);

    // Add or remove the bets
    // RULES :
    // CasinoDealer always win in case of a draw
    // A Blackjack has a value of 50 (we should not have conflicts with card combinations that would lead to a high value)

    // In case of a BlackJack by the CasinoDealer
    if(casinoDealerHandValue == 50) {
        unsigned int i{0};
        for(auto& player : this->_players) {
            player->removeCoinsOfWallet(playerHandsAndBets[i].second);
            ++i;
        }
    }
    else {
        // TODO
    }
    
    // Remove the players that wanted to quit
    for(const auto& p : this->_players) {
        if(p->getLeaving()) {
            this->Remove_Player(p);
        }
    }
    
} // end of GameBoard::Play
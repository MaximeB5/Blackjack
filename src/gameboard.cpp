// My Includes
#include "../include/gameboard.hpp"

// Indludes
#include <thread>
#include <future>   // std::future ; std::async ; std::launch
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
 * @brief check the player array attribute in order to ask a removal of an add of players
 * Current state of the project : v1.1 (i.e. using the std::cout stream for this task)
 * 
 */
void GameBoard::checkPlayers() noexcept {
    // If the min number of players isn't reached, ask to remove some to make space for new ones
    if(this->_players.size() >= NUMBER_OF_PLAYERS_MIN) {
        // TODO
        //std::cout << "Voulez-vous retirer des joueurs de la partie ?\n";
    }

    // If the max number of players isn't reached, ask to add new ones until it is
    if(this->_players.size() < NUMBER_OF_PLAYERS_MAX) {
        // TODO
        //std::cout << "Voulez-vous ajouter de nouveaux joueurs ?\n";
    }
}


/**
 * @brief Play method
 * This describes a whole and full turn of the game Blackjack
 * It has to be repeated, through a while loop for example, as many times as necessary by an external object that will handle the GameBoard.
 * 
 */
void GameBoard::Play(void) noexcept  {
    // Step 1
    //--------
    // If the min number of players isn't reached, ask to remove some to make space for new ones
    // If the max number of players isn't reached, ask to add new ones until it is
    this->checkPlayers();

    
    // Step 2
    //--------
    // Create a task for each HumanPlayer that isn't nullptr (= for each player ingame)
    // What we'll have to know after each call of Play() by HumanPlayer are :
    // - If they want to quit after this turn (known by the getLeaving accessor)
    // - The value of their hand (int)
    // - The bet they made (unsigned int)
    using PlayerDataTypes     = std::pair<int, unsigned int>;
    using uPtrPlayerDataTypes = std::unique_ptr<PlayerDataTypes>;

    std::array<uPtrPlayerDataTypes, NUMBER_OF_PLAYERS_MAX> player_data;

    // 
    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i) {
        if(this->_players[i] != nullptr) {
            auto i_see_the_future = std::async( std::launch::async, &HumanPlayer::Play, this->_players[i].get() );
            player_data[i]        = std::make_unique<PlayerDataTypes>( i_see_the_future.get() );
        }
        else
            player_data[i] = nullptr;
    }


    // Step 3
    //--------
    // Now, it's the turn of the CasinoDealer to play
    // unsigned int casinoDealerHandValue = this->_casinoDealer->Play(/* some arguments*/);

    // Step 4
    //--------
    // Add or remove the bets
    // RULES :
    // CasinoDealer always win in case of a draw
    // A Blackjack has a value of 50 (we should not have conflicts with card combinations that would lead to a high value)

    // In case of a BlackJack by the CasinoDealer
    /*
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
    */

    // Step 5
    //--------
    // Remove the players that wanted to quit
    /*
    for(const auto& p : this->_players) {
        if(p->getLeaving()) {
            this->Remove_Player(p);
        }
    }
    */
    
} // end of GameBoard::Play
// My Includes
#include "../include/gameboard.hpp"

// Indludes
#include <thread>
#include <future>    // std::future ; std::async ; std::launch
#include <utility>   // std::pair
#include <algorithm> // std::find


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
void GameBoard::Set_GameMode(void) noexcept {
    // TODO
}


/**
 * @brief Set the language
 * 
 */
void GameBoard::Set_Language(unsigned int language) noexcept {
    this->_language = language;
}


/**
 * @brief Add a new player to the game board
 * 
 */
void GameBoard::Add_New_Player(std::unique_ptr<HumanPlayer> player) noexcept {
    // TODO
}


/**
 * @brief Remove a player from the game board
 * 
 */
void GameBoard::Remove_Player(HumanPlayer& player) noexcept {
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
    if(this->_players.size() >= NUMBER_OF_PLAYERS_MIN)
    {
        bool it_must_be_done {true};

        do {
            // Ask to remove players (even after a removal)
            std::cout << SENTENCES.at(KEY_REMOVE_PLAYERS)[this->_language] << std::endl;

            std::string answer{""};
            std::cin.ignore();
            std::getline(std::cin, answer);

            if(answer == YES) {
                // Display players ingame
                std::cout << SENTENCES.at(KEY_PLAYERS_INGAME)[this->_language];
                std::vector<std::string> playerIndexes;

                for(unsigned int i{0}; i < this->_players.size(); ++i) {
                    if(this->_players[i] != nullptr) {
                        std::cout << " " << i;
                        playerIndexes.push_back(std::to_string(i));
                    }
                }
                std::cout << std::endl;

                // Ask to enter the id of the player
                std::cout << SENTENCES.at(KEY_INPUT_PLAYERS_INDEX)[this->_language] << std::endl;
                std::cin.ignore();
                std::getline(std::cin, answer);
                
                if( std::find(playerIndexes.begin(), playerIndexes.end(), answer) != playerIndexes.end() ) {
                    // We found the player found so we remove it
                    // The cast is safe since std::find validated the data
                    int tmp = std::stoi(answer);
                    unsigned int index = static_cast<unsigned int>(tmp);
                    this->_players[index].reset();
                }
                else {
                    // The player has not been found, the entry is invalid
                    std::cout << SENTENCES.at(KEY_INVALID_INPUT)[this->_language] << std::endl;
                }
            }
            else {
                // Users do not want to remove a player
                it_must_be_done = false;
            }
        } while(it_must_be_done);
    }

    // If the max number of players isn't reached, ask to add new ones until it is
    if(this->_players.size() < NUMBER_OF_PLAYERS_MAX)
    {
        // TODO
        std::cout << SENTENCES.at(KEY_ADD_PLAYERS)[this->_language] << std::endl;

        std::string answer{""};
        std::cin.ignore();
        std::getline(std::cin, answer);

        if(answer == YES) {
            // TODO
        }
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
    // The players play
    // Create a task for each HumanPlayer that isn't nullptr (= for each player ingame)
    // What we'll have to know after each call of Play() by HumanPlayer are :
    // - If they want to quit after this turn (known by the getLeaving accessor)
    // - The value of their hand (int)
    // - The bet they made (unsigned int)
    using PlayerDataTypes       = std::pair<int, unsigned int>;
    using PlayerDataTypesFuture = std::future<PlayerDataTypes>;

    std::array<PlayerDataTypesFuture, NUMBER_OF_PLAYERS_MAX> player_data_future;

    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i) {
        if(this->_players[i] != nullptr) {
            player_data_future[i] = std::async( std::launch::async,
                                                &HumanPlayer::Play,
                                                this->_players[i].get() );
        }
    }

    // Get the futures
    using uPtrPlayerDataTypes = std::unique_ptr<PlayerDataTypes>;

    unsigned int index{0};
    std::array<uPtrPlayerDataTypes, NUMBER_OF_PLAYERS_MAX> player_data;
    
    for (auto&& i_see_the_future : player_data_future) {
        if(this->_players[index] != nullptr) {
            player_data[index] = std::make_unique<PlayerDataTypes>( i_see_the_future.get() );
        }

        ++index;
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
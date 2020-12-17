// My Includes
#include "../include/gameboard.hpp"
#include "../include/gameboardexception.hpp"

// Indludes
#include <future>           // std::future ; std::async ; std::launch
#include <utility>          // std::pair
#include <algorithm>        // std::find
#include <bits/stdc++.h>    // UINT_MAX = 4 294 967 295 ; INT_MAX = 2 147 483 647


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
void GameBoard::Remove_Player(HumanPlayer* player) noexcept {
    // TODO
}


/**
 * @brief 
 * 
 * @param index 
 */
void GameBoard::Remove_Player_at_Index(unsigned int index) {
    if(index > NUMBER_OF_PLAYERS_MAX - 1) {
        throw GameBoardException{"Error in \"GameBoard::Remove_Player_at_Index\" : The index is not valid."};
    }

    this->_players[index].reset();
}


/**
 * @brief Get the number of players ingame
 * 
 * @return unsigned int 
 */
unsigned int GameBoard::Get_Nb_of_Players(void) const noexcept {
    unsigned int counter{0};

    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i) {
        if(this->_players[i] != nullptr)
            ++counter;
    }

    return counter;
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
    if(this->Get_Nb_of_Players() >= NUMBER_OF_PLAYERS_MIN)
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
        } while(it_must_be_done && (this->Get_Nb_of_Players() >= NUMBER_OF_PLAYERS_MIN));
    }

    // If the max number of players isn't reached, ask to add new ones until it is
    if(this->Get_Nb_of_Players() < NUMBER_OF_PLAYERS_MAX)
    {
        bool it_must_be_done {true};

        do {
            // Ask to add a player (even if an add has been already made before)
            std::cout << SENTENCES.at(KEY_ADD_PLAYERS)[this->_language] << std::endl;

            std::string answer{""};
            std::cin.ignore();
            std::getline(std::cin, answer);

            if(answer == YES) {
                // Ask the player's title
                std::string title;
                bool emptyTitle{false};
                std::cout << SENTENCES.at(KEY_INPUT_TITLE)[this->_language] << std::endl;
                std::cin.ignore();
                std::getline(std::cin, title);
                title.empty() ? emptyTitle = true : emptyTitle = false;

                // Ask the player's name
                std::string name;
                std::cout << SENTENCES.at(KEY_INPUT_NAME)[this->_language] << std::endl;
                std::cin.ignore();
                std::getline(std::cin, name);

                // Ask the value of the player's coins
                std::string s_coins;
                std::cout << SENTENCES.at(KEY_INPUT_COINS)[this->_language] << std::endl;
                std::cin.ignore();
                std::getline(std::cin, s_coins);
                
                // Convert the coins into unsigned int
                /**
                 * @brief lambda named str_to_ui that converts a strint into an unsigned int if it possible
                 * In case of exceptions, it returns 0.
                 * If it exceeds the unsigned int max limit, it returns 0.
                 * 
                 */
                auto str_to_ui = [&s_coins]() -> unsigned int {
                    int value{0};

                    try
                    {
                        value = std::stoi(s_coins);
                    }
                    catch(...)
                    {
                        return 0;
                    }

                    // s_coins has been converted into an int, but if it's negativ, we return 0
                    if(value < 0)
                        return 0;
                    else {
                        // If the value is > 0, it must respect the unsigned int and int limits (minus 1 is for safety)
                        // UINT_MAX = 4 294 967 295 ; INT_MAX = 2 147 483 647
                        if(value >= static_cast<int>(UINT_MAX - 1))
                            return 0;
                        else
                            return static_cast<unsigned int>(value);
                    }
                };
                unsigned int coins{ str_to_ui() };

                // Add the player to a free slot, then it leaves the search for a free slot since the player has been added
                for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i) {
                    if(this->_players[i] == nullptr) {
                        if(emptyTitle)
                            this->_players[i] = std::make_unique<HumanPlayer>(Name{name}, this->_gameDeck, coins);
                        else
                            this->_players[i] = std::make_unique<HumanPlayer>(PlayerTag{ Title{title}, Name{name} }, this->_gameDeck, coins);

                        // I want to
                        break;
                        // free
                        // https://www.youtube.com/watch?v=f4Mc-NYPHaQ&list=PLAc49vcmGBQf5VrqWzlv-4V6NzU_u1_oJ&index=28
                    }
                }
            }
            else {
                // Users do not want to add a player
                it_must_be_done = false;
            }
        } while(it_must_be_done && (this->Get_Nb_of_Players() < NUMBER_OF_PLAYERS_MAX));
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

    // TODO : ask if they're all ready to play and doesn't want to skip

    
    // Step 2
    //--------
    // The players play
    // Create a task for each HumanPlayer that isn't nullptr (= for each player ingame)
    // What we'll have to know after each call of Play() by HumanPlayer are :
    // - If they want to quit after this turn (known by the getLeaving accessor)
    // - The value of their hand (unsigned int), first of the pair
    // - The bet they made (unsigned int), second of the pair
    
    /**
     * @brief lambda named player_ingame_ready_and_notSkipping that'll help to avoir errors on that condition since we use it several times below
     * Based on the player passed as argument, returns if the player is ingame and ready to play.
     * 
     */
    auto player_ingame_ready_and_notSkipping = [](std::unique_ptr<HumanPlayer>& p) -> bool {
        return (p != nullptr && p->getReady() && !p->getSkip());
    };

    using PlayerDataTypes       = std::pair<unsigned int, unsigned int>;    // first = hand ; second = bet
    using PlayerDataTypesFuture = std::future<PlayerDataTypes>;

    std::array<PlayerDataTypesFuture, NUMBER_OF_PLAYERS_MAX> player_data_future;

    // Set the player's ID and prepare the Play tasks
    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i) {
        if(player_ingame_ready_and_notSkipping(this->_players[i])) {
            this->_players[i]->setID(i);

            player_data_future[i] = std::async( std::launch::async,
                                                &HumanPlayer::Play,
                                                this->_players[i].get(),
                                                this->_language );
        }
    }

    // Get the futures and all Play results
    using uPtrPlayerDataTypes = std::unique_ptr<PlayerDataTypes>;

    unsigned int index{0};
    std::array<uPtrPlayerDataTypes, NUMBER_OF_PLAYERS_MAX> player_data; // first = hand ; second = bet
    
    for (auto&& i_see_the_future : player_data_future) {
        if(player_ingame_ready_and_notSkipping(this->_players[index])) {
            player_data[index] = std::make_unique<PlayerDataTypes>( i_see_the_future.get() );
        }

        ++index;
    }


    // Step 3
    //--------
    // Now, it's the turn of the casino dealer to play
    unsigned int casinoDealerHandValue = this->_casinoDealer->Play();


    // Step 4
    //--------
    // Add or remove the bets
    // RULES :
    // CasinoDealer always win in case of a draw
    // A player who wins is a player rewarded by twice his bet
    // Remember: a Blackjack has a value of 50 (we should not have conflicts with card combinations that would lead to a high value)
    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i) {
        // For each player ingame and if the casino dealer won
        if(player_ingame_ready_and_notSkipping(this->_players[i]) && casinoDealerHandValue >= player_data[i]->first) {
            this->_players[i]->removeCoinsOfWallet(player_data[i]->second);
        }
        // The player won against the casino dealer
        else if(player_ingame_ready_and_notSkipping(this->_players[i]) && player_data[i]->first > casinoDealerHandValue) {
            this->_players[i]->addCoinsToWallet(player_data[i]->second * 2);
        }
    }


    // Step 5
    //--------
    // Remove the players that wanted to quit
    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i) {
        if(this->_players[i] != nullptr) {
            if(this->_players[i]->getLeaving()) {
                this->Remove_Player_at_Index(i);
            }
        }
    }

} // end of GameBoard::Play
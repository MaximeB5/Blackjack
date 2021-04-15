// My Includes
#include "../include/gameboard.hpp"
#include "../include/gameboardexception.hpp"
#include "../include/magic_enum.hpp"

// Indludes
#include <future>           // std::future ; std::async ; std::launch
#include <utility>          // std::pair
#include <algorithm>        // std::find
#include <bits/stdc++.h>    // UINT_MAX = 4 294 967 295 ; INT_MAX = 2 147 483 647
#include <ios>              // stream size
#include <limits>           // numeric limits


/**
 * @brief Construct a new Game Board:: Game Board object
 * 
 */
GameBoard::GameBoard(const Name& name, DeckSpecification gameMode, Language languageChosen)
: _gameMode         (gameMode)
, _language_ui      (static_cast<unsigned int>(magic_enum::enum_integer<Language>(languageChosen)))
, _language_str     (magic_enum::enum_name<Language>(languageChosen))
, _casinoDealerName (name.getName())
, _number_of_players(0U)
{
    // RAII
    this->Init();
}


/**
 * @brief Destroy the Game Board:: Game Board object
 * 
 */
GameBoard::~GameBoard()
{
    // RAII
    this->Release();
}


/**
 * @brief RAII method Init
 * 
 */
void GameBoard::Init(void)
{
    // Create the game deck
    this->_gameDeck = std::make_shared<Deck>(this->_gameMode);

    // Create the casino dealer
    this->_casinoDealer = std::make_unique<CasinoDealer>(this->_gameDeck, this->_casinoDealerName);
}


/**
 * @brief RAII method Release
 * 
 */
void GameBoard::Release(void) {}


/**
 * @brief Set the game mode
 * 
 */
void GameBoard::Set_GameMode(DeckSpecification gameMode) noexcept
{
    this->_gameMode = gameMode;

    // Rebuild the game deck with the new game mode
    this->_gameDeck = std::make_shared<Deck>(gameMode);
}


/**
 * @brief Set the language
 * 
 */
void GameBoard::Set_Language(Language language) noexcept
{
    this->_language_ui  = static_cast<unsigned int>(magic_enum::enum_integer<Language>(language));
    this->_language_str = magic_enum::enum_name<Language>(language);
}


/**
 * @brief Get_GameMode
 * 
 * @return DeckSpecification 
 */
DeckSpecification GameBoard::Get_GameMode(void) const noexcept
{
    return this->_gameMode;
}


/**
 * @brief Get_GameMode_Str
 * 
 * @return std::string 
 */
std::string GameBoard::Get_GameMode_Str(void) const noexcept
{
    return std::string(magic_enum::enum_name<DeckSpecification>(this->_gameMode));
}


/**
 * @brief Get_Language
 * 
 * @return std::string 
 */
std::string GameBoard::Get_Language(void) const noexcept {
    return this->_language_str;
}


/**
 * @brief 
 * 
 * @param index 
 */
void GameBoard::Remove_Player_at_Index(unsigned int index)
{
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
unsigned int GameBoard::Get_Nb_of_Players(void) const noexcept
{
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
void GameBoard::Add_Coins_To_Player(std::unique_ptr<HumanPlayer>& player, unsigned int coinsValue) noexcept
{
    player->addCoinsToWallet(coinsValue);
}


/**
 * @brief Set an amout of coins to a player
 * 
 * @param player 
 */
void GameBoard::Set_Coins_To_Player(std::unique_ptr<HumanPlayer>& player, unsigned int coinsValue) noexcept 
{
    player->setCoinsOfWallet(coinsValue);
}


/**
 * @brief Remove coins to a player
 * 
 * @param player 
 */
void GameBoard::Remove_Coins_To_Player(std::unique_ptr<HumanPlayer>& player, unsigned int coinsValue) noexcept
{
    player->removeCoinsOfWallet(coinsValue);
}


/**
 * @brief Increase the score of a player
 * 
 * @param player 
 */
void GameBoard::Increase_Score(std::unique_ptr<HumanPlayer>& player) noexcept
{
    player->getScoreObject().Increase_Win();
}


/**
 * @brief Decrease the score of a player
 * 
 * @param player 
 */
void GameBoard::Decrease_Score(std::unique_ptr<HumanPlayer>& player) noexcept
{
    player->getScoreObject().Increase_Defeat();
}


/**
 * @brief Get the score of a player
 * 
 * @param player 
 * @return int 
 */
int GameBoard::Get_Score(const std::unique_ptr<HumanPlayer>& player) const noexcept
{
    return player->getScoreObject().getScore();
}


/**
 * @brief Get the score object of a player
 * 
 * @param player 
 * @return Score
 */
Score GameBoard::Get_ScoreObject(const std::unique_ptr<HumanPlayer>& player) const noexcept
{
    return player->getScoreObject();
}


/**
 * @brief Reset the game deck by clearing it and then building a new one according to the deck specification required
 * 
 * @param deckspecification 
 */
void GameBoard::Reset_GameDeck(DeckSpecification deckspecification) noexcept
{
    // TODO
}


/**
 * @brief get a vector of string where each string represents a card of the deck
 * 
 * @return std::vector<std::string> 
 */
std::vector<std::string> GameBoard::GetDeck(void) const noexcept
{
    return this->_gameDeck->GetDeck();
}


/**
 * @brief check the player array attribute in order to ask a removal of an add of players
 * Current state of the project : v1.1 (i.e. using the std::cout stream for this task)
 * 
 */
void GameBoard::checkPlayers() noexcept
{
    // FIRST CHECK = PLAYER'S REMOVAL
    //
    // If the min number of players isn't reached, ask to remove some to make space for new ones
    if(this->Get_Nb_of_Players() >= NUMBER_OF_PLAYERS_MIN)
    {
        bool it_must_be_done {true};

        do {
            // Ask to remove players (even after a removal)
            std::cout << SENTENCES.at(KEY_REMOVE_PLAYERS)[this->_language_ui] << std::endl;

            std::string answer{""};
            std::getline(std::cin, answer);

            if(answer.compare(YES) == 0) {
                // Display players ingame
                std::cout << SENTENCES.at(KEY_PLAYERS_INGAME)[this->_language_ui];
                std::vector<std::string> playerIndexes;

                for(unsigned int i{0}; i < this->_players.size(); ++i) {
                    if(this->_players[i] != nullptr) {
                        PlayerTag pt = this->_players[i]->getPlayerTag();
                        std::cout << "(" << i << ") " << pt.to_str() << " ";
                        playerIndexes.push_back(std::to_string(i));
                    }
                }
                std::cout << std::endl;

                // Ask to enter the id of the player
                std::cout << SENTENCES.at(KEY_INPUT_PLAYERS_INDEX)[this->_language_ui] << std::endl;
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
                    std::cout << SENTENCES.at(KEY_INVALID_INPUT)[this->_language_ui] << std::endl;
                }
            }
            else {
                // Users do not want to remove a player
                it_must_be_done = false;
            }
        } while(it_must_be_done && (this->Get_Nb_of_Players() >= NUMBER_OF_PLAYERS_MIN));
    }


    // SECOND CHECK = PLAYER'S ADD
    //
    // If the max number of players isn't reached, ask to add new ones until it is
    if(this->Get_Nb_of_Players() < NUMBER_OF_PLAYERS_MAX)
    {
        bool it_must_be_done {true};

        do {
            // Ask to add a player (even if an add has been already made before)
            std::cout << SENTENCES.at(KEY_ADD_PLAYERS)[this->_language_ui] << std::endl;

            std::string answer{""};
            std::getline(std::cin, answer);

            if(answer.compare(YES) == 0) {
                // Ask the player's title
                std::string title;
                bool emptyTitle{false};
                std::cout << SENTENCES.at(KEY_INPUT_TITLE)[this->_language_ui] << std::endl;
                std::getline(std::cin, title);
                title.empty() ? emptyTitle = true : emptyTitle = false;

                // Ask the player's name
                std::string name;
                std::cout << SENTENCES.at(KEY_INPUT_NAME)[this->_language_ui] << std::endl;
                std::getline(std::cin, name);

                // Ask the value of the player's coins
                std::string s_coins;
                std::cout << SENTENCES.at(KEY_INPUT_COINS)[this->_language_ui] << std::endl;
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
                        /*if(value >= static_cast<int>(UINT_MAX - 1))
                            return 0;
                        else*/ // commented cause not working as expected
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
bool GameBoard::Play(void) noexcept
{   
    // Step 1.a
    //----------
    // If the min number of players isn't reached, ask to remove some to make space for new ones
    // If the max number of players isn't reached, ask to add new ones until it is
    this->checkPlayers();

    // Step 1.b
    //----------
    // Ask for all players ingame if they're ready to play (if not, they'll skip this turn)
    this->askPlayersSkipOrNot();

    // Step 1.c
    //----------
    // Reset and create a Deck. We can switch the mode at each turn if it is wanted by at least one player.
    // Read the documentation of GameBoard::askToSwitchOrNotTheGameMode() for more information about that point.
    this->resetGameDeck( this->askToSwitchOrNotTheGameMode() );

    
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

    // Reset the meta data (it has to be updated manually each turn (in order to decide if the CasinoDealer plays or not))
    this->_number_of_players = 0;

    // Set the player's ID, update the meta data _number_of_players and prepare the Play tasks
    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i)
    {
        if(player_ingame_ready_and_notSkipping(this->_players[i]))
        {
            this->_players[i]->setID(i);
            ++_number_of_players;
            player_data_future[i] = std::async( std::launch::async,
                                                &HumanPlayer::Play,
                                                this->_players[i].get(),
                                                this->_language_ui );
        }
    }

    // Get the futures and all Play results
    using uPtrPlayerDataTypes = std::unique_ptr<PlayerDataTypes>;

    unsigned int index{0};
    std::array<uPtrPlayerDataTypes, NUMBER_OF_PLAYERS_MAX> player_data; // first = hand ; second = bet
    
    for (auto&& i_see_the_future : player_data_future)
    {
        if(player_ingame_ready_and_notSkipping(this->_players[index]))
        {
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
    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i)
    {
        // For each player ingame
        if(player_ingame_ready_and_notSkipping(this->_players[i]))
        {
            // Display the results of the player
            // If Blackjack
            if( player_data[i]->first == BLACKJACK_ACE_VALUE ) {
                std::cout << this->_players[i]->getPlayerTag().to_str() << " " << SENTENCES.at(KEY_RESULT_PLAYER_VALUE)[this->_language_ui] << MAX_VALUE_TO_WIN << std::endl;
            }
            else {
                std::cout << this->_players[i]->getPlayerTag().to_str() << " " << SENTENCES.at(KEY_RESULT_PLAYER_VALUE)[this->_language_ui] << player_data[i]->first << std::endl;
            }

            // Display the results of the casino dealer
            if( casinoDealerHandValue == BLACKJACK_ACE_VALUE ) {
                std::cout << SENTENCES.at(KEY_RESULT_CASINO_DEALER_VALUE)[this->_language_ui] << KEY_INFO_BLACKJACK << std::endl;
            }
            else {
                std::cout << SENTENCES.at(KEY_RESULT_CASINO_DEALER_VALUE)[this->_language_ui] << std::to_string(casinoDealerHandValue) << std::endl;
            }

            // If the hand value of the casino dealer exceeded 21 but is not a Blackjack, we set it to 0 which means a win in all case for the user (if he didn't exceed 21 as well)
            if(casinoDealerHandValue > 21 && casinoDealerHandValue != BLACKJACK_ACE_VALUE)
            {
                casinoDealerHandValue = 0;
            }

            // If the casino dealer won
            if(player_ingame_ready_and_notSkipping(this->_players[i]) && casinoDealerHandValue >= player_data[i]->first && (casinoDealerHandValue <= MAX_VALUE_TO_WIN || casinoDealerHandValue == BLACKJACK_ACE_VALUE))
            {
                // If Blackjack
                if( casinoDealerHandValue == BLACKJACK_ACE_VALUE ) {
                    casinoDealerHandValue = MAX_VALUE_TO_WIN;
                }

                std::cout << SENTENCES.at(KEY_RESULT_DEFEAT)[this->_language_ui] << std::endl;
                this->_players[i]->removeCoinsOfWallet(player_data[i]->second);
            }
            // If the player won against the casino dealer
            else if(player_ingame_ready_and_notSkipping(this->_players[i]) && player_data[i]->first > casinoDealerHandValue && (player_data[i]->first <= MAX_VALUE_TO_WIN || player_data[i]->first == BLACKJACK_ACE_VALUE))
            {
                // If Blackjack
                if( player_data[i]->first == BLACKJACK_ACE_VALUE ) {
                    player_data[i]->first = MAX_VALUE_TO_WIN;
                }

                std::cout << SENTENCES.at(KEY_RESULT_WIN)[this->_language_ui] << std::endl;
                this->_players[i]->addCoinsToWallet(player_data[i]->second * 2);
            }

            // If the player lost (player hand value over MAX_VALUE_TO_WIN)
            else
            {
                std::cout << SENTENCES.at(KEY_RESULT_DEFEAT)[this->_language_ui] << std::endl;
                this->_players[i]->removeCoinsOfWallet(player_data[i]->second);
            }

            // Display the coins after change
            std::cout << SENTENCES.at(KEY_INFO_WALLET)[this->_language_ui] << std::to_string(this->_players[i]->getCoinsOfWallet()) << SENTENCES.at(KEY_INFO_COINS)[this->_language_ui] << std::endl;
        }
    }


    // Step 5
    //--------
    // Reset the player hand for all players, otherwise the cards stay in it
    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i)
    {
        if(this->_players[i] != nullptr)
        {

            this->_players[i]->resetPlayerHand();
        }
    }


    // Step 6
    //--------
    // Remove the players that wanted to quit
    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i)
    {
        if(this->_players[i] != nullptr)
        {
            if(this->_players[i]->getLeaving())
            {
                this->Remove_Player_at_Index(i);
            }
        }
    }

    // Step 6
    //--------
    // Possibility to leave the program
    if(this->askToExitProgram()) 
    {
        // if yes to exit the program, we return false to play
        return false;
    }

    // By default, we return true to keep playing
    return true;
} // end of GameBoard::Play


/**
 * @brief ask to all the players ingame if they want to skip this turn or not.
 * 
 */
void GameBoard::askPlayersSkipOrNot(void) noexcept
{
    for(unsigned int i{0}; i < NUMBER_OF_PLAYERS_MAX; ++i)
    {
        if( this->_players[i] != nullptr )
        {
            std::cout << this->_players[i]->getPlayerTag().to_str() << " " << SENTENCES.at(KEY_QUESTION_SKIP_THIS_TURN_P)[this->_language_ui] << std::endl;
            std::string answer{""};
            std::getline(std::cin, answer);

            answer.compare(YES) == 0 ? this->_players[i]->setSkip(true) : this->_players[i]->setSkip(false);
        }
    }
}


/**
 * @brief ask to the players if they want to switch the game mode or not.
 * There is a single ask request, 1st player to answer is the answer.
 * I implement it this way because it's easier to do, and for the game itself.
 * It's up to the players to agree on the game mode.
 * 
 * @return DeckSpecification 
 */
DeckSpecification GameBoard::askToSwitchOrNotTheGameMode(void) const noexcept {
    std::cout << SENTENCES.at(KEY_ASK_TO_CHANGE_GAME_MODE)[this->_language_ui] << std::endl;

    std::string answer{""};
    std::getline(std::cin, answer);

    // The user requested to change the game mode
    if(answer.compare(YES) == 0)
    {
        // Display all available modes 
        std::cout << SENTENCES.at(KEY_GAME_MODES_ARE)[this->_language_ui] << std::endl;

        constexpr std::size_t color_count = magic_enum::enum_count<DeckSpecification>();

        // It will store the integer values of the enum to compare them with the user input. I use string for an easier check with the user input (see below)
        std::array<std::string, color_count> array_of_enums;

        for(std::size_t i{0}; i < color_count; ++i)
        {
            auto enumInteger = magic_enum::enum_integer( magic_enum::enum_value<DeckSpecification>(i) );

            array_of_enums[i] = std::to_string(enumInteger);
            std::cout << "(" << enumInteger << ") " << magic_enum::enum_name<DeckSpecification>( magic_enum::enum_value<DeckSpecification>(i) ) << std::endl;
        }

        // Ask the user to enter one of the available modes
        std::string answer{""};
        std::cout << SENTENCES.at(KEY_INPUT_GAME_MODE)[this->_language_ui] << std::endl;
        std::getline(std::cin, answer);

        // Check the answer
        if( std::find(std::begin(array_of_enums), std::end(array_of_enums), answer) != std::end(array_of_enums))
        {
            // Valid answer
            auto color = magic_enum::enum_cast<DeckSpecification>( std::stoi(answer) );

            if (color.has_value())
            {
                // Change of the mode ok
                return color.value();
            }
            else {
                // Internal error during conversion
                return DeckSpecification::DefaultDeck;
            }
        }
        else {
            // Invalid answer
            return DeckSpecification::DefaultDeck;
        }
    }

    // Default case
    else {
        return DeckSpecification::DefaultDeck;
    }
}


/**
 * @brief reset the game deck and initialize it with the DeckSpecification gameMode.
 * If the DeckSpecification gameMode doesn't exist or isn't implemented, it warns the users and create a DefaultDeck.
 * 
 * @param gameMode 
 */
void GameBoard::resetGameDeck(DeckSpecification gameMode) {
    this->_gameDeck->Reset();

    try
    {
        this->_gameDeck->Create_a_new_Deck(gameMode);

        // Update the internal data
        this->_gameMode = gameMode;
    }
    catch(const std::exception& e)
    {
        std::cout << "\n\n\t\t ! ! ! ----- " << e.what() << " ----- ! ! !\n";
        std::cout << "\t\t ! ! ! ----- A DEFAULT DECK WILL NOW BE CREATING TO HANDLE THE ERROR ----- ! ! !\n\n";
        this->_gameDeck->Create_a_new_Deck(DeckSpecification::DefaultDeck);

        // Update the internal data
        this->_gameMode = DeckSpecification::DefaultDeck;
    }
}


/**
 * @brief ask to all users if they want to exit the program. It led to exiting the Game Loop in the main being given the GameBoard::Play method will return false
 * 
 * @return true 
 * @return false 
 */
bool GameBoard::askToExitProgram(void) const noexcept
{
    std::cout << SENTENCES.at(KEY_INFO_QUIT_GAME)[this->_language_ui] << std::endl;

    std::string answer{""};
    std::getline(std::cin, answer);

    // The user requested to change the game mode
    if(answer.compare(YES) == 0)
    {
        return true;
    }

    return false;
}
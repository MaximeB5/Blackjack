// My Includes
#include "../include/humanplayer.hpp"
#include "../include/deckexception.hpp"

// Includes
    // None for the moment.

// Debug
#include<iostream>


// Static members initialization
unsigned int HumanPlayer::MetaData::Total_of_Players_in_Game = 0;
unsigned int HumanPlayer::MetaData::Total_of_Coins_in_Game   = 0;


/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param playerTag
 * @param gameDeck 
 */
HumanPlayer::HumanPlayer(const PlayerTag& playerTag, std::shared_ptr<Deck> gameDeck)
: _playerTag(playerTag), _wallet(Coins(0)) {
    // RAII
    this->Init();

    this->initGameDeck(gameDeck);
}


/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param name
 * @param gameDeck
 */
HumanPlayer::HumanPlayer(const Name& name, std::shared_ptr<Deck> gameDeck)
: _playerTag(name), _wallet(Coins(0)) {
    // RAII
    this->Init();

    this->initGameDeck(gameDeck);
}


/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param title
 * @param name
 * @param gameDeck
 */
HumanPlayer::HumanPlayer(const Title& title, const Name& name, std::shared_ptr<Deck> gameDeck)
: _playerTag(title, name), _wallet(Coins(0)) {
    // RAII
    this->Init();

    this->initGameDeck(gameDeck);
}


/**
 * @brief initGameDeck
 * 
 * @param gameDeck 
 */
void HumanPlayer::initGameDeck(std::shared_ptr<Deck> gameDeck) {
    this->_deck = gameDeck;
}


/**
 * @brief Destroy the Human Player:: Human Player object
 * 
 */
HumanPlayer::~HumanPlayer()
{
    // RAII
    this->Release();
}


/**
 * @brief RAII method Init
 * 
 */
void HumanPlayer::Init() {
    // Ptr members
    this->_playerHand = std::make_unique<Deck>(NUMBER_OF_CARDS_AT_START);

    // Flags
    this->_isReadyToPlay    = false;
    this->_wantsToLeave     = false;
    this->_wantsToSkip      = false;

    // MetaData
    this->_MetaData.Total_of_Players_in_Game++;
    this->_MetaData.Total_of_Coins_in_Game += this->_wallet.getCoins();
}


/**
 * @brief RAII method Release
 * 
 */
void HumanPlayer::Release() {
    // MetaData
    this->_MetaData.Total_of_Players_in_Game--;
    this->_MetaData.Total_of_Coins_in_Game -= this->_wallet.getCoins();
}


/**
 * @brief overriden method from IGameEntity
 * It takes a card from the game deck and place it in the player hand.
 * 
 */
void HumanPlayer::Pick_a_Card() {
    this->_playerHand->Add_a_Card( this->_deck->Give_a_Card() );
}


/**
 * @brief overriden method from IGameEntity
 * 
 */
void HumanPlayer::Skip_Turn() {
    this->setBooleanMembers(false, false, true);
}


/**
 * @brief overriden method from IGameEntity
 * 
 */
void HumanPlayer::Turn_is_Over() {
    this->setBooleanMembers(false, false, false, true);
}


/**
 * @brief overriden method from IPlayer
 * 
 */
void HumanPlayer::Ready_to_Play() {
    this->setBooleanMembers(true);
}


/**
 * @brief overriden method from IPlayer
 * 
 */
void HumanPlayer::Quit_Game() {
    this->setBooleanMembers(false, true);
}


/**
 * @brief getCoinsOfWallet
 * 
 * @return unsigned int 
 */
unsigned int HumanPlayer::getCoinsOfWallet() const noexcept {
    return this->_wallet.getCoins();
}


/**
 * @brief addCoinsToWallet
 * 
 * @param value 
 */
void HumanPlayer::addCoinsToWallet(unsigned int value) noexcept {
    try
    {
        this->_wallet.addCoins(value); // can throw

        // if it throws, the MetaData will not be changed so it's ok
        this->_MetaData.Total_of_Coins_in_Game += value;
    }
    catch(const CoinsException& ce)
    {
        std::cerr << ce.what() << '\n';
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    catch(...) {
        std::cerr << "Something unforeseen just happened in HumanPlayer::addCoinsToWallet" << '\n'; // v1.1 of the project ; v1.2 -> using log system instead
    }
}


/**
 * @brief setCoinsOfWallet
 * 
 * @param value 
 */
void HumanPlayer::setCoinsOfWallet(unsigned int value) noexcept {
    try
    {
        unsigned int tmp{ this->_wallet.getCoins() };

        this->_wallet.setCoins(value); // can throw

        // if it throws, the MetaData will not be changed so it's ok
        this->_MetaData.Total_of_Coins_in_Game -= tmp;
        this->_MetaData.Total_of_Coins_in_Game += value;
    }
    catch(const CoinsException& ce)
    {
        std::cerr << ce.what() << '\n';
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    catch(...) {
        std::cerr << "Something unforeseen just happened in HumanPlayer::setCoinsToWallet" << '\n'; // v1.1 of the project ; v1.2 -> using log system instead
    }
}


/**
 * @brief removeCoinsOfWallet
 * 
 * @param value 
 */
void HumanPlayer::removeCoinsOfWallet(unsigned int value) noexcept {
    try
    {
        this->_wallet.removeCoins(value); // can throw

        // if it throws, the MetaData will not be changed so it's ok
        this->_MetaData.Total_of_Coins_in_Game -= value;
    }
    catch(const CoinsException& ce)
    {
        std::cerr << ce.what() << '\n';
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    catch(...) {
        std::cerr << "Something unforeseen just happened in HumanPlayer::removeCoinsOfWallet" << '\n'; // v1.1 of the project ; v1.2 -> using log system instead
    }
}


/**
 * @brief dropCard
 * 
 * @param card 
 */
void HumanPlayer::dropCard(Card& card) noexcept {
    try
    {
        this->_playerHand->Drop_a_Specific_Card(card);
    }
    catch(const DeckException& de)
    {
        std::cerr << de.what() << '\n'; // v1.1 of the project ; v1.2 -> using log system instead
    }
    catch(...) 
    {
        std::cerr << "HumanPlayer::dropCard thrown an unknown exception" << '\n'; // v1.1 of the project ; v1.2 -> using log system instead
    }
}


/**
 * @brief addCard
 * 
 * @param card 
 */
void HumanPlayer::addCard(Card& card) noexcept {
    this->_playerHand->Add_a_Card(card);
}


/**
 * @brief set the boolean flags
 * 
 * @param ready default value = false
 * @param leaving default value = false
 * @param skip default value = false
 * @param endTurn default value = false
 */
void HumanPlayer::setBooleanMembers(bool ready, bool leaving, bool skip, bool endTurn) {
    this->_isReadyToPlay     = ready;
    this->_wantsToLeave      = leaving;
    this->_wantsToSkip       = skip;
    this->_wantsToEndHisTurn = endTurn;
}
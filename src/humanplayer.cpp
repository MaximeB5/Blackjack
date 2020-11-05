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
    this->Release();
}

/**
 * @brief RAII method Init
 * 
 */
void HumanPlayer::Init() {
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
 * @brief overriden method from IPlayer
 * 
 */
void HumanPlayer::Ready_to_Play() {
    this->setBooleanMembers(true, false, false);
}

/**
 * @brief overriden method from IPlayer
 * 
 */
void HumanPlayer::Quit_Game() {
    this->setBooleanMembers(false, true, false);
}

/**
 * @brief getCoinsOfWallet
 * 
 * @return unsigned int 
 */
unsigned int HumanPlayer::getCoinsOfWallet() const noexcept{
    return this->_wallet.getCoins();
}

/**
 * @brief addCoinsToWallet
 * 
 * @param value 
 */
void HumanPlayer::addCoinsToWallet(unsigned int value) noexcept{
    this->_wallet.addCoins(value);
    this->_MetaData.Total_of_Coins_in_Game += value;
}

/**
 * @brief setCoinsOfWallet
 * 
 * @param value 
 */
void HumanPlayer::setCoinsOfWallet(unsigned int value) noexcept{
    this->_MetaData.Total_of_Coins_in_Game -= this->_wallet.getCoins();
    this->_wallet.setCoins(value);
    this->_MetaData.Total_of_Coins_in_Game += value;
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
void HumanPlayer::addCard(Card& card)  noexcept {
    this->_playerHand->Add_a_Card(card);
}

void HumanPlayer::setBooleanMembers(bool ready, bool leaving, bool skip) {
    this->_isReadyToPlay = ready;
    this->_wantsToLeave  = leaving;
    this->_wantsToSkip   = skip;
}
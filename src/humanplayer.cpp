// My Includes
#include "../include/humanplayer.hpp"
#include "../include/deckexception.hpp"
#include "../include/magic_enum.hpp"
#include "../include/safeio.hpp"

// Includes
    // None for the moment.

// Debug
#include<iostream>

// Static members initialization
unsigned int HumanPlayer::MetaData::Total_of_Players_in_Game = 0;
unsigned int HumanPlayer::MetaData::Total_of_Coins_in_Game   = 0;

// Special class
class SafeCoutRemake{
    static std::mutex staticMutex;
    public:
    static void print(const std::string& msg) {
        std::lock_guard<std::mutex> lock(staticMutex);      
        std::cout << msg << "\n";
    }

    std::string ask(void) {
        std::lock_guard<std::mutex> lock(staticMutex);      
        std::string answer{""};
        std::cin.ignore();
        std::getline(std::cin, answer);
        return answer;
    }
};

// Special class - Static member initialization
std::mutex SafeCoutRemake::staticMutex;


/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param playerTag
 * @param gameDeck 
 */
HumanPlayer::HumanPlayer(const PlayerTag& playerTag, std::shared_ptr<Deck> gameDeck, unsigned int coinsAtStart)
: _playerTag(playerTag), _wallet(Coins(coinsAtStart)) {
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
HumanPlayer::HumanPlayer(const Name& name, std::shared_ptr<Deck> gameDeck, unsigned int coinsAtStart)
: _playerTag(name), _wallet(Coins(coinsAtStart)) {
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
HumanPlayer::HumanPlayer(const Title& title, const Name& name, std::shared_ptr<Deck> gameDeck, unsigned int coinsAtStart)
: _playerTag(title, name), _wallet(Coins(coinsAtStart)) {
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
void HumanPlayer::Init(void) {
    // Ptr members
    this->_playerHand = std::make_unique<Deck>(NUMBER_OF_CARDS_AT_START);

    // ID
    this->_id = -1; // the id of the player, has a value of -1 by default. This id is set by the GameBoard at each turn.

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
void HumanPlayer::Release(void) {
    // MetaData
    this->_MetaData.Total_of_Players_in_Game--;
    this->_MetaData.Total_of_Coins_in_Game -= this->_wallet.getCoins();
}


/**
 * @brief overriden method from IGameEntity
 * It takes a card from the game deck and place it in the player hand.
 * 
 */
void HumanPlayer::Pick_a_Card(void) {
    this->_playerHand->Add_a_Card( this->_deck->Give_a_Card() );
}


/**
 * @brief overriden method from IGameEntity
 * 
 */
void HumanPlayer::Skip_Turn(void) {
    this->setBooleanMembers(false, false, true);
}


/**
 * @brief overriden method from IGameEntity
 * 
 */
void HumanPlayer::Turn_is_Over(void) {
    this->setBooleanMembers(false, false, false, true);
}


/**
 * @brief overriden method from IPlayer
 * 
 */
void HumanPlayer::Ready_to_Play(void) {
    this->setBooleanMembers(true);
}


/**
 * @brief overriden method from IPlayer
 * 
 */
void HumanPlayer::Quit_Game(void) {
    this->setBooleanMembers(false, true);
}


/**
 * @brief overriden method from IPlay
 * This describes all the actions a player can do during its turn
 * 
 * @return std::pair<unsigned int, unsigned int> where first is the player hand value, and second is the bet he made during his turn
 */
std::pair<unsigned int, unsigned int> HumanPlayer::Play(void) noexcept {
    auto bet        {0U};
    auto handValue  {0U};
    auto nbOfAs     {0U};   // the number of As in the hand so we can iterate on it

    // Ask for a bet
    auto sio = SafeIO();
    std::string msg = "test";
    sio.print(msg);
    
    
    // The first two picks in order to know if it's a blackjack or not
    this->Pick_a_Card();
    this->Pick_a_Card();

    auto cards = this->_deck->GetDeck();  

    // If it's a Blackjack
    if(this->isBlackjack( cards[0], cards[1] ))
    {
        handValue = BLACKJACK_ACE_VALUE;
        return std::make_pair(handValue, bet);
    }

    // If it wasn't a Blackjack, we keep playing



    // Ask if the player wants to skip next turn, or to leave

    return std::make_pair<unsigned int, unsigned int>(0, 0);
}


/**
 * @brief getCoinsOfWallet
 * 
 * @return unsigned int 
 */
unsigned int HumanPlayer::getCoinsOfWallet(void) const noexcept {
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


/**
 * @brief based on the 2 cards passed, return true if it's a Blackjack, else false
 * 
 * @param card1 
 * @param card2 
 * @return true 
 * @return false 
 */
bool HumanPlayer::isBlackjack(const std::string& card1, const std::string& card2) const noexcept {
    // If card1 is an As and card2 == 10 or similar
    if(card1.find(magic_enum::enum_name<CardValue>(CardValue::As)) != std::string::npos
        &&
        (
                card2.find(magic_enum::enum_name<CardValue>(CardValue::Ten)) != std::string::npos
            ||
                card2.find(magic_enum::enum_name<CardValue>(CardValue::Jack)) != std::string::npos
            ||
                card2.find(magic_enum::enum_name<CardValue>(CardValue::Queen)) != std::string::npos
            ||
                card2.find(magic_enum::enum_name<CardValue>(CardValue::King)) != std::string::npos
        )
    )
    return true;

    // If card2 is an As and card1 == 10 or similar
    if(card2.find(magic_enum::enum_name<CardValue>(CardValue::As)) != std::string::npos
        &&
        (
                card1.find(magic_enum::enum_name<CardValue>(CardValue::Ten)) != std::string::npos
            ||
                card1.find(magic_enum::enum_name<CardValue>(CardValue::Jack)) != std::string::npos
            ||
                card1.find(magic_enum::enum_name<CardValue>(CardValue::Queen)) != std::string::npos
            ||
                card1.find(magic_enum::enum_name<CardValue>(CardValue::King)) != std::string::npos
        )
    )
    return true;

    // It wasn't a Blackjack
    return false;
}
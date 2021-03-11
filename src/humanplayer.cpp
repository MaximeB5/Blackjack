// My Includes
#include "../include/humanplayer.hpp"
#include "../include/deckexception.hpp"
#include "../include/magic_enum.hpp"
#include "../include/constants.hpp"

// Includes
#include <algorithm>    // std::for_each

// Debug
#include<iostream>

// Static members initialization
unsigned int HumanPlayer::MetaData::Total_of_Players_in_Game = 0;
unsigned int HumanPlayer::MetaData::Total_of_Coins_in_Game   = 0;

// Special class
class SafeIO {
    static std::mutex staticMutex;

    public:
    static void print(const std::string& msg) {
        std::lock_guard<std::mutex> lock(staticMutex);      
        std::cout << msg << "\n";
    }

    static std::string ask(const std::string& msg) {
        std::lock_guard<std::mutex> lock(staticMutex);
        std::cout << msg << "\n";

        std::string answer{""};
        std::getline(std::cin, answer);

        return answer;
    }
};

// Special class - Static member initialization
std::mutex SafeIO::staticMutex;


/**
 * @brief Construct a new Human Player:: Human Player object
 * 
 * @param playerTag
 * @param gameDeck 
 */
HumanPlayer::HumanPlayer(const PlayerTag& playerTag, std::shared_ptr<Deck> gameDeck, unsigned int coinsAtStart)
: _playerTag(playerTag)
, _wallet(Coins(coinsAtStart)) {
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
: _playerTag(name)
, _wallet(Coins(coinsAtStart))
{
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
: _playerTag(title, name)
, _wallet(Coins(coinsAtStart))
{
    // RAII
    this->Init();

    this->initGameDeck(gameDeck);
}


/**
 * @brief initGameDeck
 * 
 * @param gameDeck 
 */
void HumanPlayer::initGameDeck(std::shared_ptr<Deck> gameDeck)
{
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
void HumanPlayer::Init(void)
{
    // Ptr members
    this->_playerHand = std::make_unique<Deck>(NUMBER_OF_CARDS_AT_START);

    // ID
    this->_id = -1; // the id of the player, has a value of -1 by default. This id is set by the GameBoard at each turn.

    // Flags
    this->_isReadyToPlay    = true;
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
void HumanPlayer::Release(void)
{
    // MetaData
    this->_MetaData.Total_of_Players_in_Game--;
    this->_MetaData.Total_of_Coins_in_Game -= this->_wallet.getCoins();
}


/**
 * @brief overriden method from IGameEntity
 * It takes a card from the game deck and place it in the player hand.
 * 
 */
void HumanPlayer::Pick_a_Card(void)
{
    this->_playerHand->Add_a_Card( this->_deck->Give_a_Card() );
}


/**
 * @brief overriden method from IGameEntity
 * 
 */
void HumanPlayer::Skip_Turn(void)
{
    this->setBooleanMembers(false, false, true);
}


/**
 * @brief overriden method from IGameEntity
 * 
 */
void HumanPlayer::Turn_is_Over(void)
{
    this->setBooleanMembers(false, false, false, true);
}


/**
 * @brief overriden method from IPlayer
 * 
 */
void HumanPlayer::Ready_to_Play(void)
{
    this->setBooleanMembers(true);
}


/**
 * @brief overriden method from IPlayer
 * 
 */
void HumanPlayer::Quit_Game(void)
{
    this->setBooleanMembers(false, true);
}


/**
 * @brief overriden method from IPlay
 * This describes all the actions a player can do during its turn
 * 
 * @param language 
 * @return std::pair<unsigned int, unsigned int> where first is the player hand value, and second is the bet he made during his turn
 */
std::pair<unsigned int, unsigned int> HumanPlayer::Play(const unsigned int language) noexcept
{
    // Check if the wallet is empty (= cannot play) or not. It prevents further errors such as an infinite loop when a bet is asked.
    if( this->getCoinsOfWallet() == 0 ) {
        return std::make_pair<unsigned int, unsigned int>(0U, 0U);
    }

    // Convert the coins into unsigned int
    /**
     * @brief lambda named str_to_ui that converts a strint into an unsigned int if it possible
     * In case of exceptions, it returns 0.
     * If it exceeds the unsigned int max limit, it returns 0.
     * 
     */
    auto str_to_ui = [](const std::string& s_coins) -> unsigned int {
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
        if(value < 0) {
            return 0;
        }
        else {
            // If the value is > 0, it must respect the unsigned int and int limits (minus 1 is for safety)
            // UINT_MAX = 4 294 967 295 ; INT_MAX = 2 147 483 647
            if(value >= (INT_MAX - 1)) {
                return 0;
            }
            else {
                return static_cast<unsigned int>(value);
            }
        }
    };
    
    // Stuff we need
    auto handValue  {0U};
    auto bet        {0U};

    // Ask for a bet
    bool betIsNotValid{true};

    do {
        auto tmpBet = str_to_ui( SafeIO::ask( SENTENCES.at(KEY_INPUT_BET)[language] ) );
        
        if( tmpBet > 0 && tmpBet <= this->_wallet.getCoins() )
        {
            bet = tmpBet;
            betIsNotValid = false;
        }
    } while(betIsNotValid);
    
    // The first two picks in order to know if it's a blackjack or not
    this->Pick_a_Card();
    this->Pick_a_Card();

    // Display cards picked and the value of the player hands
    this->displayPlayerHand(language);
    this->displayPlayerHandValue(language);

    auto cards = this->_deck->GetDeck();  

    // If it's a Blackjack
    if(this->isBlackjack( cards[0], cards[1] ))
    {
        // Inform the user it's a Blackjack
        SafeIO::print( SENTENCES.at(KEY_INFO_BLACKJACK)[language] );

        // Update the handValue with the defined value for a Blackjack
        handValue = BLACKJACK_ACE_VALUE;

        return std::make_pair(handValue, bet);
    }

    // If it wasn't a Blackjack, we keep playing according to the player's will
    // At each iteration, the player can :
    //  End his turn :
    //      - In this case, the system will ask to him if he wants to :
    //                                                              - Leave the game after this turn
    //                                                              - Skip the next turn
    //                                                              - Keep playing
    //
    //  Or
    //  Play :
    //      - He either maintains his bet or increase it
    //      - Then, he picks a card
    //
    // But the iterations can end if the player's hand value goes above the MAX_VALUE_TO_WIN

    bool player_s_will{true};

    do {
        // Get the current hand value
        handValue = this->getHandValue();

        // End turn
        if( SafeIO::ask( SENTENCES.at(KEY_QUESTION_END_TURN)[language] ) == YES ) {
            player_s_will = false;

            if( SafeIO::ask( SENTENCES.at(KEY_QUESTION_LEAVE_GAME)[language] ) == YES ) {
                this->setBooleanMembers(false, true, false, true);
            }/* Removed being given it is now handled by the GameBoard
            else if ( SafeIO::ask( SENTENCES.at(KEY_QUESTION_SKIP_NEXT_TURN)[language] ) == YES ) {
                this->setBooleanMembers(false, true, true, true);
            }*//*
            else {
                this->setBooleanMembers(true, true, false, true);
            }*/
        }
        // Or play
        else {
            auto answer = SafeIO::ask( SENTENCES.at(KEY_QUESTION_MAINTAIN_BET)[language] );

            if(answer != YES) {
                auto tmpBet = str_to_ui(answer);

                if(tmpBet + bet <= this->_wallet.getCoins()) {
                    bet += tmpBet;
                }
            }

            // Display the value of the bet
            SafeIO::print( SENTENCES.at(KEY_INFO_BET)[language] + std::to_string(bet) + SENTENCES.at(KEY_COINS)[language] );

            // Pick a card in all case
            this->Pick_a_Card();

            // Display cards picked and the value of the player hands
            this->displayPlayerHand(language);
            this->displayPlayerHandValue(language);
        }
    } while(player_s_will && !(this->getHandValue() > MAX_VALUE_TO_WIN));

    // Ask if the player wants to skip next turn, or to leave
    return std::make_pair(this->getHandValue(), bet);
}


/**
 * @brief getCoinsOfWallet
 * 
 * @return unsigned int 
 */
unsigned int HumanPlayer::getCoinsOfWallet(void) const noexcept
{
    return this->_wallet.getCoins();
}


/**
 * @brief addCoinsToWallet
 * 
 * @param value 
 */
void HumanPlayer::addCoinsToWallet(unsigned int value) noexcept
{
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
void HumanPlayer::setCoinsOfWallet(unsigned int value) noexcept
{
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
void HumanPlayer::removeCoinsOfWallet(unsigned int value) noexcept
{
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
void HumanPlayer::dropCard(Card& card) noexcept
{
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
void HumanPlayer::addCard(Card& card) noexcept
{
    this->_playerHand->Add_a_Card(card);
}


/**
 * @brief return the value of the player's hand
 * 
 * @return unsigned int 
 */
unsigned int HumanPlayer::getHandValue(void) const noexcept
{
    auto handValue {0U};    // the value of the hand
    auto nbOfAs    {0U};    // the number of As in the hand so we can iterate on it

    // Calculate the current handValue

    // Reset if it's another iteration
    handValue = 0;
    nbOfAs    = 0;

    // Calculate the current value without As
    for(const auto i : this->_playerHand->GetCardValuesOfTheDeck()) {
        if(i == CARD_VALUE_AS_MIN)
            ++nbOfAs;
        else
            handValue += i;
    }

    // Deal with the As now - we can get only one As at its max value, otherwise we overflow the MAX_VALUE_TO_WIN
    switch(nbOfAs) {
        case 1:
            if((handValue + CARD_VALUE_AS_MAX) <= MAX_VALUE_TO_WIN)                             handValue += CARD_VALUE_AS_MAX;
            else                                                                                handValue += CARD_VALUE_AS_MIN;
        break;

        case 2:
            if((handValue + CARD_VALUE_AS_MAX + CARD_VALUE_AS_MIN) <= MAX_VALUE_TO_WIN)         handValue += (CARD_VALUE_AS_MAX + CARD_VALUE_AS_MIN);
            else                                                                                handValue += (2 * CARD_VALUE_AS_MIN);
        break;

        case 3:
            if((handValue + CARD_VALUE_AS_MAX + (2 * CARD_VALUE_AS_MIN)) <= MAX_VALUE_TO_WIN)   handValue += (CARD_VALUE_AS_MAX +  (2 * CARD_VALUE_AS_MIN));
            else                                                                                handValue += (3 * CARD_VALUE_AS_MIN);
        break;

        case 4:
            if((handValue + CARD_VALUE_AS_MAX + (3 * CARD_VALUE_AS_MIN)) <= MAX_VALUE_TO_WIN)   handValue += (CARD_VALUE_AS_MAX +  (3 * CARD_VALUE_AS_MIN));
            else                                                                                handValue += (4 * CARD_VALUE_AS_MIN);
        break;

        // Nothing to do
        case 0:
        default:
        break;
    }

    return handValue;
}


/**
 * @brief set the boolean flags
 * 
 * @param ready default value = false
 * @param leaving default value = false
 * @param skip default value = false
 * @param endTurn default value = false
 */
void HumanPlayer::setBooleanMembers(bool ready, bool leaving, bool skip, bool endTurn)
{
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
bool HumanPlayer::isBlackjack(const std::string& card1, const std::string& card2) const noexcept
{
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


/**
 * @brief Display all the cards in the player hand by using SafeIO::print
 * 
 * @param language 
 */
void HumanPlayer::displayPlayerHand(const unsigned int language) const noexcept
{
    SafeIO::print( this->getPlayerTag().getPlayerTag() + " " + SENTENCES.at(KEY_INFO_PLAYERHAND_CARDS)[language] + "\n" );
    // std::for_each( this->_playerHand->GetDeck().begin(), this->_playerHand->GetDeck().end(), SafeIO::print );    // leads to core dumped
    for(unsigned int i{0}; i < this->_playerHand->GetDeck().size(); ++i)
    {
        SafeIO::print( this->_playerHand->GetDeck()[i] );
    }
    
}


/**
 * @brief Display the value of the player hand by using SafeIO::print
 * 
 * @param language 
 */
void HumanPlayer::displayPlayerHandValue(const unsigned int language) const noexcept
{
    std::cout << "debug enter in displayPlayerHandValue\n";
    SafeIO::print( this->getPlayerTag().getPlayerTag() + " " + SENTENCES.at(KEY_INFO_PLAYERHAND_VALUE)[language] + std::to_string(this->getHandValue() ) );
    std::cout << "debug leave displayPlayerHandValue\n";
}
#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

// My Includes
#include "../interface/iraii.hpp"
#include "../interface/igameentity.hpp"
#include "../interface/iplayer.hpp"
#include "../interface/iplay.hpp"
#include "playertag.hpp"
#include "wallet.hpp"
#include "deck.hpp"
#include "card.hpp"
#include "score.hpp"


// Includes
    // None for the moment.

/**
 * @brief Class HumanPlayer
 * It inherits from the interfaces IRAII, IGameEntity, IPlayer.
 * A player has a PlayerTag, a Wallet and a PlayerHand.
 * 
 */
class HumanPlayer : public IRAII, public IGameEntity, public IPlayer, public IPlay_HumanPlayer
{
// Attributes
private:
    PlayerTag               _playerTag;         // the player tag
    Wallet                  _wallet;            // the wallet of the player
    std::unique_ptr<Deck>   _playerHand;        // the cards the player has in hand
    std::shared_ptr<Deck>   _deck;              // the deck owned by the game board
    Score                   _score;             // the score of the player
    int                     _id;                // the id of the player, has a value of -1 by default. This id is set by the GameBoard at each turn

    // Flags
    bool                    _isReadyToPlay;     // if the player is ready to play
    bool                    _wantsToLeave;      // if the player wants to leave the game
    bool                    _wantsToSkip;       // if the player wants to skip its turn
    bool                    _wantsToEndHisTurn; // if the player has completed his actions for his turn
    
    // Meta Data
    struct MetaData
    {
        static unsigned int Total_of_Players_in_Game;
        static unsigned int Total_of_Coins_in_Game;
    };
    
    MetaData                _MetaData;          // MetaData of the class HumanPlayer


// Methods
public:
    // Constructors
    explicit HumanPlayer(const PlayerTag& playerTag, std::shared_ptr<Deck> gameDeck, unsigned int coinsAtStart = 0);
    explicit HumanPlayer(const Name& name, std::shared_ptr<Deck> gameDeck, unsigned int coinsAtStart = 0);
    explicit HumanPlayer(const Title& title, const Name& name, std::shared_ptr<Deck> gameDeck, unsigned int coinsAtStart = 0);

    // Destructor
    virtual ~HumanPlayer();

    // UI
    // Inheritance from IGameEntity
    void Pick_a_Card    (void)  override;   // During a turn of the game
    void Skip_Turn      (void)  override;   // During a turn of the game
    void Turn_is_Over   (void)  override;   // The player notifies he finished his actions

    // Inheritance from IPlayer
    void Ready_to_Play  (void)  override;   // After setting a bet, at the beginning of a turn of the game
    void Quit_Game      (void)  override;   // Must be available at the end of a turn of the game

    // Inheritance from IPlay_HumanPlayer
    std::pair<unsigned int, unsigned int> Play(const unsigned int language) noexcept override;


    // Wallet
    unsigned int getCoinsOfWallet   (void)         const noexcept;
    void         addCoinsToWallet   (unsigned int value) noexcept;
    void         setCoinsOfWallet   (unsigned int value) noexcept;
    void         removeCoinsOfWallet(unsigned int value) noexcept;

    // Deck
    void dropCard(Card& card) noexcept;
    void addCard (Card& card) noexcept;
    
    // Hand Value
    unsigned int    getHandValue(void) const noexcept;

    // Score
    /**
     * @brief Get the Score object
     * 
     * @return Score 
     */
    Score           getScoreObject(void) const noexcept { return this->_score; }

    /**
     * @brief Set the Score object
     * Deleted method.
     * 
     * @param s 
     */
    void            setScoreObject(const Score& s) = delete;

    // MetaData
    /**
     * @brief Get the Meta Data object of the HumanPlayer class
     * 
     * @return MetaData 
     */
    const MetaData  getMetaData(void) const noexcept { return this->_MetaData; }
    
    /**
     * @brief Set the Meta Data object
     * Deleted method.
     * 
     * @param metadata 
     */
    void            setMetaData(const MetaData& metadata) = delete;

    // Flags
    /**
     * @brief Get the isReadyToPlay flag
     * 
     */
    bool            getReady    (void) const noexcept { return this->_isReadyToPlay; }

    /**
     * @brief Get the wantsToLeave flag
     * 
     */
    bool            getLeaving  (void) const noexcept { return this->_wantsToLeave;  }

    /**
     * @brief Get the wantsToSkip flag
     * 
     */
    bool            getSkip     (void) const noexcept { return this->_wantsToSkip;   }

    /**
     * @brief Get the wantsToEndHisTurn flag
     * 
     */
    bool            getEndOfTurn(void) const noexcept { return this->_wantsToEndHisTurn; }
    
    /**
     * @brief Get the Id object
     * 
     * @return int 
     */
    int             getID       (void) const noexcept { return this->_id; }
    
    /**
     * @brief Get the Player Tag object
     * 
     * @return PlayerTag 
     */
    PlayerTag       getPlayerTag(void) const noexcept { return this->_playerTag; }

    /**
     * @brief Set the isReadyToPlay flag
     * Deleted method.
     * 
     */
    void setReady    (bool) noexcept = delete;

    /**
     * @brief Set the wantsToLeave flag
     * Deleted method.
     * 
     */
    void setLeaving  (bool) noexcept = delete;

    /**
     * @brief Set the wantsToSkip flag
     * 
     */
    void setSkip     (bool b) noexcept { this->_wantsToSkip = b; }

    /**
     * @brief Set the wantsToEndHisTurn flag
     * Deleted method.
     * 
     */
    void setEndOfTurn(bool) noexcept = delete;

    /**
     * @brief Set the player's ID
     * This method must be call by the GameBoard only.
     * 
     * @param i 
     */
    void setID(int i) noexcept { this->_id = i; }


    /**
     * @brief Set the Player Tag object
     * Deleted method.
     * 
     * @param pt 
     */
    void setPlayerTag(const PlayerTag& pt) noexcept = delete;

protected:
    // Inheritance from IRAII
    void Init()             override;
    void Release()          override;

private:
    void initGameDeck(std::shared_ptr<Deck> gameDeck);
    void setBooleanMembers(bool ready = false, bool leaving = false, bool skip = false, bool endTurn = false);
    bool isBlackjack(const std::string& card1, const std::string& card2) const noexcept;
    void displayPlayerHand(const unsigned int language) const noexcept;
    void displayPlayerHandValue(const unsigned int language) const noexcept;
};

#endif // HUMANPLAYER_H

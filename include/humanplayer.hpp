#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

// My Includes
#include "../interface/iraii.hpp"
#include "../interface/igameentity.hpp"
#include "../interface/iplayer.hpp"
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
class HumanPlayer : public IRAII, public IGameEntity, public IPlayer
{
// Attributes
private:
    PlayerTag               _playerTag;         // the player tag
    Wallet                  _wallet;            // the wallet of the player
    std::unique_ptr<Deck>   _playerHand;        // the cards the player has in hand
    std::shared_ptr<Deck>   _deck;              // the deck owned by the game board
    Score                   _score;             // the score of the player

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
    explicit HumanPlayer(const PlayerTag& playerTag, std::shared_ptr<Deck> gameDeck);
    explicit HumanPlayer(const Name& name, std::shared_ptr<Deck> gameDeck);
    explicit HumanPlayer(const Title& title, const Name& name, std::shared_ptr<Deck> gameDeck);

    // Destructor
    virtual ~HumanPlayer();

    // UI
    // Inheritance from IGameEntity
    void Pick_a_Card()      override;   // During a turn of the game
    void Skip_Turn()        override;   // During a turn of the game
    void Turn_is_Over()     override;   // The player notifies he finished his actions

    // Inheritance from IPlayer
    void Ready_to_Play()    override;   // After setting a bet, at the beginning of a turn of the game
    void Quit_Game()        override;   // Must be available at the end of a turn of the game

    // Wallet
    unsigned int getCoinsOfWallet   (void)         const noexcept;
    void         addCoinsToWallet   (unsigned int value) noexcept;
    void         setCoinsOfWallet   (unsigned int value) noexcept;
    void         removeCoinsOfWallet(unsigned int value) noexcept;

    // Deck
    void dropCard(Card& card) noexcept;
    void addCard (Card& card) noexcept;

    // Score
    /**
     * @brief Get the Score object
     * 
     * @return Score 
     */
    Score getScoreObject(void) const noexcept { return this->_score; }

    /**
     * @brief Set the Score object
     * Deleted method.
     * 
     * @param s 
     */
    void setScoreObject(const Score& s) = delete;

    // MetaData
    /**
     * @brief Get the Meta Data object of the HumanPlayer class
     * 
     * @return MetaData 
     */
    const MetaData getMetaData(void) const noexcept { return this->_MetaData; }
    
    /**
     * @brief Set the Meta Data object
     * Deleted method.
     * 
     * @param metadata 
     */
    void setMetaData(const MetaData& metadata) = delete;

    // Flags
    /**
     * @brief Get the isReadyToPlay flag
     * 
     */
    bool getReady    (void) const noexcept { return this->_isReadyToPlay; }

    /**
     * @brief Get the wantsToLeave flag
     * 
     */
    bool getLeaving  (void) const noexcept { return this->_wantsToLeave;  }

    /**
     * @brief Get the wantsToSkip flag
     * 
     */
    bool getSkip     (void) const noexcept { return this->_wantsToSkip;   }

    /**
     * @brief Get the wantsToEndHisTurn flag
     * 
     */
    bool getEndOfTurn(void) const noexcept { return this->_wantsToEndHisTurn; }

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
     * Deleted method.
     * 
     */
    void setSkip     (bool) noexcept = delete;

    /**
     * @brief Set the wantsToEndHisTurn flag
     * Deleted method.
     * 
     */
    void setEndOfTurn(bool) noexcept = delete;

protected:
    // Inheritance from IRAII
    void Init()             override;
    void Release()          override;

private:
    void initGameDeck(std::shared_ptr<Deck> gameDeck);
    void setBooleanMembers(bool ready = false, bool leaving = false, bool skip = false, bool endTurn = false);
};

#endif // HUMANPLAYER_H

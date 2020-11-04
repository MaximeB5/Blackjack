#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

// My Includes
#include "../interface/iraii.hpp"
#include "../interface/igameentity.hpp"
#include "../interface/iplayer.hpp"
#include "playertag.hpp"
#include "wallet.hpp"

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
    PlayerTag           _playerTag;         // the player tag
    Wallet              _wallet;            // the wallet of the player
//    std::vector<Card>   _cards;           // the cards the player has in hand --> TO BE REPLACED BY A CLASS PlayerHand THAT ENCAPSULATE THIS DATA ! ! ! --> unique_ptr<PlayerHand>
    bool                _isReadyToPlay;     // if the player is ready to play
    bool                _wantsToLeave;      // if the player wants to leave the game
    
    struct MetaData
    {
        static unsigned int Total_of_Players_in_Game;
        static unsigned int Total_of_Coins_in_Game;
    };
    
    MetaData            _MetaData;          // MetaData of the class HumanPlayer

// Methods
public:
    // Constructors
    explicit HumanPlayer(const PlayerTag& playerTag);
    explicit HumanPlayer(const Name& name);
    explicit HumanPlayer(const Title& title, const Name& name);

    // Destructor
    virtual ~HumanPlayer();

    // UI
    // Inheritance from IGameEntity
    void Pick_a_Card()      override;
    void Skip_Turn()        override;

    // Inheritance from IPlayer
    void Ready_to_Play()    override;
    void Quit_Game()        override;

    // UI MetaData
    /**
     * @brief Get the Meta Data object of the HumanPlayer class
     * 
     * @return MetaData 
     */
    MetaData getMetaData(void) const noexcept { return this->_MetaData; }
    
    /**
     * @brief Set the Meta Data object
     * Deleted method.
     * 
     * @param metadata 
     */
    void setMetaData(const MetaData& metadata) = delete;


protected:
    // Inheritance from IRAII
    void Init()             override;
    void Release()          override;

private:
    // None for the moment.
};

#endif // HUMANPLAYER_H

/*
------------
WORK TODO :
------------

In the class HumanPlayer, a private attribute std::vector<Card>   _cards; is temporarily here.

I must create new classes to encapsulate this data :  GameEntityHand inherited by PlayerHand.
PlayerHand will then replace this vector. Todo as well : provide all accesses needed.

Option 2 : inherits from Deck to create the class GameEntityDeck and delete methods that are no use for a GameEntity.
*/

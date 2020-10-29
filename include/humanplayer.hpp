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
 * 
 */
class HumanPlayer : public IRAII, public IGameEntity, public IPlayer
{
// Attributes
private:
    PlayerTag   _playerTag;     // the player tag
    Wallet      _wallet;        // the wallet of the player
    bool        _isReadyToPlay; // if the player is ready to play
    bool        _wantsToLeave;  // if the player wants to leave the game

// Methods
public:
    // Constructors
    explicit HumanPlayer(const PlayerTag& playerTag);
    explicit HumanPlayer(const Name& name);
    explicit HumanPlayer(const Title& title, const Name& name);

    // Destructor
    virtual ~HumanPlayer();

    // Inheritance from IGameEntity
    void Pick_a_Card()      override;
    void Skip_Turn()        override;

    // Inheritance from IPlayer
    void Ready_to_Play()    override;
    void Quit_Game()        override;


protected:
    // Inheritance from IRAII
    void Init()             override;
    void Release()          override;

private:
    // None for the moment.
};

#endif // HUMANPLAYER_H

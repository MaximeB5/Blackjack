#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

// My Includes
#include "../interface/igameentity.hpp"
#include "playertag.hpp"

// Includes
    // None for the moment.

/**
 * @brief Class HumanPlayer
 * It inherits from the interface IGameEntity.
 * 
 */
class HumanPlayer : public IGameEntity
{
// Attributes
private:
    PlayerTag _playerTag;

// Methods
public:
    // Constructors
    explicit HumanPlayer(const PlayerTag& playerTag);
    explicit HumanPlayer(const Name& name);
    explicit HumanPlayer(const Title& title, const Name& name);

    // Destructor
    virtual ~HumanPlayer();

    // Inheritance from IGameEntity
    void Pick_a_Card() override;
    void Skip_Turn() override;


protected:
    // Inheritance from IGameEntity - RAII Methods
    void Init() override;
    void Release() override;

private:
    // None for the moment.
};

#endif // HUMANPLAYER_H

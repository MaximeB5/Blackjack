#ifndef IGAMEBOARD_H
#define IGAMEBOARD_H

// My Includes
#include "../include/deckspecification.hpp"
#include "../include/humanplayer.hpp"

/**
 * Class IGameBoard
 */
class IGameBoard
{
public:
    // Constructors
        // None, this is an interface.

    // Destructor - virtual for interface.
    virtual ~IGameBoard() {}

    // Public Methods - User Interface
    // Game
    virtual void                     SetGameMode            (void)                                                                  const noexcept = 0;

    // Players
    virtual void                     Add_New_Player         (void)                                                                        noexcept = 0;
    virtual void                     Remove_Player          (void)                                                                        noexcept = 0;

    // Players - Coins
    virtual void                     Add_Coins_To_Player    (HumanPlayer& player)                                                         noexcept = 0;
    virtual void                     Set_Coins_To_Player    (HumanPlayer& player)                                                         noexcept = 0;
    virtual void                     Remove_Coins_To_Player (HumanPlayer& player)                                                         noexcept = 0;
    
    // Players - Score
    virtual void                     Increase_Score         (HumanPlayer& player)                                                         noexcept = 0;
    virtual void                     Decrease_Score         (HumanPlayer& player)                                                         noexcept = 0;
    virtual int                      Get_Score              (const HumanPlayer& player)                                             const noexcept = 0;

    // Deck
    virtual void                     Reset_GameDeck         (DeckSpecification deckspecification = DeckSpecification::DefaultDeck)        noexcept = 0;
    virtual std::vector<std::string> GetDeck                (void)                                                                  const noexcept = 0;

protected:
    // None.

private:
    // None.
};

#endif // IGAMEBOARD_H

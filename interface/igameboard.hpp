#ifndef IGAMEBOARD_H
#define IGAMEBOARD_H

// My Includes
#include "../include/deckspecification.hpp"
#include "../include/humanplayer.hpp"
#include "../include/score.hpp"
#include "../include/language.hpp"

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
    virtual void                     Set_GameMode           (DeckSpecification gameMode)                                                  noexcept = 0;
    virtual void                     Set_Language           (Language language)                                                           noexcept = 0;
    virtual DeckSpecification        Get_GameMode           (void)                                                                  const noexcept = 0;
    virtual std::string              Get_GameMode_Str       (void)                                                                  const noexcept = 0;
    virtual std::string              Get_Language           (void)                                                                  const noexcept = 0;


    // Players
    //virtual void                     Add_New_Player         (std::unique_ptr<HumanPlayer> player)                                         noexcept = 0;
    //virtual void                     Remove_Player          (HumanPlayer* player)                                                         noexcept = 0;
    virtual void                     Remove_Player_at_Index (unsigned int index)                                                                   = 0;
    virtual unsigned int             Get_Nb_of_Players      (void)                                                                  const noexcept = 0;

    // Players - Coins
    virtual void                     Add_Coins_To_Player    (std::unique_ptr<HumanPlayer>& player, unsigned int coinsValue)               noexcept = 0;
    virtual void                     Set_Coins_To_Player    (std::unique_ptr<HumanPlayer>& player, unsigned int coinsValue)               noexcept = 0;
    virtual void                     Remove_Coins_To_Player (std::unique_ptr<HumanPlayer>& player, unsigned int coinsValue)               noexcept = 0;
    
    // Players - Score
    virtual void                     Increase_Score         (std::unique_ptr<HumanPlayer>& player)                                        noexcept = 0;
    virtual void                     Decrease_Score         (std::unique_ptr<HumanPlayer>& player)                                        noexcept = 0;
    virtual int                      Get_Score              (const std::unique_ptr<HumanPlayer>& player)                            const noexcept = 0;
    virtual Score                    Get_ScoreObject        (const std::unique_ptr<HumanPlayer>& player)                            const noexcept = 0;

    // Deck
    virtual void                     Reset_GameDeck         (DeckSpecification deckspecification = DeckSpecification::DefaultDeck)        noexcept = 0;
    virtual std::vector<std::string> GetDeck                (void)                                                                  const noexcept = 0;

protected:
    // None.

private:
    // None.
};

#endif // IGAMEBOARD_H

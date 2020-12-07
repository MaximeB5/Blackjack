#ifndef GAMEBOARD_H
#define GAMEBOARD_H

// My Includes
#include "../interface/igameboard.hpp"
#include "../interface/iplay.hpp"
#include "deck.hpp"
#include "humanplayer.hpp"
#include "casinodealer.hpp"
#include "constants.hpp"

// Includes
#include <memory>   // smart pointers
#include <array>
#include <thread>
#include <string>

/**
 * @brief Class GameBoard
 * It inherits from the interface IGameBoard.
 * This class represents the game board of the Blackjack game.
 * This is where everything is handled, such as players, the deck of the game, etc.
 * 
 */
class GameBoard : public IGameBoard, public IPlay_GameBoard
{
// Attributes
private:
    std::shared_ptr<Deck>                                           _gameDeck;          // the deck of the game we will shared to all players and to the casino dealer
    std::array<std::unique_ptr<HumanPlayer>, NUMBER_OF_PLAYERS_MAX> _players;           // x4 players max
    std::unique_ptr<CasinoDealer>                                   _casinoDealer;      // x1 casino dealer handled by the gameboard

    // Meta Data
    std::string                                                     _gameMode;          // let know the UI the game mode we're in
    unsigned int                                                    _numberOfPlayers;   // let know the UI the number of players in game


// Methods
public:
    // Constructors
    GameBoard();

    // Destructor
    ~GameBoard();

    // UI
    // Inheritance from IGameBoard
    void                        SetGameMode             (void)                                                                  const noexcept override;
    void                        Add_New_Player          (void)                                                                        noexcept override;
    void                        Remove_Player           (void)                                                                        noexcept override;
    void                        Add_Coins_To_Player     (HumanPlayer& player)                                                         noexcept override;
    void                        Set_Coins_To_Player     (HumanPlayer& player)                                                         noexcept override;
    void                        Remove_Coins_To_Player  (HumanPlayer& player)                                                         noexcept override;
    void                        Increase_Score          (HumanPlayer& player)                                                         noexcept override;
    void                        Decrease_Score          (HumanPlayer& player)                                                         noexcept override;
    int                         Get_Score               (const HumanPlayer& player)                                             const noexcept override;
    Score                       Get_ScoreObject         (const HumanPlayer& player)                                             const noexcept override;
    void                        Reset_GameDeck          (DeckSpecification deckspecification = DeckSpecification::DefaultDeck)        noexcept override;
    std::vector<std::string>    GetDeck                 (void)                                                                  const noexcept override;
    
    // Inheritance from IPlay_GameBoard
    void                        Play                    (void)                                                                        noexcept override;
    
    // Meta Data
    /**
     * @brief Get the Game Mode object
     * 
     * @return std::string 
     */
    std::string  getGameMode       (void) const noexcept { return this->_gameMode;        }

    /**
     * @brief Get the Number Of Players object
     * 
     * @return unsigned int 
     */
    unsigned int getNumberOfPlayers(void) const noexcept { return this->_numberOfPlayers; }

    /**
     * @brief Set the game mode
     * Deleted method.
     * 
     */
    void setGameMode(const std::string& s)  = delete;

    /**
     * @brief Set the number of players
     * Deleted method.
     * 
     */
    void setNumberOfPlayers(unsigned int n) = delete;

protected:
     // None for the moment.

private:
     void checkPlayers(void) noexcept;

};

#endif // GAMEBOARD_H

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
#include <string>   // std::string ; std::getline
#include <iostream> // v1.1 of the project -> GameBoard::askPlayers

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
    unsigned int                                                    _language;          // the language currently set


// Methods
public:
    // Constructors
    GameBoard(/* args = language, and maybe gamemode at least */);

    // Destructor
    ~GameBoard();

    // UI
    // Inheritance from IGameBoard
    void                        Set_GameMode            (void)                                                                        noexcept override;
    void                        Set_Language            (unsigned int language)                                                       noexcept override;
    void                        Add_New_Player          (std::unique_ptr<HumanPlayer> player)                                         noexcept override;
    void                        Remove_Player           (HumanPlayer& player)                                                         noexcept override;
    unsigned int                Get_Nb_of_Players       (void)                                                                  const noexcept override;
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
    std::string  getGameMode    (void) const noexcept { return this->_gameMode; }

    /**
     * @brief Get the Language object
     * 
     * @return unsigned int 
     */
    unsigned int getLanguage    (void) const noexcept { return this->_language; }

    /**
     * @brief Set the game mode
     * Deleted method.
     * 
     */
    void setGameMode(const std::string& s)  = delete;

    /**
     * @brief Set the Language object
     * 
     * @param language
     */
    void setLanguage(const unsigned int& language) { this->_language = language; }

protected:
     // None for the moment.

private:
    /**
     * @brief ask the players a message awaiting a specific returned value of type T
     * The current state of the project (v1.1) includes that this method is using the std::cout and std::cin streams
     * This is absolutely not type safe, or safe at all.
     * 
     * @tparam T 
     * @param msg 
     * @return T 
     */
    template <typename T>
    T askPlayers(const std::string& msg) {
        std::cout << msg << " - Do not troll please. This program does not support it cause I'm lazy." << std::endl;
        T answer;
        std::getline(std::cin, answer);
        return answer;
    }
    
    void checkPlayers(void) noexcept;

};

#endif // GAMEBOARD_H

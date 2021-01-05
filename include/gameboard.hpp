#ifndef GAMEBOARD_H
#define GAMEBOARD_H

// My Includes
#include "../interface/igameboard.hpp"
#include "../interface/iplay.hpp"
#include "deck.hpp"
#include "humanplayer.hpp"
#include "casinodealer.hpp"
#include "constants.hpp"
#include "language.hpp"

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
class GameBoard : public IRAII, public IGameBoard, public IPlay_GameBoard
{
// Attributes
private:
    std::shared_ptr<Deck>                                           _gameDeck;          // the deck of the game we will shared to all players and to the casino dealer
    std::array<std::unique_ptr<HumanPlayer>, NUMBER_OF_PLAYERS_MAX> _players;           // x4 players max
    std::unique_ptr<CasinoDealer>                                   _casinoDealer;      // x1 casino dealer handled by the gameboard

    // Meta Data
    DeckSpecification                                               _gameMode;          // let know the UI the game mode we're in -> TODO : encapsulate this and then update Set & Get GameMode
    unsigned int                                                    _language_ui;       // the language currently set (unsigned int value, for the map)
    std::string                                                     _language_str;      // the language currently set (std::string value for the user interface)
    std::string                                                     _casinoDealerName;  // the name of the casino dealer


// Methods
public:
    // Constructors
    GameBoard(  const Name& name = Name{"Casino Dealer"},
                DeckSpecification gameMode = DeckSpecification::DefaultDeck,
                Language languageChosen = Language::English
            );

    // Destructor
    ~GameBoard();

    // UI
    // Inheritance from IGameBoard
    void                        Set_GameMode            (DeckSpecification gameMode)                                                  noexcept override;
    void                        Set_Language            (Language language)                                                           noexcept override;
    DeckSpecification           Get_GameMode            (void)                                                                  const noexcept override;
    std::string                 Get_GameMode_Str        (void)                                                                  const noexcept override;
    std::string                 Get_Language            (void)                                                                  const noexcept override;
    //void                        Add_New_Player          (std::unique_ptr<HumanPlayer> player)                                         noexcept override;
    //void                        Remove_Player           (HumanPlayer* player)                                                         noexcept override;
    void                        Remove_Player_at_Index  (unsigned int index)                                                                   override;
    unsigned int                Get_Nb_of_Players       (void)                                                                  const noexcept override;
    void                        Add_Coins_To_Player     (std::unique_ptr<HumanPlayer>& player, unsigned int coinsValue)               noexcept override;
    void                        Set_Coins_To_Player     (std::unique_ptr<HumanPlayer>& player, unsigned int coinsValue)               noexcept override;
    void                        Remove_Coins_To_Player  (std::unique_ptr<HumanPlayer>& player, unsigned int coinsValue)               noexcept override;
    void                        Increase_Score          (std::unique_ptr<HumanPlayer>& player)                                        noexcept override;
    void                        Decrease_Score          (std::unique_ptr<HumanPlayer>& player)                                        noexcept override;
    int                         Get_Score               (const std::unique_ptr<HumanPlayer>& player)                            const noexcept override;
    Score                       Get_ScoreObject         (const std::unique_ptr<HumanPlayer>& player)                            const noexcept override;
    void                        Reset_GameDeck          (DeckSpecification deckspecification = DeckSpecification::DefaultDeck)        noexcept override;
    std::vector<std::string>    GetDeck                 (void)                                                                  const noexcept override;
    
    // Inheritance from IPlay_GameBoard
    void                        Play                    (void)                                                                        noexcept override;

protected:
    // Inheritance from IRAII
    void Init()             override;
    void Release()          override;

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

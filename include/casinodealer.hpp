#ifndef CASINODEALER_H
#define CASINODEALER_H

// My Includes
#include "../interface/iraii.hpp"
#include "../interface/igameentity.hpp"
#include "deck.hpp"
#include "name.hpp"

// Includes
    // None for the moment.

/**
 * @brief Class CasinoDealer
 * It inherits from the interfaces IRAII, IGameEntity.
 * 
 */
class CasinoDealer : public IRAII, public IGameEntity
{
// Attributes
private:
    Name                    _name;              // the name of this game entity
    std::unique_ptr<Deck>   _playerHand;        // the cards the player has in hand
    std::shared_ptr<Deck>   _deck;              // the deck owned by the game board

    // Flags
    bool                    _wantsToSkip;       // if the casino dealer wants to skip its turn
    bool                    _wantsToEndHisTurn; // if the player has completed his actions for his turn

// Methods
public:
    // Constructors
    explicit CasinoDealer(std::shared_ptr<Deck> gameDeck, const Name& name = Name{"Casino Dealer"});

    // Destructor
    virtual ~CasinoDealer();

    // UI
    // Inheritance from IGameEntity
    void Pick_a_Card()  override;
    void Skip_Turn()    override;
    void Turn_is_Over() override;   // The casino dealer game entitty notifies it finished its actions

    
    // Deck playerHand
    void dropCard(Card& card) noexcept;
    void addCard (Card& card) noexcept;

    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName(void) const noexcept { return this->_name.getName(); }
    
    /**
     * @brief Get the wantsToSkip flag
     * 
     * @return true 
     * @return false 
     */
    bool getSkip       (void) const noexcept { return this->_wantsToSkip;    }

    /**
     * @brief Get the wantsToEndHisTurn flag
     * 
     */
    bool getEndOfTurn  (void) const noexcept { return this->_wantsToEndHisTurn; }
    
    /**
     * @brief Set the wantsToSkip flag
     * Deleted method.
     * 
     */
    void setSkip       (bool) noexcept = delete;

    /**
     * @brief Set the wantsToEndHisTurn flag
     * Deleted method.
     * 
     */
    void setEndOfTurn  (bool) noexcept = delete;


protected:
    // Inheritance from IRAII
    void Init()         override;
    void Release()      override;

private:
    void initGameDeck(std::shared_ptr<Deck> gameDeck);
    void setBooleanMembers(bool skip = false, bool endTurn = false);
};

#endif // CASINODEALER_H
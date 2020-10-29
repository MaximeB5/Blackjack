#ifndef WALLET_H
#define WALLET_H

// My Includes
#include "coins.hpp"

/**
 * @brief Class Wallet
 * It contains the money of the players.
 * 
 */
class Wallet
{
// Attributes
private:
    Coins _coins;

// Methods
public:
    // Constructors
    /**
     * @brief Construct a new Wallet object
     * 
     * @param coins 
     */
    explicit Wallet(Coins coins) : _coins(coins) {}

    // Destructor
    ~Wallet() {}

    // Methods
    /**
     * @brief Get the Coins object
     * 
     * @return unsigned int 
     */
    unsigned int getCoins(void) const noexcept { return this->_coins.getValue(); }

    /**
     * @brief 
     * 
     * @param value 
     */
    void addCoins(unsigned int value)          { this->_coins.addValue(value);   }

    /**
     * @brief Set the Coins object
     * 
     * @param value 
     */
    void setCoins(unsigned int value)          { this->_coins.setValue(value);   }

    /**
     * @brief is the wallet empty or not
     * 
     * @return true if yes
     * @return false if not
     */
    bool isEmpty(void) const noexcept {
        if(_coins.getValue() != 0)  return false;
        else                        return  true;
    }
};

#endif // WALLET_H

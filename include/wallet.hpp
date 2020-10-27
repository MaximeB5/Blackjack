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
    bool _isEmpty;  // is the wallet empty or not

// Methods
public:
    // Constructors
    Wallet(Coins coins) : _coins(coins) {}

    // Destructor
    ~Wallet() {}

    // Methods
    unsigned int getCoins(void) const noexcept { return this->_coins.getCoins(); }
    void addCoins(unsigned int value)          { this->_coins.addCoins(value);   }
    void setCoins(unsigned int value)          { this->_coins.setCoins(value);   }
};

#endif // WALLET_H

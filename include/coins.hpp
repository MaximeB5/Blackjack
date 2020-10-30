#ifndef COINS_H
#define COINS_H

// Includes
#include <bits/stdc++.h>    // UINT_MAX = 4 294 967 295

/**
 * @brief Class Coins
 * It represents the money value in game.
 * 
 */
class Coins
{
// Attributes
private:
    unsigned int _value;

// Methods
public:
    // Constructors
    explicit Coins(unsigned int value = 0) : _value(value) {}    

    // Destructor
    ~Coins() {}

    // Methods
    /**
     * @brief Get the Coins object
     * 
     * @return unsigned int _value
     */
    unsigned int getValue(void) const noexcept { return this->_value; }
    
    /**
     * @brief addValue
     * It adds the value to _value.
     * @throw if the check fail
     * @param value 
     */
    void addValue(unsigned int value) {
        if(!check(value))
            throw;

        this->_value += value;
    }

    /**
     * @brief Set the Coins object
     * @throw if the check fail
     * @param value 
     */
    void setValue(unsigned int value) {
        if(!check(value))
            throw;

        this->_value = value;
    }

    /**
     * @brief return the max value coins can have, UINT_MAX
     * 
     * @return unsigned int max value
     */
    static unsigned int maxValue() noexcept { return UINT_MAX; }

private:
    /**
     * @brief check if the value is valid
     * 
     * @param value 
     * @return true if the value is positive and under the maximum value for an unsigned int
     * @return false if it is not
     */
    bool check(unsigned int value) {
        // Set check
        if(value < 0 or value >= UINT_MAX)
            return false;

        // Add check
        if(this->_value + value < 0 or this->_value + value >= UINT_MAX)
            return false;
        
        return true;
    }

};

#endif // COINS_H
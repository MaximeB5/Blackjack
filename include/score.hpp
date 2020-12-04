#ifndef SCORE_H
#define SCORE_H

// My Includes
#include "../interface/iraii.hpp"

// Includes
    // None for the moment.

/**
 * @brief Class Score
 * It inherits from the interface IRAII.
 * It represents the score of the game entities.
 * it can be negative, null or positive.
 * Max and min values are those of an int.
 * 
 */
class Score : public IRAII
{
// Attributes
private:
    int          _score;
    unsigned int _gamesWon;
    unsigned int _gamesLost;
    unsigned int _numberOfWinsInARow;
    unsigned int _numberOfDefeatsInARow;


// Methods
public:
    // Constructors
    explicit Score();

    // Destructor
    ~Score();

    // UI
    void Increase_Win()     noexcept;
    void Increase_Defeat()  noexcept;
    void Reset_Stats()      noexcept;

    /**
     * @brief Get the Score object
     * 
     * @return int 
     */
    int getScore()      const noexcept  { return this->_score;     }
    
    /**
     * @brief Get the Games Won object
     * 
     * @return int 
     */
    int getGamesWon()   const noexcept  { return this->_gamesWon;  }

    /**
     * @brief Get the Games Lost object
     * 
     * @return int 
     */
    int getGamesLost()  const noexcept  { return this->_gamesLost; }

    /**
     * @brief Set the Score object
     * Deleted method.
     */
    void setScore()     = delete;
    
    /**
     * @brief Set the Games Won object
     * Deleted method.
     * 
     */
    void setGamesWon()  = delete;
    
    /**
     * @brief Set the Games Lost object
     * Deleted method.
     * 
     */
    void setGamesLost() = delete;

protected:
    // Inheritance from IRAII
    void Init()     override;
    void Release()  override;

private:
    // None for the moment.
};

#endif // SCORE_H

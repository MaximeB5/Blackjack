#ifndef PLAYERTAG_H
#define PLAYERTAG_H

// My Includes
#include "title.hpp"
#include "name.hpp"

// Includes
#include <string>

/**
 * @brief Class PlayerTag
 * It contains a Title and a Name.
 * 
 */
class PlayerTag
{
// Attributes
private:
    Title _title;
    Name _name;


// Methods
public:
    // Constructors
    /**
     * @brief Construct a new Player Tag object
     * 
     * @param name 
     */
    explicit PlayerTag(const Name& name) : _title(""), _name(name) {}

    /**
     * @brief Construct a new Player Tag object
     * 
     * @param title 
     * @param name 
     */
    explicit PlayerTag(const Title& title, const Name& name) : _title(title), _name(name) {}

    // Destructor
    /**
     * @brief Destroy the Player Tag object
     * 
     */
    ~PlayerTag() {}

    // UI
    /**
     * @brief Get the Player Tag object
     * 
     * @return std::string 
     */
    std::string getPlayerTag(void) const noexcept
    {
        if( this->_title.getTitle().empty() )
            return this->_name.getName();

        return this->_title.getTitle() + " " + this->_name.getName();
    }

    /**
     * @brief Set the Player Tag object
     * Deleted method.
     * 
     * @param title 
     * @param name 
     */
    void setPlayerTag(const Title& title, const Name& name) = delete;

    /**
     * @brief addTitle
     * 
     * @param title 
     */
    void addTitle(const std::string& title) noexcept {
        this->_title = Title{title};
    }

    /**
     * @brief removeTitle
     * 
     */
    void removeTitle(void) noexcept {
        this->_title = Title{""};
    }
};

#endif // PLAYERTAG_H

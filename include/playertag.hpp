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
    explicit PlayerTag(const Name& name) : _title(""), _name(name) {}
    explicit PlayerTag(const Title& title, const Name& name) : _title(title), _name(name) {}

    // Destructor
    ~PlayerTag() {}

    // Methods
    std::string getPlayerTag(void) const noexcept { 
        return this->_title.getTitle() + " " + this->_name.getName();
    }
    void setPlayerTag(const Title& title, const Name& name) = delete;
};

#endif // PLAYERTAG_H

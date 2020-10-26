#ifndef NAME_H
#define NAME_H

// Includes
#include <string>

/**
 * @brief Class Name
 * It can only get the name, not set it to a new one.
 * 
 */
class Name
{
// Attributes
private:
    std::string _name;

// Methods
public:
    // Constructors
    Name(const std::string& name) {
        this->_name = name;
    }    

    // Destructor
    ~Name() {}

    // Methods
    std::string getName(void) const noexcept { return this->_name; }
    void setName(const std::string& name) = delete;
};

#endif // NAME_H

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
    /**
     * @brief Construct a new Name object
     * 
     * @param name 
     */
    Name(const std::string& name) {
        this->_name = name;
    }    

    // Destructor
    /**
     * @brief Destroy the Name object
     * 
     */
    ~Name() {}

    // UI
    /**
     * @brief Get the Name object
     * 
     * @return std::string 
     */
    std::string getName(void) const noexcept { return this->_name; }

    /**
     * @brief Set the Name object
     * Deleted method.
     * 
     * @param name 
     */
    void setName(const std::string& name) = delete;
};

#endif // NAME_H

#ifndef TITLE_H
#define TITLE_H

// Includes
#include <string>

/**
 * @brief Class Title
 * It can only get the title, not set it to a new one.
 * 
 */
class Title
{
// Attributes
private:
    std::string _title;

// Methods
public:
    // Constructors
    /**
     * @brief Construct a new Title object
     * 
     * @param title 
     */
    Title(const std::string& title) {
        this->_title = title;
    }

    // Destructor
    /**
     * @brief Destroy the Title object
     * 
     */
    ~Title() {}

    // UI
    /**
     * @brief Get the Title object
     * 
     * @return std::string 
     */
    std::string getTitle(void) const noexcept { return this->_title; }

    /**
     * @brief Set the Title object
     * Deleted method.
     * 
     * @param Title 
     */

    /**
     * @brief Set the Title object
     * Deleted method.
     * 
     * @param Title 
     */
    void setTitle(const std::string& Title) = delete;
};

#endif // TITLE_H

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
    Title(const std::string& title) {
        this->_title = title;
    }

    // Destructor
    ~Title() {}

    // Methods
    std::string getTitle(void) const noexcept { return this->_title; }
    void setTitle(const std::string& Title) = delete;
};

#endif // TITLE_H

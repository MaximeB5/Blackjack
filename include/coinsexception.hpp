#ifndef COINSEXCEPTION_H
#define COINSEXCEPTION_H

// Includes
#include <exception>    // std::exception
#include <string>

class CoinsException : public std::exception
{
// Attributes
private:
    std::string _msg;

// Methods
public:
    /**
     * @brief Construct a new Deck Exception object
     * 
     * @param msg 
     */
    CoinsException(const std::string& msg) : _msg(msg) {}

    /**
     * @brief what
     * 
     * @return const char* _msg.c_str()
     */
    virtual const char* what() const noexcept override
    {
        return _msg.c_str();
    }
}; 

#endif // COINSEXCEPTION_H
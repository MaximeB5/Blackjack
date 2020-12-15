#ifndef GAMEBOARDEXCEPTION_H
#define GAMEBOARDEXCEPTION_H

// Includes
#include <exception>    // std::exception
#include <string>

class GameBoardException : public std::exception
{
// Attributes
private:
    std::string _msg;


// Methods
public:
    /**
     * @brief Construct a new GameBoardException Exception object
     * 
     * @param msg 
     */
    GameBoardException(const std::string& msg) : _msg(msg) {}

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

#endif // GAMEBOARDEXCEPTION_H
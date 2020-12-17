// My Includes
#include "../include/safeio.hpp"

// Includes
#include <iostream>


/**
 * @brief Construct a new SafeIO:: SafeIO object
 * 
 */
SafeIO::SafeIO(void) {
}


/**
 * @brief Destroy the SafeIO:: SafeIO object
 * 
 */
SafeIO::~SafeIO(void) {
}


/**
 * @brief print a string
 * 
 * @param msg 
 */
void SafeIO::print(const std::string& msg) noexcept {
    std::lock_guard<std::mutex> lock(_m);
    std::cout << msg << "\n";
}


/**
 * @brief ask a message and return the answer
 * 
 * @param msg 
 * @return std::string 
 */
std::string SafeIO::ask(const std::string& msg) noexcept {
    std::lock_guard<std::mutex> lock(_m);
    std::cout << msg << "\n";

    std::string answer{""};
    std::cin.ignore();
    std::getline(std::cin, answer);
    
    return answer;
}
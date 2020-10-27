#include <iostream>

#include"include/coins.hpp"

int main(int argc, char *argv[])
{
    std::cout << "Blackjack program" << "\n";
    std::cout << "Test : UINT_MAX from Class Coins : " << Coins::maxValue() << "\n";    // 4 294 967 295

    return 0;
}

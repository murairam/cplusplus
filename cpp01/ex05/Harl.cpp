// Harl.cpp

#include <iostream>
#include "Harl.hpp"

void Harl::debug() {
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl;
}

void Harl::info() {
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger!" << std::endl;
}

void Harl::warning() {
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free." << std::endl;
}

void Harl::error() {
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl;
}

void Harl::complain(std::string level) {
    // Array of function pointers
    typedef void (Harl::*ComplaintFunc)();
    ComplaintFunc functions[] = {
        &Harl::debug,
        &Harl::info,
        &Harl::warning,
        &Harl::error
    };

    std::string levels[] = { "DEBUG", "INFO", "WARNING", "ERROR" };

    for (int i = 0; i < 4; ++i) {
        if (level == levels[i]) {
            (this->*functions[i])();  // Call the right function via pointer
            return;
        }
    }

    std::cout << "[ UNKNOWN ] Harl doesn’t care about this level." << std::endl;
}

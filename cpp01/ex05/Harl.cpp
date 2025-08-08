// Harl.cpp

#include "Harl.hpp"

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug()    { 
    std::cout << "[ DEBUG ]\nI love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!" << std::endl; 
}
void Harl::info()     { 
    std::cout << "[ INFO ]\nI cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for it!" << std::endl; 
}

void Harl::warning()  { 
    std::cout << "[ WARNING ]\nI think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl; 
}

void Harl::error()    { 
    std::cout << "[ ERROR ]\nThis is unacceptable! I want to speak to the manager now."<< std::endl; 
}


void Harl::complain(std::string level) {
    // Create a mapping structure - shows string-to-function matching
    struct complaintMap {
        std::string level;
        void (Harl::*function)(void);
    };
    
    complaintMap complaints[] = {
        {"DEBUG", &Harl::debug},
        {"INFO", &Harl::info},
        {"WARNING", &Harl::warning},
        {"ERROR", &Harl::error}
    };
    
    // Find and execute the matching function
    for (int i = 0; i < 4; i++) {
        if (complaints[i].level == level) {
            (this->*complaints[i].function)();
            return;
        }
    }
}

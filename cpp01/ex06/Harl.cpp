// Harl.cpp

#include "Harl.hpp"
#include <iostream>
#include <fstream>
#include <sstream>


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
	void    (Harl::*functionPTRS[])( void ) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	std::string complains[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (complains[i] == level)
			(this->*functionPTRS[i])();
	}
}

void Harl::harlFilter(std::string level) {
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    int code = -1;

    for (int i = 0; i < 4; i++) {
        if (level == levels[i]) {
            code = i;
            break;
        }
    }

    switch (code) {
        case 0: 
            complain("DEBUG");
        case 1: // INFO
            complain("INFO");
        case 2: 
            complain("WARNING");
        case 3: 
            complain("ERROR");
            break;
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
    }
}
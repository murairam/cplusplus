// Harl.cpp

#include "Harl.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Harl::Harl() {}

void Harl::debug()    { std::cout << "[ DEBUG ]\n"   << messages["DEBUG"]   << std::endl; }
void Harl::info()     { std::cout << "[ INFO ]\n"    << messages["INFO"]    << std::endl; }
void Harl::warning()  { std::cout << "[ WARNING ]\n" << messages["WARNING"] << std::endl; }
void Harl::error()    { std::cout << "[ ERROR ]\n"   << messages["ERROR"]   << std::endl; }

void Harl::loadMessages(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file) {
        std::cerr << "Error: Cannot open file: " << filename << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::size_t delim = line.find(':');
        if (delim != std::string::npos) {
            std::string level = line.substr(0, delim);
            std::string message = line.substr(delim + 1);
            messages[level] = message;
        }
    }
}

void Harl::complain(std::string level) {
    typedef void (Harl::*HarlFunc)();
    std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    HarlFunc funcs[] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

    for (int i = 0; i < 4; ++i) {
        if (levels[i] == level) {
            (this->*funcs[i])();
            return;
        }
    }
    std::cout << "[ " << level << " ] Message not found." << std::endl;
}

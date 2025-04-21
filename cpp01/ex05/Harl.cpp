// Harl.cpp

#include "Harl.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

Harl::Harl() {}

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
    if (messages.find(level) != messages.end()) {
        std::cout << "[ " << level << " ]" << std::endl;
        std::cout << messages[level] << std::endl;
    } else {
        std::cout << "[ " << level << " ] Message not found." << std::endl;
    }
}

// main.cpp

#include "Harl.hpp"
#include <iostream>

int main() {
    Harl harl;

    harl.complain("DEBUG");
    std::cout << std::endl;

    harl.complain("INFO");
    std::cout << std::endl;

    harl.complain("WARNING");
    std::cout << std::endl;

    harl.complain("ERROR");
    std::cout << std::endl;

    harl.complain("RANDOM");  // Unknown level
    return 0;
}

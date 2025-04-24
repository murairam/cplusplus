// main.cpp

#include "Harl.hpp"
#include <iostream>

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Usage: ./harl <complaints_file>" << std::endl;
        return 1;
    }

    Harl harl;
    harl.loadMessages(argv[1]);

    // Test all levels
    harl.complain("DEBUG");
    harl.complain("INFO");
    harl.complain("WARNING");
    harl.complain("ERROR");
    return 0;
}

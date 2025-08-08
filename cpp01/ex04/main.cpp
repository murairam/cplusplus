#include "FileReplacer.hpp"

int main(int argc, char** argv) {
    // Check argument count
    if (argc != 4) {
        std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
        std::cerr << "  filename: input file to process" << std::endl;
        std::cerr << "  s1: string to search for" << std::endl;
        std::cerr << "  s2: string to replace s1 with" << std::endl;
        return 1;
    }

    // Extract arguments
    std::string filename = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];

    // Create FileReplacer object and perform replacement
    FileReplacer replacer(filename, s1, s2);
    
    if (replacer.replace()) {
        return 0;  // Success
    } else {
        return 1;  // Failure
    }
}
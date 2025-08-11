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

/* Einstein's theory of relativity revolutionized physics.
The theory consists of special relativity and general relativity.
Special relativity explains motion at high speeds.
General relativity explains gravity as a curvature of spacetime.
Relativity introduced the idea that time is not absolute.
According to relativity, observers moving at different speeds measure time differently.
Relativity also showed that mass and energy are equivalent, as described by E=mc^2.
The predictions of general relativity have been confirmed by many experiments.
Relativity remains one of the pillars of modern physics. */

#ifndef FILEREPLACER_HPP
#define FILEREPLACER_HPP

#include <string>
#include <iostream>
#include <fstream>

class FileReplacer {
private:
    std::string _filename;
    std::string _s1;
    std::string _s2;
    std::string _outputFilename;

public:
    // Constructor
    FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2);
    
    // Destructor
    ~FileReplacer();
    
    // Main functionality
    bool replace();

private:
    // Helper methods
    bool validateInputs() const;
    bool openInputFile(std::ifstream& inputFile) const;
    bool createOutputFile(std::ofstream& outputFile) const;
    std::string replaceInLine(const std::string& line) const;
    void generateOutputFilename();
};

#endif
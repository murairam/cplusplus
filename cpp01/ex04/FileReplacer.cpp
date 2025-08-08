#include "FileReplacer.hpp"

// Constructor
FileReplacer::FileReplacer(const std::string& filename, const std::string& s1, const std::string& s2)
    : _filename(filename), _s1(s1), _s2(s2) {
    generateOutputFilename();
}

// Destructor
FileReplacer::~FileReplacer() {
    // Nothing to clean up in this case
}

// Main replace functionality
bool FileReplacer::replace() {
    // Validate inputs first
    if (!validateInputs()) {
        return false;
    }

    // Open input file
    std::ifstream inputFile;
    if (!openInputFile(inputFile)) {
        return false;
    }

    // Create output file
    std::ofstream outputFile;
    if (!createOutputFile(outputFile)) {
        inputFile.close();
        return false;
    }

    // Process file line by line
    std::string line;
    while (std::getline(inputFile, line)) {
        std::string processedLine = replaceInLine(line);
        outputFile << processedLine << std::endl;
    }

    // Close files
    inputFile.close();
    outputFile.close();

    std::cout << "File processed successfully. Output written to: " << _outputFilename << std::endl;
    return true;
}

// Private helper methods

bool FileReplacer::validateInputs() const {
    if (_s1.empty()) {
        std::cerr << "Error: Search string (s1) cannot be empty." << std::endl;
        return false;
    }
    if (_s2.empty()) {
        std::cerr << "Error: Replace string (s2) cannot be empty." << std::endl;
        return false;
    }
    if (_filename.empty()) {
        std::cerr << "Error: Filename cannot be empty." << std::endl;
        return false;
    }
    return true;
}

bool FileReplacer::openInputFile(std::ifstream& inputFile) const {
    inputFile.open(_filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Cannot open input file '" << _filename << "'." << std::endl;
        return false;
    }
    
    // Check if file is empty
    if (inputFile.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: Input file is empty." << std::endl;
        inputFile.close();
        return false;
    }
    
    return true;
}

bool FileReplacer::createOutputFile(std::ofstream& outputFile) const {
    outputFile.open(_outputFilename.c_str());
    if (!outputFile) {
        std::cerr << "Error: Cannot create output file '" << _outputFilename << "'." << std::endl;
        return false;
    }
    return true;
}

std::string FileReplacer::replaceInLine(const std::string& line) const {
    std::string result = line;
    size_t pos = 0;
    
    // Find and replace all occurrences of s1 with s2
    while ((pos = result.find(_s1, pos)) != std::string::npos) {
        result.erase(pos, _s1.length());
        result.insert(pos, _s2);
        pos += _s2.length();  // Move past the replacement to avoid infinite loops
    }
    
    return result;
}

void FileReplacer::generateOutputFilename() {
    _outputFilename = _filename + ".replace";
}
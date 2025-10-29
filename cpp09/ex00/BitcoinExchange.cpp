/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:06:53 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/29 18:12:10 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <sstream>
#include <cstdlib>

// ocf
BitcoinExchange::BitcoinExchange() 
    : _inputFile(""), _databaseFile("data.csv") {}

BitcoinExchange::BitcoinExchange(const std::string& inputFile, const std::string& databaseFile)
    : _inputFile(inputFile), _databaseFile(databaseFile) {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange& other)
    : _inputFile(other._inputFile), _databaseFile(other._databaseFile), 
      _exchangeRates(other._exchangeRates) {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other) {
    if (this != &other) {
        _inputFile = other._inputFile;
        _databaseFile = other._databaseFile;
        _exchangeRates = other._exchangeRates;
    }
    return *this;
}

BitcoinExchange::~BitcoinExchange() {}

// string util

static std::string trim(const std::string& str) {
    const char* whitespace = " \t\n\r\f\v";
    size_t start = str.find_first_not_of(whitespace);
    if (start == std::string::npos) {
        return "";
    }
    size_t end = str.find_last_not_of(whitespace);
    return str.substr(start, end - start + 1);
}

// public interface

bool BitcoinExchange::execute() {
    if (!validateInput()) {
        return false;
    }
    
    if (!loadDatabase()) {
        return false;
    }
    
    std::ifstream inputFile;
    if (!openFile(inputFile, _inputFile)) {
        return false;
    }
    
    std::string line;
    std::getline(inputFile, line);
    
    // Validate header
    std::string expectedHeader = "date | value";
    if (trim(line) != expectedHeader) {
        std::cerr << "Error: invalid header. Expected '" << expectedHeader << "', got '" << line << "'" << std::endl;
        inputFile.close();
        return false;
    }
    
    while (std::getline(inputFile, line)) {
        processLine(line);
    }
    
    inputFile.close();
    return true;
}

// file operations

bool BitcoinExchange::openFile(std::ifstream& file, const std::string& filename) const {
    file.open(filename.c_str());
    if (!file) {
        std::cerr << "Error: could not open file." << std::endl;
        return false;
    }
    
    if (file.peek() == std::ifstream::traits_type::eof()) {
        std::cerr << "Error: file is empty." << std::endl;
        file.close();
        return false;
    }
    
    return true;
}

bool BitcoinExchange::loadDatabase() {
    std::ifstream dbFile;
    if (!openFile(dbFile, _databaseFile)) {
        return false;
    }
    
    std::string line;
    std::getline(dbFile, line);  // Skip header
    
    while (std::getline(dbFile, line)) {
        std::stringstream ss(line);
        std::string date, priceStr;
        
        std::getline(ss, date, ',');
        std::getline(ss, priceStr);
        
        float price = std::atof(priceStr.c_str());
        _exchangeRates[date] = price;
    }
    
    dbFile.close();
    return true;
}

// line processing

void BitcoinExchange::processLine(const std::string& line) {
    std::string date, valueStr;
    
    if (!parseLine(line, date, valueStr)) {
        std::cout << "Error: bad input => " << line << std::endl;
        return;
    }
    
    if (!isValidDate(date)) {
        std::cout << "Error: bad input => " << date << std::endl;
        return;
    }
    
    if (!isValidNumber(valueStr)) {
        std::cout << "Error: bad input => " << valueStr << std::endl;
        return;
    }
    
    float value = std::atof(valueStr.c_str());
    
    if (value < 0) {
        std::cout << "Error: not a positive number." << std::endl;
        return;
    }
    
    if (value > MAX_VALUE) {
        std::cout << "Error: too large a number." << std::endl;
        return;
    }
    
    calculateAndPrint(date, value);
}

bool BitcoinExchange::parseLine(const std::string& line, std::string& date, std::string& value) const {
    size_t pipePos = line.find('|');
    if (pipePos == std::string::npos) {
        return false;
    }
    
    date = trim(line.substr(0, pipePos));
    value = trim(line.substr(pipePos + 1));
    
    return true;
}

// ============================================================================
// VALIDATION
// ============================================================================

bool BitcoinExchange::validateInput() const {
    if (_inputFile.empty()) {
        std::cerr << "Error: filename cannot be empty." << std::endl;
        return false;
    }
    return true;
}

bool BitcoinExchange::isValidDate(const std::string& date) const {
    if (date.length() != 10 || date[4] != '-' || date[7] != '-') {
        return false;
    }
    
    for (int i = 0; i < 10; i++) {
        if (i != 4 && i != 7 && !std::isdigit(date[i])) {
            return false;
        }
    }
    
    int year = std::atoi(date.substr(0, 4).c_str());
    int month = std::atoi(date.substr(5, 2).c_str());
    int day = std::atoi(date.substr(8, 2).c_str());
    
    if (year < 0 || month < 1 || month > 12 || day < 1 || day > 31) {
        return false;
    }
    
    // Days in each month (with leap year calculation for February)
    int daysInMonth[] = {
        31, 
        28 + ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)), 
        31, 30, 31, 30, 31, 31, 30, 31, 30, 31
    };
    
    return day <= daysInMonth[month - 1];
}

bool BitcoinExchange::isValidNumber(const std::string& str) const {
    if (str.empty()) {
        return false;
    }
    
    size_t i = 0;
    if (str[0] == '+' || str[0] == '-') {
        i = 1;
    }
    
    bool hasDigit = false;
    bool hasDot = false;
    
    for (; i < str.length(); i++) {
        if (std::isdigit(str[i])) {
            hasDigit = true;
        } else if (str[i] == '.') {
            if (hasDot) {
                return false;
            }
            hasDot = true;
        } else {
            return false;
        }
    }
    
    return hasDigit;
}

// ============================================================================
// CALCULATION
// ============================================================================

float BitcoinExchange::findExchangeRate(const std::string& date) const {
    std::map<std::string, float>::const_iterator it = _exchangeRates.lower_bound(date);
    
    // Exact match found
    if (it != _exchangeRates.end() && it->first == date) {
        return it->second;
    }
    
    // No exact match, use closest lower date
    if (it != _exchangeRates.begin()) {
        --it;
        return it->second;
    }
    
    // Date is before all database entries
    return -1.0f;
}

void BitcoinExchange::calculateAndPrint(const std::string& date, float value) const {
    float rate = findExchangeRate(date);
    
    if (rate < 0) {
        std::cout << "Error: no exchange rate available for this date." << std::endl;
        return;
    }
    
    std::cout << date << " => " << value << " = " << (value * rate) << std::endl;
}
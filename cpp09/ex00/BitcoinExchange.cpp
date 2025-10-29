/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:06:53 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/29 17:46:00 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <iomanip>
#include <sstream>
#include <cstdlib> 
#include "BitcoinExchange.hpp"
#include <climits>

File::File(const std::string& txtfile, const std::string& datafile) : _txtfile(txtfile), _datafile(datafile){};

File::File(const File &other) : _txtfile(other._txtfile), _datafile(other._datafile) {};

File& File::operator=(const File &other) {
    if (this != &other){
        _txtfile = other._txtfile;
        _datafile = other._datafile;
    }
    return *this;
};

File::~File(){};
 
/* bool get_date(std::istream &in, std::tm &tm) { 
  in >> std::get_time(&tm, "%m/%d/%Y"); 
  return in; 
} 
 
// tm_year = year - 1900 (may be negative) 
// tm_mon  = month - 1 
// tm_mday = day of the month 
 
std::tm date_info { }; 
bool ok = get_date(std::istringstream(my_date), date_info);  */


bool File::isValidDate(const std::string& date){
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
	
	if (month < 1 || month > 12 || day < 1 || day > 31) {
		return false;
	}
	
	int daysInMonth[] = {31, 28 + ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
	return day <= daysInMonth[month - 1];
}

bool isValidNumber(const std::string& str) {
    if (str.empty()) return false;
    
    size_t start = 0;
    if (str[0] == '+' || str[0] == '-') {
        start = 1;
    }
    
    bool hasDigit = false;
    bool hasDot = false;
    
    for (size_t i = start; i < str.length(); i++) {
        if (std::isdigit(str[i])) {
            hasDigit = true;
        } else if (str[i] == '.') {
            if (hasDot) return false;  // Two dots!
            hasDot = true;
        } else {
            return false;  // Invalid character
        }
    }
    
    return hasDigit;
}

const char* ws = " \t\n\r\f\v";

// trim from end of string (right)
inline std::string& rtrim(std::string& s, const char* t = ws)
{
    s.erase(s.find_last_not_of(t) + 1);
    return s;
}

// trim from beginning of string (left)
inline std::string& ltrim(std::string& s, const char* t = ws)
{
    s.erase(0, s.find_first_not_of(t));
    return s;
}

// trim from both ends of string (right then left)
inline std::string& trim(std::string& s, const char* t = ws)
{
    return ltrim(rtrim(s, t), t);
}

bool File::read() {
    // Validate inputs first
    if (!validateInput()) {
        return false;
    }
	
	if (!loadDatabase()) {
    return false;
}

    // Open input file
    std::ifstream txtfile;
    if (!openFile(txtfile, _txtfile)) {
        return false;
    }

    
    // Process file line by line
    std::string line;
	std::getline(txtfile, line);
    while (std::getline(txtfile, line)) {
		if (line.find('|') == std::string::npos) {
			std::cout << "Error: bad input => " << line << std::endl;
			continue;
		}
		std::stringstream ss(line);
		std::string date, num;
		std::getline(ss, date, '|');
		trim(date);
		std::getline(ss, num);
		trim(num);
		if (!isValidDate(date)) {
			std::cout << "Error: bad input => " << date << std::endl;
		}
		else{
			if (isValidNumber(num)){
				float value = std::atof(num.c_str());		
				if (value < 0){
					std::cout << "Error: not a positive number." << std::endl;
				}
				else if (value > 1000){
					std::cout << "Error: too large a number." << std::endl;
				}
				else {
					std::map<std::string, float>::iterator it = _database.lower_bound(date);
					if (it != _database.end() && it->first == date){
						std::cout << date << " => " << value << " = " << value*(it->second) << std::endl;
					}
					else if (it != _database.begin()){
						--it;
						std::cout << date << " => " << value << " = " << value*(it->second) << std::endl;
					}
					else {
						std::cout << "Error: no valid exchange rate" << std::endl;
					}
			
				}
			}
			else
				std::cout << "Error: not a valid number." << std::endl;
		}
    }
	
    // Close file
    txtfile.close();

    return true;
}

// Private helper methods

bool File::validateInput() const {
    if (_txtfile.empty()) {
        std::cerr << "Error: Filename cannot be empty." << std::endl;
        return false;
    }
    return true;
}

bool File::openFile(std::ifstream& inputFile, const std::string& filename) const {
    inputFile.open(filename.c_str());
    if (!inputFile) {
        std::cerr << "Error: Cannot open input file '" << filename << "'." << std::endl;
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

bool  File::loadDatabase(){
	
	std::ifstream datafile;
	if (!openFile(datafile, _datafile)) {
        return false;
    }
	
	std::string line;
	std::getline(datafile, line);

    while (std::getline(datafile, line)) {
		std::stringstream ss(line);
		std::string date, price_str;
		std::getline(ss, date, ',');      // Get everything before comma
		std::getline(ss, price_str);       // Get everything after comma
		float price = std::atof(price_str.c_str());	
		_database[date] = price;
    }
	datafile.close();
	return true;
}
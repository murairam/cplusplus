/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:06:53 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/29 15:15:09 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream> 
#include <iomanip> 
#include "BitcoinExchange.hpp"

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

// Main replace functionality
bool File::read() {
    // Validate inputs first
    if (!validateInput()) {
        return false;
    }

    // Open input file
    std::ifstream txtfile;
    if (!openInputFile(txtfile)) {
        return false;
    }

    std::ifstream datafile;
    if (!openInputFile(datafile)) {
        return false;
    }
    
    // Process file line by line
    std::string line;
    while (std::getline(txtfile, line)){
      while (std::getline(txtfile, line, '|')) {
        std::cout << line << std::endl;
      } 
    }

    std::string lines;
    while (std::getline(datafile, lines)){
      while (std::getline(datafile, lines, ',')) {
        std::cout << lines << std::endl;
      } 
    }

    // Close files
    txtfile.close();
    datafile.close();

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

bool File::openInputFile(std::ifstream& inputFile) const {
    inputFile.open(_txtfile.c_str());
    if (!inputFile) {
        std::cerr << "Error: Cannot open input file '" << _txtfile << "'." << std::endl;
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
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 16:54:32 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 16:56:59 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <limits>
#include <string>
#include <iostream>
#include <climits>
#include <cmath>
#include <cstdlib>

enum LiteralType { CHAR, INT, FLOAT, DOUBLE, INVALID };

static void printChar(double value) {
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "char: impossible" << std::endl;
    }
    else if (value < 0 || value > 127) {  // Outside ASCII range
        std::cout << "char: impossible" << std::endl;
    }
    else if (value < 32 || value == 127) {  // Non-displayable ASCII
        std::cout << "char: Non displayable" << std::endl;
    }
    else {
        char c = static_cast<char>(value);
        std::cout << "char: '" << c << "'" << std::endl;
    }
}

static void printInt(double value) {
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "int: impossible" << std::endl;
    }
    else if (value > INT_MAX || value < INT_MIN) {
        std::cout << "int: impossible" << std::endl;
    }
    else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}

static void printFloat(double value) {
    if (std::isnan(value)) {
        std::cout << "float: nanf" << std::endl;
    }
    else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "float: +inff" << std::endl;
        } else {
            std::cout << "float: -inff" << std::endl;
        }
    }
    else {
        float f = static_cast<float>(value);
        std::cout << "float: " << f;
        if (f == static_cast<int>(f)) {  // No decimal part
            std::cout << ".0";
        }
        std::cout << "f" << std::endl;
    }
}

static void printDouble(double value) {
    if (std::isnan(value)) {
        std::cout << "double: nan" << std::endl;
    }
    else if (std::isinf(value)) {
        if (value > 0) {
            std::cout << "double: +inf" << std::endl;
        } else {
            std::cout << "double: -inf" << std::endl;
        }
    }
    else {
        std::cout << "double: " << value;
        if (value == static_cast<int>(value)) {  // No decimal part
            std::cout << ".0";
        }
        std::cout << std::endl;
    }
}

static void convertAndPrint(double value) {
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}

static bool isValidNumber(const std::string& input) {
    if (input.empty()) return false;
    
    size_t i = 0;
    
    // Handle optional sign
    if (input[i] == '+' || input[i] == '-') i++;
    
    bool hasDigits = false;
    bool hasDot = false;
    
    // Parse digits and decimal point
    while (i < input.length() && (std::isdigit(input[i]) || input[i] == '.')) {
        if (input[i] == '.') {
            if (hasDot) return false;  // Second decimal point = invalid
            hasDot = true;
        } else {
            hasDigits = true;
        }
        i++;
    }
    
    // Handle 'f' suffix for floats
    if (i < input.length() && input[i] == 'f') {
        i++;
    }
    
    // Must have consumed entire string AND have at least one digit
    return (i == input.length()) && hasDigits;
}

static LiteralType detectType(const std::string& input) {
    // Handle special cases first
    if (input == "nanf" || input == "+inff" || input == "-inff") return FLOAT;
    if (input == "nan" || input == "+inf" || input == "-inf") return DOUBLE;
    
    // Handle chars - but exclude digits and +/- signs
    if (input.length() == 3 && input[0] == '\'' && input[2] == '\'') return CHAR;
    if (input.length() == 1 && std::isprint(input[0]) && 
        !std::isdigit(input[0]) && input[0] != '+' && input[0] != '-') return CHAR;
    
    // Check if it's a valid number format first
    if (!isValidNumber(input)) return INVALID;
    
    // Now classify the valid number
    if (!input.empty() && input[input.length() - 1] == 'f') return FLOAT;
    if (input.find('.') != std::string::npos) return DOUBLE;
    return INT;
}

static int parseInt(const std::string& input) { return atoi(input.c_str()); }

static float parseFloat(const std::string& input) {
    if (input == "+inff") return std::numeric_limits<float>::infinity();
    if (input == "-inff") return -std::numeric_limits<float>::infinity();
    if (input == "nanf") return std::numeric_limits<float>::quiet_NaN();
    
    return strtof(input.c_str(), NULL);
}

static double parseDouble(const std::string& input) {
    if (input == "+inf") return std::numeric_limits<double>::infinity();
    if (input == "-inf") return -std::numeric_limits<double>::infinity();
    if (input == "nan") return std::numeric_limits<double>::quiet_NaN();
    
    return strtod(input.c_str(), NULL);
}

static char parseChar(const std::string& input) {
    if (input.length() == 3) {
        return input[1];  // Quoted: 'c' -> return middle char
    } else {
        return input[0];  // Unquoted: c -> return the char
    }
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter()
{
}

void ScalarConverter::convert(const std::string &literal)
{
    LiteralType type = detectType(literal);
    
	switch(type) {
 	   case CHAR: convertAndPrint(parseChar(literal)); break;
 	   case INT: convertAndPrint(parseInt(literal)); break;
 	   case FLOAT: convertAndPrint(static_cast<double>(parseFloat(literal))); break;
 	   case DOUBLE: convertAndPrint(parseDouble(literal)); break;
 	   case INVALID: 
 	       std::cout << "Error: Invalid input format" << std::endl;
 	       break;
}
}

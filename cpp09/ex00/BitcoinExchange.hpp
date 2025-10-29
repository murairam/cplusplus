/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:43:05 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/29 18:02:32 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>
#include <map>

class BitcoinExchange {
private:
    std::string _inputFile;
    std::string _databaseFile;
    std::map<std::string, float> _exchangeRates;
    
    static const int MAX_VALUE = 1000;
    
    // File operations
    bool openFile(std::ifstream& file, const std::string& filename) const;
    bool loadDatabase();
    
    // Line processing
    void processLine(const std::string& line);
    bool parseLine(const std::string& line, std::string& date, std::string& value) const;
    
    // Validation
    bool validateInput() const;
    bool isValidDate(const std::string& date) const;
    bool isValidNumber(const std::string& str) const;
    
    // Calculation
    float findExchangeRate(const std::string& date) const;
    void calculateAndPrint(const std::string& date, float value) const;
    
public:
    BitcoinExchange();
    BitcoinExchange(const std::string& inputFile, const std::string& databaseFile);
    BitcoinExchange(const BitcoinExchange& other);
    BitcoinExchange& operator=(const BitcoinExchange& other);
    ~BitcoinExchange();
    
    bool execute();
};

#endif

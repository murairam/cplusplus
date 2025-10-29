/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:43:05 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/29 15:10:08 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <iostream>
#include <fstream>

class File {
private:
    std::string _txtfile;
    std::string _datafile;
    
public:
    File(const std::string& txtfile, const std::string& datafile);
    File(const File &other);
    File& operator=(const File &other);
    ~File();

    bool read();
    bool validateInput() const;
    bool openInputFile(std::ifstream& inputFile) const;
    
    
    
};

#endif

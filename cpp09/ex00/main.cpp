/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:12:30 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/29 15:10:12 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv){

    // Check argument count
    if (argc != 2) {
        std::cerr << "Usage: ./btc <filename>" << std::endl;
        std::cerr << "  filename: input file to process" << std::endl;
        return 1;
    }

    // Extract arguments
    std::string txtfile = argv[1];
    std::string datafile  = "data.csv";
    

    // Create File object and perform replacement
    File input(txtfile, datafile);
    
    if (input.read()) {
        return 0;  // Success
    } else {
        return 1;  // Failure
    }
}
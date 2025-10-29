/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 19:12:30 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/29 17:58:43 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char** argv) {
    if (argc != 2) {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }
    
    BitcoinExchange exchange(argv[1], "data.csv");
    
    if (!exchange.execute()) {
        return 1;
    }
    
    return 0;
}
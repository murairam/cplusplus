/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:13:21 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/04/07 15:10:45 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;

    while (true) {
        std::cout << "Enter a command (ADD, SEARCH, EXIT): ";
        std::getline(std::cin, command);

        if (command == "ADD") {
            phoneBook.addContact();
        } 
        else if (command == "SEARCH") {
            phoneBook.searchContact();
        } 
        else if (command == "EXIT") {
            std::cout << "Goodbye!" << std::endl;
            break;
        } 
        else {
            std::cout << "Invalid command. Use ADD, SEARCH, or EXIT." << std::endl;
        }
    }
    return 0;
}


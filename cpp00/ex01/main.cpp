/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:13:21 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/08/07 17:32:58 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main() {
    PhoneBook phoneBook;
    std::string command;

    // Welcome message
    std::cout << "==================================" << std::endl;
    std::cout << "   Welcome to Your PhoneBook!    " << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << "Available commands:" << std::endl;
    std::cout << "  ADD    - Add a new contact" << std::endl;
    std::cout << "  SEARCH - Search and view contacts" << std::endl;
    std::cout << "  EXIT   - Exit the application" << std::endl;
    std::cout << "==================================" << std::endl;
    std::cout << std::endl;

    while (true) {
        std::cout << "PhoneBook> ";
        if (!std::getline(std::cin, command)) {
            // EOF reached (Ctrl+D or input stream ended)
            std::cout << std::endl << "EOF detected. Goodbye!" << std::endl;
            break;
        }

        // Commands must be exactly "ADD", "SEARCH", or "EXIT" (uppercase)
        if (command == "ADD") {
            phoneBook.addContact();
        } 
        else if (command == "SEARCH") {
            phoneBook.searchContact();
        } 
        else if (command == "EXIT") {
            std::cout << std::endl << "Thank you for using PhoneBook! Goodbye!" << std::endl;
            break;
        } 
        else {
            if (command.empty()) {
                std::cout << "⚠️  Please enter a command. Valid commands (case-sensitive):" << std::endl;
            } else {
                std::cout << "⚠️  '" << command << "' is not a valid command. Valid commands (case-sensitive):" << std::endl;
            }
            std::cout << "   • ADD    - Add a new contact" << std::endl;
            std::cout << "   • SEARCH - Search and view contacts" << std::endl;
            std::cout << "   • EXIT   - Exit the application" << std::endl;
            std::cout << "   Note: Commands must be in UPPERCASE" << std::endl;
            std::cout << std::endl;
        }
    }
    return 0;
}


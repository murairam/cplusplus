/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:29:37 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/03/10 17:24:47 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip> // For formatting table output
#include <cstdlib>

class PhoneBook {
private:
    Contact contacts[8];  // Array to store up to 8 contacts
    int contactIndex;     // Keeps track of where to store next contact
    int totalContacts;    // Keeps track of how many contacts are stored

public:
    // Constructor
    PhoneBook();

    // Methods
    void addContact();
    void displayContacts();
    void searchContact();
};

#endif

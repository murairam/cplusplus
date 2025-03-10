#include "PhoneBook.hpp"

// Constructor initializes indexes
PhoneBook::PhoneBook() {
    contactIndex = 0;   // Points to where the next contact should be stored
    totalContacts = 0;  // Tracks the number of contacts
}

// Method to add a new contact
void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    std::cout << "Enter First Name: ";
    std::getline(std::cin, input);
    newContact.setFirstName(input);

    std::cout << "Enter Last Name: ";
    std::getline(std::cin, input);
    newContact.setLastName(input);

    std::cout << "Enter Nickname: ";
    std::getline(std::cin, input);
    newContact.setNickname(input);

    std::cout << "Enter Phone Number: ";
    std::getline(std::cin, input);
    newContact.setPhoneNumber(input);

    std::cout << "Enter Darkest Secret: ";
    std::getline(std::cin, input);
    newContact.setDarkestSecret(input);

    // Store contact in a circular buffer
    contacts[contactIndex] = newContact;

    // Update index (overwrite oldest if full)
    contactIndex = (contactIndex + 1) % 8;

    // Ensure totalContacts never exceeds 8
    if (totalContacts < 8)
        totalContacts++;

    std::cout << "Contact added successfully!" << std::endl;
}

// Helper function to format text for display (max 10 characters)
std::string formatText(std::string text) {
    if (text.length() > 10)
        return text.substr(0, 9) + "."; // Truncate and add "."
    return text;
}

// Display all contacts in a formatted table
void PhoneBook::displayContacts() {
    if (totalContacts == 0) {
        std::cout << "No contacts available." << std::endl;
        return;
    }

    // Table Header
    std::cout << std::setw(10) << "Index" << "|"
              << std::setw(10) << "First Name" << "|"
              << std::setw(10) << "Last Name" << "|"
              << std::setw(10) << "Nickname" << std::endl;

    // Display in correct order, considering the circular buffer
    for (int i = 0; i < totalContacts; i++) {
        int displayIndex = (contactIndex + i) % totalContacts;  // Correct order
        std::cout << std::setw(10) << (i + 1) << "|"
                  << std::setw(10) << formatText(contacts[displayIndex].getFirstName()) << "|"
                  << std::setw(10) << formatText(contacts[displayIndex].getLastName()) << "|"
                  << std::setw(10) << formatText(contacts[displayIndex].getNickname()) << std::endl;
    }
}

// Search for a contact by index
void PhoneBook::searchContact() {
    if (totalContacts == 0) {
        std::cout << "No contacts to search!" << std::endl;
        return;
    }

    displayContacts();  // Show the list first

    int index;
    std::cout << "Enter index to view details (1 - " << totalContacts << "): ";

    // Validate user input to prevent looping issues
    while (!(std::cin >> index) || index < 1 || index > totalContacts) {
        std::cin.clear(); // Reset fail state
        std::cin.ignore(10000, '\n'); // Remove invalid input
        std::cout << "Invalid input! Please enter a number between 1 and " << totalContacts << ": ";
    }

    std::cin.ignore(); // Clear the buffer after valid input

    // Convert user input (1-8) to the correct index in the circular buffer
    int realIndex = (contactIndex + index - 1) % totalContacts;

    // Display selected contact's details
    std::cout << "First Name: " << contacts[realIndex].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[realIndex].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[realIndex].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[realIndex].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[realIndex].getDarkestSecret() << std::endl;
}

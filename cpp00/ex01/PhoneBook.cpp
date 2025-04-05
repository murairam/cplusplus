#include "PhoneBook.hpp"
// make sure printing is 10 characters long
// contact cant be empty (addcontact.empty?)
// phone number can only be digits, cant be numbers
// if 9th contact is added, the first one is removed and the new contact goes to the first,  index the oldest one and overwwrite it when ninth is added

// Constructor initializes indexes
PhoneBook::PhoneBook() {
    contactIndex = 0;   // Points to where the next contact should be stored
    totalContacts = 0;  // Tracks the number of contacts
}

bool isValidInput(const std::string& str) {
    return !str.empty() && str.find_first_not_of(" \t\n\v\f\r") != std::string::npos;
}

std::string trim(const std::string& str) {
    size_t first = str.find_first_not_of(" \t\n\v\f\r");
    if (first == std::string::npos) {
        return ""; // String is all whitespace
    }
    size_t last = str.find_last_not_of(" \t\n\v\f\r");
    return str.substr(first, (last - first + 1));
}

bool isNumeric(const std::string& str) {
    if (str.empty()) {
        return false;
    }
    for (size_t i = 0; i < str.length(); i++) {
        if (!std::isdigit(str[i])) {
            return false;
        }
    }
    return true;
}

// Method to add a new contact
void PhoneBook::addContact() {
    Contact newContact;
    std::string input;

    // First Name
    do {
        std::cout << "Enter First Name: ";
        std::getline(std::cin, input);
        input = trim(input); // Trim the input
    } while (!isValidInput(input));
    newContact.setFirstName(input);

    // Last Name
    do {
        std::cout << "Enter Last Name: ";
        std::getline(std::cin, input);
        input = trim(input); // Trim the input
    } while (!isValidInput(input));
    newContact.setLastName(input);

    // Nickname
    do {
        std::cout << "Enter Nickname: ";
        std::getline(std::cin, input);
        input = trim(input); // Trim the input
    } while (!isValidInput(input));
    newContact.setNickname(input);

    // Phone Number
    do {
        std::cout << "Enter Phone Number: ";
        std::getline(std::cin, input);
        input = trim(input); // Trim the input
    } while (!isNumeric(input));
    newContact.setPhoneNumber(input);

    // Darkest Secret
    do {
        std::cout << "Enter Darkest Secret: ";
        std::getline(std::cin, input);
        input = trim(input); // Trim the input
    } while (!isValidInput(input));
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

    // Display contacts in the circular buffer order
    for (int i = 0; i < totalContacts; i++) {
        int displayIndex = (contactIndex + i) % 8; // Start from the current contactIndex
        std::cout << std::setw(10) << (displayIndex + 1) << "|"
                  << std::setw(10) << formatText(contacts[displayIndex].getFirstName()) << "|"
                  << std::setw(10) << formatText(contacts[displayIndex].getLastName()) << "|"
                  << std::setw(10) << formatText(contacts[displayIndex].getNickname()) << std::endl;
    }
}

void PhoneBook::searchContact() {
    if (totalContacts == 0) {
        std::cout << "No contacts to search!" << std::endl;
        return;
    }

    displayContacts();  // Show the list first

    std::cout << "Enter index to view details (1 - " << totalContacts << "): ";

    std::string input;
    std::getline(std::cin, input);  // Read the entire input line

    // Validate input: Check if input is empty or contains non-numeric characters
    if (input.empty() || input.find_first_not_of("0123456789") != std::string::npos) {
        std::cout << "Invalid input! Please enter a number between 1 and " << totalContacts << "." << std::endl;
        return;
    }

    int index = atoi(input.c_str()); // Convert string to integer safely

    if (index < 1 || index > totalContacts) {
        std::cout << "Invalid index! Please enter a number between 1 and " << totalContacts << "." << std::endl;
        return;
    }

    // Convert user input (1-based index) to the correct index in the circular buffer
    int realIndex = (contactIndex - totalContacts + (index - 1) + 8) % 8;

    // Display selected contact's details
    std::cout << "First Name: " << contacts[realIndex].getFirstName() << std::endl;
    std::cout << "Last Name: " << contacts[realIndex].getLastName() << std::endl;
    std::cout << "Nickname: " << contacts[realIndex].getNickname() << std::endl;
    std::cout << "Phone Number: " << contacts[realIndex].getPhoneNumber() << std::endl;
    std::cout << "Darkest Secret: " << contacts[realIndex].getDarkestSecret() << std::endl;
}

#include "PhoneBook.hpp"

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

// Helper function for user-friendly input collection
std::string getValidInput(const std::string& fieldName, bool isPhoneNumber = false) {
    std::string input;
    int attempts = 0;
    const int maxAttempts = 5;
    
    do {
        std::cout << fieldName << ": ";
        if (!std::getline(std::cin, input)) {
            // EOF reached
            std::cout << std::endl << "EOF detected. Returning to main menu." << std::endl;
            return "";
        }
        input = trim(input);
        
        if (isPhoneNumber) {
            if (isNumeric(input)) {
                return input;
            }
            attempts++;
            if (attempts >= maxAttempts) {
                std::cout << "❌ Too many invalid attempts. Returning to main menu." << std::endl;
                return "";
            }
            if (input.empty()) {
                std::cout << "⚠️  " << fieldName << " cannot be empty." << std::endl;
                std::cout << "   Please enter digits only (e.g., 1234567890)" << std::endl;
            } else {
                std::cout << "⚠️  " << fieldName << " must contain only digits (0-9)." << std::endl;
                std::cout << "   Example: 1234567890" << std::endl;
            }
        } else {
            if (isValidInput(input)) {
                return input;
            }
            attempts++;
            if (attempts >= maxAttempts) {
                std::cout << "❌ Too many invalid attempts. Returning to main menu." << std::endl;
                return "";
            }
            std::cout << "⚠️  " << fieldName << " cannot be empty or contain only whitespace." << std::endl;
            std::cout << "   Please enter a valid " << fieldName << "." << std::endl;
        }
        
        if (attempts >= 3) {
            std::cout << "💡 Tip: Make sure to enter some actual text, not just spaces or empty input." << std::endl;
        }
        
    } while (true);
}

// Method to add a new contact
void PhoneBook::addContact() {
    Contact newContact;

    std::cout << std::endl << "=== Adding New Contact ===" << std::endl;
    std::cout << "Please fill in all the required fields:" << std::endl << std::endl;
    
    // Use helper function for cleaner input collection
    std::string firstName = getValidInput("First Name");
    if (firstName.empty()) return;
    
    std::string lastName = getValidInput("Last Name");
    if (lastName.empty()) return;
    
    std::string nickname = getValidInput("Nickname");
    if (nickname.empty()) return;
    
    std::string phoneNumber = getValidInput("Phone Number", true);
    if (phoneNumber.empty()) return;
    
    std::string darkestSecret = getValidInput("Darkest Secret");
    if (darkestSecret.empty()) return;

    newContact.setFirstName(firstName);
    newContact.setLastName(lastName);
    newContact.setNickname(nickname);
    newContact.setPhoneNumber(phoneNumber);
    newContact.setDarkestSecret(darkestSecret);
    newContact.setDisplayIndex(contactIndex + 1); // logical position (1–8)

    // Store contact in a circular buffer
    contacts[contactIndex] = newContact;

    // Update index (overwrite oldest if full)
    contactIndex = (contactIndex + 1) % 8;

    // Ensure totalContacts never exceeds 8
    if (totalContacts < 8)
        totalContacts++;

    std::cout << std::endl << "✅ Contact '" << newContact.getFirstName() << " " << newContact.getLastName() 
              << "' added successfully!" << std::endl;
    std::cout << "   Total contacts: " << totalContacts << "/8" << std::endl << std::endl;
}

// Helper function to format text for display (max 10 characters)
std::string formatText(std::string text) {
    // Replace control characters with spaces
    for (size_t i = 0; i < text.length(); i++) {
        if (text[i] == '\t' || text[i] == '\n' || text[i] == '\r')
            text[i] = ' ';
    }

    // Truncate if too long
    if (text.length() > 10)
        return text.substr(0, 9) + ".";

    // Return as-is - setw() will handle the right-alignment
    return text;
}



void PhoneBook::displayContacts() {
    // Create array of valid contacts
    Contact sortedContacts[8];
    for (int i = 0; i < totalContacts; i++) {
        sortedContacts[i] = contacts[i];
    }

    // Sort contacts by displayIndex
    for (int i = 0; i < totalContacts - 1; i++) {
        for (int j = i + 1; j < totalContacts; j++) {
            if (sortedContacts[i].getDisplayIndex() > sortedContacts[j].getDisplayIndex()) {
                Contact temp = sortedContacts[i];
                sortedContacts[i] = sortedContacts[j];
                sortedContacts[j] = temp;
            }
        }
    }

    // Print table header
    std::cout << "┌──────────┬──────────┬──────────┬──────────┐" << std::endl;
    std::cout << "│" << std::setw(10) << "Index" << "│"
              << std::setw(10) << "First Name" << "│"
              << std::setw(10) << "Last Name" << "│"
              << std::setw(10) << "Nickname" << "│" << std::endl;
    std::cout << "├──────────┼──────────┼──────────┼──────────┤" << std::endl;

    // Print contacts
    for (int i = 0; i < totalContacts; i++) {
        Contact c = sortedContacts[i];
        std::cout << "│" << std::setw(10) << c.getDisplayIndex() << "│"
                << std::setw(10) << formatText(c.getFirstName()) << "│"
                << std::setw(10) << formatText(c.getLastName()) << "│"
                << std::setw(10) << formatText(c.getNickname()) << "│" << std::endl;
    }
    std::cout << "└──────────┴──────────┴──────────┴──────────┘" << std::endl;
}


void PhoneBook::searchContact() {
    if (totalContacts == 0) {
        std::cout << std::endl << "📋 Your phonebook is empty!" << std::endl;
        std::cout << "   Use the ADD command to add some contacts first." << std::endl << std::endl;
        return;
    }

    std::cout << std::endl << "=== Contact List ===" << std::endl;
    displayContacts();  // Show the list first
    std::cout << std::endl;

    std::string input;
    int attempts = 0;
    const int maxAttempts = 5;
    
    do {
        std::cout << "Enter contact index (1-" << totalContacts << ") or 0 to cancel: ";
        if (!std::getline(std::cin, input)) {
            // EOF reached
            std::cout << std::endl << "EOF detected. Returning to main menu." << std::endl;
            return;
        }

        // Allow user to cancel
        if (input == "0") {
            std::cout << "Search cancelled." << std::endl << std::endl;
            return;
        }

        // Validate input: Check if input is empty
        if (input.empty()) {
            attempts++;
            if (attempts >= maxAttempts) {
                std::cout << "❌ Too many invalid attempts. Returning to main menu." << std::endl;
                return;
            }
            std::cout << "⚠️  Index cannot be empty." << std::endl;
            if (attempts < 3) {
                std::cout << "   Please enter a number between 1 and " << totalContacts << ", or 0 to cancel." << std::endl;
            } else {
                std::cout << "💡 Tip: Type a number like '1', '2', etc., or '0' to go back." << std::endl;
            }
            continue;
        }
        
        // Check for non-numeric characters
        if (input.find_first_not_of("0123456789") != std::string::npos) {
            attempts++;
            if (attempts >= maxAttempts) {
                std::cout << "❌ Too many invalid attempts. Returning to main menu." << std::endl;
                return;
            }
            std::cout << "⚠️  Index must contain only digits." << std::endl;
            if (attempts < 3) {
                std::cout << "   Please enter a valid number between 1 and " << totalContacts << ", or 0 to cancel." << std::endl;
            } else {
                std::cout << "💡 Tip: Use only numbers (0-9). For example: 1, 2, 3..." << std::endl;
            }
            continue;
        }

        // Convert to integer
        int selectedIndex = 0;
        for (size_t i = 0; i < input.length(); i++) {
            selectedIndex = selectedIndex * 10 + (input[i] - '0');
        }

        // Find the contact
        int foundIndex = -1;
        for (int i = 0; i < totalContacts; i++) {
            if (contacts[i].getDisplayIndex() == selectedIndex) {
                foundIndex = i;
                break;
            }
        }
        
        if (foundIndex == -1) {
            attempts++;
            if (attempts >= maxAttempts) {
                std::cout << "❌ Too many invalid attempts. Returning to main menu." << std::endl;
                return;
            }
            std::cout << "⚠️  Contact with index " << selectedIndex << " not found." << std::endl;
            if (attempts < 3) {
                std::cout << "   Please enter a valid index from the list above (1-" << totalContacts << ") or 0 to cancel." << std::endl;
            } else {
                std::cout << "💡 Tip: Look at the table above and choose one of the Index numbers shown." << std::endl;
            }
            continue;
        }
        
        // Display details with better formatting
        Contact &c = contacts[foundIndex];
        std::cout << std::endl << "=== Contact Details ===" << std::endl;
        std::cout << "First Name     : " << c.getFirstName() << std::endl;
        std::cout << "Last Name      : " << c.getLastName() << std::endl;
        std::cout << "Nickname       : " << c.getNickname() << std::endl;
        std::cout << "Phone Number   : " << c.getPhoneNumber() << std::endl;
        std::cout << "Darkest Secret : " << c.getDarkestSecret() << std::endl;
        std::cout << "======================" << std::endl << std::endl;
        return;
        
    } while (true);
}

#include "Contact.hpp"

// Constructor (optional, can initialize empty values)
Contact::Contact() {displayIndex = 0;}

// Setter Methods
void Contact::setFirstName(std::string name) { first_name = name; }
void Contact::setLastName(std::string name) { last_name = name; }
void Contact::setNickname(std::string name) { nickname = name; }
void Contact::setPhoneNumber(std::string number) { phone_number = number; }
void Contact::setDarkestSecret(std::string secret) { darkest_secret = secret; }

// Getter Methods
std::string Contact::getFirstName() { return first_name; }
std::string Contact::getLastName() { return last_name; }
std::string Contact::getNickname() { return nickname; }
std::string Contact::getPhoneNumber() { return phone_number; }
std::string Contact::getDarkestSecret() { return darkest_secret; }

void Contact::setDisplayIndex(int index) { displayIndex = index; }

int Contact::getDisplayIndex() { return displayIndex; }


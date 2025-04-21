#include "Weapon.hpp"

// Constructor
// Initializes the type of the weapon

Weapon::Weapon(std::string type) {
    this->type = type;
}

// Getter method
// Returns the type of the weapon
// This method is marked as const because it does not modify the object

const std::string& Weapon::getType() const {
    return this->type;
}

// Setter method
// Sets the type of the weapon
// This method allows changing the type of the weapon after it has been created

void Weapon::setType(std::string type) {
    this->type = type;
}
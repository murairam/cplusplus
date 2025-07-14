// HumanB.cpp

#include <iostream>
#include "HumanB.hpp"

/* What’s happening:
- weapon starts as nullptr (no weapon)
- setWeapon() sets the pointer
- attack() checks if there’s a weapon before using it


A pointer is used in `HumanB` because the weapon is optional and can be assigned or changed after the object is created.
*/

// Constructor
HumanB::HumanB(std::string name) : name(name), weapon(NULL) {}

// Setter
void HumanB::setWeapon(Weapon& weapon) {
    this->weapon = &weapon;
}

// attack() method
void HumanB::attack() const {
    if (this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " has no weapon to attack with!" << std::endl;
}

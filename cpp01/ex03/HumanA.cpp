// HumanA.cpp

#include <iostream>
#include "HumanA.hpp"

// Constructor
HumanA::HumanA(std::string name, Weapon& weapon) : name(name), weapon(weapon) {}

// attack() method
void HumanA::attack() const {
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}

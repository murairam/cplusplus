#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructed!" << std::endl;
    _hitPoints = 100;
    _energyPoints = 100;
    _attackDamage = 30; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " constructed!" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 100;
	_attackDamage = 30;
}

FragTrap::FragTrap(const FragTrap& other) : ClapTrap(other) {
	std::cout << "FragTrap copy constructed!" << std::endl;
}

FragTrap& FragTrap::operator=(const FragTrap& other) {
	ClapTrap::operator=(other); // Reuse base assignment
	std::cout << "FragTrap assigned!" << std::endl;
	return *this;
}

FragTrap::~FragTrap() {
	std::cout << "FragTrap " << this->name << " destructed!" << std::endl;
}


void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->name << " is now in Gate keeper mode!" << std::endl;
}

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap() {
    std::cout << "FragTrap default constructed!" << std::endl;
    this->_hitPoints = _defaultHitPoints;
    this->_energyPoints = _defaultEnergyPoints;
    this->_attackDamage = _defaultAttackDamage; 
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	std::cout << "FragTrap " << name << " constructed!" << std::endl;
	this->_hitPoints = _defaultHitPoints;
	this->_energyPoints = _defaultEnergyPoints;
	this->_attackDamage = _defaultAttackDamage;
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
	std::cout << "FragTrap " << this->_name << " destructed!" << std::endl;
}


void FragTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << "FragTrap " << _name << " is destroyed and can't attack!" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "FragTrap " << _name << " has no energy left to attack!" << std::endl;
		return;
	}
	std::cout << "FragTrap " << _name << " devastatingly attacks " << target
	          << ", dealing " << _attackDamage << " damage!" << std::endl;
	_energyPoints--;
}

void FragTrap::highFivesGuys() {
	std::cout << "FragTrap " << this->_name << " requests a high five! ✋" << std::endl;
}

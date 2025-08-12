#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructed!" << std::endl;
    this->_hitPoints = 100;
    this->_energyPoints = 50;
    this->_attackDamage = 20; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " constructed!" << std::endl;
	this->_hitPoints = 100;
	this->_energyPoints = 50;
	this->_attackDamage = 20;
}

ScavTrap::ScavTrap(const ScavTrap &other) : ClapTrap(other) {
	std::cout << "ScavTrap copy constructed!" << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &other) {
	ClapTrap::operator=(other); // Reuse base assignment
	std::cout << "ScavTrap assigned!" << std::endl;
	return *this;
}

ScavTrap::~ScavTrap() {
	std::cout << "ScavTrap " << _name << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << "ScavTrap " << _name << " is destroyed and can't attack!" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "ScavTrap " << _name << " has no energy left to attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << _name << " viciously attacks " << target
	          << ", dealing " << _attackDamage << " damage!" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate() {
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode!" << std::endl;
}

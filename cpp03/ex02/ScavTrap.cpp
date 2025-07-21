#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap() {
    std::cout << "ScavTrap default constructed!" << std::endl;
    _hitPoints = 100;
    _energyPoints = 50;
    _attackDamage = 20; 
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	std::cout << "ScavTrap " << name << " constructed!" << std::endl;
	_hitPoints = 100;
	_energyPoints = 50;
	_attackDamage = 20;
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
	std::cout << "ScavTrap " << name << " destructed!" << std::endl;
}

void ScavTrap::attack(const std::string& target) {
	if (_hitPoints <= 0) {
		std::cout << "ScavTrap " << name << " is destroyed and can't attack!" << std::endl;
		return;
	}
	if (_energyPoints <= 0) {
		std::cout << "ScavTrap " << name << " has no energy left to attack!" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << name << " viciously attacks " << target
	          << ", dealing " << _attackDamage << " damage!" << std::endl;
	_energyPoints--;
}

void ScavTrap::guardGate() {
	if (this-> _energyPoints <= 0 || this->_attackDamage <= 0)
	{
		std::cout << "ScavTrap " << this->name << " can't high five :(" << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << ": High five?" << std::endl;
	this->_energyPoints--;
}

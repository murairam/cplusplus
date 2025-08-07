#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
	: name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap " << this->name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap()
	: name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
	std::cout << "ClapTrap default constructed!" << std::endl;
}

ClapTrap::~ClapTrap() {
	std::cout << "ClapTrap " << this->name << " destructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
	: name(other.name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
	std::cout << "ClapTrap copy constructed!" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other)
{
	if (this != &other)
	{
		this->name = other.name;
		this->_hitPoints = other._hitPoints;
		this->_energyPoints = other._energyPoints;
		this->_attackDamage = other._attackDamage;
	}
	std::cout << "ClapTrap assigned!" << std::endl;
	return *this;
}

void    ClapTrap::attack(const std::string& target)
{
    if (_hitPoints <= 0){
        std::cout << "ClapTrap " << name << " is destroyed and cannot attack!" << std::endl;
        return;
    }
    if (_energyPoints <= 0){
        std::cout << "ClapTrap " << name << " has no energy left to attack!" << std::endl;
        return;
    }
    std::cout << "ClapTrap " << name << " attacks " << target << " -> " << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (_hitPoints <= 0) {
		std::cout << "ClapTrap " << name << " is already destroyed and can't take more damage!" << std::endl;
		return;
	}
    
    if (amount >= _hitPoints)
        _hitPoints = 0;
    else
        _hitPoints -= amount;
        
    std::cout << "ClapTrap " << name << " took " << amount << " damage. Remaining HP: " << _hitPoints << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
    if (_hitPoints <= 0){
        std::cout << "ClapTrap " << name << " is destroyed and cannot repair!" << std::endl;
        return;
    }
    if (_energyPoints <= 0){
        std::cout << "ClapTrap " << name << " has no energy left to repair!" << std::endl;
        return;
    }
    _energyPoints -= 1;
    _hitPoints += amount;
    std::cout << "ClapTrap " << name << " repairs itself, gaining " << amount << " HP (Total: " << _hitPoints << ")" << std::endl;
}



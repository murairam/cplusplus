#include "ClapTrap.hpp"

ClapTrap::ClapTrap()
    : _name("Unnamed"), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0)
{
    std::cout << "ClapTrap " << _name << " constructed!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout << "ClapTrap " << _name << " destructed!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& other)
    : _name(other._name), _hitPoints(other._hitPoints), _energyPoints(other._energyPoints), _attackDamage(other._attackDamage)
{
    std::cout << "ClapTrap copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& other) {
    if (this != &other) {
        this->_name = other._name;
        this->_hitPoints = other._hitPoints;
        this->_energyPoints = other._energyPoints;
        this->_attackDamage = other._attackDamage;
    }
    std::cout << "ClapTrap assignment operator called" << std::endl;
    return *this;
}

void ClapTrap::attack(const std::string& target) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is destroyed and cannot attack!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy left to attack!" << std::endl;
        return;
    }
    this->_energyPoints--;
    std::cout << "ClapTrap " << this->_name << " attacks " << target << " -> " << this->_attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is already destroyed and can't take more damage!" << std::endl;
        return;
    }
    if (amount >= this->_hitPoints)
        this->_hitPoints = 0;
    else
        this->_hitPoints -= amount;
        
    std::cout << "ClapTrap " << this->_name << " took " << amount << " damage. Remaining HP: " << this->_hitPoints << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    if (this->_hitPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " is destroyed and cannot repair!" << std::endl;
        return;
    }
    if (this->_energyPoints <= 0) {
        std::cout << "ClapTrap " << this->_name << " has no energy left to repair!" << std::endl;
        return;
    }
    this->_energyPoints--;
    this->_hitPoints += amount;
    std::cout << "ClapTrap " << this->_name << " repairs itself, gaining " << amount << " HP (Total: " << this->_hitPoints << ")" << std::endl;
}
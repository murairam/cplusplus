#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : ClapTrap("default_clap_name"), _name("default")
{
    std::cout << "DiamondTrap default constructed!" << std::endl;
    this->_hitPoints = 100;     // FragTrap's HP
    this->_energyPoints = 50;   // ScavTrap's energy
    this->_attackDamage = 30;   // FragTrap's attack
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), _name(name)
{
    std::cout << "DiamondTrap " << name << " constructed!" << std::endl;
    this->_hitPoints = 100;     // FragTrap's HP
    this->_energyPoints = 50;   // ScavTrap's energy
    this->_attackDamage = 30;   // FragTrap's attack
}

DiamondTrap::DiamondTrap(const DiamondTrap &other)
    : ClapTrap(other), ScavTrap(other), FragTrap(other), _name(other._name)
{
    std::cout << "DiamondTrap copy constructor called" << std::endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& other)
{
    if (this != &other)
    {
        ClapTrap::operator=(other);
        this->_name = other._name;
    }
    std::cout << "DiamondTrap assignment operator called" << std::endl;
    return *this;
}

DiamondTrap::~DiamondTrap()
{
    std::cout << "DiamondTrap " << this->_name << " destructed!" << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
    ScavTrap::attack(target);
}

void DiamondTrap::whoAmI()
{
    std::cout << "I am DiamondTrap " << this->_name 
              << " and my ClapTrap name is " << ClapTrap::_name << std::endl;
}
#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap{
    private:
		std::string name;
        int		_hitPoints ;
        int		_energyPoints;
        int 	_attackDamage;

	public:
		ClapTrap(); // default constructor
		ClapTrap(std::string name);
		ClapTrap(const ClapTrap& other); // copy constructor
		ClapTrap& operator=(const ClapTrap& other); // copy assignment
		~ClapTrap(); // destructor

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
};

#endif
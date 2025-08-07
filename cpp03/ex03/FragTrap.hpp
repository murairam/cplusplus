#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap : public virtual ClapTrap
{
    protected:
        static const unsigned int _defaultHitPoints = 100;
        static const unsigned int _defaultEnergyPoints = 100;
        static const unsigned int _defaultAttackDamage = 30;
        
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap& other);
        FragTrap& operator=(const FragTrap& other);
        ~FragTrap();

        void attack(const std::string& target);
        void highFivesGuys(void);
};

#endif

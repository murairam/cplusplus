// HumanA.hpp

#ifndef HUMANA_HPP
#define HUMANA_HPP

#include <string>
#include "Weapon.hpp"

class HumanA {
    private:
        std::string name;
        Weapon& weapon;  // always has a weapon (by reference)

    public:
        HumanA(std::string name, Weapon& weapon);  // constructor
        void attack() const;
};

#endif

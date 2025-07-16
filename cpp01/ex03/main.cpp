// main.cpp

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"
/* 
Key Differences:
**Reference vs Pointer**:
   - `HumanA` uses a reference to `Weapon`, meaning it must always have a weapon.
   - `HumanB` uses a pointer to `Weapon`, which can be set later and can be null.
   
Use a reference when you're sure the object is always present.
Use a pointer when the presence of the object is optional or it may change later. */

int main() {
    {
        Weapon club("crude spiked club");
        HumanA bob("Bob", club);

        bob.attack();
        club.setType("some other type of club");
        bob.attack();
    }

    std::cout << "------------------------" << std::endl;

    {
        Weapon club("crude spiked club");
        HumanB jim("Jim");
        HumanB jimWithoutWeapon("JimWithoutWeapon");


        jim.setWeapon(club);
        jim.attack();
        club.setType("some other type of club");
        jim.attack();
    }

    return 0;
}

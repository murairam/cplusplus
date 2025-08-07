#include <iostream>
#include "DiamondTrap.hpp"

int main()
{
    std::cout << "Creating DiamondTrap objects..." << std::endl;
    
    DiamondTrap dt1;
    DiamondTrap dt2("Warrior");
    
    std::cout << "\nTesting attack method (should use ScavTrap's attack):" << std::endl;
    dt2.attack("target");
    
    std::cout << "\nTesting whoAmI method:" << std::endl;
    dt2.whoAmI();
    
    std::cout << "\nTesting copy constructor:" << std::endl;
    DiamondTrap dt3(dt2);
    dt3.whoAmI();
    
    std::cout << "\nProgram ending..." << std::endl;
    return 0;
}

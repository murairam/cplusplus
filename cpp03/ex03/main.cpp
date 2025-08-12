#include "DiamondTrap.hpp"

int main() {
    std::cout << "=================================" << std::endl;
    std::cout << "CPP03 EX03: DIAMOND INHERITANCE" << std::endl;
    std::cout << "Learning: Virtual Inheritance, Diamond Problem, Multiple Inheritance" << std::endl;
    std::cout << "=================================" << std::endl;
    
    // Diamond inheritance demonstration
    std::cout << "\n--- Diamond Inheritance Pattern ---" << std::endl;
    std::cout << "DiamondTrap inherits from BOTH ScavTrap AND FragTrap" << std::endl;
    std::cout << "Both ScavTrap and FragTrap inherit from ClapTrap" << std::endl;
    std::cout << "Virtual inheritance ensures only ONE ClapTrap instance\n" << std::endl;
    
    // Constructor chain
    std::cout << "--- Constructor Chain ---" << std::endl;
    DiamondTrap diamond("Warrior");
    
    // Stats combination
    std::cout << "\n--- Mixed Stats ---" << std::endl;
    std::cout << "DiamondTrap combines best of both worlds:" << std::endl;
    std::cout << "HP: 100 (from FragTrap)" << std::endl;
    std::cout << "Energy: 50 (from ScavTrap)" << std::endl;
    std::cout << "Attack: 30 (from FragTrap)" << std::endl;
    
    // Method selection
    std::cout << "\n--- Method Selection ---" << std::endl;
    std::cout << "Uses ScavTrap's attack method:" << std::endl;
    diamond.attack("target");
    
    // Name management
    std::cout << "\n--- Name Management ---" << std::endl;
    std::cout << "DiamondTrap has TWO names:" << std::endl;
    diamond.whoAmI();
    
    // Inherited abilities from both parents
    std::cout << "\n--- Inherited Abilities ---" << std::endl;
    std::cout << "Can use abilities from both parent classes:" << std::endl;
    diamond.guardGate();        // From ScavTrap
    diamond.highFivesGuys();    // From FragTrap
    
    // Copy constructor test
    std::cout << "\n--- Copy Constructor Test ---" << std::endl;
    DiamondTrap diamond2(diamond);
    diamond2.whoAmI();
    
    // Demonstrate virtual inheritance works
    std::cout << "\n--- Virtual Inheritance Success ---" << std::endl;
    std::cout << "Only ONE ClapTrap was constructed (not two!)" << std::endl;
    std::cout << "This solves the Diamond Problem!" << std::endl;
    
    std::cout << "\n--- Program End ---" << std::endl;
    return 0;
}
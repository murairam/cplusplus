#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=================================" << std::endl;
    std::cout << "CPP03 EX02: MULTIPLE INHERITANCE" << std::endl;
    std::cout << "Learning: Multiple classes from same base, Polymorphism" << std::endl;
    std::cout << "=================================" << std::endl;
    
    // Multiple inheritance from same base
    std::cout << "\n--- Creating Multiple Derived Classes ---" << std::endl;
    ClapTrap base("BasicBot");
    ScavTrap scav("GuardBot");
    FragTrap frag("DestroyBot");
    
    // Stats comparison
    std::cout << "\n--- Stats Comparison ---" << std::endl;
    std::cout << "ClapTrap: 10 HP,  10 Energy,  0 Attack" << std::endl;
    std::cout << "ScavTrap: 100 HP, 50 Energy, 20 Attack" << std::endl;
    std::cout << "FragTrap: 100 HP, 100 Energy, 30 Attack\n" << std::endl;
    
    // Polymorphic behavior
    std::cout << "--- Polymorphic Behavior ---" << std::endl;
    std::cout << "Same method name, different implementations:" << std::endl;
    base.attack("enemy");        // ClapTrap version
    scav.attack("enemy");        // ScavTrap version
    frag.attack("enemy");        // FragTrap version
    
    // Shared inherited methods
    std::cout << "\n--- Shared Inherited Methods ---" << std::endl;
    std::cout << "All use same takeDamage and beRepaired from ClapTrap:" << std::endl;
    base.takeDamage(5);
    scav.takeDamage(25);
    frag.takeDamage(35);
    
    base.beRepaired(3);
    scav.beRepaired(10);
    frag.beRepaired(15);
    
    // Unique abilities
    std::cout << "\n--- Unique Class Abilities ---" << std::endl;
    scav.guardGate();           // ScavTrap special ability
    frag.highFivesGuys();       // FragTrap special ability
    // base.guardGate();        // ❌ ClapTrap doesn't have this!
    
    // Performance differences
    std::cout << "\n--- Performance Differences ---" << std::endl;
    std::cout << "Energy comparison:" << std::endl;
    std::cout << "ClapTrap can attack 10 times, FragTrap can attack 100 times!" << std::endl;
    
    std::cout << "\n--- Program End ---" << std::endl;
    return 0;
}
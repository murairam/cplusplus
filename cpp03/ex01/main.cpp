#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=================================" << std::endl;
    std::cout << "CPP03 EX01: INHERITANCE" << std::endl;
    std::cout << "Learning: Class Inheritance, Constructor Chains, Method Overriding" << std::endl;
    std::cout << "=================================" << std::endl;
    
    // Constructor chain demonstration
    std::cout << "\n--- Constructor Chain ---" << std::endl;
    std::cout << "Creating base class:" << std::endl;
    ClapTrap base("BasicBot");
    std::cout << "\nCreating derived class (watch chain):" << std::endl;
    ScavTrap derived("SuperBot");
    
    // Stats comparison
    std::cout << "\n--- Stats Comparison ---" << std::endl;
    std::cout << "ClapTrap: 10 HP, 10 Energy, 0 Attack" << std::endl;
    std::cout << "ScavTrap: 100 HP, 50 Energy, 20 Attack\n" << std::endl;
    
    // Method overriding demonstration
    std::cout << "--- Method Overriding ---" << std::endl;
    std::cout << "Same method name, different behavior:" << std::endl;
    base.attack("target");       // ClapTrap version
    derived.attack("target");    // ScavTrap version (overridden)
    
    // Inherited methods
    std::cout << "\n--- Inherited Methods ---" << std::endl;
    std::cout << "ScavTrap uses ClapTrap's takeDamage and beRepaired:" << std::endl;
    derived.takeDamage(30);
    derived.beRepaired(15);
    
    // Special abilities
    std::cout << "\n--- Special Abilities ---" << std::endl;
    std::cout << "ScavTrap has unique ability:" << std::endl;
    derived.guardGate();
    // base.guardGate(); // ❌ Would cause compilation error!
    
    // Destructor chain test
    std::cout << "\n--- Destructor Chain Test ---" << std::endl;
    {
        ScavTrap temp("TempBot");
        std::cout << "TempBot going out of scope..." << std::endl;
    } // Watch destructor chain: ScavTrap -> ClapTrap
    
    std::cout << "\n--- Program End (watch destruction order) ---" << std::endl;
    return 0;
}
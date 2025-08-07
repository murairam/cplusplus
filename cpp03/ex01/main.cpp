#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
    std::cout << "=== CPP03 EX01: INHERITANCE DEMONSTRATION ===" << std::endl;
    std::cout << "Purpose: Show how ScavTrap inherits from ClapTrap but has different stats and behavior\n" << std::endl;
    
    // ========== PART 1: CONSTRUCTOR INHERITANCE ==========
    std::cout << "--- PART 1: Constructor Chain (Base -> Derived) ---" << std::endl;
    ClapTrap base("BasicBot");
    std::cout << std::endl;
    ScavTrap derived("SuperBot");
    std::cout << std::endl;
    
    // ========== PART 2: STAT COMPARISON ==========
    std::cout << "--- PART 2: Stat Differences (Inheritance with different values) ---" << std::endl;
    std::cout << "ClapTrap stats: 10 HP, 10 Energy, 0 Attack" << std::endl;
    std::cout << "ScavTrap stats: 100 HP, 50 Energy, 20 Attack\n" << std::endl;
    
    base.attack("target");
    derived.attack("target");
    std::cout << "^ Notice: Same method name, different behavior (polymorphism)\n" << std::endl;
    
    // ========== PART 3: INHERITED METHODS ==========
    std::cout << "--- PART 3: Method Inheritance (ScavTrap uses ClapTrap's methods) ---" << std::endl;
    std::cout << "ScavTrap taking damage (uses inherited ClapTrap::takeDamage):" << std::endl;
    derived.takeDamage(30);
    
    std::cout << "ScavTrap repairing (uses inherited ClapTrap::beRepaired):" << std::endl;
    derived.beRepaired(15);
    std::cout << std::endl;
    
    // ========== PART 4: SPECIALIZED BEHAVIOR ==========
    std::cout << "--- PART 4: Specialized Behavior (ScavTrap-only features) ---" << std::endl;
    std::cout << "ScavTrap has special ability that ClapTrap doesn't have:" << std::endl;
    derived.guardGate();
    // base.guardGate(); // This would cause compilation error!
    std::cout << std::endl;
    
    // ========== PART 5: ENERGY/DAMAGE DIFFERENCES ==========
    std::cout << "--- PART 5: Resource Management Differences ---" << std::endl;
    std::cout << "ClapTrap (weak): Can only attack 10 times before running out of energy" << std::endl;
    std::cout << "ScavTrap (strong): Can attack 50 times + deals 20 damage per hit\n" << std::endl;
    
    std::cout << "Demonstrating ClapTrap energy limit:" << std::endl;
    for (int i = 0; i < 12; ++i) {
        base.attack("dummy");
        if (i == 9) std::cout << "^ Energy depleted after 10 attacks!" << std::endl;
    }
    std::cout << std::endl;
    
    // ========== PART 6: DESTRUCTOR CHAIN ==========
    std::cout << "--- PART 6: Destructor Chain (Derived -> Base) ---" << std::endl;
    std::cout << "When objects go out of scope, destructors are called in reverse order:" << std::endl;
    
    {
        ScavTrap temp("TempBot");
        std::cout << "TempBot created in local scope..." << std::endl;
    } // TempBot destroyed here
    
    std::cout << "\n=== KEY LEARNING POINTS DEMONSTRATED ===" << std::endl;
    std::cout << "1. Constructor chain: Base constructor called first" << std::endl;
    std::cout << "2. Method inheritance: ScavTrap uses ClapTrap's takeDamage/beRepaired" << std::endl;
    std::cout << "3. Method overriding: ScavTrap::attack() replaces ClapTrap::attack()" << std::endl;
    std::cout << "4. Specialized behavior: ScavTrap has guardGate(), ClapTrap doesn't" << std::endl;
    std::cout << "5. Different stats: Derived class can have enhanced capabilities" << std::endl;
    std::cout << "6. Destructor chain: Derived destructor called first, then base" << std::endl;
    
    std::cout << "\nProgram ending - watch destructor chain:" << std::endl;
    return 0;
}

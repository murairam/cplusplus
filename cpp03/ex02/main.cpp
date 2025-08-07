#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main() {
    std::cout << "=== CPP03 EX02: MULTIPLE INHERITANCE DEMONSTRATION ===" << std::endl;
    std::cout << "Purpose: Show multiple classes inheriting from same base with different capabilities\n" << std::endl;
    
    // ========== PART 1: CONSTRUCTOR INHERITANCE CHAIN ==========
    std::cout << "--- PART 1: Multiple Inheritance from Same Base ---" << std::endl;
    std::cout << "Creating all three types - watch constructor chains:\n" << std::endl;
    
    ClapTrap base("BasicBot");
    std::cout << std::endl;
    ScavTrap scav("GuardBot");
    std::cout << std::endl;
    FragTrap frag("DestroyBot");
    std::cout << std::endl;
    
    // ========== PART 2: STAT COMPARISON ==========
    std::cout << "--- PART 2: Different Stats from Same Base Class ---" << std::endl;
    std::cout << "ClapTrap: 10 HP,  10 Energy,  0 Attack" << std::endl;
    std::cout << "ScavTrap: 100 HP, 50 Energy, 20 Attack" << std::endl;
    std::cout << "FragTrap: 100 HP, 100 Energy, 30 Attack" << std::endl;
    std::cout << std::endl;
    
    // ========== PART 3: POLYMORPHIC BEHAVIOR ==========
    std::cout << "--- PART 3: Same Method, Different Behavior (Polymorphism) ---" << std::endl;
    base.attack("enemy");
    scav.attack("enemy");
    frag.attack("enemy");
    std::cout << "^ Notice: Same method name, different implementations\n" << std::endl;
    
    // ========== PART 4: SHARED INHERITED METHODS ==========
    std::cout << "--- PART 4: Shared Inherited Methods (Code Reuse) ---" << std::endl;
    std::cout << "All use the same inherited takeDamage() and beRepaired() from ClapTrap:" << std::endl;
    base.takeDamage(5);
    scav.takeDamage(25);
    frag.takeDamage(35);
    std::cout << std::endl;
    
    base.beRepaired(3);
    scav.beRepaired(10);
    frag.beRepaired(15);
    std::cout << std::endl;
    
    // ========== PART 5: UNIQUE SPECIALIZED ABILITIES ==========
    std::cout << "--- PART 5: Class-Specific Special Abilities ---" << std::endl;
    std::cout << "Each derived class has unique functionality:" << std::endl;
    scav.guardGate();
    frag.highFivesGuys();
    // base.guardGate(); // Would cause compilation error - base doesn't have this!
    std::cout << std::endl;
    
    // ========== PART 6: ENERGY/CAPABILITY DIFFERENCES ==========
    std::cout << "--- PART 6: Different Capabilities in Action ---" << std::endl;
    std::cout << "Demonstrating energy differences (ClapTrap weak, FragTrap strong):" << std::endl;
    
    std::cout << "\nClapTrap (10 energy) - depletes quickly:" << std::endl;
    for (int i = 0; i < 12; ++i) {
        base.attack("target");
        if (i == 9) {
            std::cout << "^ ClapTrap exhausted after 10 attacks!" << std::endl;
            break;
        }
    }
    
    std::cout << "\nFragTrap (100 energy) - much more endurance:" << std::endl;
    for (int i = 0; i < 5; ++i) {
        frag.attack("target");
    }
    std::cout << "^ FragTrap still has 95 energy remaining!\n" << std::endl;
    
    // ========== PART 7: DESTRUCTOR CHAIN ==========
    std::cout << "--- PART 7: Destructor Chain (Reverse Order) ---" << std::endl;
    std::cout << "When program ends, destructors called in reverse inheritance order:" << std::endl;
    
    {
        FragTrap temp("TempFrag");
        std::cout << "TempFrag going out of scope..." << std::endl;
    } // Destructor chain: FragTrap -> ClapTrap
    
    std::cout << "\n=== KEY LEARNING POINTS DEMONSTRATED ===" << std::endl;
    std::cout << "1. Multiple classes can inherit from the same base class" << std::endl;
    std::cout << "2. Each derived class can have different stats while sharing structure" << std::endl;
    std::cout << "3. Method overriding allows specialized behavior per class" << std::endl;
    std::cout << "4. Code reuse: All classes share takeDamage/beRepaired implementation" << std::endl;
    std::cout << "5. Extensibility: Each class can add unique features (guardGate vs highFive)" << std::endl;
    std::cout << "6. Polymorphism: Same interface, different implementations" << std::endl;
    std::cout << "7. This prepares for more complex inheritance patterns in ex03" << std::endl;
    
    std::cout << "\nProgram ending - watch multiple destructor chains:" << std::endl;
    return 0;
}

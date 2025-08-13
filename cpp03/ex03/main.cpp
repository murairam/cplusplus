#include "DiamondTrap.hpp"
#include "DiamondTrap.hpp"

int main() {
    // Colors for better readability
    const std::string BOLD = "\033[1m";
    const std::string RESET = "\033[0m";
    const std::string CYAN = "\033[36m";
    const std::string GREEN = "\033[32m";
    const std::string YELLOW = "\033[33m";
    const std::string RED = "\033[31m";
    const std::string BLUE = "\033[34m";
    const std::string PURPLE = "\033[35m";

    std::cout << CYAN << BOLD << "=========================================" << RESET << std::endl;
    std::cout << CYAN << BOLD << "DIAMONDTRAP VERIFICATION TEST" << RESET << std::endl;
    std::cout << BLUE << "Proving which methods and values are used" << RESET << std::endl;
    std::cout << CYAN << BOLD << "=========================================" << RESET << std::endl;

    // Create DiamondTrap
    std::cout << "\n" << YELLOW << BOLD << "--- Creating DiamondTrap ---" << RESET << std::endl;
    DiamondTrap diamond("TestBot");
    
    // Test 1: Verify Stats Combination
    std::cout << "\n" << YELLOW << BOLD << "--- TEST 1: Stats Verification ---" << RESET << std::endl;
    std::cout << BLUE << "Expected stats according to subject:" << RESET << std::endl;
    std::cout << GREEN << "HP: 100 (from FragTrap)" << RESET << std::endl;
    std::cout << GREEN << "Energy: 50 (from ScavTrap)" << RESET << std::endl;
    std::cout << GREEN << "Attack: 30 (from FragTrap)" << RESET << std::endl;
    
    // Test 2: Attack Method - Should use ScavTrap's attack
    std::cout << "\n" << YELLOW << BOLD << "--- TEST 2: Attack Method ---" << RESET << std::endl;
    std::cout << BLUE << "Should use ScavTrap's attack (says 'viciously attacks')" << RESET << std::endl;
    diamond.attack("training dummy");
    std::cout << GREEN << "✓ If you see 'viciously attacks' = ScavTrap's method used!" << RESET << std::endl;
    
    // Test 3: Damage Testing - Verify HP decreases correctly
    std::cout << "\n" << YELLOW << BOLD << "--- TEST 3: Damage Testing ---" << RESET << std::endl;
    std::cout << BLUE << "Taking 20 damage - should go from 100 HP to 80 HP" << RESET << std::endl;
    diamond.takeDamage(20);
    std::cout << GREEN << "✓ If it shows '80 HP remaining' = FragTrap's 100 HP was used!" << RESET << std::endl;
    
    // Test 4: Energy Depletion Test
    std::cout << "\n" << YELLOW << BOLD << "--- TEST 4: Energy Depletion Test ---" << RESET << std::endl;
    std::cout << BLUE << "Attack 50 times to test ScavTrap's 50 energy limit:" << RESET << std::endl;
    
    int attacks = 0;
    while (attacks < 52) {  // Try to attack more than 50 times
        attacks++;
        std::cout << "Attack " << attacks << ": ";
        diamond.attack("dummy");
        
        if (attacks == 49) {
            std::cout << YELLOW << "⚠️  Should have 1 energy left..." << RESET << std::endl;
        }
        if (attacks == 50) {
            std::cout << RED << "⚠️  Should be out of energy after this!" << RESET << std::endl;
        }
        if (attacks == 51) {
            std::cout << GREEN << "✓ If you see 'no energy left' = ScavTrap's 50 energy was used!" << RESET << std::endl;
            break;
        }
    }
    
    // Test 5: Name Management
    std::cout << "\n" << YELLOW << BOLD << "--- TEST 5: Name Management ---" << RESET << std::endl;
    std::cout << BLUE << "Testing dual name system:" << RESET << std::endl;
    diamond.whoAmI();
    std::cout << GREEN << "✓ Should show 'TestBot' and 'TestBot_clap_name'" << RESET << std::endl;
    
    // Test 6: Parent Methods Access
    std::cout << "\n" << YELLOW << BOLD << "--- TEST 6: Parent Methods Access ---" << RESET << std::endl;
    std::cout << BLUE << "Testing access to both parent special methods:" << RESET << std::endl;
    diamond.guardGate();      // From ScavTrap
    diamond.highFivesGuys();  // From FragTrap
    std::cout << GREEN << "✓ Can access both parent special methods!" << RESET << std::endl;
    
    // Test 7: Virtual Inheritance Proof
    std::cout << "\n" << YELLOW << BOLD << "--- TEST 7: Virtual Inheritance Proof ---" << RESET << std::endl;
    std::cout << BLUE << "Constructor count test:" << RESET << std::endl;
    std::cout << PURPLE << "Count how many 'ClapTrap constructed' messages you saw:" << RESET << std::endl;
    std::cout << GREEN << "✓ Should be only 1 (not 2) = Virtual inheritance working!" << RESET << std::endl;
    
    // Test 8: Comparison with Individual Classes
    std::cout << "\n" << YELLOW << BOLD << "--- TEST 8: Comparison Test ---" << RESET << std::endl;
    std::cout << BLUE << "Creating individual classes for comparison:" << RESET << std::endl;
    
    FragTrap frag("FragBot");
    ScavTrap scav("ScavBot");
    
    std::cout << "\n" << PURPLE << "Attack message comparison:" << RESET << std::endl;
    std::cout << "FragTrap: ";
    frag.attack("target");
    std::cout << "ScavTrap: ";
    scav.attack("target");
    std::cout << "DiamondTrap: ";
    DiamondTrap diamond2("CompareBot");
    diamond2.attack("target");
    
    std::cout << GREEN << "\n✓ DiamondTrap should match ScavTrap's message!" << RESET << std::endl;
    
    std::cout << "\n" << CYAN << BOLD << "=========================================" << RESET << std::endl;
    std::cout << CYAN << BOLD << "VERIFICATION COMPLETE!" << RESET << std::endl;
    std::cout << BLUE << "Check the output above to confirm:" << RESET << std::endl;
    std::cout << GREEN << "1. HP starts at 100 (FragTrap)" << RESET << std::endl;
    std::cout << GREEN << "2. Energy limited to 50 (ScavTrap)" << RESET << std::endl;
    std::cout << GREEN << "3. Attack uses 'viciously' (ScavTrap)" << RESET << std::endl;
    std::cout << GREEN << "4. Only 1 ClapTrap constructed (Virtual inheritance)" << RESET << std::endl;
    std::cout << GREEN << "5. Both parent methods accessible" << RESET << std::endl;
    std::cout << CYAN << BOLD << "=========================================" << RESET << std::endl;
    
    return 0;
}
/* 
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
} */
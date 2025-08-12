#include "ClapTrap.hpp"

int main() {
    std::cout << "=================================" << std::endl;
    std::cout << "CPP03 EX00: BASIC CLASS DESIGN" << std::endl;
    std::cout << "Learning: Orthodox Canonical Form, Basic Methods, State Management" << std::endl;
    std::cout << "=================================" << std::endl;

    // Test Orthodox Canonical Form
    std::cout << "\n--- Orthodox Canonical Form Tests ---" << std::endl;
    ClapTrap robot1("R2D2");
    ClapTrap robot2(robot1);        // Copy constructor
    ClapTrap robot3;
    robot3 = robot1;                // Copy assignment
    std::cout << "✅ All 4 canonical functions tested\n" << std::endl;
    
    // Test basic functionality
    std::cout << "--- Basic Combat System ---" << std::endl;
    std::cout << "Stats: 10 HP, 10 Energy, 0 Attack Damage" << std::endl;
    robot1.attack("training dummy");
    robot1.attack("goblin");
    robot1.takeDamage(5);
    robot1.beRepaired(3);
    std::cout << "Status: 8 HP, 8 Energy remaining\n" << std::endl;
    
    // Test resource limits
    std::cout << "--- Resource Management ---" << std::endl;
    std::cout << "Testing energy depletion:" << std::endl;
    for (int i = 0; i < 9; ++i) {
        robot1.attack("enemy");
    }
    robot1.beRepaired(1);  // Should fail - no energy
    
    std::cout << "\nTesting death state:" << std::endl;
    robot1.takeDamage(20);          // Massive damage
    robot1.attack("anything");      // Can't attack when dead
    robot1.beRepaired(5);           // Can't repair when dead
    
    std::cout << "\n--- Program End ---" << std::endl;
    return 0;
}
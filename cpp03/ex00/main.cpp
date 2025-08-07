#include "ClapTrap.hpp"

int main() {
    std::cout << "=== ClapTrap Testing (No Direct Interaction) ===" << std::endl;
    
    // Create a single ClapTrap
    ClapTrap robot("R2D2");
    
    std::cout << "\n--- Basic Combat Against External Enemies ---" << std::endl;
    robot.attack("training dummy");
    robot.attack("wild goblin");
    robot.attack("practice target");
    
    std::cout << "\n--- Taking Environmental Damage ---" << std::endl;
    robot.takeDamage(3);  // Damage from trap or environment
    robot.takeDamage(2);  // Damage from falling rocks
    
    std::cout << "\n--- Self Repair ---" << std::endl;
    robot.beRepaired(4);  // Repair at repair station
    robot.beRepaired(1);  // Minor self-repair
    
    std::cout << "\n--- Energy Depletion Test ---" << std::endl;
    // Exhaust remaining energy (started with 10, used 5 so far)
    for (int i = 0; i < 6; ++i) {
        robot.attack("practice dummy");
    }
    robot.beRepaired(1);  // Should fail - no energy
    
    std::cout << "\n--- Destruction Test ---" << std::endl;
    robot.takeDamage(20); // Massive environmental damage
    robot.attack("anything");   // Should fail - destroyed
    robot.beRepaired(5);        // Should fail - destroyed
    
    std::cout << "\n--- Testing Different ClapTrap (Independent) ---" << std::endl;
    ClapTrap robot2("Wall-E");
    robot2.attack("scrap metal");
    robot2.takeDamage(1);
    robot2.beRepaired(2);
    
    return 0;
}

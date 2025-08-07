#include "Zombie.hpp"
#include <iostream>

Zombie* zombieHorde(int N, std::string name);

int main() {
    std::cout << "=== CPP01 EX01 COMPREHENSIVE TESTS ===" << std::endl;
    
    // Test 1: Normal horde
    std::cout << "\n--- Test 1: Normal Horde (5 zombies) ---" << std::endl;
    Zombie* horde1 = zombieHorde(5, "Walker");
    for (int i = 0; i < 5; i++) {
        horde1[i].announce();
    }
    delete[] horde1;
    
    // Test 2: Single zombie horde
    std::cout << "\n--- Test 2: Single Zombie Horde ---" << std::endl;
    Zombie* horde2 = zombieHorde(1, "Lone");
    horde2[0].announce();
    delete[] horde2;
    
    // Test 3: Zero zombies (edge case)
    std::cout << "\n--- Test 3: Edge Case - Zero Zombies ---" << std::endl;
    Zombie* horde3 = zombieHorde(0, "None");
    if (horde3 == NULL) {
        std::cout << "Correctly returned NULL for zero zombies" << std::endl;
    } else {
        std::cout << "Error: Should return NULL for zero zombies" << std::endl;
        delete[] horde3;
    }
    
    // Test 4: Negative number (edge case)
    std::cout << "\n--- Test 4: Edge Case - Negative Number ---" << std::endl;
    Zombie* horde4 = zombieHorde(-5, "Negative");
    if (horde4 == NULL) {
        std::cout << "Correctly handled negative number" << std::endl;
    } else {
        std::cout << "Error: Should handle negative numbers gracefully" << std::endl;
        delete[] horde4;
    }
    
    // Test 5: Empty name
    std::cout << "\n--- Test 5: Edge Case - Empty Name ---" << std::endl;
    Zombie* horde5 = zombieHorde(3, "");
    for (int i = 0; i < 3; i++) {
        horde5[i].announce();
    }
    delete[] horde5;
    
    // Test 6: Large horde
    std::cout << "\n--- Test 6: Large Horde (10 zombies) ---" << std::endl;
    Zombie* horde6 = zombieHorde(10, "Legion");
    for (int i = 0; i < 10; i++) {
        std::cout << "Zombie " << i+1 << ": ";
        horde6[i].announce();
    }
    delete[] horde6;
    
    // Test 7: Special characters in name
    std::cout << "\n--- Test 7: Special Characters ---" << std::endl;
    Zombie* horde7 = zombieHorde(3, "Zombie@123");
    for (int i = 0; i < 3; i++) {
        horde7[i].announce();
    }
    delete[] horde7;
    
    // Test 8: Memory leak test (create and destroy multiple hordes)
    std::cout << "\n--- Test 8: Memory Management Test ---" << std::endl;
    for (int i = 0; i < 5; i++) {
        std::cout << "Creating horde " << i+1 << std::endl;
        Zombie* temp_horde = zombieHorde(3, "TempZombie");
        temp_horde[0].announce(); // Just announce first one
        delete[] temp_horde;
        std::cout << "Horde " << i+1 << " destroyed" << std::endl;
    }
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}

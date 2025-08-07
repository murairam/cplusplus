#include "Zombie.hpp"
#include <iostream>

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {
    std::cout << "=== CPP01 EX00 COMPREHENSIVE TESTS ===" << std::endl;
    
    // Test 1: Basic heap zombie
    std::cout << "\n--- Test 1: Heap Zombie Creation/Deletion ---" << std::endl;
    Zombie* heapZombie = newZombie("HeapWalker");
    heapZombie->announce();
    delete heapZombie;
    
    // Test 2: Multiple heap zombies
    std::cout << "\n--- Test 2: Multiple Heap Zombies ---" << std::endl;
    Zombie* zombie1 = newZombie("Zombie1");
    Zombie* zombie2 = newZombie("Zombie2");
    zombie1->announce();
    zombie2->announce();
    delete zombie1;
    delete zombie2;
    
    // Test 3: Stack zombies (automatic destruction)
    std::cout << "\n--- Test 3: Stack Zombies (Auto-destruction) ---" << std::endl;
    randomChump("StackWalker1");
    randomChump("StackWalker2");
    
    // Test 4: Edge cases - empty name
    std::cout << "\n--- Test 4: Edge Case - Empty Name ---" << std::endl;
    Zombie* emptyNameZombie = newZombie("");
    emptyNameZombie->announce();
    delete emptyNameZombie;
    randomChump("");
    
    // Test 5: Edge cases - special characters
    std::cout << "\n--- Test 5: Edge Case - Special Characters ---" << std::endl;
    Zombie* specialZombie = newZombie("Zombie@123!#$");
    specialZombie->announce();
    delete specialZombie;
    randomChump("Stack~Zombie%^&*");
    
    // Test 6: Long names
    std::cout << "\n--- Test 6: Edge Case - Long Names ---" << std::endl;
    std::string longName = "ThisIsAVeryLongZombieNameThatTestsStringHandling";
    Zombie* longNameZombie = newZombie(longName);
    longNameZombie->announce();
    delete longNameZombie;
    randomChump("AnotherVeryLongStackZombieNameForTesting");
    
    // Test 7: Demonstrate scope differences
    std::cout << "\n--- Test 7: Scope Demonstration ---" << std::endl;
    std::cout << "Creating heap zombie (survives beyond this scope)" << std::endl;
    Zombie* persistentZombie = newZombie("Persistent");
    {
        std::cout << "Inside inner scope - creating stack zombie" << std::endl;
        randomChump("TemporaryScope");
        std::cout << "Stack zombie destroyed when leaving scope" << std::endl;
    }
    std::cout << "Back in outer scope - heap zombie still exists" << std::endl;
    persistentZombie->announce();
    delete persistentZombie;
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}

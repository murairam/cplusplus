#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include <iostream>

int main() {
    std::cout << "=== CHARACTER CLASS TESTING ===" << std::endl;
    
    // Test 1: Basic creation and getName
    std::cout << "\n--- Test 1: Basic Creation ---" << std::endl;
    Character* alice = new Character("Alice");
    std::cout << "Character name: " << alice->getName() << std::endl;
    
    // Test 2: Equipping materias
    std::cout << "\n--- Test 2: Equipping Materias ---" << std::endl;
    AMateria* ice1 = new Ice();
    AMateria* cure1 = new Cure();
    AMateria* ice2 = new Ice();
    AMateria* cure2 = new Cure();
    
    alice->equip(ice1);
    alice->equip(cure1);
    alice->equip(ice2);
    alice->equip(cure2);
    
    // Test 3: Try to equip to full inventory
    std::cout << "\n--- Test 3: Full Inventory ---" << std::endl;
    AMateria* extra = new Ice();
    alice->equip(extra);  // Should do nothing
    std::cout << "Tried to equip to full inventory" << std::endl;
    delete extra;  // We need to clean this up since Character didn't take it
    
    // Test 4: Using materias
    std::cout << "\n--- Test 4: Using Materias ---" << std::endl;
    Character* bob = new Character("Bob");
    
    alice->use(0, *bob);  // Should use ice
    alice->use(1, *bob);  // Should use cure
    alice->use(2, *bob);  // Should use ice
    alice->use(3, *bob);  // Should use cure
    
    // Test 5: Invalid use cases
    std::cout << "\n--- Test 5: Invalid Use Cases ---" << std::endl;
    alice->use(4, *bob);   // Invalid index - should do nothing
    alice->use(-1, *bob);  // Invalid index - should do nothing
    
    // Test 6: Unequip
    std::cout << "\n--- Test 6: Unequip ---" << std::endl;
    alice->unequip(0);     // Remove ice from slot 0
    alice->use(0, *bob);   // Should do nothing (slot now empty)
    alice->use(1, *bob);   // Should still work (cure in slot 1)
    
    // Test 7: Copy constructor
    std::cout << "\n--- Test 7: Copy Constructor ---" << std::endl;
    Character alice_copy = *alice;  // Copy constructor
    std::cout << "Copy name: " << alice_copy.getName() << std::endl;
    alice_copy.use(1, *bob);  // Should use cure (copied from alice)
    
    // Test 8: Assignment operator
    std::cout << "\n--- Test 8: Assignment Operator ---" << std::endl;
    Character charlie("Charlie");
    charlie.equip(new Ice());
    std::cout << "Charlie before assignment: " << charlie.getName() << std::endl;
    
    charlie = *alice;  // Assignment operator
    std::cout << "Charlie after assignment: " << charlie.getName() << std::endl;
    charlie.use(1, *bob);  // Should use cure (copied from alice)
    
    // Test 9: Self-assignment
    std::cout << "\n--- Test 9: Self-Assignment ---" << std::endl;
    Character& charlie_ref = charlie;
    charlie = charlie_ref;  // Should not crash
    std::cout << "Self-assignment completed safely" << std::endl;
    
    // Test 10: NULL materia equip
    std::cout << "\n--- Test 10: NULL Materia ---" << std::endl;
    alice->equip(NULL);  // Should do nothing
    std::cout << "Tried to equip NULL materia" << std::endl;
    
    // Cleanup
    std::cout << "\n--- Cleanup ---" << std::endl;
    delete alice;
    delete bob;
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}
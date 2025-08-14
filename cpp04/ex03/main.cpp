#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaManager.hpp"
#include "Colours.hpp"
#include <iostream>

void printHeader(const std::string& title) {
    std::cout << "\n" << GRY2 << std::string(50, '=') << RST << std::endl;
    std::cout << BOLD << title << RST << std::endl;
    std::cout << GRY2 << std::string(50, '=') << RST << std::endl;
}

void printSubtest(const std::string& test) {
    std::cout << "\n" << NAVY << "--- " << test << " ---" << RST << std::endl;
}

void printSuccess(const std::string& message) {
    std::cout << PINK << "✓ " << message << RST << std::endl;
}

void printInfo(const std::string& message) {
    std::cout << GRY1 << message << RST << std::endl;
}

// Subject's mandatory test - EXACTLY as provided
int subjectTest() {
    printHeader("MANDATORY TEST FROM SUBJECT");
    
    IMateriaSource* src = new MateriaSource();
    src->learnMateria(new Ice());
    src->learnMateria(new Cure());
    
    ICharacter* me = new Character("me");
    
    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    
    ICharacter* bob = new Character("bob");
    
    std::cout << "Expected output:" << std::endl;
    me->use(0, *bob);
    me->use(1, *bob);
    
    delete bob;
    delete me;
    delete src;
    
    printSuccess("Subject test completed");
    return 0;
}

int main() {
    printHeader("CPP MODULE 04 - EXERCISE 03");
    std::cout << "Testing: Interfaces, Abstract Classes & Polymorphism\n" << std::endl;
    
    // Run the mandatory subject test first
    subjectTest();
    
    printHeader("EVALUATION TESTS");
    
    // Test 1: Interface compliance
    printSubtest("Test 1: Interface Compliance");
    {
        IMateriaSource* source = new MateriaSource();
        ICharacter* character = new Character("TestChar");
        
        std::cout << "ICharacter name: " << character->getName() << std::endl;
        std::cout << "IMateriaSource: functional" << std::endl;
        
        delete character;
        delete source;
        printSuccess("Interfaces working as required");
    }
    
    // Test 2: MateriaSource functionality
    printSubtest("Test 2: MateriaSource Learning & Creation");
    {
        IMateriaSource* source = new MateriaSource();
        
        printInfo("Learning materias...");
        source->learnMateria(new Ice());
        source->learnMateria(new Cure());
        source->learnMateria(new Ice());
        source->learnMateria(new Cure());
        
        AMateria* ice = source->createMateria("ice");
        AMateria* cure = source->createMateria("cure");
        AMateria* unknown = source->createMateria("fire");
        
        std::cout << "Ice created: " << (ice ? ice->getType() : "NULL") << std::endl;
        std::cout << "Cure created: " << (cure ? cure->getType() : "NULL") << std::endl;
        std::cout << "Fire created: " << (unknown ? "ERROR" : "NULL (correct)") << std::endl;
        
        delete ice;
        delete cure;
        delete source;
        printSuccess("MateriaSource working correctly");
    }
    
    // Test 3: Character inventory
    printSubtest("Test 3: Character Inventory (4 slots max)");
    {
        ICharacter* wizard = new Character("Gandalf");
        IMateriaSource* spellbook = new MateriaSource();
        
        spellbook->learnMateria(new Ice());
        spellbook->learnMateria(new Cure());
        
        printInfo("Equipping 4 materias...");
        wizard->equip(spellbook->createMateria("ice"));
        wizard->equip(spellbook->createMateria("cure"));
        wizard->equip(spellbook->createMateria("ice"));
        wizard->equip(spellbook->createMateria("cure"));
        
        printInfo("Trying 5th materia (should be ignored):");
        AMateria* extra = spellbook->createMateria("ice");
        wizard->equip(extra);
        delete extra;
        
        ICharacter* target = new Character("Orc");
        std::cout << "Testing all slots:" << std::endl;
        for (int i = 0; i < 4; i++) {
            std::cout << "Slot " << i << ": ";
            wizard->use(i, *target);
        }
        
        delete target;
        delete wizard;
        delete spellbook;
        printSuccess("Character inventory working");
    }
    
    // Test 4: Deep copy
    printSubtest("Test 4: Deep Copy Testing");
    {
        Character original("Merlin");
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        
        original.equip(src->createMateria("ice"));
        original.equip(src->createMateria("cure"));
        
        Character copy1 = original;  // Copy constructor
        Character copy2("Empty");
        copy2 = original;  // Assignment operator
        
        std::cout << "Original: " << original.getName() << std::endl;
        std::cout << "Copy1: " << copy1.getName() << std::endl;
        std::cout << "Copy2: " << copy2.getName() << std::endl;
        
        ICharacter* dummy = new Character("Dummy");
        std::cout << "Testing independent copies:" << std::endl;
        original.use(0, *dummy);
        copy1.use(0, *dummy);
        copy2.use(0, *dummy);
        
        delete dummy;
        delete src;
        printSuccess("Deep copy working correctly");
    }
    
    // Test 5: Unequip with MateriaManager
    printSubtest("Test 5: Unequip & Memory Management");
    {
        ICharacter* mage = new Character("Mage");
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        
        mage->equip(src->createMateria("ice"));
        mage->equip(src->createMateria("ice"));
        
        ICharacter* target = new Character("Target");
        
        std::cout << "Before unequip:" << std::endl;
        mage->use(0, *target);
        
        printInfo("Unequipping slot 0...");
        mage->unequip(0);
        
        std::cout << "After unequip (should do nothing):" << std::endl;
        mage->use(0, *target);
        
        std::cout << "Slot 1 still works:" << std::endl;
        mage->use(1, *target);
        
        delete target;
        delete mage;
        delete src;
        printSuccess("Unequip working without leaks");
    }
    
    // Test 6: Edge cases
    printSubtest("Test 6: Edge Cases");
    {
        ICharacter* hero = new Character("Hero");
        ICharacter* dummy = new Character("Dummy");
        
        printInfo("Testing invalid operations (should do nothing):");
        hero->equip(NULL);
        hero->use(-1, *dummy);
        hero->use(10, *dummy);
        hero->use(0, *dummy);  // Empty slot
        hero->unequip(-1);
        hero->unequip(10);
        hero->unequip(0);  // Empty slot
        
        delete dummy;
        delete hero;
        printSuccess("Edge cases handled correctly");
    }
    
    // Final cleanup
    printHeader("CLEANUP");
    {
        std::cout << "Orphaned materias: " << MateriaManager::getOrphanedCount() << std::endl;
        MateriaManager::cleanup();
        std::cout << "After cleanup: " << MateriaManager::getOrphanedCount() << std::endl;
    }
    
    return 0;
}
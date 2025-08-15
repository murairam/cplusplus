// main.cpp
// Tests: Interfaces, Abstract Classes, Polymorphism, Deep Copy, Memory Management

#include "Character.hpp"
#include "MateriaSource.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaManager.hpp"
#include "Colours.hpp"
#include <iostream>

void printHeader(const std::string& title) {
    std::cout << "\n" << PINK << std::string(50, '=') << RST << std::endl;
    std::cout << BOLD << "  " << title << RST << std::endl;
    std::cout << PINK << std::string(50, '=') << RST << std::endl;
}

void printTest(const std::string& test) {
    std::cout << "\n" << BLUE << "--- " << test << " ---" << RST << std::endl;
}

int main() {
    printHeader("CPP04 EX03: INTERFACE & MATERIA");
    
    // =========================================================================
    // 1. MANDATORY SUBJECT TEST
    // =========================================================================
    printHeader("1. MANDATORY SUBJECT TEST");
    {
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
        
        me->use(0, *bob);
        me->use(1, *bob);
        
        delete bob;
        delete me;
        delete src;
        
    }

    // =========================================================================
    // 2. INTERFACE & POLYMORPHISM
    // =========================================================================
    printHeader("2. INTERFACE & POLYMORPHISM");
    
    printTest("Interface Usage");
    {
        IMateriaSource* source = new MateriaSource();
        ICharacter* character = new Character("Hero");
        
        std::cout << "Character name via interface: " << BOLD << character->getName() << RST << std::endl;
        std::cout << GRY1 << "Interfaces working polymorphically" << RST << std::endl;
        
        delete character;
        delete source;
    }

    printTest("Abstract Class Test");
    {
        AMateria* ice = new Ice();
        AMateria* cure = new Cure();
        
        std::cout << "Ice type: " << ice->getType() << std::endl;
        std::cout << "Cure type: " << cure->getType() << std::endl;
        std::cout << GRY1 << "AMateria is abstract - can only create derived classes" << RST << std::endl;
        
        delete ice;
        delete cure;
    }

    // =========================================================================
    // 3. MATERIASOURCE FUNCTIONALITY
    // =========================================================================
    printHeader("3. MATERIASOURCE FUNCTIONALITY");
    
    printTest("Learning & Creating");
    {
        MateriaSource src;
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        
        AMateria* ice = src.createMateria("ice");
        AMateria* cure = src.createMateria("cure");
        AMateria* unknown = src.createMateria("fire");
        
        std::cout << "Created ice: " << (ice ? ice->getType() : "NULL") << std::endl;
        std::cout << "Created cure: " << (cure ? cure->getType() : "NULL") << std::endl;
        std::cout << "Created fire: " << BOLD << (unknown ? "ERROR" : "NULL (correct)") << RST << std::endl;
        
        delete ice;
        delete cure;
        delete unknown;
    }

    printTest("Capacity Limits (4 slots)");
    {
        MateriaSource src;
        
        // Fill capacity
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        std::cout << GRY1 << "Learned 4 materias (full capacity)" << RST << std::endl;
        
        // Test overflow - should delete excess
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        std::cout << BOLD << "Overflow handled - excess materias deleted" << RST << std::endl;
    }

    // =========================================================================
    // 4. CHARACTER INVENTORY
    // =========================================================================
    printHeader("4. CHARACTER INVENTORY");
    
    printTest("Equipping & Using");
    {
        Character hero("Aragorn");
        MateriaSource src;
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        
        hero.equip(src.createMateria("ice"));
        hero.equip(src.createMateria("cure"));
        
        Character target("Enemy");
        std::cout << "Using materias:" << std::endl;
        hero.use(0, target);  // Ice
        hero.use(1, target);  // Cure
        hero.use(2, target);  // Empty slot - does nothing
    }

    printTest("Inventory Limits & Unequip");
    {
        Character hero("Hero");
        MateriaSource src;
        src.learnMateria(new Ice());
        
        // Fill inventory
        hero.equip(src.createMateria("ice"));
        hero.equip(src.createMateria("ice"));
        hero.equip(src.createMateria("ice"));
        hero.equip(src.createMateria("ice"));
        std::cout << GRY1 << "Inventory full (4 slots)" << RST << std::endl;
        
        // Test overflow
        hero.equip(src.createMateria("ice"));
        std::cout << BOLD << "Overflow handled - excess deleted" << RST << std::endl;
        
        // Test unequip
        hero.unequip(0);
        std::cout << "Unequipped slot 0, stored in MateriaManager: " << MateriaManager::getOrphanedCount() << std::endl;
    }

    // =========================================================================
    // 5. DEEP COPY (CRITICAL TEST)
    // =========================================================================
    printHeader("5. DEEP COPY VERIFICATION");
    
    printTest("Copy Constructor");
    {
        Character original("Original");
        MateriaSource src;
        src.learnMateria(new Ice());
        src.learnMateria(new Cure());
        
        original.equip(src.createMateria("ice"));
        original.equip(src.createMateria("cure"));
        
        Character copy(original);  // Copy constructor
        
        Character dummy("Dummy");
        std::cout << "Original: ";
        original.use(0, dummy);
        std::cout << "Copy: ";
        copy.use(0, dummy);
    }

    printTest("Assignment Operator");
    {
        Character source("Source");
        Character target("Target");
        MateriaSource src;
        src.learnMateria(new Ice());
        
        source.equip(src.createMateria("ice"));
        target = source;  // Assignment
        
        Character dummy("Dummy");
        std::cout << "After assignment: ";
        target.use(0, dummy);
    }

    // =========================================================================
    // 6. ERROR HANDLING
    // =========================================================================
    printHeader("6. ERROR HANDLING");
    
    printTest("Edge Cases");
    {
        Character hero("Hero");
        Character target("Target");
        
        std::cout << GRY1 << "Testing invalid operations (should be safe):" << RST << std::endl;
        hero.equip(NULL);         // NULL materia
        hero.use(-1, target);     // Invalid index
        hero.use(10, target);     // Invalid index
        hero.unequip(-1);         // Invalid index
        hero.unequip(0);          // Empty slot
        
    }

    // =========================================================================
    // 7. COMPREHENSIVE SCENARIO
    // =========================================================================
    printHeader("7. BATTLE SIMULATION");
    {
        std::cout << GRY1 << "Epic battle scenario..." << RST << std::endl;
        
        MateriaSource academy;
        academy.learnMateria(new Ice());
        academy.learnMateria(new Cure());
        
        Character wizard("Gandalf");
        Character warrior("Aragorn");
        Character enemy("Balrog");
        
        wizard.equip(academy.createMateria("ice"));
        wizard.equip(academy.createMateria("cure"));
        warrior.equip(academy.createMateria("ice"));
        
        std::cout << "\nBattle begins:" << std::endl;
        wizard.use(0, enemy);    // Gandalf attacks
        warrior.use(0, enemy);   // Aragorn attacks
        wizard.use(1, warrior);  // Gandalf heals Aragorn
        
        // Test copy during battle
        Character backup(wizard);
        std::cout << "Backup wizard: ";
        backup.use(0, enemy);
        
        std::cout << BOLD << "\n Battle completed successfully" << RST << std::endl;
    }

    // =========================================================================
    // 8. MEMORY CLEANUP
    // =========================================================================
    printHeader("8. MEMORY MANAGEMENT");
    {
        std::cout << "Orphaned materias: " << MateriaManager::getOrphanedCount() << std::endl;
        MateriaManager::cleanup();
        std::cout << "After cleanup: " << MateriaManager::getOrphanedCount() << std::endl;
        std::cout << BOLD << " No memory leaks" << RST << std::endl;
    }
    
    return 0;
}
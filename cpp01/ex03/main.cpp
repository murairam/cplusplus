// main.cpp

#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

/* 
Key Differences Demonstrated:
**Reference vs Pointer**:
   - HumanA uses a reference to Weapon - must always have a weapon, can't change weapons
   - HumanB uses a pointer to Weapon - can be null, can change weapons later
   
Use a reference when you're sure the object is always present and won't change.
Use a pointer when the presence of the object is optional or it may change later. 
*/

int main() {
    std::cout << "=== HumanA Tests (Reference - Always Armed) ===" << std::endl;
    {
        Weapon club("crude spiked club");
        Weapon sword("sharp sword");
        HumanA bob("Bob", club);  // Must provide weapon in constructor
        
        bob.attack();
        club.setType("some other type of club");
        bob.attack();
        
        // ATTEMPTING TO CHANGE BOB'S WEAPON (Won't work!):
        // bob.weapon = sword;        // ❌ Won't compile - weapon is private
        // bob.weapon = &sword;       // ❌ Won't compile - weapon is reference, not pointer
        // bob.setWeapon(sword);      // ❌ Won't compile - HumanA has no setWeapon method!
        // HumanA badBob("BadBob");   // ❌ Won't compile - must provide weapon!
        
        // The ONLY way to change Bob's "weapon" is to modify the original weapon object:
        club.setType("upgraded magical club");
        bob.attack();  // Bob still uses the same weapon object, but it's been modified
        
        std::cout << "→ Bob's weapon reference cannot be changed, only the weapon itself can be modified" << std::endl;
    }
    
    std::cout << "\n=== HumanB Tests (Pointer - Optionally Armed) ===" << std::endl;
    {
        // Test 1: HumanB without weapon
        HumanB jim("Jim");
        std::cout << "Jim starts without a weapon:" << std::endl;
        jim.attack();  // Should show "no weapon" message
        
        // Test 2: Give Jim a weapon
        std::cout << "\nGiving Jim a weapon:" << std::endl;
        Weapon club("crude spiked club");
        jim.setWeapon(club);
        jim.attack();
        
        // Test 3: Modify the weapon (both humans would see this change)
        std::cout << "\nModifying Jim's current weapon:" << std::endl;
        club.setType("some other type of club");
        jim.attack();
        
        // Test 4: Change Jim's weapon entirely (only possible with pointers!)
        std::cout << "\nChanging Jim's weapon to a completely different one:" << std::endl;
        Weapon sword("sharp steel sword");
        jim.setWeapon(sword);  // HumanB can change weapons - pointer reassignment!
        jim.attack();
        
        // Test 5: Show that the old weapon still exists
        std::cout << "\nThe old weapon still exists and can be modified independently:" << std::endl;
        club.setType("rusty old club");
        std::cout << "Club type is now: " << club.getType() << std::endl;
        jim.attack();  // Jim still has the sword, not affected by club changes
        
        std::cout << "→ Jim's weapon pointer can be reassigned to point to different weapons" << std::endl;
    }
    
    std::cout << "\n=== Summary ===" << std::endl;
    std::cout << "HumanA (reference): Always armed, weapon cannot be changed, only modified" << std::endl;
    std::cout << "HumanB (pointer): Optionally armed, can change weapons completely" << std::endl;
    
    return 0;
}
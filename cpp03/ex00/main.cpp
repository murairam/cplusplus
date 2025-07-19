#include "ClapTrap.hpp"

int main() {
    ClapTrap ct1("Marvin");

    std::cout << "\n--- Testing attack ---\n";
    ct1.attack("Goblin");

    std::cout << "\n--- Testing takeDamage ---\n";
    ct1.takeDamage(3);

    std::cout << "\n--- Testing beRepaired ---\n";
    ct1.beRepaired(5);

    std::cout << "\n--- Testing energy depletion ---\n";
    for (int i = 0; i < 11; ++i) {
        ct1.attack("EnergyEater");
    }

    std::cout << "\n--- Testing death ---\n";
    ct1.takeDamage(100);
    ct1.attack("Ghost");
    ct1.beRepaired(5);

    return 0;
}

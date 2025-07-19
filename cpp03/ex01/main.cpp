#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main() {
	std::cout << "\n--- Constructing ScavTrap ---\n";
	ScavTrap scav("Zaphod");

	std::cout << "\n--- Testing attack ---\n";
	scav.attack("Vogon");

	std::cout << "\n--- Testing takeDamage ---\n";
	scav.takeDamage(42); // iconic number

	std::cout << "\n--- Testing beRepaired ---\n";
	scav.beRepaired(23); // Slartibartfast's fjord budget maybe?

	std::cout << "\n--- Testing guardGate ---\n";
	scav.guardGate();

	std::cout << "\n--- Depleting energy by firing at Marvin ---\n";
	for (int i = 0; i < 51; ++i) {
		scav.attack("Marvin");
	}

	std::cout << "\n--- Destroying Zaphod with a Total Perspective Vortex ---\n";
	scav.takeDamage(1337); // you know it's overkill
	scav.attack("Arthur Dent");
	scav.beRepaired(7); // seven is nice, but not helpful here

	std::cout << "\n--- End of test ---\n";
	return 0;
}

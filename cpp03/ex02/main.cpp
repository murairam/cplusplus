#include <iostream>
#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#define RESET   "\033[0m"
#define BLUE    "\033[34m"
#define BOLD    "\033[1m"

int main() {
	std::cout << BOLD << BLUE << "=== 🧪 Welcome to the Towel Arena ===" << RESET << std::endl;

	// Construction
	ClapTrap ford("Ford");
	ScavTrap zaphod("Zaphod");
	FragTrap arthur("Arthur");

	std::cout << BOLD << "\n--- Round 1: Attack the same enemy ---" << RESET << std::endl;
	ford.attack("Heart of Gold");
	zaphod.attack("Heart of Gold");
	arthur.attack("Heart of Gold");

	std::cout << BOLD << "\n--- Round 2: Take damage from Vogon Poetry ---" << RESET << std::endl;
	ford.takeDamage(10);
	zaphod.takeDamage(20);
	arthur.takeDamage(30);

	std::cout << BOLD << "\n--- Round 3: Self-repair with Pan Galactic Gargle Blasters ---" << RESET << std::endl;
	ford.beRepaired(5);
	zaphod.beRepaired(10);
	arthur.beRepaired(15);

	std::cout << BOLD << "\n--- Round 4: Show off special moves ---" << RESET << std::endl;
	zaphod.guardGate();
	arthur.highFivesGuys();

	std::cout << BOLD << "\n--- Round 5: Burn out all energy ---" << RESET << std::endl;
	for (int i = 0; i < 50; ++i)
		ford.attack("Energy Dummy");
	for (int i = 0; i < 50; ++i)
		zaphod.attack("Energy Dummy");
	for (int i = 0; i < 50; ++i)
		arthur.attack("Energy Dummy");

	std::cout << BOLD << "\n--- Round 6: They're hit by a Total Perspective Vortex ---" << RESET << std::endl;
	ford.takeDamage(1000);
	zaphod.takeDamage(1000);
	arthur.takeDamage(1000);

	std::cout << BOLD << "\n--- Final moves (should all fail) ---" << RESET << std::endl;
	ford.attack("Nothing");
	zaphod.beRepaired(5);
	arthur.attack("Void");

	std::cout << BOLD << "\n=== 🧹 Arena is closing... Destruction begins ===" << RESET << std::endl;

	return 0;
}

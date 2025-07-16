#include "Zombie.hpp"

Zombie* newZombie(std::string name);
void randomChump(std::string name);

int main() {

    std::cout << "--- Heap Zombie Test ---" << std::endl;
    Zombie* zombie = newZombie("zombuella");
    zombie->announce();
    delete zombie;

    std::cout << "--- Stack Zombie Test ---" << std::endl;
    randomChump("Club Foot");
    randomChump("BOB");
    return 0;
}
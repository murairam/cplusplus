// main.cpp

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int count = 5;
    Zombie* horde = zombieHorde(count, "mr zombie nr");

    if (!horde) {
        std::cout << "Failed to create horde." << std::endl;
        return 1;
    }

    for (int i = 0; i < count; ++i) {
        horde[i].announce();
    }

    delete[] horde;
    return 0;
}

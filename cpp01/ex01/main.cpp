// main.cpp

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name);

int main() {
    int count = 10;
    if (count >= 10000) {
        std::cerr << "Error: Count must be less than 10000." << std::endl;
        return 1;
    }
    Zombie* horde = zombieHorde(count, "walker");

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

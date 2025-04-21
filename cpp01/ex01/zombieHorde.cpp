#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string baseName) {
    if (N <= 0)
        return NULL;

    Zombie* horde = new Zombie[N];
    for (int i = 0; i < N; ++i) {
        std::ostringstream fullName;
        fullName << baseName << (i + 1);
        horde[i].setName(fullName.str());
    }
    return horde;
}
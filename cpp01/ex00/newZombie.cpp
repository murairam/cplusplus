#include "Zombie.hpp"

Zombie* newZombie(std::string name){
    if (name.empty()) {
        std::cerr << "Error: Zombie name cannot be empty." << std::endl;
        return NULL;
    }
    return new Zombie(name);
}
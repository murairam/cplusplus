#include "Zombie.hpp"

void randomChump(std::string name){
    if (name.empty()) {
        std::cerr << "Error: Zombie name cannot be empty." << std::endl;
        return;
    }
    Zombie zombie(name);
    zombie.announce();
}
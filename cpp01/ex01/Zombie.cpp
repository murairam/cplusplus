#include "Zombie.hpp"

Zombie::Zombie() {
    this->name = "nameless";
}

Zombie::Zombie(std::string name){
    this->name = name;
}

Zombie::~Zombie() {
    std::cout << name << " is dead!" << std::endl;
}

void Zombie::setName(std::string name){
    this->name = name;
}

void Zombie::announce(){
    std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
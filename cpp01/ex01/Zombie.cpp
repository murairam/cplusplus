#include "Zombie.hpp"

Zombie::Zombie() {
    this->_name = "nameless";
}

Zombie::Zombie(std::string name){
    this->_name = name;
}

Zombie::~Zombie() {
    std::cout << _name << " is dead!" << std::endl;
}

void Zombie::setName(std::string name){
    this->_name = name;
}

void Zombie::announce(){
    std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}
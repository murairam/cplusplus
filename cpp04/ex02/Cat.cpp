// Cat.cpp
#include "Cat.hpp"

Cat::Cat() {
    type = "Cat";
    std::cout << "Cat created\n";
}

Cat::Cat(const Cat &other){
    brain = new Brain(*other.brain);
    std::cout << "Cat copied\n";
}
Cat &Cat::operator=(const Cat &other){
    if (this != &other){
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Cat assigned\n";
    return *this;
}
    
Cat::~Cat() {
    std::cout << "Cat destroyed\n";

}

void Cat::makeSound() const {
    std::cout << "Meow!\n";
}

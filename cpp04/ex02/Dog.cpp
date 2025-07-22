// Dog.cpp
#include "Dog.hpp"
#include <iostream>

Dog::Dog() : brain(new Brain()) {
    type = "Dog";
    std::cout << "Dog created\n";
}

Dog::Dog(const Dog& other) : Animal(other) {
    brain = new Brain(*other.brain);
    std::cout << "Dog copied\n";
}

Dog& Dog::operator=(const Dog& other) {
    if (this != &other) {
        Animal::operator=(other);
        delete brain;
        brain = new Brain(*other.brain);
    }
    std::cout << "Dog assigned\n";
    return *this;
}

Dog::~Dog() {
    delete brain;
    std::cout << "Dog destroyed\n";
}

void Dog::makeSound() const {
    std::cout << "Woof!\n";
}

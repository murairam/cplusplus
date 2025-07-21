// WrongAnimal.cpp
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("WrongAnimal") {
    std::cout << "WrongAnimal created\n";
}

WrongAnimal::~WrongAnimal() {
    std::cout << "WrongAnimal destroyed\n";
}

void WrongAnimal::makeSound() const {
    std::cout << "WrongAnimal sound\n";
}

std::string WrongAnimal::getType() const {
    return type;
}

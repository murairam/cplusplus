// WrongCat.cpp
#include "WrongCat.hpp"

WrongCat::WrongCat() {
    type = "WrongCat";
    std::cout << "WrongCat created\n";
}

WrongCat::~WrongCat() {
    std::cout << "WrongCat destroyed\n";
}

void WrongCat::makeSound() const {
    std::cout << "Wrong Meow?\n";
}

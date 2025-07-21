#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main() {
    const int size = 4;
    Animal* animals[size];

    for (int i = 0; i < size; ++i) {
        if (i < size / 2)
            animals[i] = new Dog();
        else
            animals[i] = new Cat();
    }

    std::cout << "Deleting animals...\n";
    for (int i = 0; i < size; ++i)
        delete animals[i];

    std::cout << "Testing deep copy:\n";
    Dog a;
    Dog b = a;  // Calls copy constructor

    return 0;
}
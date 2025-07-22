#include "Dog.hpp"
#include "Cat.hpp"
#include <iostream>

int main() {
    std::cout << "Creating animals...\n";

    const Animal* dog = new Dog();
    const Animal* cat = new Cat();

    std::cout << "\nTypes:\n";
    std::cout << "Dog type: " << dog->getType() << std::endl;
    std::cout << "Cat type: " << cat->getType() << std::endl;

    std::cout << "\nSounds:\n";
    dog->makeSound();
    cat->makeSound();

    std::cout << "\nDeleting animals...\n";
    delete dog;
    delete cat;

    // Uncommenting the line below should cause a compile error,
    // because Animal is now an abstract class.
    //const Animal* meta = new Animal(); // ❌ Should fail to compile

    return 0;
}

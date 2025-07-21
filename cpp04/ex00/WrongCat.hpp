// WrongCat.hpp
#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal {
public:
    WrongCat();
    ~WrongCat();
    void makeSound() const; // 👈 not virtual in base!
};

#endif

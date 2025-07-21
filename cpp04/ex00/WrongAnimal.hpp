// WrongAnimal.hpp
#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal {
protected:
    std::string type;

public:
    WrongAnimal();
    virtual ~WrongAnimal(); // this can stay virtual
    void makeSound() const;
    std::string getType() const;
};

#endif

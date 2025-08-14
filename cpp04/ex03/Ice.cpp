#include "Ice.hpp"

Ice::Ice() : AMateria("ice"){
    //std::cout << "Ice constructed!" << std::endl;
}

Ice::Ice(const Ice& other): AMateria(other){
    //std::cout << "Ice copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice& other){
    (void)other;
    return *this;
}

Ice::~Ice(){
    //std::cout << "Ice " << this->_type << " destructed!" << std::endl;
}

AMateria* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
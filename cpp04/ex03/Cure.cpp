#include "Cure.hpp"

Cure::Cure() : AMateria("cure"){
    //std::cout << "Cure constructed!" << std::endl;
}

Cure::Cure(const Cure& other): AMateria(other){
    //std::cout << "Cure copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure& other){
    (void)other;
    return *this;
}

Cure::~Cure(){
   // std::cout << "Cure " << this->_type << " destructed!" << std::endl;
}

AMateria* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
#include "AMateria.hpp"

AMateria::AMateria(std::string const & type): _type(type){
    std::cout << "Amateria " << this->_type << " constructed!" << std::endl;
}

AMateria::AMateria(const AMateria& other): _type(other._type) {
    std::cout << "AMateria copy constructor called" << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other){
    (void)other;
    return *this;
}

AMateria::~AMateria(){
    std::cout << "AMateria " << this->_type << " destructed!" << std::endl;
}

std::string const & AMateria::getType() const{
    return this->_type;
} //Returns the materia type

void AMateria::use(ICharacter& target) {
    (void)target;
}

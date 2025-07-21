#include "Animal.hpp"

Animal::Animal(){
    std::cout << "Animal default constructed!" << std::endl; 
}

Animal::Animal(std::string type){
    std::cout << "Animal " << this->type << " constructed!" << std::endl;
}

Animal::~Animal(){
    std::cout << "Animal " << this->type << " destructed!" << std::endl;
}

Animal::Animal(const Animal &other)
:type(other.type)
{
    std::

}


Animal &Animal::operator=(const Animal &other){

}
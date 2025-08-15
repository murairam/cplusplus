#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(){

}
Bureaucrat::Bureaucrat(const Bureaucrat& other){

}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){

}
Bureaucrat::~Bureaucrat(){

}

std::string getName(){
    return _name;
}
int         getGrade(){

}


std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << getName() <<", bureaucrat grade " << getGrade();
    return out;
}
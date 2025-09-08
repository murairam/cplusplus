#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include <iostream>
#include <string>


Intern::Intern(){

}
Intern::Intern(const Intern& other){
    *this = other;
}

Intern& Intern::operator=(const Intern& other){
    (void)other;
    return *this;
}

Intern::~Intern(){

}

static AForm* createShrubbery(const std::string &target){
    return new ShrubberyCreationForm(target);
}

static AForm* createRobotomy(const std::string &target){
    return new RobotomyRequestForm(target);
}

static AForm* createPresidential(const std::string &target){
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& formCall, const std::string& target){
    std::string formCalls[3] = {"shrubbery", "robotomy", "presidential"};
    AForm* (*formNames[3])(const std::string &) = {
        createShrubbery,
        createRobotomy,
        createPresidential
    };
    AForm* form = NULL;

    for(int i = 0; i < 3; i++){
        if (formCall == formCalls[i]){
            form = formNames[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
        }
    }
    if (!form)
        std::cout << "Intern is useless and form does not exist" << std::endl;
    return form;
}
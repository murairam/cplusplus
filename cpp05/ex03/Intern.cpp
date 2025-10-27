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
    std::string formCalls[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*formNames[3])(const std::string &) = {
        createShrubbery,
        createRobotomy,
        createPresidential
    };

    for(int i = 0; i < 3; i++){
        if (formCall == formCalls[i]){
            AForm* form = formNames[i](target);
            std::cout << "Intern creates " << form->getName() << std::endl;
            return form;
        }
    }
    std::cout << "Intern cannot create form \"" << formCall << "\" because it doesn't exist" << std::endl;
    return NULL;
}
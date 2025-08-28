#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>


Intern::Intern() {
}
Intern::Intern(const Intern &src) {
    (void)src;
}

Intern::~Intern() {
}
Intern &Intern::operator=(const Intern &rhs) {
    (void)rhs;
    return *this;
}

static AForm* createShrubbery(const std::string &target) {
    return new ShrubberyCreationForm(target);
}
static AForm* createRobotomy(const std::string &target) {
    return new RobotomyRequestForm(target);
}
static AForm* createPresidential(const std::string &target) {
    return new PresidentialPardonForm(target);
}

AForm *Intern::makeForm(const std::string &formName, const std::string &target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    AForm* (*formCreators[3])(const std::string &) = {
        createShrubbery,
        createRobotomy,
        createPresidential
    };

    for (int i = 0; i < 3; ++i) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << " form." << std::endl;
            return formCreators[i](target);
        }
    }

    std::cout << "Error: Unknown form name '" << formName << "'." << std::endl;
    return NULL;
}
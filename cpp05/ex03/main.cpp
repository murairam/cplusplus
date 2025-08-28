#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main() {

	srand(time(NULL));

	std::cout << "\033[33m" << std::endl << "Test ex03" << "\033[0m" << std::endl;

	Intern intern;
	AForm *form = intern.makeForm("shrubbery creation", "Target");
	if (form) {
		delete form;
	}

	form = intern.makeForm("robotomy request", "Target");
	if (form) {
		delete form;
	}

	form = intern.makeForm("presidential pardon", "Target");
	if (form) {
		delete form;
	}

	form = intern.makeForm("unknown form", "Target");
	if (form) {
		delete form;
	}

    return 0;
}
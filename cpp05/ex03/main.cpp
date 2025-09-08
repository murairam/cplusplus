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
	AForm* form;
	Intern goodBoy;

	form = goodBoy.makeForm("shrubbery", "shrubs");
	if (form)
		delete form;

	form = goodBoy.makeForm("robotomy", "robot");
	if (form)
		delete form;
		
	form = goodBoy.makeForm("presidential", "president");
	if (form)
		delete form;

	form = goodBoy.makeForm("coffee", "make coffee");
	if (form)
		delete form;

    return 0;
}
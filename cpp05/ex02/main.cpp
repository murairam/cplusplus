#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>

int main() {

	srand(time(NULL));

	std::cout << "\033[33m" << std::endl << "Test ex02" << "\033[0m" << std::endl;

	std::cout << "\033[33m" << std::endl << "Test ex02 ShrubberyCreationForm" << "\033[0m" << std::endl;
	Bureaucrat james("james", 130);
	ShrubberyCreationForm Shrubbyform("Hello");
	std::cout << std::endl;
	std::cout << Shrubbyform;
	james.signForm(Shrubbyform);
	std::cout << Shrubbyform;
	james.executeForm(Shrubbyform);

	std::cout << "\033[33m" << std::endl << "Test ex02 RobotomyRequestForm" << "\033[0m" << std::endl;
	RobotomyRequestForm RoboForm("I am a robo form");
	Bureaucrat mrrobot("mrrobot", 45);

	mrrobot.executeForm(RoboForm);
	mrrobot.signForm(RoboForm);
	mrrobot.executeForm(RoboForm);
	mrrobot.executeForm(RoboForm);
	mrrobot.executeForm(RoboForm);

	std::cout << "\033[33m" << std::endl << "Test ex02 PresidentialPardonForm" << "\033[0m" << std::endl;
	PresidentialPardonForm President_form("I am a robo form");
	Bureaucrat Trump("Trump", 5);

	mrrobot.executeForm(President_form);
	mrrobot.signForm(President_form);

	Trump.executeForm(President_form);
	Trump.signForm(President_form);
	Trump.executeForm(President_form);

    return 0;
}
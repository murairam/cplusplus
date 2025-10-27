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

	std::cout << "\033[33m" << std::endl << "=== EX03 INTERN TESTS ===" << "\033[0m" << std::endl;

	Intern someRandomIntern;
	AForm* form;

	std::cout << "\033[32m" << std::endl << "Testing valid form creation:" << "\033[0m" << std::endl;
	
	// Test 1: Create ShrubberyCreationForm
	std::cout << "\n--- Creating Shrubbery Creation Form ---" << std::endl;
	form = someRandomIntern.makeForm("shrubbery creation", "home");
	if (form) {
		std::cout << *form << std::endl;
		delete form;
	}

	// Test 2: Create RobotomyRequestForm (as per subject example)
	std::cout << "\n--- Creating Robotomy Request Form ---" << std::endl;
	form = someRandomIntern.makeForm("robotomy request", "Bender");
	if (form) {
		std::cout << *form << std::endl;
		delete form;
	}
		
	// Test 3: Create PresidentialPardonForm
	std::cout << "\n--- Creating Presidential Pardon Form ---" << std::endl;
	form = someRandomIntern.makeForm("presidential pardon", "Arthur Dent");
	if (form) {
		std::cout << *form << std::endl;
		delete form;
	}

	std::cout << "\033[31m" << std::endl << "Testing invalid form creation:" << "\033[0m" << std::endl;
	
	// Test 4: Invalid form name
	std::cout << "\n--- Trying to create non-existent form ---" << std::endl;
	form = someRandomIntern.makeForm("coffee request", "espresso");
	if (form) {
		delete form;
	}

	// Test 5: Case sensitivity
	std::cout << "\n--- Testing case sensitivity ---" << std::endl;
	form = someRandomIntern.makeForm("ROBOTOMY REQUEST", "R2D2");
	if (form) {
		delete form;
	}

	std::cout << "\033[33m" << std::endl << "Testing complete form workflow:" << "\033[0m" << std::endl;
	
	// Test 6: Complete workflow with signing and execution
	std::cout << "\n--- Complete workflow test ---" << std::endl;
	Bureaucrat boss("Boss", 1);  // High-level bureaucrat who can do everything
	Bureaucrat clerk("Clerk", 150); // Low-level bureaucrat
	
	form = someRandomIntern.makeForm("robotomy request", "Test Subject");
	if (form) {
		std::cout << "\nBefore signing:" << std::endl;
		std::cout << *form << std::endl;
		
		// Test signing with insufficient grade
		clerk.signForm(*form);
		
		// Test signing with sufficient grade
		boss.signForm(*form);
		
		std::cout << "\nAfter signing:" << std::endl;
		std::cout << *form << std::endl;
		
		// Test execution
		boss.executeForm(*form);
		boss.executeForm(*form);  // Try again for robotomy randomness
		
		delete form;
	}

	// Test 7: Test all three forms in sequence
	std::cout << "\033[36m" << std::endl << "Testing all forms in sequence:" << "\033[0m" << std::endl;
	std::string formTypes[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	std::string targets[3] = {"garden", "C3PO", "Ford Prefect"};
	
	for (int i = 0; i < 3; i++) {
		std::cout << "\n--- Form " << (i+1) << " ---" << std::endl;
		form = someRandomIntern.makeForm(formTypes[i], targets[i]);
		if (form) {
			boss.signForm(*form);
			boss.executeForm(*form);
			delete form;
		}
	}

    return 0;
}
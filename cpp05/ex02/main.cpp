/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:49:26 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 14:04:56 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	std::cout << std::endl;
	james.signForm(Shrubbyform);
	std::cout << Shrubbyform;
	std::cout << std::endl;
	james.executeForm(Shrubbyform);

	std::cout << "\033[33m" << std::endl << "Test ex02 RobotomyRequestForm" << "\033[0m" << std::endl;
	RobotomyRequestForm RoboForm("I am a robo form");
	Bureaucrat mrrobot("mrrobot", 45);

	mrrobot.executeForm(RoboForm);
	std::cout << RoboForm << std::endl;
	mrrobot.signForm(RoboForm);
	mrrobot.executeForm(RoboForm);
	mrrobot.executeForm(RoboForm);
	mrrobot.executeForm(RoboForm);
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

	std::cout << "\033[33m" << std::endl << "Test edge cases" << "\033[0m" << std::endl;
	
	// Test signing already signed form
	std::cout << "\033[32m" << "Testing double signing:" << "\033[0m" << std::endl;
	Trump.signForm(President_form); // Should fail - already signed
	
	// Test executing unsigned form
	std::cout << "\033[32m" << "Testing execution of unsigned form:" << "\033[0m" << std::endl;
	PresidentialPardonForm unsigned_form("unsigned");
	Trump.executeForm(unsigned_form); // Should fail - not signed
	
	// Test insufficient grade for signing
	std::cout << "\033[32m" << "Testing insufficient grade for signing:" << "\033[0m" << std::endl;
	Bureaucrat lowGrade("lowGrade", 150);
	lowGrade.signForm(unsigned_form); // Should fail - grade too low
	
	// Test insufficient grade for execution
	std::cout << "\033[32m" << "Testing insufficient grade for execution:" << "\033[0m" << std::endl;
	Bureaucrat midGrade("midGrade", 25);
	midGrade.signForm(unsigned_form); // Should succeed
	midGrade.executeForm(unsigned_form); // Should fail - grade too low for execution

    return 0;
}
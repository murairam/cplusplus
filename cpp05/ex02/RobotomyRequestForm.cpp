#include "RobotomyRequestForm.hpp"



RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
}

RobotomyRequestForm::RobotomyRequestForm(const std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
{
}	

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : AForm(src)
{
	*this = src;
}


RobotomyRequestForm::~RobotomyRequestForm()
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=( RobotomyRequestForm const & other )
{
	_target = other._target;
	setIsSigned(other.getIsSigned());
	return (*this);
}

void RobotomyRequestForm::performAction() const
{
	int random_number;

	random_number = rand() % 2;

	if (random_number == 1)
		std::cout << "Beeep Be Be Beeeee Beeeeeeeep. " << getName() << " has been robotomized successfully!" << std::endl; 		
	else
		throw RobotizationFailed();
}

const char *RobotomyRequestForm::RobotizationFailed::what() const throw()
{
	return ("Unfortunately robotomy failed.");
}
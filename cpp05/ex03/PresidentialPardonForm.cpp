#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5)
{
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : AForm(src)
{
	*this = src;
}
PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm("PresidentialPardonForm", 25, 5), _target(target)
{

}
PresidentialPardonForm::~PresidentialPardonForm()
{
}


PresidentialPardonForm &PresidentialPardonForm::operator=( PresidentialPardonForm const &other )
{
	if ( this != &other )
	{
		this->_target = other._target;
	}
	setIsSigned(other.getIsSigned());
	return *this;
}

void PresidentialPardonForm::performAction() const
{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
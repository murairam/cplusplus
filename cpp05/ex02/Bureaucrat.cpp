/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:49:23 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 14:04:56 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

int Bureaucrat::validateGrade(int grade) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    return grade;  // Return valid grade
}

Bureaucrat::Bureaucrat() : _name("Unknown"), _grade(150) {
}

Bureaucrat::Bureaucrat(const std::string& name, int grade) : _name(name), _grade(validateGrade(grade)){

}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade){

}
Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other){
    if (this != &other){
        _grade = validateGrade(other._grade);
    }
    return  *this;
}
Bureaucrat::~Bureaucrat(){

}

std::string Bureaucrat::getName() const{
    return _name;
}

int         Bureaucrat::getGrade() const {
    return _grade;
}

void    Bureaucrat::incrementGrade(){
    int newGrade = _grade - 1;
    validateGrade(newGrade);
    _grade = newGrade;
}

void    Bureaucrat::decrementGrade(){
    int newGrade = _grade + 1;
    validateGrade(newGrade);
    _grade = newGrade;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade too low!");
}

void Bureaucrat::signForm(AForm& form){
    if (form.getIsSigned()) {
        std::cout << this->getName() << " couldn't sign " << form.getName() << " because it's already signed" << std::endl;
        return;
    }
    try {
        form.beSigned(*this);
        std::cout << this->getName() << " signed " << form.getName() << std::endl;
    }
    catch (std::exception& e){
        std::cout <<  this->getName() << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
    }
}
void Bureaucrat::executeForm(AForm const & form) const {
    if (!form.getIsSigned()) {
        std::cout << this->getName() << " couldn't execute " << form.getName() << " because it's not signed" << std::endl;
        return;
    }
    try {
        form.execute(*this);
        std::cout << this->getName() << " executed " << form.getName() << std::endl;
    }
    catch (std::exception& e){
        std::cout <<  this->getName() << " couldn't execute " << form.getName() << " because " << e.what() << std::endl;
    }
}

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat)
{
    out << bureaucrat.getName() <<", bureaucrat grade " << bureaucrat.getGrade();
    return out;
}
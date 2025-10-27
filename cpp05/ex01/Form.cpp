/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 12:50:49 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 12:50:50 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp" 

int Form::validateGrade(int grade){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    return grade;
}

Form::Form() : _name("Unknown"), _is_signed(false), _grade_s(150), _grade_e(150){

}

Form::Form(const std::string& name, const int grade_s, const int grade_e) : _name(name), _is_signed(false), _grade_s(validateGrade(grade_s)), _grade_e(validateGrade(grade_e)){

}

Form::Form(const Form& other) : _name(other._name), _is_signed(other._is_signed), _grade_s(other._grade_s), _grade_e(other._grade_e){

}

Form& Form::operator=(const Form& other){
    if (this != &other){
        _is_signed = other._is_signed;
    }
    return  *this;
}

Form::~Form(){

}

std::string Form::getName() const{
    return _name;
}

bool         Form::getIsSigned() const{
    return  _is_signed;
}

int         Form::getSignGrade() const{
    return  _grade_s;
}

int         Form::getExecGrade() const{
    return _grade_e;
}

void    Form::beSigned(const Bureaucrat& bureaucrat){
    int bureaucratGrade = bureaucrat.getGrade();
    if (bureaucratGrade <= _grade_s){
        _is_signed = true;
    } else {
        throw Form::GradeTooLowException();
    }
}

const char *Form::GradeTooHighException::what() const throw(){
	return ("Grade too high!");
}

const char *Form::GradeTooLowException::what() const throw(){
	return ("Grade too low!");
}


std::ostream& operator<<(std::ostream& out, const Form& form){
    out << "Form " << form.getName() 
        << ", signed: " << (form.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << form.getSignGrade()
        << ", exec grade: " << form.getExecGrade();
    return out;
}
#include "AForm.hpp"
#include "Bureaucrat.hpp" 

int AForm::validateGrade(int grade){
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
    return grade;
}

AForm::AForm() : _name("Unknown"), _is_signed(false), _grade_s(150), _grade_e(150){

}

AForm::AForm(const std::string& name, const int grade_s, const int grade_e) : _name(name), _is_signed(false), _grade_s(validateGrade(grade_s)), _grade_e(validateGrade(grade_e)){

}

AForm::AForm(const AForm& other) : _name(other._name), _is_signed(other._is_signed), _grade_s(other._grade_s), _grade_e(other._grade_e){

}

AForm& AForm::operator=(const AForm& other){
    if (this != &other){
        _is_signed = other._is_signed;
    }
    return  *this;
}

AForm::~AForm(){

}

std::string AForm::getName() const{
    return _name;
}

bool         AForm::getIsSigned() const{
    return  _is_signed;
}

int         AForm::getSignGrade() const{
    return  _grade_s;
}

int         AForm::getExecGrade() const{
    return _grade_e;
}

void    AForm::beSigned(const Bureaucrat& bureaucrat){
    int bureaucratGrade = bureaucrat.getGrade();
    if (bureaucratGrade <= _grade_s){
        _is_signed = true;
    } else {
        throw AForm::GradeTooLowException();
    }
}

const char *AForm::GradeTooHighException::what() const throw(){
	return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw(){
	return ("Grade too low!");
}

const char *AForm::IsNotSignedException::what() const throw()
{
    return ("Form is not signed!");
}

void AForm::execute(Bureaucrat const & executor) const {
    if (!getIsSigned())
        throw AForm::IsNotSignedException();
    if (executor.getGrade() > getExecGrade())
        throw AForm::GradeTooLowException();
    performAction();
}

void AForm::setIsSigned(bool is_signed){
    _is_signed = is_signed;
}


std::ostream& operator<<(std::ostream& out, const AForm& AForm){
    out << "AForm " << AForm.getName() 
        << ", signed: " << (AForm.getIsSigned() ? "yes" : "no")
        << ", sign grade: " << AForm.getSignGrade()
        << ", exec grade: " << AForm.getExecGrade();
    return out;
}
#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class   Form {
    private:
        const std::string _name;
        bool    _is_signed;
        const int   _grade_s;
        const int   _grade_e;
        static int validateGrade(int grade);

    public:
        Form();
        Form(const std::string& name, const int grade_s, const int grade_e);
        Form(const Form& other);
        Form &operator=(const Form& other);
        ~Form();
        std::string getName() const;
        bool         getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;

        void    beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
        };

};

std::ostream& operator<<(std::ostream& out, const Form& form);

#endif
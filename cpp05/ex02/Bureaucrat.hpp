#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <string>
#include <iostream>
#include <exception>
#include "AForm.hpp"

class AForm;

class Bureaucrat {
    private:
        const std::string _name;
        int _grade;        
        static int validateGrade(int grade);

    public:
        Bureaucrat();
        Bureaucrat(const std::string& name, int grade);
        Bureaucrat(const Bureaucrat& other);
        Bureaucrat& operator=(const Bureaucrat& other);
        ~Bureaucrat();

        std::string getName() const;
        int         getGrade() const;

        void    incrementGrade();
        void    decrementGrade();


        class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
        
        void    signForm(AForm& form);

        void    executeForm(AForm const & form) const;

};

std::ostream& operator<<(std::ostream& out, const Bureaucrat& bureaucrat);

#endif
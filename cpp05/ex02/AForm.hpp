#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>
#include <exception>
#include "Bureaucrat.hpp"

class Bureaucrat;

class   AForm {
    private:
        const std::string   _name;
        bool                _is_signed;
        const int           _grade_s;
        const int           _grade_e;
        static int          validateGrade(int grade);
        virtual void        performAction() const = 0;

    public:
        AForm();
        AForm(const std::string& name, const int grade_s, const int grade_e);
        AForm(const AForm& other);
        AForm &operator=(const AForm& other);
        virtual ~AForm();

        virtual void execute(Bureaucrat const & executor) const;

        std::string getName() const;
        bool         getIsSigned() const;
        int         getSignGrade() const;
        int         getExecGrade() const;
        void        setIsSigned(bool is_signed);

        void    beSigned(const Bureaucrat& bureaucrat);

        class GradeTooHighException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
        
        class GradeTooLowException : public std::exception {
        public:
            virtual const char *what() const throw();
        };
        class IsNotSignedException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif
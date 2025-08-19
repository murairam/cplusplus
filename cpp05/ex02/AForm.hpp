#ifndef AForm_HPP
#define AForm_HPP

#include <string>
#include <iostream>

class Bureaucrat;

class   AForm {
    private:
        const std::string _name;
        bool    _is_signed;
        const int   _grade_s;
        const int   _grade_e;
        static int validateGrade(int grade);

    public:
        AForm();
        AForm(const std::string& name, const int grade_s, const int grade_e);
        AForm(const AForm& other);
        AForm &operator=(const AForm& other);
        ~AForm();

        virtual void execute(Bureaucrat const & executor) const = 0;

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

std::ostream& operator<<(std::ostream& out, const AForm& AForm);

#endif
#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"

class Intern {
public:
    Intern();
    Intern(const Intern &src);
    ~Intern();

    Intern &operator=(const Intern &rhs);

    AForm *makeForm(const std::string &formName, const std::string &target);
};

#endif
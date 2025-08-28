#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=( ShrubberyCreationForm const & other );

		class OpenFileExeption : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

	private:

		std::string _target;
		virtual void performAction() const;

};


#endif 
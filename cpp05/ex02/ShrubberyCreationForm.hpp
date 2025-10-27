/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:48:47 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 13:48:48 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
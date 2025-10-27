/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:49:07 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 13:49:08 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( std::string target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=( PresidentialPardonForm const & other );

	private:
		std::string _target;
		virtual void performAction() const;

};

#endif
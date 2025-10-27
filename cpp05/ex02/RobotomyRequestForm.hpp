/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 13:48:58 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 13:48:59 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <stdlib.h>
#include <time.h>

class RobotomyRequestForm : public AForm
{
	private:
		std::string _target;
		virtual void performAction() const;

	public:

		RobotomyRequestForm();
		RobotomyRequestForm(const std::string target);
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &other);

		class RobotizationFailed : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};

};

#endif
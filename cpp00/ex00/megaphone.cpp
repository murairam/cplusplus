/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 13:33:14 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/03/10 14:06:30 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cctype>

int main(int argc, char **argv)
{
    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return 0;
    }
    for (int i = 1; i < argc; i++)
    {
        std::string arg = argv[i];  // Convert char* to std::string
        for (size_t j = 0; j < arg.length(); j++)
            std::cout << (char)std::toupper(arg[j]);
    }
    std::cout << std::endl;
	return 0;
}
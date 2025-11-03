/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 19:40:17 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/11/03 20:04:10 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char**argv){
    (void)argv;
    if (argc != 2){
        std::cout << "Error: Usage: ./PmergeMe <arguments>" << std::endl;
        return 0;
    }
    return 0;
}

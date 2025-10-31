/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 16:27:42 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/31 15:09:06 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "RPN.hpp"

int main(int argc, char**argv){
    (void)argv;
    if (argc != 2){
        std::cout << "Error: Usage: ./RPN <inverted Polish mathematical expression>" << std::endl;
        return 0;
    }
    std::string exp = argv[1];
    RPN calculate(exp);
    
    if (!calculate.calc()){
        return 1;
    }
    return 0;
}
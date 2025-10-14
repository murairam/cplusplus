/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:27:30 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/14 13:28:17 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    // Step 1: Create vector
    std::vector<int> vec;
	vec.push_back(0);
	vec.push_back(1);
	vec.push_back(42);
	vec.push_back(77);
	vec.push_back(98);



    // Step 3: Test finding a value that exists
    std::cout << "=== Test 1: Find existing value ===" << std::endl;
    try {
		std::vector<int>::iterator it = easyfind(vec, 42);
		std::cout << "found: " << *it <<std::endl;

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Step 4: Test finding a value that doesn't exist
    std::cout << "\n=== Test 2: Find non-existing value ===" << std::endl;
    try {
		std::vector<int>::iterator it = easyfind(vec, 33);
		std::cout << "found: " << *it <<std::endl;

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 16:27:30 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/13 18:22:29 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <vector>
#include "easyfind.hpp"

int main() {
    // Step 1: Create vector
    std::vector<int> vec;

    // Step 2: Fill it with numbers (YOU WRITE THIS)
    // Add: 1, 5, 10, 42, 100



    // Step 3: Test finding a value that exists
    std::cout << "=== Test 1: Find existing value ===" << std::endl;
    try {
        // Call easyfind for 42 (YOU WRITE THIS)

        // Print the result (YOU WRITE THIS)

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    // Step 4: Test finding a value that doesn't exist
    std::cout << "\n=== Test 2: Find non-existing value ===" << std::endl;
    try {
        // Call easyfind for 999 (YOU WRITE THIS)

        // Print the result (YOU WRITE THIS)

    } catch (std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}

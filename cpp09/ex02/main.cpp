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
#include "PmergeMe.hpp"

/**
 * @brief Main entry point for the PmergeMe program
 *
 * This program demonstrates the Ford-Johnson merge-insertion sort algorithm
 * using two different STL containers (vector and deque) and compares their
 * performance.
 *
 * Usage:
 *   ./PmergeMe <positive integers>
 *
 * Examples:
 *   ./PmergeMe 3 5 9 7 4
 *   ./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`
 *
 * Output format:
 *   Before: <first 4 numbers> [...]
 *   Time to process a range of N elements with std::vector : X.XXXXX us
 *   Time to process a range of N elements with std::deque  : X.XXXXX us
 *   After:  <first 4 numbers> [...]
 *
 * @param argc Argument count (must be >= 2)
 * @param argv Argument values (positive integers to sort)
 * @return 0 on success, 1 on error
 *
 * Error cases:
 * - No arguments provided
 * - Negative numbers
 * - Non-numeric input
 * - Numbers out of int range
 */
int main(int argc, char** argv) {
	// Check for minimum argument requirement
	if (argc < 2) {
		std::cerr << "Error" << std::endl;
		return 1;
	}

	try {
		// Create sorter instance
		PmergeMe sorter;

		// Parse and validate input
		sorter.parseInput(argc, argv);

		// Display unsorted sequence
		sorter.displayBefore();

		// Sort both containers and display timings
		sorter.sort();

		// Display sorted sequence
		sorter.displayAfter();

	} catch (const std::exception& e) {
		// Handle any exceptions (invalid input)
		std::cerr << e.what() << std::endl;
		return 1;
	}

	return 0;
}

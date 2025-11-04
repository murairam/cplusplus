/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:47:14 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/11/03 16:47:15 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <vector>
#include <deque>
#include <string>
#include <iostream>
#include <sstream>
#include <ctime>
#include <algorithm>
#include <cstdlib>

/**
 * @class PmergeMe
 * @brief Implements the Ford-Johnson merge-insertion sort algorithm
 *
 * This class sorts positive integers using the Ford-Johnson algorithm
 * (also known as merge-insertion sort) with two different STL containers:
 * std::vector and std::deque. It measures and compares the performance
 * of both container types.
 *
 * The Ford-Johnson algorithm minimizes the number of comparisons needed
 * to sort a sequence by combining merge sort's divide-and-conquer approach
 * with binary insertion.
 */
class PmergeMe {
private:
	std::vector<int> _vector;	///< Vector container for sorting
	std::deque<int> _deque;		///< Deque container for sorting

	/**
	 * @brief Implements Ford-Johnson sort algorithm for std::vector
	 *
	 * Algorithm steps:
	 * 1. Pair elements and sort within pairs (larger first)
	 * 2. Recursively sort the larger elements
	 * 3. Build main chain from larger elements
	 * 4. Insert smaller elements using binary insertion
	 * 5. Handle odd element (straggler) if present
	 *
	 * @param data Reference to vector to be sorted
	 */
	void fordJohnsonVector(std::vector<int>& data);

	/**
	 * @brief Performs binary search insertion for vector
	 *
	 * Finds the correct position to insert a value in a sorted range
	 * using binary search, then inserts it.
	 *
	 * @param data Reference to the vector
	 * @param start Iterator to start of search range
	 * @param end Iterator to end of search range
	 * @param value Value to insert
	 * @return Iterator to the inserted element
	 */
	std::vector<int>::iterator binaryInsertVector(std::vector<int>& data,
		std::vector<int>::iterator start, std::vector<int>::iterator end, int value);

	/**
	 * @brief Implements Ford-Johnson sort algorithm for std::deque
	 *
	 * Same algorithm as fordJohnsonVector but operates on std::deque.
	 * Implemented separately (not as template) as per subject requirements.
	 *
	 * @param data Reference to deque to be sorted
	 */
	void fordJohnsonDeque(std::deque<int>& data);

	/**
	 * @brief Performs binary search insertion for deque
	 *
	 * Finds the correct position to insert a value in a sorted range
	 * using binary search, then inserts it.
	 *
	 * @param data Reference to the deque
	 * @param start Iterator to start of search range
	 * @param end Iterator to end of search range
	 * @param value Value to insert
	 * @return Iterator to the inserted element
	 */
	std::deque<int>::iterator binaryInsertDeque(std::deque<int>& data,
		std::deque<int>::iterator start, std::deque<int>::iterator end, int value);

public:
	/**
	 * @brief Default constructor
	 *
	 * Constructs an empty PmergeMe object with empty vector and deque.
	 */
	PmergeMe();

	/**
	 * @brief Copy constructor
	 *
	 * Creates a deep copy of another PmergeMe object.
	 *
	 * @param other The PmergeMe object to copy
	 */
	PmergeMe(const PmergeMe& other);

	/**
	 * @brief Copy assignment operator
	 *
	 * Assigns the contents of another PmergeMe object to this one.
	 *
	 * @param other The PmergeMe object to assign from
	 * @return Reference to this object
	 */
	PmergeMe& operator=(const PmergeMe& other);

	/**
	 * @brief Destructor
	 *
	 * Cleans up resources (containers clean themselves up automatically).
	 */
	~PmergeMe();

	/**
	 * @brief Parses and validates command-line arguments
	 *
	 * Reads positive integers from argv, validates them, and stores
	 * them in both vector and deque containers.
	 *
	 * Validation rules:
	 * - Only positive integers allowed
	 * - No negative numbers or non-numeric input
	 * - Values must be within int range
	 *
	 * @param argc Number of command-line arguments
	 * @param argv Array of command-line argument strings
	 * @throw InvalidArgumentException if validation fails
	 */
	void parseInput(int argc, char** argv);

	/**
	 * @brief Sorts both containers and measures execution time
	 *
	 * Executes the Ford-Johnson algorithm on both vector and deque,
	 * measures the time taken for each, and displays the results.
	 * Times are displayed in microseconds (us).
	 */
	void sort();

	/**
	 * @brief Displays the unsorted sequence
	 *
	 * Shows the first 4 elements of the unsorted vector, followed
	 * by "[...]" if there are more elements.
	 * Format: "Before: 3 5 9 7 [...]"
	 */
	void displayBefore() const;

	/**
	 * @brief Displays the sorted sequence
	 *
	 * Shows the first 4 elements of the sorted vector, followed
	 * by "[...]" if there are more elements.
	 * Format: "After:  3 4 5 7 [...]"
	 */
	void displayAfter() const;

	/**
	 * @class InvalidArgumentException
	 * @brief Exception thrown for invalid input arguments
	 *
	 * Thrown when:
	 * - No arguments provided
	 * - Negative numbers detected
	 * - Non-numeric input found
	 * - Values out of valid range
	 */
	class InvalidArgumentException : public std::exception {
		public:
			/**
			 * @brief Returns the error message
			 * @return "Error" string
			 */
			virtual const char* what() const throw();
	};
};

#endif

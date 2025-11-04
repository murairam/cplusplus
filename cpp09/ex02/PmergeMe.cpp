/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:47:12 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/11/03 16:47:13 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"
#include <iomanip>

/* ************************************************************************** */
/*                        Orthodox Canonical Form                             */
/* ************************************************************************** */

/**
 * @brief Default constructor - initializes empty containers
 */
PmergeMe::PmergeMe() {}

/**
 * @brief Copy constructor - performs deep copy of both containers
 */
PmergeMe::PmergeMe(const PmergeMe& other) : _vector(other._vector), _deque(other._deque) {}

/**
 * @brief Assignment operator - handles self-assignment and copies containers
 */
PmergeMe& PmergeMe::operator=(const PmergeMe& other) {
	if (this != &other) {
		_vector = other._vector;
		_deque = other._deque;
	}
	return *this;
}

/**
 * @brief Destructor - containers automatically clean up their memory
 */
PmergeMe::~PmergeMe() {}

/* ************************************************************************** */
/*                             Exception Class                                */
/* ************************************************************************** */

/**
 * @brief Returns error message as required by subject
 * @return Simple "Error" string as per PDF specification
 */
const char* PmergeMe::InvalidArgumentException::what() const throw() {
	return "Error";
}

/* ************************************************************************** */
/*                      Binary Insertion Functions                            */
/* ************************************************************************** */

/**
 * @brief Binary search insertion for std::vector
 *
 * Uses binary search to find the correct insertion position in O(log n) time,
 * then inserts the element. This is a key part of the Ford-Johnson algorithm
 * which minimizes comparisons.
 *
 * How it works:
 * 1. Binary search narrows down the insertion point
 * 2. Each iteration halves the search space
 * 3. Inserts when the correct position is found
 *
 * @param data The vector to insert into
 * @param start Beginning of search range
 * @param end End of search range (one past last element)
 * @param value The value to insert
 * @return Iterator pointing to newly inserted element
 *
 * Time complexity: O(log n) search + O(n) insertion = O(n)
 */
std::vector<int>::iterator PmergeMe::binaryInsertVector(std::vector<int>& data,
	std::vector<int>::iterator start, std::vector<int>::iterator end, int value) {

	std::vector<int>::iterator low = start;
	std::vector<int>::iterator high = end;

	// Binary search for insertion position
	while (low != high) {
		std::vector<int>::iterator mid = low;
		std::advance(mid, std::distance(low, high) / 2);
		if (*mid < value)
			low = ++mid;	// Search right half
		else
			high = mid;		// Search left half
	}
	return data.insert(low, value);
}

/**
 * @brief Binary search insertion for std::deque
 *
 * Identical algorithm to binaryInsertVector but operates on deque.
 * Implemented separately (not as template) as advised in the subject PDF.
 *
 * Deque may have different performance characteristics:
 * - Better insertion at both ends
 * - Potentially more overhead for random access
 *
 * @param data The deque to insert into
 * @param start Beginning of search range
 * @param end End of search range
 * @param value The value to insert
 * @return Iterator pointing to newly inserted element
 */
std::deque<int>::iterator PmergeMe::binaryInsertDeque(std::deque<int>& data,
	std::deque<int>::iterator start, std::deque<int>::iterator end, int value) {

	std::deque<int>::iterator low = start;
	std::deque<int>::iterator high = end;

	// Binary search for insertion position
	while (low != high) {
		std::deque<int>::iterator mid = low;
		std::advance(mid, std::distance(low, high) / 2);
		if (*mid < value)
			low = ++mid;
		else
			high = mid;
	}
	return data.insert(low, value);
}

/* ************************************************************************** */
/*                     Ford-Johnson Algorithm - Vector                        */
/* ************************************************************************** */

/**
 * @brief Ford-Johnson merge-insertion sort for std::vector
 *
 * The Ford-Johnson algorithm (1959) minimizes the number of comparisons
 * needed to sort a sequence. It's optimal for small sequences.
 *
 * Algorithm overview:
 * 1. Group elements into pairs
 * 2. Compare and order within each pair (larger element first)
 * 3. Sort the larger elements (creates a sorted "main chain")
 * 4. Insert smaller elements using binary insertion
 * 5. Handle any leftover element (straggler)
 *
 * Why it's efficient:
 * - Reduces total comparisons compared to naive insertion sort
 * - Binary insertion is O(log n) per element
 * - Works well with small to medium datasets
 *
 * @param data Reference to vector to be sorted in-place
 *
 * Time complexity: O(n log n) on average
 * Space complexity: O(n) for temporary structures
 */
void PmergeMe::fordJohnsonVector(std::vector<int>& data) {
	// Base case: already sorted
	if (data.size() <= 1)
		return;

	// Step 1: Create pairs and sort within pairs (larger first)
	std::vector<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;

	// Pair up elements: [0,1], [2,3], [4,5], ...
	for (size_t i = 0; i + 1 < data.size(); i += 2) {
		if (data[i] > data[i + 1])
			pairs.push_back(std::make_pair(data[i], data[i + 1]));
		else
			pairs.push_back(std::make_pair(data[i + 1], data[i]));
	}

	// Save any odd element for later
	if (data.size() % 2 != 0) {
		straggler = data[data.size() - 1];
		hasStraggler = true;
	}

	if (pairs.empty())
		return;

	// Step 2: Sort pairs by their larger element (first in pair)
	// Using simple insertion sort for clarity
	for (size_t i = 0; i < pairs.size(); i++) {
		for (size_t j = i + 1; j < pairs.size(); j++) {
			if (pairs[i].first > pairs[j].first)
				std::swap(pairs[i], pairs[j]);
		}
	}

	// Step 3: Build main chain (larger elements) and pending list (smaller elements)
	std::vector<int> mainChain;
	std::vector<int> pending;

	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);	// Larger elements form sorted chain
		pending.push_back(pairs[i].second);		// Smaller elements to be inserted
	}

	// Step 4: Insert first pending element at the beginning
	// (it's guaranteed to be smaller than first mainChain element)
	if (!pending.empty()) {
		mainChain.insert(mainChain.begin(), pending[0]);
		pending.erase(pending.begin());
	}

	// Step 5: Insert remaining pending elements using binary insertion
	// Each insertion maintains sorted order
	for (size_t i = 0; i < pending.size(); i++)
		binaryInsertVector(mainChain, mainChain.begin(), mainChain.end(), pending[i]);

	// Step 6: Insert straggler if exists
	if (hasStraggler)
		binaryInsertVector(mainChain, mainChain.begin(), mainChain.end(), straggler);

	// Copy sorted result back to original container
	data = mainChain;
}

/* ************************************************************************** */
/*                     Ford-Johnson Algorithm - Deque                         */
/* ************************************************************************** */

/**
 * @brief Ford-Johnson merge-insertion sort for std::deque
 *
 * Implements the same algorithm as fordJohnsonVector but for deque container.
 * Separated as per subject requirement: "strongly advised to implement your
 * algorithm for each container and thus to avoid using a generic function."
 *
 * Deque (Double-Ended Queue) characteristics:
 * - Fast insertion/removal at both ends: O(1)
 * - Random access: O(1) but slower than vector
 * - Memory: Non-contiguous blocks (vs vector's contiguous)
 *
 * This allows us to compare performance between the two containers.
 *
 * @param data Reference to deque to be sorted in-place
 */
void PmergeMe::fordJohnsonDeque(std::deque<int>& data) {
	if (data.size() <= 1)
		return;

	// Step 1: Create pairs and sort within pairs
	std::vector<std::pair<int, int> > pairs;
	int straggler = -1;
	bool hasStraggler = false;

	for (size_t i = 0; i + 1 < data.size(); i += 2) {
		if (data[i] > data[i + 1])
			pairs.push_back(std::make_pair(data[i], data[i + 1]));
		else
			pairs.push_back(std::make_pair(data[i + 1], data[i]));
	}

	if (data.size() % 2 != 0) {
		straggler = data[data.size() - 1];
		hasStraggler = true;
	}

	if (pairs.empty())
		return;

	// Step 2: Sort pairs by their larger element
	for (size_t i = 0; i < pairs.size(); i++) {
		for (size_t j = i + 1; j < pairs.size(); j++) {
			if (pairs[i].first > pairs[j].first)
				std::swap(pairs[i], pairs[j]);
		}
	}

	// Step 3: Build main chain and pending list
	std::deque<int> mainChain;
	std::vector<int> pending;

	for (size_t i = 0; i < pairs.size(); i++) {
		mainChain.push_back(pairs[i].first);
		pending.push_back(pairs[i].second);
	}

	// Step 4: Insert first pending element at beginning
	// Using push_front() which is O(1) for deque (vs O(n) for vector)
	if (!pending.empty()) {
		mainChain.push_front(pending[0]);
		pending.erase(pending.begin());
	}

	// Step 5: Insert remaining pending elements using binary insertion
	for (size_t i = 0; i < pending.size(); i++)
		binaryInsertDeque(mainChain, mainChain.begin(), mainChain.end(), pending[i]);

	// Step 6: Insert straggler if exists
	if (hasStraggler)
		binaryInsertDeque(mainChain, mainChain.begin(), mainChain.end(), straggler);

	data = mainChain;
}

/* ************************************************************************** */
/*                         Input Parsing & Validation                         */
/* ************************************************************************** */

/**
 * @brief Parses command-line arguments and validates input
 *
 * Reads integers from argv and performs strict validation:
 * - Must be positive integers only
 * - No negative numbers allowed
 * - No non-numeric characters allowed
 * - Must fit in int range (0 to 2147483647)
 *
 * Valid:   "./PmergeMe 3 5 9 7 4"
 * Invalid: "./PmergeMe -1 5" (negative)
 * Invalid: "./PmergeMe 1 2a 3" (non-numeric)
 * Invalid: "./PmergeMe 9999999999" (out of range)
 *
 * Populates both _vector and _deque with the same data for comparison.
 *
 * @param argc Argument count (must be >= 2)
 * @param argv Argument vector (argv[1..n] are the numbers)
 * @throws InvalidArgumentException if validation fails
 */
void PmergeMe::parseInput(int argc, char** argv) {
	if (argc < 2)
		throw InvalidArgumentException();

	for (int i = 1; i < argc; i++) {
		std::string arg = argv[i];

		// Check for empty string or negative sign
		if (arg.empty() || arg[0] == '-')
			throw InvalidArgumentException();

		// Validate: all characters must be digits
		for (size_t j = 0; j < arg.length(); j++) {
			if (!std::isdigit(arg[j]))
				throw InvalidArgumentException();
		}

		// Convert to long to check for overflow
		std::stringstream ss(arg);
		long num;
		ss >> num;

		// Verify within int range
		if (num < 0 || num > 2147483647)
			throw InvalidArgumentException();

		// Store in both containers for comparison
		_vector.push_back(static_cast<int>(num));
		_deque.push_back(static_cast<int>(num));
	}
}

/* ************************************************************************** */
/*                          Sorting & Timing                                  */
/* ************************************************************************** */

/**
 * @brief Executes sorting algorithm on both containers and measures performance
 *
 * Performs the following steps:
 * 1. Sort vector using Ford-Johnson and measure time
 * 2. Sort deque using Ford-Johnson and measure time
 * 3. Display both timings in microseconds
 *
 * Uses clock() from <ctime> for timing:
 * - clock() returns CPU time used
 * - Divided by CLOCKS_PER_SEC to get seconds
 * - Multiplied by 1,000,000 to get microseconds
 *
 * Example output:
 * "Time to process a range of 5 elements with std::vector : 0.00031 us"
 * "Time to process a range of 5 elements with std::deque  : 0.00014 us"
 *
 * The timing includes all operations: pairing, sorting, insertion, copying.
 */
void PmergeMe::sort() {
	// Time vector sorting
	clock_t startVec = clock();
	fordJohnsonVector(_vector);
	clock_t endVec = clock();
	double timeVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC * 1000000;

	// Time deque sorting
	clock_t startDeq = clock();
	fordJohnsonDeque(_deque);
	clock_t endDeq = clock();
	double timeDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC * 1000000;

	// Display results with 5 decimal places
	std::cout << "Time to process a range of " << _vector.size()
	          << " elements with std::vector : " << std::fixed << std::setprecision(5)
	          << timeVec << " us" << std::endl;
	std::cout << "Time to process a range of " << _deque.size()
	          << " elements with std::deque  : " << std::fixed << std::setprecision(5)
	          << timeDeq << " us" << std::endl;
}

/* ************************************************************************** */
/*                           Display Functions                                */
/* ************************************************************************** */

/**
 * @brief Displays the unsorted sequence before sorting
 *
 * Shows up to 4 elements followed by "[...]" if there are more.
 * This gives a preview without cluttering the output with thousands of numbers.
 *
 * Examples:
 * "Before: 3 5 9 7 4"       (if size <= 4)
 * "Before: 3 5 9 7 [...]"   (if size > 4)
 */
void PmergeMe::displayBefore() const {
	std::cout << "Before: ";
	size_t count = _vector.size() <= 4 ? _vector.size() : 4;
	for (size_t i = 0; i < count; i++)
		std::cout << _vector[i] << " ";
	if (_vector.size() > 4)
		std::cout << "[...]";
	std::cout << std::endl;
}

/**
 * @brief Displays the sorted sequence after sorting
 *
 * Shows up to 4 elements followed by "[...]" if there are more.
 * Uses the sorted vector to display results.
 *
 * Examples:
 * "After:  3 4 5 7 9"       (if size <= 4)
 * "After:  1 2 3 4 [...]"   (if size > 4)
 */
void PmergeMe::displayAfter() const {
	std::cout << "After:  ";
	size_t count = _vector.size() <= 4 ? _vector.size() : 4;
	for (size_t i = 0; i < count; i++)
		std::cout << _vector[i] << " ";
	if (_vector.size() > 4)
		std::cout << "[...]";
	std::cout << std::endl;
}

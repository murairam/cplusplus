/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:44:05 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/11/03 13:31:52 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <numeric>
#include <functional>

/**
 * @brief Default constructor
 * Initializes a Span object with capacity of 0 elements
 */
Span::Span() : _N(0), _numbers(){

}

/**
 * @brief Parameterized constructor
 * @param N Maximum number of integers that can be stored
 *
 * Initializes a Span object with capacity to store N integers
 */
Span::Span(unsigned int N) : _N(N), _numbers() {
}

/**
 * @brief Copy constructor
 * @param other The Span object to copy from
 *
 * Creates a deep copy of the Span object including capacity and stored numbers
 */
Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {
}

/**
 * @brief Copy assignment operator
 * @param other The Span object to assign from
 * @return Reference to this Span object
 *
 * Performs deep copy assignment with self-assignment check
 */
Span& Span::operator=(const Span& other){
	if (this == &other)
		return *this;

	_N = other._N;
	_numbers = other._numbers;
	return *this;
}

/**
 * @brief Destructor
 * Cleans up the Span object
 */
Span::~Span(){
}

/**
 * @brief Adds a single number to the Span
 * @param number The integer to add to the container
 * @throws FullContainerException if container already has N elements
 *
 * Stores a single integer in the Span if capacity allows
 */
void Span::addNumber(int number){
	if (_numbers.size() == _N){
		throw FullContainerException();
	}
	_numbers.push_back(number);
}

/**
 * @brief Finds the shortest span between stored numbers
 * @return The minimum difference between any two numbers
 * @throws std::out_of_range if less than 2 elements are stored
 *
 * Sorts the numbers and computes differences between consecutive elements
 * using STL algorithms (std::sort, std::transform, std::min_element).
 * Returns the smallest difference found.
 */
int Span::shortestSpan(){
	if (_numbers.size() < 2){
		throw std::out_of_range("not enough elements to compare");
	}
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());

	std::vector<int> differences(sorted.size() - 1);
	std::transform(sorted.begin() + 1, sorted.end(), sorted.begin(),
	               differences.begin(), std::minus<int>());

	return *std::min_element(differences.begin(), differences.end());
}

/**
 * @brief Finds the longest span between stored numbers
 * @return The maximum difference between any two numbers
 * @throws std::out_of_range if less than 2 elements are stored
 *
 * Uses STL algorithms (std::max_element, std::min_element) to find
 * the difference between the largest and smallest numbers stored.
 */
int Span::longestSpan(){
	if (_numbers.size() < 2){
		throw std::out_of_range("not enough elements to compare");
	}
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

/**
 * @brief Returns exception message for full container
 * @return Descriptive error message
 *
 * Overrides std::exception::what() to provide meaningful error context
 */
const char *Span::FullContainerException::what() const throw(){
	return ("container is full");
}

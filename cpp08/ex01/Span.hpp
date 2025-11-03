#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
#	include <climits>

/**
 * @class Span
 * @brief A container class that stores up to N integers and finds spans
 *
 * Span manages a collection of integers with a fixed maximum capacity.
 * It provides functionality to find the shortest and longest spans (distances)
 * between stored numbers using STL algorithms.
 */
class Span {
	private:
	unsigned int _N;              // Maximum capacity
	std::vector<int> _numbers;    // Container storing the integers

	public:
	// Orthodox Canonical Form
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	// Member functions
	void addNumber(int number);

	int shortestSpan();
	int longestSpan();

	/**
	 * @brief Adds multiple numbers using a range of iterators
	 * @tparam Iterator Iterator type for the range
	 * @param begin Iterator to the beginning of the range
	 * @param end Iterator to the end of the range
	 * @throws FullContainerException if adding range exceeds capacity
	 *
	 * Efficiently adds a sequence of integers from any container
	 * that provides iterators. Validates that total size won't exceed N.
	 */
	template<typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		if (_numbers.size() + std::distance(begin, end) > _N) {
			throw FullContainerException();
		}
		_numbers.insert(_numbers.end(), begin, end);
	}

	/**
	 * @class FullContainerException
	 * @brief Exception thrown when attempting to exceed container capacity
	 */
	class FullContainerException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif

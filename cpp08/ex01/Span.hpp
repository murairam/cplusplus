#ifndef SPAN_HPP
#define SPAN_HPP

# include <iostream>
# include <vector>
# include <algorithm>
# include <exception>
#	include <climits>


class Span {
	private:
	unsigned int _N;
	std::vector<int> _numbers;

	public:
	Span();
	Span(unsigned int N);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	int shortestSpan();
	int longestSpan();

	template<typename Iterator>
	void addRange(Iterator begin, Iterator end) {
		if (_numbers.size() + std::distance(begin, end) > _N) {
			throw FullContainerException();
		}
		_numbers.insert(_numbers.end(), begin, end);
	}

	class FullContainerException : public std::exception
	{
		public:
			virtual const char *what() const throw();
	};
};

#endif

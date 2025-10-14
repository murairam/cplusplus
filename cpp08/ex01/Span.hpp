#ifndef SPAN_HPP
#define SPAN_HPP

class Span {
	private:
	unsigned int _N;

	public:
	Span();
	Span(unsigned int _maxnums);
	Span(const Span& other);
	Span& operator=(const Span& other);
	~Span();

	void addNumber(int number);

	void shortestSpan();
	void longestSpan();

};

#endif

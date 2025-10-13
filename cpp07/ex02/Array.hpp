#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array {
private:
	unsigned int	_size;
	T				*_data;
public:
	Array();
	Array(unsigned int n);
	Array(const Array &other);

	Array &operator=(const Array &other);
	~Array();

	// Non-const version (for modifying)
	T& operator[](unsigned int index) ;

	// Const version (for reading)
	const T& operator[](unsigned int index) const;

	unsigned int size() const;
};

# include "Array.tpp"

#endif

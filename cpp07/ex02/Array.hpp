#ifndef ARRAY_HPP
# define ARRAY_HPP

template<typename T>
class Array {
	private:
	int	_size;
	T *array;
	public:
	Array(){};
	Array(unsigned int n){};
	Array(const Array &other){};

	
	int size(){return _size};



};

#endif

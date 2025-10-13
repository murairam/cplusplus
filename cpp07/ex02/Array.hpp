#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array {
private:
	unsigned int	_size;
	T				*_data;
public:
	Array(): _size(0),_data(NULL) {};
	Array(unsigned int n) : _size(n), _data(NULL) { _data = new T[n];};
	Array(const Array &other) :_size(other._size)
	{
		if(_size == 0){
			_data = NULL;
		} else {
			_data = new T[_size];
		for (unsigned int i = 0; i < _size; i++){
			_data[i] = other._data[i];
		}
		}
	};

	Array &operator=(const Array &other){
		if (this == &other)
			return *this;
		delete[] _data;
		_size = other._size;
		if (_size == 0) {
			_data = NULL;
		} else {
			_data = new T[_size];
			for (unsigned int i = 0; i < _size; i++) {
				_data[i] = other._data[i];
			}
		}
		return *this;
	};
	~Array(){
		delete[] _data;
	};

	// Non-const version (for modifying)
	T& operator[](unsigned int index) {
		if (index >= _size) {
			throw std::out_of_range("index out of bounds");
	}
		return _data[index];
	}

	// Const version (for reading)
	const T& operator[](unsigned int index) const {
		if (index >= _size) {
			throw std::out_of_range("index out of bounds");
		}
		return _data[index];
	}
	unsigned int size()const {return _size;};
};

#endif

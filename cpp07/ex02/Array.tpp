#pragma once

# include <stdexcept>

#include "Array.hpp"
template <typename T>
Array<T>::Array() : _size(0),_data(NULL) {};

template <typename T>
Array<T>::Array(unsigned int n) : _size(n), _data(NULL) { _data = new T[n];};

template <typename T>
Array<T>::Array(const Array &other) :_size(other._size)
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

template <typename T>
Array<T>& Array<T>::operator=(const Array &other){
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

template <typename T>
Array<T>::~Array(){
	delete[] _data;
};

// Non-const version (for modifying)
template <typename T>
T& Array<T>::operator[](unsigned int index) {
	if (index >= _size) {
		throw std::out_of_range("index out of bounds");
}
	return _data[index];
}

// Const version (for reading)
template <typename T>
const T& Array<T>::operator[](unsigned int index) const {
	if (index >= _size) {
		throw std::out_of_range("index out of bounds");
	}
	return _data[index];
}

template <typename T>
unsigned int Array<T>::size()const {return _size;};


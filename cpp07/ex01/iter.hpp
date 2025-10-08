#ifndef ITER_HPP
# define ITER_HPP

#include <cstdlib>
#include <iostream>

template<typename T, typename Func>
void iter(T* arr, size_t length, Func f)
{
	for (size_t i = 0; i < length; i++){
		f(arr[i]);
	}
}

#endif

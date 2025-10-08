#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T& a,T& b){
    T temp = std::move(a);
    a = std::move(b);
    b = std::move(temp);
}

template<typename T>
T max(const T&lhs, const T& rhs){
	return lhs < rhs ? rhs : lhs;
}

template<typename T>
T min(const T&lhs, const T& rhs){
	return lhs > rhs ? rhs : lhs;
}

#endif

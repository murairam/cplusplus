#pragma once

template<typename Iterator>
void addRange(Iterator begin, Iterator end) {
	if (_numbers.size() + std::distance(begin, end) > _N) {
		throw FullContainerException();
	}
	_numbers.insert(_numbers.end(), begin, end);
}

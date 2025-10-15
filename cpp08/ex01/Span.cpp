/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 12:44:05 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/15 13:41:25 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <algorithm>

Span::Span() : _N(0), _numbers(){

}

Span::Span(unsigned int N) : _N(N), _numbers() {
}

Span::Span(const Span& other) : _N(other._N), _numbers(other._numbers) {
}

Span& Span::operator=(const Span& other){
	if (this == &other)
		return *this;

	_N = other._N;
	_numbers = other._numbers;
	return *this;
}
Span::~Span(){
}

void Span::addNumber(int number){
	if (_numbers.size() == _N){
		throw std::out_of_range("array full");
	}
	_numbers.push_back(number);
}

int Span::shortestSpan(){
	if (_numbers.size() < 2){
		throw std::out_of_range("not enough elements to compare");
	}
	std::vector<int> sorted = _numbers;
	std::sort(sorted.begin(), sorted.end());
	int min_diff = INT_MAX;
	for (int i = 0; i < (int)_numbers.size() - 2; i++){
		int diff = sorted[i + 1] - sorted[i];
		if (diff < min_diff){
			min_diff = diff;
		}
	}
	return min_diff;
}
int Span::longestSpan(){
	if (_numbers.size() < 2){
		throw std::out_of_range("not enough elements to compare");
	}
	return *std::max_element(_numbers.begin(), _numbers.end()) - *std::min_element(_numbers.begin(), _numbers.end());
}

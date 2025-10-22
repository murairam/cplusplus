/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 14:47:56 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/16 11:55:10 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"
#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
	Span sp = Span(5);
	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);
	std::cout << sp.shortestSpan() << std::endl;
	std::cout << sp.longestSpan() << std::endl << std::endl;

	std::vector<int> v1;
	int size = 10000000;
	std::srand(time(NULL));
	for (int i = 0; i < size; i++){
		v1.push_back(rand() % (INT_MAX - 1));
	}
	Span span = Span(size);
	try{
		std::cout << "-test 100k numbers-" << std::endl;
		span.addRange(v1.begin(), v1.end());
		std::cout << "short: " << span.shortestSpan() << std::endl;
		std::cout << "long:: " << span.longestSpan() << std::endl;
	}
	catch(std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

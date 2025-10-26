/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:35:55 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/26 15:39:13 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
    std::cout << "=== SUBJECT TEST ===" << std::endl;
    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << mstack.top() << std::endl;

    mstack.pop();
    std::cout << mstack.size() << std::endl;

    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;

    while (it != ite) {
        std::cout << *it << std::endl;
        ++it;
    }
    std::stack<int> s(mstack);

    std::cout << "\n=== COMPARISON WITH LIST ===" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << list.back() << std::endl;
    list.pop_back();
    std::cout << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);

    std::list<int>::iterator it2 = list.begin();
    std::list<int>::iterator ite2 = list.end();
    ++it2;
    --it2;
    while (it2 != ite2) {
        std::cout << *it2 << std::endl;
        ++it2;
    }

    std::cout << "\n=== EXTRA: REVERSE ITERATION ===" << std::endl;
    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
         rit != mstack.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }

    return 0;
}

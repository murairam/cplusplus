/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 15:35:55 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/11/03 13:41:48 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

/**
 * @brief Test subject's required example
 */
void subjectTest() {
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
}

/**
 * @brief Compare MutantStack behavior with std::list
 */
void comparisonTest() {
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
}

/**
 * @brief Test reverse iteration
 */
void reverseIterationTest() {
    std::cout << "\n=== REVERSE ITERATION ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);

    for (MutantStack<int>::reverse_iterator rit = mstack.rbegin();
         rit != mstack.rend(); ++rit) {
        std::cout << *rit << std::endl;
    }
}

/**
 * @brief Test copy constructor and assignment
 */
void copyTest() {
    std::cout << "\n=== COPY CONSTRUCTOR & ASSIGNMENT ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(42);
    mstack.push(100);
    mstack.push(200);

    // Test copy constructor
    MutantStack<int> copy(mstack);
    std::cout << "Original top: " << mstack.top() << std::endl;
    std::cout << "Copy top: " << copy.top() << std::endl;

    // Test assignment operator
    MutantStack<int> assigned;
    assigned = mstack;
    std::cout << "Assigned top: " << assigned.top() << std::endl;

    // Modify copy to ensure deep copy
    copy.push(999);
    std::cout << "After modifying copy:" << std::endl;
    std::cout << "Original size: " << mstack.size() << std::endl;
    std::cout << "Copy size: " << copy.size() << std::endl;
}

/**
 * @brief Test with different types
 */
void differentTypesTest() {
    std::cout << "\n=== TEST WITH STRINGS ===" << std::endl;
    MutantStack<std::string> strStack;
    strStack.push("Hello");
    strStack.push("World");
    strStack.push("MutantStack");

    for (MutantStack<std::string>::iterator it = strStack.begin();
         it != strStack.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

/**
 * @brief Test const iterators
 */
void constIteratorTest() {
    std::cout << "\n=== CONST ITERATOR TEST ===" << std::endl;
    MutantStack<int> mstack;
    mstack.push(10);
    mstack.push(20);
    mstack.push(30);

    const MutantStack<int>& constRef = mstack;
    for (MutantStack<int>::const_iterator it = constRef.begin();
         it != constRef.end(); ++it) {
        std::cout << *it << std::endl;
    }
}

int main() {
    subjectTest();
    comparisonTest();
    reverseIterationTest();
    copyTest();
    differentTypesTest();
    constIteratorTest();

    return 0;
}

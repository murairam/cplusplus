/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 14:29:12 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/11/03 13:41:20 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP
#include <deque>
#include <stack>

/**
 * @class MutantStack
 * @brief An iterable version of std::stack
 * @tparam T Type of elements stored in the stack
 * @tparam Container Underlying container type (default: std::deque<T>)
 *
 * MutantStack extends std::stack to add iterator functionality,
 * making it possible to traverse the stack's elements.
 * It inherits all standard stack operations (push, pop, top, size, empty)
 * and adds bidirectional iteration capabilities.
 *
 * The class exposes the protected member 'c' from std::stack to provide
 * access to the underlying container's iterators.
 */
template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
public:
	// Iterator type definitions
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;

	/**
	 * @brief Returns iterator to the beginning of the stack
	 * @return Iterator pointing to the first element
	 */
	iterator begin() {return this->c.begin();}

	/**
	 * @brief Returns iterator to the end of the stack
	 * @return Iterator pointing past the last element
	 */
	iterator end() { return this->c.end(); }

	/**
	 * @brief Returns const iterator to the beginning of the stack
	 * @return Const iterator pointing to the first element
	 */
	const_iterator begin() const { return this->c.begin(); }

	/**
	 * @brief Returns const iterator to the end of the stack
	 * @return Const iterator pointing past the last element
	 */
	const_iterator end() const { return this->c.end(); }

	/**
	 * @brief Returns reverse iterator to the beginning (top of stack)
	 * @return Reverse iterator pointing to the last element
	 */
	reverse_iterator rbegin() { return this->c.rbegin(); }

	/**
	 * @brief Returns reverse iterator to the end (bottom of stack)
	 * @return Reverse iterator pointing before the first element
	 */
	reverse_iterator rend() { return this->c.rend(); }

	/**
	 * @brief Returns const reverse iterator to the beginning (top of stack)
	 * @return Const reverse iterator pointing to the last element
	 */
	const_reverse_iterator rbegin() const { return this->c.rbegin(); }

	/**
	 * @brief Returns const reverse iterator to the end (bottom of stack)
	 * @return Const reverse iterator pointing before the first element
	 */
	const_reverse_iterator rend() const { return this->c.rend(); }

	// Orthodox Canonical Form

	/**
	 * @brief Default constructor
	 * Constructs an empty MutantStack
	 */
	MutantStack() {};

	/**
	 * @brief Copy constructor
	 * @param other The MutantStack to copy from
	 * Creates a deep copy of the stack
	 */
	MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {};

	/**
	 * @brief Copy assignment operator
	 * @param other The MutantStack to assign from
	 * @return Reference to this MutantStack
	 * Performs deep copy assignment with self-assignment check
	 */
	MutantStack& operator=(const MutantStack& other){
		if (this != &other){
			std::stack<T, Container>::operator=(other);
		}
		return *this;
	};

	/**
	 * @brief Destructor
	 * Cleans up the MutantStack
	 */
	~MutantStack() {};

};

#endif



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:41:59 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 17:42:00 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BASE_HPP
#define BASE_HPP

// Base class with public virtual destructor only
class Base {
public:
    virtual ~Base();
};

// Three empty classes that inherit from Base
class A : public Base {
};

class B : public Base {
};

class C : public Base {
};

// Function declarations
Base* generate(void);
void identify(Base* p);
void identify(Base& p);

#endif

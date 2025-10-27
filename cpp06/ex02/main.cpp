/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:41:57 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 17:41:58 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>

int main() {
    
    // Test 1: Basic random generation and identification
    std::cout << "\n=== Random Generation Test ===\n";
    for (int i = 0; i < 3; i++) {
        Base* obj = generate();
        std::cout << "Pointer identify: ";
        identify(obj);
        std::cout << "Reference identify: ";
        identify(*obj);
        delete obj;
        std::cout << std::endl;
    }
    
    // Test 2: Direct type creation
    std::cout << "=== Direct Type Creation ===\n";
    A* a = new A();
    B* b = new B();
    C* c = new C();
    
    std::cout << "A -> ";
    identify(a);
    std::cout << "B -> ";
    identify(b);
    std::cout << "C -> ";
    identify(c);
    
    delete a;
    delete b;
    delete c;
    
    // Test 3: Polymorphism (Base pointers to different types)
    std::cout << "\n=== Polymorphism Test ===\n";
    Base* polymorphic[3];
    polymorphic[0] = new A();
    polymorphic[1] = new B();
    polymorphic[2] = new C();
    
    for (int i = 0; i < 3; i++) {
        std::cout << "Base[" << i << "] -> ";
        identify(polymorphic[i]);
        delete polymorphic[i];
    }
    
    // Test 4: Error handling
    std::cout << "\n=== Error Test ===\n";
    Base* nullPtr = NULL;
    identify(nullPtr);
    
    return 0;
}

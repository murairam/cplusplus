#include "Base.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>

// Base class destructor implementation
Base::~Base() {
}

// Generate function - randomly instantiates A, B, or C
Base* generate(void) {
    std::srand(std::time(NULL));  // Simple seeding each time (acceptable for this exercise)
    
    int random = std::rand() % 3;
    
    switch (random) {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
        default:
            return new C();
    }
}

// Identify function using pointer
void identify(Base* p) {
    if (p == NULL) {
        std::cout << "Error: NULL pointer" << std::endl;
        return;
    }
    
    // Try to dynamic_cast to each type
    if (dynamic_cast<A*>(p)) {
        std::cout << "A" << std::endl;
    } else if (dynamic_cast<B*>(p)) {
        std::cout << "B" << std::endl;
    } else if (dynamic_cast<C*>(p)) {
        std::cout << "C" << std::endl;
    } else {
        std::cout << "Unknown type" << std::endl;
    }
}

// Identify function using reference (no pointers allowed inside)
void identify(Base& p) {
    // Since we can't use pointers, we use dynamic_cast with references
    // If the cast fails, it throws std::bad_cast exception
    
    try {
        A& a = dynamic_cast<A&>(p);
        (void)a; // Suppress unused variable warning
        std::cout << "A" << std::endl;
        return;
    } catch (std::exception&) {
        // Not type A, continue
    }
    
    try {
        B& b = dynamic_cast<B&>(p);
        (void)b; // Suppress unused variable warning
        std::cout << "B" << std::endl;
        return;
    } catch (std::exception&) {
        // Not type B, continue
    }
    
    try {
        C& c = dynamic_cast<C&>(p);
        (void)c; // Suppress unused variable warning
        std::cout << "C" << std::endl;
        return;
    } catch (std::exception&) {
        // Not type C either
        std::cout << "Unknown type" << std::endl;
    }
}

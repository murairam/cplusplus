#include "Bureaucrat.hpp"

#include <iostream>
#include <string>

int main(){
    std::cout << "=== Test 1: Valid Bureaucrat Creation ===" << std::endl;
    try {
        Bureaucrat alice("Alice", 50);
        std::cout << alice << std::endl;
        
        alice.incrementGrade();  // 50 -> 49 (better)
        std::cout << "After increment: " << alice << std::endl;
        
        alice.decrementGrade();  // 49 -> 50 (worse) 
        std::cout << "After decrement: " << alice << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    std::cout << "=== Test 2: Costructor grade too high===" << std::endl;
    try {
        Bureaucrat bob("bob", 0);
        std::cout << bob << std::endl;
        
        bob.incrementGrade();  
        std::cout << "After increment: " << bob << std::endl;
        
        bob.decrementGrade(); 
        std::cout << "After decrement: " << bob << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
    std::cout << "=== Test 3: Costructor grade too low===" << std::endl;
    try {
        Bureaucrat steve("steve", 152);
        std::cout << steve << std::endl;
        
        steve.incrementGrade();  
        std::cout << "After increment: " << steve << std::endl;
        
        steve.decrementGrade(); 
        std::cout << "After decrement: " << steve << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test 4: incr boundary test===" << std::endl;
    try {
        Bureaucrat jane("jane", 1);
        std::cout << jane << std::endl;
        
        jane.incrementGrade();  
        std::cout << "After increment: " << jane << std::endl;
        
        jane.decrementGrade(); 
        std::cout << "After decrement: " << jane << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    std::cout << "=== Test 5: decr boundary test===" << std::endl;
    try {
        Bureaucrat lisa("lisa", 150);
        std::cout << lisa << std::endl;

        lisa.decrementGrade(); 
        std::cout << "After decrement: " << lisa << std::endl;

        lisa.incrementGrade();  
        std::cout << "After increment: " << lisa << std::endl;
    }
    catch (std::exception & e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }


    return 0;
}
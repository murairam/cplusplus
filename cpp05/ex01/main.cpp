#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Test 1: Valid Form Creation ===" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 25);
        std::cout << taxForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "=== Test 2: Successful Signing ===" << std::endl;
    try {
        Form easyForm("Easy Form", 100, 50);  // Low requirements
        Bureaucrat manager("Manager", 50);    // High grade (qualified)
        
        std::cout << "Before: " << easyForm << std::endl;
        manager.signForm(easyForm);
        std::cout << "After: " << easyForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "=== Test 3: Failed Signing ===" << std::endl;
    try {
        Form hardForm("Hard Form", 10, 5);    // High requirements  
        Bureaucrat intern("Intern", 100);     // Low grade (unqualified)
        
        std::cout << "Before: " << hardForm << std::endl;
        intern.signForm(hardForm);
        std::cout << "After: " << hardForm << std::endl;
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    std::cout << "=== Test 4: Invalid Form Grades ===" << std::endl;
    try {
        Form invalidForm("Invalid", 0, 50);  // Grade too high
    }
    catch (std::exception& e) {
        std::cout << "Caught: " << e.what() << std::endl;
    }
    std::cout << "=== Test 5: Copy Operations ===" << std::endl;
    Form original("Original", 75, 50);
    Form copy(original);
    std::cout << "Copy: " << copy << std::endl;
    return 0;
}
// main.cpp

#include <iostream>
#include <string>

int main() {
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;   // pointer to brain
    std::string& stringREF = brain;    // reference to brain

    std::cout << "Memory address of brain:      " << &brain << std::endl;
    std::cout << "Memory address held by PTR:   " << stringPTR << std::endl;
    std::cout << "Memory address held by REF:   " << &stringREF << std::endl;

    std::cout << "Value of brain:               " << brain << std::endl;
    std::cout << "Value pointed to by PTR:      " << *stringPTR << std::endl;
    std::cout << "Value pointed to by REF:      " << stringREF << std::endl;
    return 0;
}

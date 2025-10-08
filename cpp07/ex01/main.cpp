#include "iter.hpp"
#include <iostream>
#include <string>

// Function taking const reference
void print(const int& x) {
    std::cout << x << " ";
}

// Function taking non-const reference
void increment(int& x) {
    x++;
}

// Generic template function
template<typename T>
void display(const T& x) {
    std::cout << x << " ";
}

void multiplyByTwo(const int& x) {
    std::cout << x * 2 << " ";
}

int main() {
    // Test with int array
    int numbers[] = {1, 2, 3, 4, 5};

    std::cout << "Original: ";
    iter(numbers, 5, print);
    std::cout << std::endl;

    iter(numbers, 5, increment);

    std::cout << "After increment: ";
    iter(numbers, 5, print);
    std::cout << std::endl;

    // Test with string array
    std::string words[] = {"Hello", "World", "42"};
    iter(words, 3, display<std::string>);
    std::cout << std::endl;

    // Test multiplication
    iter(numbers, 5, multiplyByTwo);
    std::cout << std::endl;

    // Test with const array
    const int constNumbers[] = {10, 20, 30};
    iter(constNumbers, 3, print);
    std::cout << std::endl;

    return 0;
}

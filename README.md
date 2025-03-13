This repository contains all c++ modules of 42 school common core

module 00
ex00
goal: write a program that converts input into uppercase, if no input then it prints a " * LOUD AND UNBEARABLE FEEDBACK NOISE * "

libraries used
iostream - standard input-output library
cctype (for *toupper* function)

new terms used
std::cout
	cout (Console Output) is used to print text.
	It's part of the Standard Library (std).
	std::cout stands for "Standard Character Output".

std::endl
	std::endl means "end of line".
	It inserts a new line (\n) and flushes the output buffer.

ex01
create a phonebook of up to 8 contacts
User Commands
ADD → The program asks for details (name, phone number, etc.) and stores them.
SEARCH → The program displays a list of contacts, then asks for an index to show details.
EXIT → Ends the program.

what is a class?
A class is like a blueprint for creating objects.
It defines data (variables) and functions (methods) that operate on that data.

Think of it like:

A blueprint (class) for building houses (objects).
A Car class can define properties like color, brand, and speed, and behaviors like accelerate() and brake().

std::cin
The active selection `std::cin` is a standard input stream in C++ that is used to read input from the standard input device, typically the keyboard. The `std` namespace is part of the C++ Standard Library, and `cin` stands for "character input". It is an object of the `istream` class, which provides various methods to read data of different types.

When you use `std::cin` in your code, you can read input from the user and store it in variables. For example, you can use the extraction operator (`>>`) to read data from `std::cin` and assign it to a variable. This operator skips any leading whitespace and reads the next value of the specified type. Here is a simple example:

```cpp
#include <iostream>

int main() {
    int number;
    std::cout << "Enter a number: ";
    std::cin >> number;
    std::cout << "You entered: " << number << std::endl;
    return 0;
}
```

In this example, the program prompts the user to enter a number, reads the input using `std::cin`, and then prints the entered number. The `std::cin` object ensures that the input is correctly interpreted and stored in the variable `number`.

It's important to handle input errors when using `std::cin`, as invalid input can cause the stream to enter a fail state. You can check the state of the stream using methods like `std::cin.fail()` and clear the error state with `std::cin.clear()`. This ensures that your program can handle unexpected input gracefully.

resources 
https://learn.microsoft.com/en-us/cpp/cpp/namespaces-cpp?view=msvc-170

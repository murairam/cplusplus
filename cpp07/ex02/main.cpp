/* #include <iostream>
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    //SCOPE
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;//
    return 0;
} */

#include "Array.hpp"
#include <iostream>

int main() {
    // Test construction and basic access
    Array<int> arr(5);
    for (unsigned int i = 0; i < arr.size(); i++)
        arr[i] = i * 10;

    // Test copy constructor
    Array<int> copy(arr);
    copy[0] = 999;
    std::cout << "Original: " << arr[0] << ", Copy: " << copy[0] << std::endl;

    // Test assignment operator
    Array<int> assigned;
    assigned = arr;
    assigned[1] = 777;
    std::cout << "Original: " << arr[1] << ", Assigned: " << assigned[1] << std::endl;

    // Test bounds checking
    try {
        arr[99] = 0;
    } catch (std::exception& e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    // Test with strings
    Array<std::string> words(2);
    words[0] = "Hello";
    words[1] = "42";
    std::cout << words[0] << " " << words[1] << std::endl;

    return 0;
}

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
/* 
A **reference to the string** is an alias for the original string variable. In your code:

```cpp
std::string& stringREF = brain;
```

- `stringREF` is a reference to `brain`.
- It does **not** create a new string or copy the value; instead, `stringREF` is just another name for `brain`.
- Any changes made to `stringREF` will affect `brain`, and vice versa.
- A reference must always refer to a valid object and cannot be changed to refer to something else after initialization.

**In summary:**  
A reference is like a constant pointer that is automatically dereferenced and cannot be null. It provides another way to access the same variable. */
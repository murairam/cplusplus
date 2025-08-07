#include <iostream>
#include <string>

int main() {
    std::cout << "=== CPP01 EX02 COMPREHENSIVE TESTS ===" << std::endl;
    
    // Original test
    std::cout << "\n--- Test 1: Original Brain Test ---" << std::endl;
    std::string brain = "HI THIS IS BRAIN";
    std::string* stringPTR = &brain;
    std::string& stringREF = brain;
    
    std::cout << "Memory address of brain:      " << &brain << std::endl;
    std::cout << "Memory address held by PTR:   " << stringPTR << std::endl;
    std::cout << "Memory address held by REF:   " << &stringREF << std::endl;
    std::cout << "Value of brain:               " << brain << std::endl;
    std::cout << "Value pointed to by PTR:      " << *stringPTR << std::endl;
    std::cout << "Value pointed to by REF:      " << stringREF << std::endl;
    
    // Test 2: Modification through pointer
    std::cout << "\n--- Test 2: Modification Through Pointer ---" << std::endl;
    std::string original = "Original String";
    std::string* ptr = &original;
    std::string& ref = original;
    
    std::cout << "Before modification:" << std::endl;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Via PTR:  " << *ptr << std::endl;
    std::cout << "Via REF:  " << ref << std::endl;
    
    *ptr = "Modified via pointer";
    std::cout << "After modifying via pointer:" << std::endl;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Via PTR:  " << *ptr << std::endl;
    std::cout << "Via REF:  " << ref << std::endl;
    
    // Test 3: Modification through reference
    std::cout << "\n--- Test 3: Modification Through Reference ---" << std::endl;
    ref = "Modified via reference";
    std::cout << "After modifying via reference:" << std::endl;
    std::cout << "Original: " << original << std::endl;
    std::cout << "Via PTR:  " << *ptr << std::endl;
    std::cout << "Via REF:  " << ref << std::endl;
    
    // Test 4: Address comparison verification
    std::cout << "\n--- Test 4: Address Verification ---" << std::endl;
    std::cout << "Address of original: " << &original << std::endl;
    std::cout << "Value of ptr:        " << ptr << std::endl;
    std::cout << "Address of ref:      " << &ref << std::endl;
    std::cout << "All addresses equal? " << ((&original == ptr) && (ptr == &ref) ? "YES" : "NO") << std::endl;
    
    // Test 5: Empty string test
    std::cout << "\n--- Test 5: Empty String Test ---" << std::endl;
    std::string empty = "";
    std::string* emptyPtr = &empty;
    std::string& emptyRef = empty;
    
    std::cout << "Empty string address: " << &empty << std::endl;
    std::cout << "Empty ptr address:    " << emptyPtr << std::endl;
    std::cout << "Empty ref address:    " << &emptyRef << std::endl;
    std::cout << "Empty string value:   '" << empty << "'" << std::endl;
    std::cout << "Via ptr:              '" << *emptyPtr << "'" << std::endl;
    std::cout << "Via ref:              '" << emptyRef << "'" << std::endl;
    
    // Test 6: Long string test
    std::cout << "\n--- Test 6: Long String Test ---" << std::endl;
    std::string longStr = "This is a very long string that tests how pointers and references handle larger amounts of data in memory";
    std::string* longPtr = &longStr;
    std::string& longRef = longStr;
    
    std::cout << "Long string length: " << longStr.length() << std::endl;
    std::cout << "Same via ptr:       " << (*longPtr).length() << std::endl;
    std::cout << "Same via ref:       " << longRef.length() << std::endl;
    std::cout << "Addresses match:    " << ((&longStr == longPtr) && (longPtr == &longRef) ? "YES" : "NO") << std::endl;
    
    std::cout << "\n=== KEY LEARNING POINTS ===" << std::endl;
    std::cout << "1. Pointers store memory addresses" << std::endl;
    std::cout << "2. References are aliases to existing variables" << std::endl;
    std::cout << "3. Both point to the same memory location" << std::endl;
    std::cout << "4. Modifications through either affect the original" << std::endl;
    std::cout << "5. References cannot be reassigned, pointers can" << std::endl;
    
    std::cout << "\n=== ALL TESTS COMPLETED ===" << std::endl;
    return 0;
}

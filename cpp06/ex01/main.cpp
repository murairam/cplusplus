#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main(){

    Data student;
    student.name = "bobby";
    student.level = 12;
    student.score = 9000;

    Data* originalPtr = &student;

    std::cout << "ptr value is: " << originalPtr << std::endl;
    
    uintptr_t serializedPtr = Serializer::serialize(originalPtr);
    
    std::cout << "ptr int is: 0x" << std::hex << serializedPtr << std::dec << std::endl;

    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    if (deserializedPtr == originalPtr)
        std::cout << "values match: " << deserializedPtr << " and " << originalPtr << std::endl;
    else
         std::cout << "values dont match: " << deserializedPtr << " and " << originalPtr << std::endl;

    return 0;
}
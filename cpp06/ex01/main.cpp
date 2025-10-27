/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmiilpal <mmiilpal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 17:17:04 by mmiilpal          #+#    #+#             */
/*   Updated: 2025/10/27 17:17:05 by mmiilpal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "Data.hpp"
#include <iostream>

int main() {

    Data student;
    student.name = "bobby";
    student.level = 12;
    student.score = 9000;

    Data* originalPtr = &student;

    std::cout << "ptr value is: " << originalPtr << std::endl;
    
    uintptr_t serializedPtr = Serializer::serialize(originalPtr);

    std::cout << "after serialization, ptr int is: 0x" << std::hex << serializedPtr << std::dec << std::endl;

    Data* deserializedPtr = Serializer::deserialize(serializedPtr);

    std::cout << "after deserialization, ptr value is: " << deserializedPtr << std::endl;

    if (deserializedPtr == originalPtr)
        std::cout << "values match: " << deserializedPtr << " and " << originalPtr << std::endl;
    else
         std::cout << "values dont match: " << deserializedPtr << " and " << originalPtr << std::endl;

    return 0;
}
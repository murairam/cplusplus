#include "Brain.hpp"
#include <iostream>

Brain::Brain(){
    for(int i = 0; i < 100; ++i)
        ideas[i] = "";
    std::cout << "Brain created\n";
}

Brain::Brain(const Brain &other){
    for(int i = 0; i < 100; ++i)
        ideas[i] = other.ideas[i];
    std::cout << "Brain copied\n";
}

Brain &Brain::operator=(const Brain &other) {
    if (this != &other){
        for (int i = 0; i < 100; ++i)
            ideas[i] = other.ideas[i];
    }
    std::cout << "Brain assigned\n";
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain destroyed\n";
}
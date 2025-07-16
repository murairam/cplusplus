#include <iostream>
#include "Fixed.hpp"

#include <iostream>
int main( void ) {
    Fixed a;
    Fixed const b( 10 );
    Fixed const c( 42.42f );
    Fixed const d( b );
    a = Fixed( 1234.4321f );

    std::cout << "a is " << a << std::endl;
    std::cout << "b is " << b << std::endl;
    std::cout << "c is " << c << std::endl;
    std::cout << "d is " << d << std::endl;

    std::cout << "a is " << a.toInt() << " as integer" << std::endl;
    std::cout << "b is " << b.toInt() << " as integer" << std::endl;
    std::cout << "c is " << c.toInt() << " as integer" << std::endl;
    std::cout << "d is " << d.toInt() << " as integer\n" << std::endl;

    std::cout << "a: " << a << ", b: " << b << ", c: " << c << "\n\n";

    std::cout << "a > b:  " << (a > b) << std::endl;
    std::cout << "a < b:  " << (a < b) << std::endl;
    std::cout << "a >= c: " << (a >= c) << std::endl;
    std::cout << "a <= c: " << (a <= c) << std::endl;
    std::cout << "a == c: " << (a == c) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;

    std::cout << "\na + b:  " << (a + b) << std::endl;
    std::cout << "a - b:  " << (a - b) << std::endl;
    std::cout << "a * c: " << (a * c) << std::endl;
    std::cout << "a / c: " << (a / c) << std::endl;

return 0;
}
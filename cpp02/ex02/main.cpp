#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;
	std::cout << b << std::endl;
	std::cout << Fixed::max( a, b ) << std::endl;
	
	return 0;
}

/* int main() {
	std::cout << "\n--- Constructors ---" << std::endl;

	Fixed a(42);             // "Answer to the Ultimate Question"
	Fixed const b(256);      // Buffer overflow classic size
	Fixed const c(3.1415f);  // Pi
	Fixed const d(b);        // Copy constructor test
	a = Fixed(0.0f);         // NULL or zero value

	std::cout << "\n--- getRawBits / setRawBits ---" << std::endl;
	std::cout << "a.getRawBits(): " << a.getRawBits() << std::endl;
	a.setRawBits(512);
	std::cout << "a.getRawBits() after setRawBits(512): " << a.getRawBits() << std::endl;

	std::cout << "\n--- toInt / toFloat ---" << std::endl;
	std::cout << "a.toInt(): " << a.toInt() << std::endl;
	std::cout << "a.toFloat(): " << a.toFloat() << std::endl;

	std::cout << "\n--- Operator << ---" << std::endl;
	std::cout << "a: " << a << std::endl;
	std::cout << "b: " << b << std::endl;
	std::cout << "c: " << c << std::endl;
	std::cout << "d: " << d << std::endl;

	std::cout << "Address of a: " << &a << std::endl;
	std::cout << "Address of b: " << &b << std::endl;
	std::cout << "Address of c: " << &c << std::endl;
	std::cout << "Address of d: " << &d << std::endl;

	std::cout << "\n--- Comparison Operators ---" << std::endl;
	std::cout << "a > b:  " << (a > b) << std::endl;
	std::cout << "a < b:  " << (a < b) << std::endl;
	std::cout << "a >= d: " << (a >= d) << std::endl;
	std::cout << "a <= d: " << (a <= d) << std::endl;
	std::cout << "b == d: " << (b == d) << std::endl;
	std::cout << "b != c: " << (b != c) << std::endl;

	std::cout << "\n--- Arithmetic Operators ---" << std::endl;
	Fixed x(0x2A);    // Hex 42
	Fixed y(-1.0f);   // Typical error return

	std::cout << "[VAR] x = " << x << std::endl;
	std::cout << "[VAR] y = " << y << std::endl;

	std::cout << "\n[EXPR] x + y" << std::endl;
	Fixed sum = x + y;
	std::cout << "Result: " << sum << std::endl;

	std::cout << "\n[EXPR] x - y" << std::endl;
	Fixed diff = x - y;
	std::cout << "Result: " << diff << std::endl;

	std::cout << "\n[EXPR] x * y" << std::endl;
	Fixed prod = x * y;
	std::cout << "Result: " << prod << std::endl;

	std::cout << "\n[EXPR] x / y" << std::endl;
	Fixed quot = x / y;
	std::cout << "Result: " << quot << std::endl;

	std::cout << "\n--- Increment / Decrement ---" << std::endl;
	Fixed inc(1.21f); // Back to the Future: 1.21 gigawatts
	std::cout << "[VAR] inc = " << inc << std::endl;

	std::cout << "\n[EXPR] ++inc (pre-increment)" << std::endl;
	Fixed preInc = ++inc;
	std::cout << "Result: " << preInc << std::endl;
	std::cout << "Current inc: " << inc << std::endl;

	std::cout << "\n[EXPR] inc++ (post-increment)" << std::endl;
	Fixed postInc = inc++;
	std::cout << "Returned: " << postInc << std::endl;
	std::cout << "Current inc: " << inc << std::endl;

	std::cout << "\n[EXPR] --inc (pre-decrement)" << std::endl;
	Fixed preDec = --inc;
	std::cout << "Result: " << preDec << std::endl;
	std::cout << "Current inc: " << inc << std::endl;

	std::cout << "\n[EXPR] inc-- (post-decrement)" << std::endl;
	Fixed postDec = inc--;
	std::cout << "Returned: " << postDec << std::endl;
	std::cout << "Current inc: " << inc << std::endl;

	std::cout << "\n--- min / max ---" << std::endl;
	Fixed m1(1337.0f);     // Leet
	Fixed m2(0.1984f);     // Orwell’s 1984
	const Fixed cm1(1.618f);  // Golden Ratio
	const Fixed cm2(2.718f);  // Euler’s number

	std::cout << "min(m1, m2): " << Fixed::min(m1, m2) << std::endl;
	std::cout << "max(m1, m2): " << Fixed::max(m1, m2) << std::endl;
	std::cout << "min(cm1, cm2): " << Fixed::min(cm1, cm2) << std::endl;
	std::cout << "max(cm1, cm2): " << Fixed::max(cm1, cm2) << std::endl;

	std::cout << "\n--- End of test ---" << std::endl;

	Fixed aa(3.14159f);
	Fixed bb(2.71828f);

	Fixed old_mult = Fixed(aa.toFloat() * bb.toFloat());  // Old way
	Fixed new_mult = aa * bb;  // New optimized way

	std::cout << "Old multiplication: " << old_mult << std::endl;
	std::cout << "New multiplication: " << new_mult << std::endl;
	std::cout << "Difference: " << (new_mult - old_mult).toFloat() << std::endl;
	return 0;
} */


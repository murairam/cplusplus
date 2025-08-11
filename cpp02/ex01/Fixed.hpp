#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int                 _rawBits;
    static const int    _fractionalBits = 8;

public:
    Fixed();                            // Default constructor
    Fixed(const int value);            // New: from int
    Fixed(const float value);          // New: from float
    Fixed(const Fixed& other);         // Copy constructor
    Fixed& operator=(const Fixed& other); // Assignment operator
    ~Fixed();                           // Destructor

    int     getRawBits() const;
    void    setRawBits(int const raw);

    float   toFloat() const;             // New
    int     toInt() const;                 // New
};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed); // << overload

#endif

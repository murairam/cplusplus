#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed {
private:
    int _rawBits;
    static const int _fractionalBits = 8;

public:
    Fixed();                            // Default constructor
    Fixed(const int value);            // New: from int
    Fixed(const float value);          // New: from float
    Fixed(const Fixed& other);         // Copy constructor
    Fixed &operator=(const Fixed& other); // Assignment operator
    ~Fixed();                           // Destructor

    int     getRawBits() const;
    void    setRawBits(int const raw);

    float   toFloat() const;
    int     toInt() const;

    bool    operator>(const Fixed &other) const;
    bool    operator<(const Fixed &other) const;
    bool    operator>=(const Fixed &other) const;
    bool    operator<=(const Fixed &other) const;
    bool    operator==(const Fixed &other) const;
    bool    operator!=(const Fixed &other) const;

    Fixed   operator+(const Fixed &other) const;
    Fixed   operator-(const Fixed &other) const;
    Fixed   operator*(const Fixed &other) const;
    Fixed   operator/(const Fixed &other) const;

    Fixed&  operator++();       // pre-increment
    Fixed   operator++(int);     // post-increment
    Fixed&  operator--();       // pre-decrement
    Fixed   operator--(int);     // post-decrement

    static Fixed& min(Fixed& a, Fixed& b);
    static const Fixed& min(const Fixed& a, const Fixed& b);
    static Fixed& max(Fixed& a, Fixed& b);
    static const Fixed& max(const Fixed& a, const Fixed& b);

};

std::ostream& operator<<(std::ostream& out, const Fixed& fixed); // << overload

#endif

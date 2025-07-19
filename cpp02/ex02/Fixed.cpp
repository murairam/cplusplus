#include "Fixed.hpp"
#include <iostream>
#include <cmath>

Fixed::Fixed() : _rawBits(0) {
    std::cout << "Default constructor called [" << this << "]" << std::endl;
}

Fixed::Fixed(const int value) {
    std::cout << "Int constructor called [" << this << "]" << std::endl;
    this->_rawBits = value << this->_fractionalBits;
}

Fixed::Fixed(const float value) {
    std::cout << "Float constructor called [" << this << "]" << std::endl;
    this->_rawBits = roundf(value * (1 << this->_fractionalBits));
}

Fixed::Fixed(const Fixed& other) {
    std::cout << "Copy constructor called [" << this << "] from [" << &other << "]" << std::endl;
    *this = other;
}

Fixed& Fixed::operator=(const Fixed& other) {
    std::cout << "Copy assignment operator called [" << this << "] from [" << &other << "]" << std::endl;
    if (this != &other)
        this->_rawBits = other.getRawBits();
    return *this;
}

Fixed::~Fixed() {
    std::cout << "Destructor called [" << this << "]" << std::endl;
}

int Fixed::getRawBits() const {
    return this->_rawBits;
}

void Fixed::setRawBits(int const raw) {
    this->_rawBits = raw;
}

float Fixed::toFloat() const {
    return static_cast<float>(this->_rawBits) / (1 << this->_fractionalBits);
}

int Fixed::toInt() const {
    return this->_rawBits >> this->_fractionalBits;
}

// Comparison operators
bool Fixed::operator>(const Fixed& other) const {
    return this->_rawBits > other._rawBits;
}

bool Fixed::operator<(const Fixed& other) const {
    return this->_rawBits < other._rawBits;
}

bool Fixed::operator>=(const Fixed& other) const {
    return this->_rawBits >= other._rawBits;
}

bool Fixed::operator<=(const Fixed& other) const {
    return this->_rawBits <= other._rawBits;
}

bool Fixed::operator==(const Fixed& other) const {
    return this->_rawBits == other._rawBits;
}

bool Fixed::operator!=(const Fixed& other) const {
    return this->_rawBits != other._rawBits;
}

// Arithmetic operators
Fixed Fixed::operator+(const Fixed& other) const {
    return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(const Fixed& other) const {
    return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(const Fixed& other) const {
    return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(const Fixed& other) const {
    if (other.toFloat() == 0) {
        std::cerr << "Error: Division by zero" << std::endl;
        return Fixed();
    }
    return Fixed(this->toFloat() / other.toFloat());
}

// Increment and decrement
Fixed& Fixed::operator++() {
    this->setRawBits(this->getRawBits() + 1);
    return *this;
}

Fixed Fixed::operator++(int) {
    Fixed temp = *this;
    this->setRawBits(this->getRawBits() + 1);
    return temp;
}

Fixed& Fixed::operator--() {
    this->setRawBits(this->getRawBits() - 1);
    return *this;
}

Fixed Fixed::operator--(int) {
    Fixed temp = *this;
    this->setRawBits(this->getRawBits() - 1);
    return temp;
}

// min/max static functions
Fixed& Fixed::min(Fixed& a, Fixed& b) {
    return (a < b) ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
    return (a > b) ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
    return (a > b) ? a : b;
}

// Output stream operator
std::ostream& operator<<(std::ostream& out, const Fixed& fixed) {
    out << fixed.toFloat();
    return out;
}

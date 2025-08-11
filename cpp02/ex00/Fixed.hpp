#ifndef FIXED_HPP
# define FIXED_HPP

class Fixed{
    private:
        int                 _rawBits; // Raw fixed-point value
        static const int    _fractionalBits = 8;    
    public:
        Fixed();
        Fixed(const Fixed &other); // Copy constructor
        Fixed &operator=(const Fixed &other); // Assignment operator
        ~Fixed();

        int     getRawBits(void) const; // Getter for the raw fixed-point value
        void    setRawBits(int const raw); // Setter for the raw fixed-point value
};

# endif
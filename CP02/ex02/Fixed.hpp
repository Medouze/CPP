#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <math.h>

class Fixed
{
private:
	int			_nbr;
	static int	_frac;
public:
	Fixed();
	Fixed(float const n);
	Fixed(int const n);
	~Fixed();
	Fixed(Fixed const &other);
	Fixed&	operator=(Fixed const &other);
	// Comparison operators
	bool operator>(Fixed const &other) const;
	bool operator<(Fixed const &other) const;
	bool operator>=(Fixed const &other) const;
	bool operator<=(Fixed const &other) const;
	bool operator==(Fixed const &other) const;
	bool operator!=(Fixed const &other) const;

	// Arithmetic operators
	Fixed operator+(Fixed const &other) const;
	Fixed operator-(Fixed const &other) const;
	Fixed operator*(Fixed const &other) const;
	Fixed operator/(Fixed const &other) const;

	// Increment/Decrement operators
	Fixed& operator++();
	Fixed operator++(int);
	Fixed& operator--();
	Fixed operator--(int);

	static Fixed& min(Fixed &a, Fixed &b);
    static Fixed const& min(Fixed const &a, Fixed const &b);
    static Fixed& max(Fixed &a, Fixed &b);
    static Fixed const& max(Fixed const &a, Fixed const &b);

	int		getRawBits(void) const;
	void	setRawBits(int const raw); 
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif

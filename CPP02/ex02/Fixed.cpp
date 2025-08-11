#include "Fixed.hpp"

int Fixed::_frac = 8;

Fixed::Fixed(void) : _nbr(0)
{
}
Fixed::~Fixed(void)
{
}

Fixed::Fixed(Fixed const &other)
{
	this->_nbr = other.getRawBits();
}

Fixed::Fixed(int const n) 
{
	this->_nbr = n << this->_frac;
}

Fixed::Fixed(float const n) 
{
	this->_nbr = (int)roundf(n * (1 << this->_frac));
}

Fixed&	Fixed::operator=(Fixed const &other)
{
	if (this != &other)
		this->_nbr = other.getRawBits();
	return *this;
}

float Fixed::toFloat( void ) const
{
	return (float)this->_nbr / (1 << this->_frac);
}

int Fixed::toInt( void ) const
{
	return this->_nbr >> this->_frac;
}

int		Fixed::getRawBits(void) const
{
	return (this->_nbr);
}

void	Fixed::setRawBits(int const raw)
{
	this->_nbr = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& _nbr)
{
	out << _nbr.toFloat();
	return out;
}

bool Fixed::operator>(Fixed const &other) const
{
	return (this->toFloat() > other.toFloat());
}

bool Fixed::operator<(Fixed const &other) const
{
	return (this->toFloat() < other.toFloat());
}

bool Fixed::operator>=(Fixed const &other) const
{
	return (this->toFloat() >= other.toFloat());
}

bool Fixed::operator<=(Fixed const &other) const
{
	return (this->toFloat() <= other.toFloat());
}

bool Fixed::operator==(Fixed const &other) const
{
	return (this->toFloat() == other.toFloat());
}

bool Fixed::operator!=(Fixed const &other) const
{
	return (this->toFloat() != other.toFloat());
}

Fixed Fixed::operator+(Fixed const &other) const
{
	return Fixed(this->toFloat() + other.toFloat());
}

Fixed Fixed::operator-(Fixed const &other) const
{
	return Fixed(this->toFloat() - other.toFloat());
}

Fixed Fixed::operator*(Fixed const &other) const
{
	return Fixed(this->toFloat() * other.toFloat());
}

Fixed Fixed::operator/(Fixed const &other) const
{
	return Fixed(this->toFloat() / other.toFloat());
}

Fixed& Fixed::operator++()
{
	this->_nbr += 1;
	return (*this);
}

Fixed& Fixed::operator--()
{
	this->_nbr -= 1;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed temp = *this;
	this->_nbr += 1;
	return (temp);
}

Fixed Fixed::operator--(int)
{
	Fixed temp = *this;
	this->_nbr -= 1;
	return (temp);
}

Fixed& Fixed::min(Fixed &a, Fixed &b)
{
    return (a < b) ? a : b;
}

Fixed const& Fixed::min(Fixed const &a, Fixed const &b)
{
    return (a < b) ? a : b;
}

Fixed& Fixed::max(Fixed &a, Fixed &b)
{
    return (a > b) ? a : b;
}

Fixed const& Fixed::max(Fixed const &a, Fixed const &b)
{
    return (a > b) ? a : b;
}



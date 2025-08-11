#include "Fixed.hpp"

int Fixed::_frac = 8;

Fixed::Fixed(void) : _nbr(0)
{
	std::cout << "Default constructor called" << std::endl;
}
Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(Fixed const &other)
{
	std::cout << "Copy constructor called" << std::endl;
	this->_nbr = other.getRawBits();
}

Fixed::Fixed(int const n) 
{
	std::cout << "Int constructor called" << std::endl;
	this->_nbr = n << this->_frac;
}

Fixed::Fixed(float const n) 
{
	std::cout << "Float constructor called" << std::endl;
	this->_nbr = (int)roundf(n * (1 << this->_frac));
}

Fixed&	Fixed::operator=(Fixed const &other)
{
	std::cout << "Copy assignement overload called" << std::endl;
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
	std::cout << "getRawBits member function called" << std::endl;
	return (this->_nbr);
}

void	Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	this->_nbr = raw;
}

std::ostream& operator<<(std::ostream& out, const Fixed& _nbr)
{
	out << _nbr.toFloat();
	return out;
}
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

	int		getRawBits(void) const;
	void	setRawBits(int const raw); 
	float	toFloat( void ) const;
	int		toInt( void ) const;
};

std::ostream& operator<<(std::ostream& out, const Fixed& value);

#endif

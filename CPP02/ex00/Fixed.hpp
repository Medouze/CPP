#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int			_nbr;
	static int	_frac;
public:
	Fixed();
	~Fixed();
	Fixed(Fixed const &other);
	Fixed&	operator=(Fixed const &other);

	int		getRawBits(void) const;
	void	setRawBits(int const raw); 
};

#endif

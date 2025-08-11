#ifndef WRONGCAT_HPP
#define WRONGCAT_HPP

#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
private:
public:
	WrongCat();
	~WrongCat();
	WrongCat& operator=(const WrongCat &other);
	WrongCat(const WrongCat &copy);

	void makeSound() const;
};


#endif
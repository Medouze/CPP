#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal()
{
	this->type = "WrongCat";
	std::cout << "WrongCat constructor callled" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy) : WrongAnimal(copy)
{
	std::cout << "WrongCat Copy Constructor called" << std::endl;
	*this = copy;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat destructor called!" << std::endl;
}

void WrongCat::makeSound() const
{
	std::cout << "UUUUUUUUUUUUUUUUUUUUUUUUUUU" << std::endl;
}
#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("default")
{
	std::cout << "WrongAnimal Default Constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy)
{
	std::cout << "WrongAnimal Copy Constructor called" << std::endl;
	*this = copy;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Deconstructor called" << std::endl;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

void WrongAnimal::makeSound() const
{
	std::cout << "WrongAnimal sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
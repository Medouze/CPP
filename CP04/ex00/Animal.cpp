#include "Animal.hpp"

Animal::Animal():type("default")
{
	std::cout << "Animal Default Constructor called" << std::endl;
}

Animal::Animal(const Animal &copy)
{
	std::cout << "Animal Copy Constructor called" << std::endl;
	*this = copy;
}

Animal::~Animal()
{
	std::cout << "Animal Deconstructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	return *this;
}

void Animal::makeSound() const
{
	std::cout << "Unkown animal sound" << std::endl;
}

std::string Animal::getType() const
{
	return (this->type);
}
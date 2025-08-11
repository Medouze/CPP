#include "Cat.hpp"

Cat::Cat() : Animal()
{
	this->type = "Cat";
	this->myBrain = new Brain();
	std::cout << "Cat constructor callled!" << std::endl;
}

Cat::Cat(const Cat &copy) : Animal(copy), myBrain(NULL)
{
	std::cout << "Cat Copy Constructor called" << std::endl;
	*this = copy;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	if (this->myBrain)
		delete myBrain;
	this->myBrain = new Brain(*other.myBrain);
	return *this;
}

Cat::~Cat()
{
	std::cout << "Cat destructor called!" << std::endl;
	delete myBrain;
}

void Cat::setNewIdea(int index, std::string str)
{
    this->myBrain->setNewIdea(index, str);
}

void Cat::getAllIdeas() const
{
    this->myBrain->getAllIdeas();
}

void Cat::getIdea(int index) const
{
    this->myBrain->getIdea(index);
}

void Cat::makeSound() const
{
	std::cout << "Mew mew mew" << std::endl;
}
#include "Dog.hpp"

Dog::Dog() : Animal()
{
	this->type = "Dog";
	this->myBrain = new Brain();
	std::cout << "Dog constructor callled!" << std::endl;
}

Dog::Dog(const Dog &copy) : Animal(copy), myBrain(NULL)
{
	std::cout << "Dog Copy Constructor called" << std::endl;
	*this = copy;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
	this->type = other.type;
	if (this->myBrain)
		delete myBrain;
	this->myBrain = new Brain(*other.myBrain);
	return *this;
}

Dog::~Dog()
{
	std::cout << "Dog destructor called!" << std::endl;
	delete myBrain;
}

void Dog::setNewIdea(int index, std::string str)
{
    this->myBrain->setNewIdea(index, str);
}

void Dog::getAllIdeas() const
{
    this->myBrain->getAllIdeas();
}

void Dog::getIdea(int index) const
{
    this->myBrain->getIdea(index);
}

void Dog::makeSound() const
{
	std::cout << "Wouf wouf" << std::endl;
}
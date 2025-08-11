#include "Brain.hpp"

Brain::Brain()
{
	std::cout << "Brain Default Constructor called" << std::endl;
}

Brain::Brain(const Brain &copy)
{
	std::cout << "Brain Copy Constructor called" << std::endl;
	*this = copy;
}

Brain::~Brain()
{
	std::cout << "Brain Deconstructor called" << std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain Assignation operator called" << std::endl;
	if (this == &other)
		return *this;
    for (int i = 0; i < 100; i++)        
	    this->ideas[i] = other.ideas[i];
	return *this;
}

void Brain::setNewIdea(int index, std::string str)
{
    if (index < 0 || index > 99){
        std::cout << "Wrong index! Select an index between 0 and 99" << std::endl;
        return;
    }
    this->ideas[index] = str;
}

void Brain::getAllIdeas() const
{
    for (int i = 0; i < 100; i++){
        if (!this->ideas[i].empty()) // Delete if u want to see all of the thoughts
            std::cout << i << ": " << this->ideas[i] << std::endl;
    }
}

void Brain::getIdea(int index) const
{
    if (index < 0 || index > 99){
        std::cout << "Wrong index! Select between 0 and 99" << std::endl;
        return;
    }
    std::cout << index << ": " << this->ideas[index] << std::endl;
}

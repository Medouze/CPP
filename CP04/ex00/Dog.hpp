#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"

class Dog : public Animal
{
private:
public:
	Dog();
	~Dog();
	Dog& operator=(const Dog &other);
	Dog(const Dog &copy);

	void makeSound() const;
};


#endif
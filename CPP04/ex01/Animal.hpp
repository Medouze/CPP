#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal
{
	protected:
		std::string type;
	public:
		Animal();
		virtual ~Animal();
		Animal& operator=(const Animal &other);
		Animal(const Animal &copy);
		//getter
		std::string getType() const;
		virtual void makeSound() const;
};

#endif
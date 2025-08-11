#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>

class WrongAnimal
{
	protected:
		std::string type;
	public:
		WrongAnimal();
		virtual ~WrongAnimal();
		WrongAnimal& operator=(const WrongAnimal &other);
		WrongAnimal(const WrongAnimal &copy);
		//getter
		std::string getType() const;
		virtual void makeSound() const;
};

#endif
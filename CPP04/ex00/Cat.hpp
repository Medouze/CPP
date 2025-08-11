#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"

class Cat : public Animal
{
private:
public:
	Cat();
	~Cat();
	Cat& operator=(const Cat &other);
	Cat(const Cat &copy);

	void makeSound() const;
};


#endif
#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal
{
private:
	Brain *myBrain;
public:
	Dog();
	~Dog();
	Dog& operator=(const Dog &other);
	Dog(const Dog &copy);

	void makeSound() const;
	void setNewIdea(int index, std::string str);
    void getAllIdeas() const;
    void getIdea(int index) const;
};


#endif
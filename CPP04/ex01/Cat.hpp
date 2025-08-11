#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal
{
private:
	Brain *myBrain;
public:
	Cat();
	~Cat();
	Cat& operator=(const Cat &other);
	Cat(const Cat &copy);

	void makeSound() const;
	void setNewIdea(int index, std::string str);
    void getAllIdeas() const;
    void getIdea(int index) const;
};


#endif
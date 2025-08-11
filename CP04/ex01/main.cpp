#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();

        delete i;
        delete j;
    }
    std::cout << std::endl << "Delete zoo:" << std::endl;
    {
        Animal *zoo[] = {
            new Dog(),
            new Dog(),
            new Cat(),
            new Cat(),
            NULL
	    };
	
        std::cout << std::endl;
        
        for (int i = 0; zoo[i]; ++i) {
            std::cout << &zoo[i] << " Deleted !" << std::endl;
            delete zoo[i];
            std::cout << std::endl;
        }
    }
    std::cout << std::endl << "Dog and Cat ideas:" << std::endl;
    {
        Dog bob;
        Cat bib;

        bob.setNewIdea(10, "I love steak");
        bob.getIdea(100);
        bob.getIdea(10);
        std::cout << std::endl;
        bob.setNewIdea(98, "I love water !");
        bob.getAllIdeas();

        std::cout << std::endl << std::endl;

        bib.setNewIdea(10, "I love catisfaction !");
        bib.getIdea(-9);
        bib.getIdea(10);
        std::cout << std::endl;
        bib.setNewIdea(98, "I love my owner");
        bib.getAllIdeas();
    }
    std::cout << std::endl << std::endl;
    {
        Dog basic;
        {
        Dog tmp = basic;
        }
    }
    return 0;
}
#include "Cat.hpp"
#include "Dog.hpp"

int main(void) {
    // it cannot be instanced because it's an abstract class
    //const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;
    i->makeSound();
    j->makeSound();

    delete i;
    delete j;

    return 0;
}
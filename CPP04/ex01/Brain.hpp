#ifndef BRAIN_HPP
#define BRAIN_HPP

#include "Animal.hpp"

class Brain
{
private:
    std::string ideas[100];
public:
    Brain();
    ~Brain();
    Brain& operator=(const Brain &other);
	Brain(const Brain &copy);

    void setNewIdea(int index, std::string str);
    void getAllIdeas() const;
    void getIdea(int index) const;
};

#endif 
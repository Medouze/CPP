#include "Zombie.hpp"

void Zombie::announce(void)
{
    std::cout << this->_name << " : " << "BraiiiiiiinnnzzzZ..." << std::endl;
}

Zombie::~Zombie()
{
    std::cout << this->_name << " died !" << std::endl;
}

Zombie::Zombie(std::string name)
{
    this->_name = name;
}

Zombie::Zombie()
{
}

void    Zombie::setName(std::string name)
{
    this->_name = name;
}
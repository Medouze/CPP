#include "Zombie.hpp"

int main(void)
{
    Zombie *newZ = newZombie("test");
    newZ->announce();
    randomChump("Zombie");
    delete newZ;
    return 0;
}

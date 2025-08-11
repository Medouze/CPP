#include "Zombie.hpp"

int main(void)
{
    Zombie *newZ = zombieHorde(10, "Med");
    for (int i = 0; i < 10; i++)
        newZ[i].announce();
    delete[] newZ;
    return 0;
}

#include "Harl.hpp"

int main(int ac, char **av)
{
    if (ac == 2)
    {
        Harl harl = Harl();
        harl.complain(av[1]);
    }
    else
        std::cout << "Enter one argument only" << std::endl;
    return 0;
}

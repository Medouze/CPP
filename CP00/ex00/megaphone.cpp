#include <iostream>
#include <string>

int main(int argc, char const *argv[])
{
    std::string av;
    int i = 1;

    if (argc == 1)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *\n";
    else
    {
        while (i < argc && argv[i])
        {
            int j = 0;
            while (argv[i][j++])
                std::cout << (char)std::toupper(argv[i][j]);
            i++;
        }
        std::cout << std::endl;
    }
    return 0;
}

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc < 2) {
        std::cerr << "Error: No expression provided" << std::endl;
        return 1;
    }else if (argc > 2){
        std::cerr << "Error: Expression should be in quotes and have only one expression" << std::endl;
        return 1;
    }
    RPN calc(argc, argv);
    calc.operation();
    return 0;
}

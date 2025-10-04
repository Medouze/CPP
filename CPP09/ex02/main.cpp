#include "PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2){
        std::cerr << "Error: arguments" << std::endl;
    }
    PmergeMe test;
    PmergeMe test2(argc, argv);
    //test.fillContainers();
    test2.MergeMe();
    return 0;
}

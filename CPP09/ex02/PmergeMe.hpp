#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits.h>
#include <cstdlib>

class PmergeMe
{
    private:
        std::string str;
        std::vector<int> vecMerge;
        std::deque<int> dequeMerge;
    public:
        //Cannonical form
        PmergeMe();
        PmergeMe(int argc, char** argv);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        //Tests
        void printContainers();

        //Parsing
        int validArg();


        //Sort
        void fillContainers();
};


#endif
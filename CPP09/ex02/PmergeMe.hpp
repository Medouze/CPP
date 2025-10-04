#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <vector>
#include <deque>
#include <limits.h>
#include <cstdlib>
#include <utility>
#include <ctime>

class PmergeMe
{
    private:
        std::string str;
        std::vector<int> vecMerge;
        std::deque<int> dequeMerge;
        bool hasOdd;
        int oddElement;
    public:
        //Cannonical form
        PmergeMe();
        PmergeMe(int argc, char** argv);
        PmergeMe(const PmergeMe& other);
        PmergeMe& operator=(const PmergeMe& other);
        ~PmergeMe();

        //Parsing
        int validArg();
        void fillContainers();

        //Helpers
        void printContainers();
        double getFinalTime(clock_t start);
        void finalPrint(clock_t startVec, clock_t endVec, clock_t startDeque, clock_t endDeque);
        std::vector<size_t> generateJacobsthal(size_t max);
        std::vector<size_t> createInsertionOrder(size_t size);

        //Algorithm
        void MergeMe();
        std::vector<int> vecSort();
        std::deque<int> dequeSort();
        std::vector<std::pair<int, int> > pairVecElements();
        std::deque<std::pair<int, int> > pairDequeElements();
        void insertRemainVec(std::vector<int> &firstElements, std::vector<int> &secondeElements);
        void insertRemainDeque(std::deque<int> &firstElements, std::deque<int> &secondeElements);
};


#endif
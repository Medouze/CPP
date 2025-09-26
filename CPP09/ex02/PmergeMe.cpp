#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};
PmergeMe::PmergeMe(int argc, char** argv){
    for (int i = 1; i < argc; i++) {
        if (i > 1) str += " ";
        str += argv[i];
    }
}
PmergeMe::PmergeMe(const PmergeMe& other) : str(other.str), vecMerge(other.vecMerge), dequeMerge(other.dequeMerge){}
PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    if (this != &other){
        vecMerge = other.vecMerge;
        dequeMerge = other.dequeMerge;
        str = other.str;
    }
    return (*this);
}
PmergeMe::~PmergeMe(){}

int PmergeMe::validArg(){
    bool nbr = false;
    for (unsigned int i = 0; i < str.size(); i++){
        if (isdigit(str[i]))
            nbr = true;
        if (!isspace(str[i]) && !isdigit(str[i]))
            return 0;
    }
    return nbr ? 1 : 0;
}

void PmergeMe::printContainers(){
    if (!vecMerge.empty()){
        for (unsigned int i = 0; i < vecMerge.size(); i++){
            std::cout << vecMerge[i] << " "; 
        }
        std::cout << std::endl;
    }
    if (!dequeMerge.empty()){
        for (unsigned int i = 0; i < dequeMerge.size(); i++){
            std::cout << dequeMerge[i] << " "; 
        }
        std::cout << std::endl;
    }
}

void PmergeMe::fillContainers(){
    if (!validArg()){
        std::cerr << "Error: arguments" << std::endl;
        return ;
    }

    std::istringstream iss(str);
    std::string token;
    while (iss >> token){
        long temp = atol(token.c_str());
        if (temp > INT_MAX){
            std::cerr << "Error: Number is too big" << std::endl;
            return;
        }
        int number = static_cast<int>(temp);
        vecMerge.push_back(number);
        dequeMerge.push_back(number);
    }
}


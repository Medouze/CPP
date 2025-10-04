#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : hasOdd(false), oddElement(-1){};
PmergeMe::PmergeMe(int argc, char** argv) : hasOdd(false), oddElement(-1){
    for (int i = 1; i < argc; i++) {
        if (i > 1) str += " ";
        str += argv[i];
    }
}
PmergeMe::PmergeMe(const PmergeMe& other) : str(other.str), vecMerge(other.vecMerge), dequeMerge(other.dequeMerge)
 ,hasOdd(other.hasOdd), oddElement(other.oddElement){}
PmergeMe& PmergeMe::operator=(const PmergeMe& other){
    if (this != &other){
        vecMerge = other.vecMerge;
        dequeMerge = other.dequeMerge;
        str = other.str;
        oddElement = other.oddElement;
        hasOdd = other.hasOdd;
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
    std::cout << "Before vector :   ";
    if (!vecMerge.empty()){
        for (unsigned int i = 0; i < vecMerge.size(); i++){
            std::cout << vecMerge[i] << " "; 
        }
        std::cout << std::endl;
    }
    // std::cout << "Before deque  :   ";
    // if (!dequeMerge.empty()){
    //     for (unsigned int i = 0; i < dequeMerge.size(); i++){
    //         std::cout << dequeMerge[i] << " "; 
    //     }
    //     std::cout << std::endl;
    // }
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

double PmergeMe::getFinalTime(clock_t start){
    clock_t end = clock();
    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000000;
    return duration;
}

std::vector<size_t> PmergeMe::generateJacobsthal(size_t max){
    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while (jacobsthal.back() < max) {
        size_t next = jacobsthal[jacobsthal.size() - 1] + 2 * jacobsthal[jacobsthal.size() - 2];
        jacobsthal.push_back(next);
    }

    return jacobsthal;
}

std::vector<size_t> PmergeMe::createInsertionOrder(size_t size){
    std::vector<size_t> jacobsthal = generateJacobsthal(size);
    std::vector<size_t> insertionOrder;
    std::vector<bool> used(size, false);

    size_t pos = 1;

    while (pos < jacobsthal.size()) {
        size_t current = jacobsthal[pos];
        size_t previous = jacobsthal[pos - 1];

        for (size_t i = current; i > previous; i--) {
            if (i < size) {
                insertionOrder.push_back(i);
                used[i] = true;
            }
        }
        pos++;
    }

    // Add any remaining indices not yet inserted
    for (size_t i = 0; i < size; i++) {
        if (!used[i]) {
            insertionOrder.push_back(i);
        }
    }

    return insertionOrder;
}

std::vector<std::pair<int, int> > PmergeMe::pairVecElements(){
    std::vector<std::pair<int, int> > pairs;

    for (unsigned int i = 0; i < vecMerge.size() - 1; i += 2){
        pairs.push_back(std::make_pair(vecMerge[i], vecMerge[i + 1]));
    }
    if (vecMerge.size() % 2 != 0){
        oddElement = vecMerge[vecMerge.size() - 1];
        hasOdd = true;
    }

    //Sort pairs with larger elemts first
    for (unsigned int i = 0; i < pairs.size(); i++){
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
    for (unsigned int i = 0; i < pairs.size() - 1; i++){
        for (unsigned int j = 0; j < pairs.size() - 1 - i; j++){
            if (pairs[j].first > pairs[j + 1].first){
                std::swap(pairs[j], pairs[j + 1]);
            }
        }
    }
    return pairs;
}

std::deque<std::pair<int, int> > PmergeMe::pairDequeElements(){
    std::deque<std::pair<int, int> > pairs;

    for (unsigned int i = 0; i < dequeMerge.size() - 1; i += 2){
        pairs.push_back(std::make_pair(dequeMerge[i], dequeMerge[i + 1]));
    }

    //Sort pairs with larger elemts first
    for (unsigned int i = 0; i < pairs.size(); i++){
        if (pairs[i].first < pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }
    for (unsigned int i = 0; i < pairs.size() - 1; i++){
        for (unsigned int j = 0; j < pairs.size() - 1 - i; j++){
            if (pairs[j].first > pairs[j + 1].first){
                std::swap(pairs[j], pairs[j + 1]);
            }
        }
    }
    return pairs;
}

void PmergeMe::insertRemainVec(std::vector<int> &firstElements, std::vector<int> &secondElements){
    std::vector<size_t> insertionOrder = createInsertionOrder(secondElements.size());

    for (unsigned int i = 0; i < insertionOrder.size(); i++){
        size_t idx = insertionOrder[i];
        int insertValue = secondElements[idx];

        unsigned int left = 0;
        unsigned int right = firstElements.size();

        while (left < right){
            unsigned int mid = (right + left) / 2;
            if (insertValue < firstElements[mid]){
                right = mid;
            }
            else
                left = mid + 1;
        }
        firstElements.insert(firstElements.begin() + left, insertValue);
    }
    if (hasOdd){
        unsigned int left = 0;
        unsigned int right = firstElements.size();
    
        while (left < right){
            unsigned int mid = (right + left) / 2;
            if (oddElement < firstElements[mid]){
                right = mid;
            }
            else
                left = mid + 1;
        }
        firstElements.insert(firstElements.begin() + left, oddElement);
    }
}

void PmergeMe::insertRemainDeque(std::deque<int> &firstElements, std::deque<int> &secondElements){
      std::vector<size_t> insertionOrder = createInsertionOrder(secondElements.size());

      for (unsigned int i = 0; i < insertionOrder.size(); i++){
          size_t idx = insertionOrder[i];
          int insertValue = secondElements[idx];

          unsigned int left = 0;
          unsigned int right = firstElements.size();

          while (left < right){
              unsigned int mid = (right + left) / 2;
              if (insertValue < firstElements[mid]){
                  right = mid;
              }
              else
                  left = mid + 1;
          }
          firstElements.insert(firstElements.begin() + left, insertValue);
      }
      if (hasOdd){
          unsigned int left = 0;
          unsigned int right = firstElements.size();

          while (left < right){
              unsigned int mid = (right + left) / 2;
              if (oddElement < firstElements[mid]){
                  right = mid;
              }
              else
                  left = mid + 1;
          }
          firstElements.insert(firstElements.begin() + left, oddElement);
      }
  }

std::vector<int> PmergeMe::vecSort(){
    std::vector<std::pair<int, int> > pairs = pairVecElements();

    //Extract first elements of pairs and sort them then insert first smaller element
    std::vector<int> firstElements;

    for (unsigned int i = 0; i < pairs.size(); i++){
        firstElements.push_back(pairs[i].first);
    }
    if (pairs.size() > 0)
        firstElements.insert(firstElements.begin(), pairs[0].second);

    //Create a vector with remaining smaller elements
    std::vector<int> secondElements;
    for (unsigned int i = 1; i < pairs.size(); i++){
        secondElements.push_back(pairs[i].second);
    }

    //Insert remaining elements 
    insertRemainVec(firstElements, secondElements);
    return firstElements;
}

std::deque<int> PmergeMe::dequeSort(){
    std::deque<std::pair<int, int> > pairs = pairDequeElements();

    //Extract first elements of pairs and sort them then insert first smaller element
    std::deque<int> firstElements;

    for (unsigned int i = 0; i < pairs.size(); i++){
        firstElements.push_back(pairs[i].first);
    }
    if (pairs.size() > 0)
        firstElements.insert(firstElements.begin(), pairs[0].second);

    //Create a deque with remaining smaller elements
    std::deque<int> secondElements;
    for (unsigned int i = 1; i < pairs.size(); i++){
        secondElements.push_back(pairs[i].second);
    }

    insertRemainDeque(firstElements, secondElements);
    return firstElements;
}

void PmergeMe::finalPrint(clock_t startVec, clock_t endVec, clock_t startDeque, clock_t endDeque){
    std::cout << "After vector:   ";
    if (!vecMerge.empty()){
        for (unsigned int i = 0; i < vecMerge.size(); i++){
            std::cout << vecMerge[i] << " "; 
        }
        std::cout << std::endl;
    }
    // std::cout << "After deque :   ";
    // if (!dequeMerge.empty()){
    //     for (unsigned int i = 0; i < dequeMerge.size(); i++){
    //         std::cout << dequeMerge[i] << " "; 
    //     }
    //     std::cout << std::endl;
    // }
    double durationVec = (double)(endVec - startVec) / CLOCKS_PER_SEC * 1000000; 
    std::cout << "Time to process a range of " << vecMerge.size() << " elements with std::vector : " << durationVec << " us" << std::endl;
    double durationDeque = (double)(endDeque - startDeque) / CLOCKS_PER_SEC * 1000000; 
    std::cout << "Time to process a range of " << dequeMerge.size() << " elements with std::deque : " << durationDeque << " us" << std::endl;
}

void PmergeMe::MergeMe(){
    fillContainers();
    printContainers();
    clock_t startVec = clock();
    vecMerge = vecSort();
    clock_t endVec = clock();
    clock_t startDeque = clock();
    dequeMerge = dequeSort();
    clock_t endDeque = clock();
    finalPrint(startVec, endVec, startDeque, endDeque);
}


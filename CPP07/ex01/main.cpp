#include "iter.hpp"

void	fctIncrement(int& toAdd) {
	++toAdd;
}

void	fctDecremente(int& toDecrement) {
	--toDecrement;
}

int main() {
    int numbers[5] = {1, 2, 3, 4, 5};
    
    iter(numbers, sizeof(numbers) / sizeof(numbers[0]), &print);
    std::cout << std::endl;
    
    iter(numbers, sizeof(numbers) / sizeof(numbers[0]), &fctIncrement);
    
    iter(numbers, sizeof(numbers) / sizeof(numbers[0]), &print);
    std::cout << std::endl;
    
    iter(numbers, sizeof(numbers) / sizeof(numbers[0]), &fctDecremente);
    
    iter(numbers, sizeof(numbers) / sizeof(numbers[0]), &print);
    std::cout << std::endl;
    
    return 0;
}

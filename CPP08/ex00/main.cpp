#include "easyfind.hpp"

int main()
{
    //Tests with a vector

    std::cout << "VECTOR TESTS" << std::endl;
    std::vector<int> container;
    for (int i = 0; i < 5; i++){
        container.push_back(i);
    }
    try{
        std::vector<int>::iterator it = easyfind(container, 2);
        std::cout << "Found " << *it << std::endl;
    }
    catch(const std::exception&e){
        std::cout << "Error : " << e.what() << std::endl;
    }
    try{
        std::vector<int>::iterator it = easyfind(container, 10);
        std::cout << "Found " << *it << std::endl;
    }
    catch(const std::exception&e){
        std::cout << "Error : " << e.what() << std::endl;
    }

    //Tests with a list

    std::cout << std::endl;
    std::cout << "LIST TESTS" << std::endl;
    std::list<int> lst;
    for (int i = 10; i < 15; i++) {
        lst.push_back(i);
    }
    try {
        std::list<int>::iterator it = easyfind(lst, 12);
        std::cout << "Found " << *it << std::endl;
    } catch(const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    try {
        std::list<int>::iterator it = easyfind(lst, 25);
        std::cout << "Found " << *it << std::endl;
    } catch(const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    //Test with empty container
    std::cout << std::endl;
    std::cout << "EMPTY CONTAINER TEST" << std::endl;
    std::vector<int> emptyVec;
    try {
        std::vector<int>::iterator it = easyfind(emptyVec, 12);
        std::cout << "Found " << *it << std::endl;
    } catch(const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    return 0;
}

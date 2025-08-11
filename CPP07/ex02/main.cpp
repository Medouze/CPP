#include "Array.hpp"

int main()
{
    std::cout << "Test without size" << std::endl;
    Array<int> test;
    std::cout << test.size() << "\n\n";
    try{
        test[0] = 42;
    }
    catch (const std::exception& e){
        std::cerr << "Error : " << e.what() << std::endl;
    }



    std::cout << "Test with size" << std::endl;
    Array<int> test2(42);
    std::cout << test2.size() << std::endl;
    std::cout << test2[2] << std::endl;
    try {
        std::cout << test2[43] << std::endl;
    }
    catch (const std::exception& e){
        std::cerr << "Error : " << e.what() << std::endl;
    }
    try {
        std::cout << test2[41] << std::endl;
    }
    catch (const std::exception& e){
        std::cerr << "Error : " << e.what() << std::endl;
    }
    test2[2] = 55;
    std::cout << test2[2] << "\n\n";


    std::cout << "Test with filled array and his copy and copy constructor" << std::endl;
    Array<int> filledArr(10);
    for (size_t i = 0; i < filledArr.size(); i++){
        filledArr[i] = i;
        std::cout << filledArr[i] << ' ';
    }
    std::cout << std::endl;
    Array<int> copyArr = filledArr;
    Array<int> copyConst(filledArr);
    std::cout << "Operator = print" << std::endl;
    for (size_t i = 0; i < copyArr.size(); i++){
        std::cout << copyArr[i] << ' ';
    }
    std::cout << std::endl;
    std::cout << "Copy constructor print" << std::endl;
    for (size_t i = 0; i < copyArr.size(); i++){
        std::cout << copyConst[i] << ' ';
    }
    std::cout << std::endl;
    copyArr[0] = 42;
    std::cout << "Print after changes in copy = " << std::endl;
    for (size_t i = 0; i < filledArr.size(); i++){
        std::cout << filledArr[i] << ' ';
    }
    std::cout << std::endl;
    for (size_t i = 0; i < copyArr.size(); i++){
        std::cout << copyArr[i] << ' ';
    }
    std::cout << std::endl;
    copyConst[0] = 40;
    std::cout << "Print after changes in copy constructor" << std::endl;
    for (size_t i = 0; i < filledArr.size(); i++){
        std::cout << filledArr[i] << ' ';
    }
    std::cout << std::endl;
    for (size_t i = 0; i < copyConst.size(); i++){
        std::cout << copyConst[i] << ' ';
    }
    std::cout << "\n\n";


    std::cout << "Randoms tests" << std::endl;
    filledArr = filledArr;
    Array<char> charArr(5);
    for (size_t i = 0; i < charArr.size(); i++){
        charArr[i] = i + 65;
        std::cout << charArr[i];
    }
    std::cout << std::endl;
    return 0;
}

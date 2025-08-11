#include "Bureaucrat.hpp"
#include <iostream>

int main() {
    std::cout << "=== Bureaucrat Testing ===" << std::endl;

    // Test 1
    std::cout << "\n1. Testing valid construction:" << std::endl;
    try {
        Bureaucrat alice("Alice", 42);
        Bureaucrat bob("Bob", 1);
        Bureaucrat charlie("Charlie", 150);
        
        std::cout << alice << std::endl;
        std::cout << bob << std::endl;
        std::cout << charlie << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2
    std::cout << "\n2. Testing invalid construction (grade too high):" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 0);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 3
    std::cout << "\n3. Testing invalid construction (grade too low):" << std::endl;
    try {
        Bureaucrat invalid("Invalid", 151);
        std::cout << invalid << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}

#include "Intern.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing Intern Class ===" << std::endl << std::endl;
    
    Intern someRandomIntern;
    AForm* form;
    
    // Test 1: Valid form - robotomy request
    std::cout << "Test 1: Creating robotomy request for Bender" << std::endl;
    form = someRandomIntern.makeForm("robotomy request", "Bender");
    if (form) {
        std::cout << "Success: Form created!" << std::endl;
        std::cout << "Form name: " << form->getName() << std::endl;
        delete form;
    } else {
        std::cout << "Failed: Form is NULL" << std::endl;
    }
    std::cout << std::endl;
    
    // Test 2: Valid form - shrubbery creation
    std::cout << "Test 2: Creating shrubbery creation for Garden" << std::endl;
    form = someRandomIntern.makeForm("shrubbery creation", "Garden");
    if (form) {
        std::cout << "Success: Form created!" << std::endl;
        std::cout << "Form name: " << form->getName() << std::endl;
        delete form;
    } else {
        std::cout << "Failed: Form is NULL" << std::endl;
    }
    std::cout << std::endl;
    
    // Test 3: Valid form - presidential pardon
    std::cout << "Test 3: Creating presidential pardon for Alice" << std::endl;
    form = someRandomIntern.makeForm("presidential pardon", "Alice");
    if (form) {
        std::cout << "Success: Form created!" << std::endl;
        std::cout << "Form name: " << form->getName() << std::endl;
        delete form;
    } else {
        std::cout << "Failed: Form is NULL" << std::endl;
    }
    std::cout << std::endl;
    
    // Test 4: Invalid form name
    std::cout << "Test 4: Creating invalid form" << std::endl;
    form = someRandomIntern.makeForm("invalid form", "Target");
    if (form) {
        std::cout << "Error: Form should be NULL but isn't!" << std::endl;
        delete form;
    } else {
        std::cout << "Success: Correctly returned NULL for invalid form" << std::endl;
    }
    std::cout << std::endl;
    
    // Test 5: Another invalid form name
    std::cout << "Test 5: Creating another invalid form" << std::endl;
    form = someRandomIntern.makeForm("unknown request", "Bob");
    if (form) {
        std::cout << "Error: Form should be NULL but isn't!" << std::endl;
        delete form;
    } else {
        std::cout << "Success: Correctly returned NULL for invalid form" << std::endl;
    }
    std::cout << std::endl;
    
    // Test 6: Copy constructor and assignment operator
    std::cout << "Test 6: Testing copy constructor and assignment operator" << std::endl;
    Intern intern1;
    Intern intern2(intern1);  // Copy constructor
    Intern intern3;
    intern3 = intern1;        // Assignment operator
    
    std::cout << "Copy operations completed successfully (no crashes)" << std::endl;
    
    // Test that all interns work the same
    AForm* form1 = intern1.makeForm("robotomy request", "Test1");
    AForm* form2 = intern2.makeForm("robotomy request", "Test2");
    AForm* form3 = intern3.makeForm("robotomy request", "Test3");
    
    if (form1 && form2 && form3) {
        std::cout << "All intern copies work correctly!" << std::endl;
        delete form1;
        delete form2;
        delete form3;
    }
    
    std::cout << std::endl << "=== All Tests Completed ===" << std::endl;
    
    return 0;
}
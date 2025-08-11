#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
    std::cout << "=== Form and Bureaucrat Testing ===" << std::endl;

    // Test 1: Valid form construction
    std::cout << "\n1. Testing valid form construction:" << std::endl;
    try {
        Form taxForm("Tax Form", 50, 25);
        Form permitForm("Building Permit", 10, 5);
        
        std::cout << taxForm << std::endl;
        std::cout << permitForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 2: Invalid form construction
    std::cout << "\n2. Testing invalid form construction:" << std::endl;
    try {
        Form invalidForm("Invalid Form", 0, 25); // Grade too high
        std::cout << invalidForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    try {
        Form invalidForm2("Invalid Form 2", 25, 151); // Grade too low
        std::cout << invalidForm2 << std::endl;
    } catch (std::exception& e) {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }

    // Test 3: Successful form signing
    std::cout << "\n3. Testing successful form signing:" << std::endl;
    try {
        Bureaucrat alice("Alice", 20);
        Form simpleForm("Simple Form", 50, 30);
        
        std::cout << "Before signing:" << std::endl;
        std::cout << alice << std::endl;
        std::cout << simpleForm << std::endl;
        
        alice.signForm(simpleForm);
        
        std::cout << "After signing:" << std::endl;
        std::cout << simpleForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 4: Failed form signing - grade too low
    std::cout << "\n4. Testing failed form signing (grade too low):" << std::endl;
    try {
        Bureaucrat bob("Bob", 100);
        Form highLevelForm("CEO Authorization", 10, 5);
        
        std::cout << "Before signing attempt:" << std::endl;
        std::cout << bob << std::endl;
        std::cout << highLevelForm << std::endl;
        
        bob.signForm(highLevelForm);
        
        std::cout << "After signing attempt:" << std::endl;
        std::cout << highLevelForm << std::endl;
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 5: Multiple bureaucrats, multiple forms
    std::cout << "\n5. Testing multiple bureaucrats and forms:" << std::endl;
    try {
        Bureaucrat ceo("CEO", 1);
        Bureaucrat manager("Manager", 25);
        Bureaucrat intern("Intern", 149);
        
        Form lowForm("Coffee Request", 150, 150);
        Form midForm("Budget Approval", 50, 30);
        Form highForm("Company Merger", 1, 1);
        
        std::cout << "\n--- Intern tries to sign all forms ---" << std::endl;
        intern.signForm(lowForm);
        intern.signForm(midForm);
        intern.signForm(highForm);
        
        std::cout << "\n--- Manager tries to sign remaining forms ---" << std::endl;
        manager.signForm(midForm);
        manager.signForm(highForm);
        
        std::cout << "\n--- CEO signs the high-level form ---" << std::endl;
        ceo.signForm(highForm);
        
        std::cout << "\n--- Final form states ---" << std::endl;
        std::cout << lowForm << std::endl;
        std::cout << midForm << std::endl;
        std::cout << highForm << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    // Test 6: Form copy and assignment
    std::cout << "\n6. Testing form copy and assignment:" << std::endl;
    try {
        Form original("Original Form", 42, 21);
        Bureaucrat signer("Signer", 30);
        
        signer.signForm(original);
        
        Form copy(original);
        std::cout << "Original: " << original << std::endl;
        std::cout << "Copy: " << copy << std::endl;
        
        Form assigned("Temp", 100, 100);
        assigned = original;
        std::cout << "Assigned: " << assigned << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }

    std::cout << "\n=== All tests completed ===" << std::endl;
    return 0;
}
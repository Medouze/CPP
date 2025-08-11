#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

int main() {
    std::cout << "=== FORM TESTING ===" << std::endl << std::endl;
    
    try {
        // Create bureaucrats with different grades
        Bureaucrat lowGrade("Bob", 150);        // Lowest grade
        Bureaucrat midGrade("Alice", 50);       // Mid grade  
        Bureaucrat highGrade("CEO", 1);         // Highest grade
        
        std::cout << "Created bureaucrats:" << std::endl;
        std::cout << lowGrade << std::endl;
        std::cout << midGrade << std::endl;
        std::cout << highGrade << std::endl << std::endl;
        
        // Create different forms
        ShrubberyCreationForm shrub("home");
        RobotomyRequestForm robot("Wall-e");
        PresidentialPardonForm pardon("Criminal");
        
        std::cout << "Created forms:" << std::endl;
        std::cout << shrub << std::endl;
        std::cout << robot << std::endl;
        std::cout << pardon << std::endl << std::endl;
        
        // Test 1: Try to execute unsigned forms (should fail)
        std::cout << "=== TEST 1: Execute unsigned forms ===" << std::endl;
        highGrade.executeForm(shrub);
        highGrade.executeForm(robot);
        highGrade.executeForm(pardon);
        std::cout << std::endl;
        
        // Test 2: Sign forms with different grade bureaucrats
        std::cout << "=== TEST 2: Signing forms ===" << std::endl;
        
        // Low grade trying to sign (should fail for some)
        std::cout << "Low grade bureaucrat trying to sign:" << std::endl;
        lowGrade.signForm(shrub);    // Should work (needs 145)
        lowGrade.signForm(robot);    // Should fail (needs 72)
        lowGrade.signForm(pardon);   // Should fail (needs 25)
        std::cout << std::endl;
        
        // High grade signing remaining forms
        std::cout << "High grade bureaucrat signing remaining:" << std::endl;
        highGrade.signForm(shrub);
        highGrade.signForm(robot);
        highGrade.signForm(pardon);
        std::cout << std::endl;
        
        // Test 3: Execute signed forms with appropriate grades
        std::cout << "=== TEST 3: Execute signed forms ===" << std::endl;
        
        // Try with low grade (should fail execution)
        std::cout << "Low grade trying to execute:" << std::endl;
        lowGrade.executeForm(shrub);   // Should fail (needs 137)
        std::cout << std::endl;
        
        // Try with appropriate grades
        std::cout << "Appropriate grade executions:" << std::endl;
        midGrade.executeForm(shrub);   // Should work (has 50, needs 137)
        midGrade.executeForm(robot);   // Should work (has 50, needs 45)
        
        // Only highest grade can execute presidential pardon
        highGrade.executeForm(pardon); // Should work (has 1, needs 5)
        std::cout << std::endl;
        
        // Test 4: Multiple robotomy attempts (to see randomness)
        std::cout << "=== TEST 4: Multiple robotomy attempts ===" << std::endl;
        for (int i = 0; i < 5; i++) {
            std::cout << "Attempt " << (i+1) << ": ";
            highGrade.executeForm(robot);
        }
        std::cout << std::endl;
        
        // Test 5: Grade manipulation
        std::cout << "=== TEST 5: Grade manipulation ===" << std::endl;
        Bureaucrat testBureaucrat("Tester", 100);
        std::cout << "Before: " << testBureaucrat << std::endl;
        
        testBureaucrat.incrementGrade();  // Should become 99
        std::cout << "After increment: " << testBureaucrat << std::endl;
        
        testBureaucrat.decrementGrade();  // Should become 100 again
        std::cout << "After decrement: " << testBureaucrat << std::endl;
        std::cout << std::endl;
        
        // Test 6: Exception testing
        std::cout << "=== TEST 6: Exception testing ===" << std::endl;
        try {
            Bureaucrat invalid("Invalid", 0);  // Should throw
        } catch (std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
        try {
            Bureaucrat invalid2("Invalid2", 151);  // Should throw
        } catch (std::exception& e) {
            std::cout << "Caught exception: " << e.what() << std::endl;
        }
        
        std::cout << std::endl << "=== ALL TESTS COMPLETED ===" << std::endl;
        
    } catch (std::exception& e) {
        std::cout << "Unexpected exception: " << e.what() << std::endl;
    }
    
    return 0;
}
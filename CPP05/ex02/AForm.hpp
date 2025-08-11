#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>
#include <exception>

class Bureaucrat; // Forward declaration

class AForm {
    private:
        const std::string _name;
        bool _signed;
        const int _gradeToSign;
        const int _gradeToExecute;

    public:
        // Orthodox Canonical AForm
        AForm();
        AForm(const std::string& name, int gradeToSign, int gradeToExecute);
        AForm(const AForm& other);
        AForm& operator=(const AForm& other);
        virtual ~AForm();

        // Getters
        const std::string& getName() const;
        bool getSigned() const;
        int getGradeToSign() const;
        int getGradeToExecute() const;

        // AForm operations
        void beSigned(const Bureaucrat& bureaucrat);

        //Function to make it abstract
        virtual void execute(const Bureaucrat& executor) const = 0;

        // Exception classes
        class GradeTooHighException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        class GradeTooLowException : public std::exception {
            public:
                virtual const char* what() const throw();
        };

        // Constants
        static const int HIGHEST_GRADE = 1;
        static const int LOWEST_GRADE = 150;

    private:
        void validateGrade(int grade) const;
};

// Insertion operator overload
std::ostream& operator<<(std::ostream& os, const AForm& f);

#endif
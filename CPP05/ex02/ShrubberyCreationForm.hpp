#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
    private:
        std::string target_name;
    public:
        // Orthodox Canonical AForm
        ShrubberyCreationForm(const std::string& target);
        ShrubberyCreationForm(const ShrubberyCreationForm& other);
        ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
        virtual ~ShrubberyCreationForm();

        //Function from parent class
        virtual void execute(const Bureaucrat& executor) const;

        //Grades required to grade / exec
        static const int requiredSign = 145;
        static const int requiredExec = 137;
};

#endif
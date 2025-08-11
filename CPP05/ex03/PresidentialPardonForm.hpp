#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
    private:
        std::string target_name;
    public:
        // Orthodox Canonical AForm
        PresidentialPardonForm(const std::string& target);
        PresidentialPardonForm(const PresidentialPardonForm& other);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& other);
        virtual ~PresidentialPardonForm();

        //Function from parent class
        virtual void execute(const Bureaucrat& executor) const;

        //Grades required to grade / exec
        static const int requiredSign = 25;
        static const int requiredExec = 5;
};

#endif
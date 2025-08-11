#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <string>
#include <exception>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
    private:
        std::string target_name;
    public:
        // Orthodox Canonical AForm
        RobotomyRequestForm(const std::string& target);
        RobotomyRequestForm(const RobotomyRequestForm& other);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
        virtual ~RobotomyRequestForm();

        //Function from parent class
        virtual void execute(const Bureaucrat& executor) const;

        //Grades required to grade / exec
        static const int requiredSign = 72;
        static const int requiredExec = 45;
};

#endif
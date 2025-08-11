#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <stdexcept>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) 
    : AForm("Shruberry Creation", requiredSign, requiredExec), target_name(target){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other) 
    : AForm(other), target_name(other.target_name) {
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target_name = other.target_name;
    }
    return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const {
    if (!getSigned()){
       throw std::runtime_error("Form is not signed");
    }
    if (executor.getGrade() > getGradeToExecute()){
        throw GradeTooLowException();
    }
    std::ofstream file((target_name + "_shrubbery").c_str());
    if (!file.is_open()){
        throw std::runtime_error("Could not create file");
    }
    file    << "    /\\    \n"
            << "   /  \\   \n" 
            << "  /____\\  \n"
            << "    ||    \n";
}


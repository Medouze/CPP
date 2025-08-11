#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <stdexcept> 

PresidentialPardonForm::PresidentialPardonForm(const std::string &target) 
    : AForm("Presidential Pardon", requiredSign, requiredExec), target_name(target){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other) 
    : AForm(other), target_name(other.target_name) {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target_name = other.target_name;
    }
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(const Bureaucrat& executor) const {
    if (!getSigned()){
       throw std::runtime_error("Form is not signed");
    }
    if (executor.getGrade() > getGradeToExecute()){
        throw GradeTooLowException();
    }
    std::cout << target_name << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
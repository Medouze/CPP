#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>  

RobotomyRequestForm::RobotomyRequestForm(const std::string &target) 
    : AForm("Robotomy Request", requiredSign, requiredExec), target_name(target){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other) 
    : AForm(other), target_name(other.target_name) {
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
    if (this != &other) {
        AForm::operator=(other);
        target_name = other.target_name;
    }
    return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    static bool t;
    if (!t)
    {
        srand(time(0));
        t = true;
    }
    if (!getSigned()){
       throw std::runtime_error("Form is not signed");
    }
    if (executor.getGrade() > getGradeToExecute()){
        throw std::runtime_error("grade is too low");
    }
    std::cout << "* DRILLING NOISES * BZZZZT! DRILL DRILL!" << std::endl;
    if (rand() % 2){
        std::cout << target_name << " has been robotomized" << std::endl;
    }else{
        std::cout << "Robotomy failed on " << target_name << std::endl;
    }
}
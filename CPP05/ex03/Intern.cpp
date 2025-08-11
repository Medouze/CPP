#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
    (void)other;
}

Intern& Intern::operator=(const Intern& other) {
    (void)other;
    return *this;
}

Intern::~Intern() {
}

AForm *Intern::makeForm(std::string formName, std::string target){
    std::string forms[] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    int i = 0;
    while (formName != forms[i] && i < 3)
        i++;
    switch(i){
        case 0: std::cout << "Intern creates " << forms[0] << std::endl;
                return (new ShrubberyCreationForm(target));
        case 1: std::cout << "Intern creates " << forms[1] << std::endl;
                return (new RobotomyRequestForm(target));
        case 2: std::cout << "Intern creates " << forms[2] << std::endl;
                return (new PresidentialPardonForm(target));
        default:    std::cout << "Form doesnt exist" << std::endl;
                    return NULL;
    }
}
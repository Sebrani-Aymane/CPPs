#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::Intern() {}


Intern::Intern(const Intern &src) {
    *this = src;
}

Intern& Intern::operator=(const Intern &rhs) {
    (void)rhs;
    return *this;
}
Intern::~Intern() {}

const char* Intern::NoSuchFormException::what() const throw() {
    return "Form name not found";
}

AForm* Intern::makeForm(std::string formName, std::string target) {
    std::string formNames[3] = {
        "shrubbery creation",
        "robotomy request",
        "presidential pardon"
    };
    
    AForm* forms[3] = {
        new ShrubberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    
    for (int i = 0; i < 3; i++) {
        if (formName == formNames[i]) {
            std::cout << "Intern creates " << formName << std::endl;
            return forms[i];
        }
    }
    for (int i = 0; i < 3; i++) {
        delete forms[i];
    }
    throw NoSuchFormException();
}
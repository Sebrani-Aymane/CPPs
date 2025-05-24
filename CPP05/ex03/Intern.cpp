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
    struct FormCreator {
        std::string name;
        AForm* (*create)(const std::string&);
    };

    FormCreator creators[3] = {
        {"shrubbery creation", &Intern::createShrubbery},
        {"robotomy request", &Intern::createRobotomy},
        {"presidential pardon", &Intern::createPresidential}
    };

    for (int i = 0; i < 3; i++) {
        if (formName == creators[i].name) {
            std::cout << "Intern creates " << formName << std::endl;
            return creators[i].create(target);
        }
    }
    throw NoSuchFormException();
}
AForm* Intern::createShrubbery(const std::string& target) {
    return new ShrubberyCreationForm(target);
}
AForm* Intern::createRobotomy(const std::string& target) {
    return new RobotomyRequestForm(target);
}
AForm* Intern::createPresidential(const std::string& target) {
    return new PresidentialPardonForm(target);
}
    
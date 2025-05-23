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
AForm* Intern::
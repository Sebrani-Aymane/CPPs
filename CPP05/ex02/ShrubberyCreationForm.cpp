#include "ShrubberyCreationForm.hpp"
#include <fstream>


ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), target("default") {
    //std::cout << "Default constructor called"<< std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), target(target) {
    //std::cout << "Constructor with target called"<< std::endl;
}
ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target) {
    //std::cout << "Copy constructor called"<< std::endl;
}
ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
    //std::cout << "Copy assignment operator called"<< std::endl;
    if (this != &other)  
        target = other.target;
  
    return *this;
}
ShrubberyCreationForm::~ShrubberyCreationForm() {
    //std::cout << "Destructor called"<< std::endl;
}
void ShrubberyCreationForm::execute(Bureaucrat const &executor) const {
    if (this->getState() == false)
    throw ShrubberyCreationForm::FormNotSignedException();
if (executor.getGrade() > this->getExecuteGrade())
throw ShrubberyCreationForm::GradeTooLowException();

    std ::string name = executor.getName() + "_shrubbery";
    std::ofstream file( name.c_str());
    if (!file.is_open())
        throw FileOpenException();
    file << "         ccee88oo\n";
    file << "      C8O8O8Q8PoOb o8oo\n";
    file << "   dOB69QO8PdUOpugoO9bD\n";
    file << "CgggbU8OU qOp qOdoUOdcb\n";
    file << "    6OuU  /p u gcoUodpP\n";
    file << "      \\\\//  /douUP\n";
    file << "        \\\\////\n";
    file << "         |||/\\\n";
    file << "         |||\\/\n";
    file << "         |||||\n";
    file << "   .....//||||\\....\n";
    file.close();
}
const char *ShrubberyCreationForm::FileOpenException::what() const throw()
{
    return "Coudn t open file";
}
const char *ShrubberyCreationForm::FormNotSignedException::what() const throw()
{
    return "This form is not signed";
}
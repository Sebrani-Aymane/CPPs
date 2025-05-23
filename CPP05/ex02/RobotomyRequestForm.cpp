#include "RobotomyRequestForm.hpp"
#include <iostream>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), target("default") {
   //std::cout << "Default constructor called"<< std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), target(target) {
   //std::cout << "Constructor with target called"<< std::endl;
}
RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target) {
   //std::cout << "Copy constructor called"<< std::endl;
}
RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
   //std::cout << "Copy assignment operator called"<< std::endl;
   if (this != &other)  
       target = other.target;
 
   return *this;
}
RobotomyRequestForm::~RobotomyRequestForm() {
   //std::cout << "Destructor called"<< std::endl;
}
void RobotomyRequestForm::execute(Bureaucrat const &executor) const {
   if (this->getState() == false)
       throw RobotomyRequestForm::FormNotSignedException();
   if (executor.getGrade() > this->getExecuteGrade())
       throw AForm::GradeTooLowException();
   std::cout <<  "Drilling noises..." << std::endl;
   srand(time(NULL));
   if (rand()%2==0)
      std::cout<< executor.getName()<<" has been robotomized successfully" <<std::endl;
   std::cout << executor.getName()<< "robotomy s failed"<<std::endl;

}
const char *RobotomyRequestForm::FormNotSignedException::what() const throw()
{
    return "This form is not signed";
}
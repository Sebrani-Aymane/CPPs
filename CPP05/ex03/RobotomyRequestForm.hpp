#ifndef ROBOTONOMYREQUESTFORM_HPP
#define ROBOTONOMYREQUESTFORM_HPP

#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:
    std::string target; 
public:
    RobotomyRequestForm();
    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    RobotomyRequestForm &operator=(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();

    void execute(Bureaucrat const &executor) const;
    std::string getTarget() const;

        class FormNotSignedException  : public std::exception {
        public:
            const char* what() const throw();
    };

};

#endif
#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{

   private :
   std ::string target;
   bool state;
   

    public:
    PresidentialPardonForm::PresidentialPardonForm(Bureaucrat &target);
    
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &src);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
   void execute(Bureaucrat const &executor);
   bool getState() const;

    class GradeTooHighException : public std::exception
    {
    public:
       virtual const char *what() const throw();
    };

    class GradeTooLowException : public std::exception
    {
    public:
       virtual const char *what()const throw() ;
};
};

#endif
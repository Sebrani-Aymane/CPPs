#ifndef PRESIDENTALPARDONFORM_HPP
#define PRESIDENTALPARDONFORM_HPP

#include "AForm.hpp"

class PresidentialPardonForm : public AForm{

   private :
   std::string target;
   bool state;
   

    public:
    
    PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm &src);
    ~PresidentialPardonForm();
    PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);
   void execute(Bureaucrat const &executor) const;
   std::string getTarget() const;

           class FormNotSignedException  : public std::exception {
        public:
            const char* what() const throw();
    };

   
};

#endif
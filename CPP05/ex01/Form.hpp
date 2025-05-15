#ifndef FORM_HPP
#define FORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;
class Form{
    private:
        std::string const name;
        bool state;
        int const sign_grade;
        int const execute_grade;
    public:
        Form(std::string name,int const si_grade,int const exec_grade);
        
        Form();
        Form(const Form &src);
        ~Form();
        Form &operator=(const Form &rhs);

        std::string getName()const;
        int getSignGrade()const;
        bool getState()const;
        int getExecuteGrade()const;
        void beSigned(Bureaucrat &signer);


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

std::ostream &operator<<(std::ostream &o, Form const &i);

#endif
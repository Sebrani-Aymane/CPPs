#ifndef AFORM_HPP
#define AFORM_HPP

#include <string>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm{
    private:
        std::string const name;
        bool state;
        int const sign_grade;
        int const execute_grade;
    public:
        AForm(std::string name,int const si_grade,int const exec_grade);

        AForm();
        AForm(const AForm &src);
        virtual ~AForm();
        AForm &operator=(const AForm &rhs);

        std::string getName()const;
        int getSignGrade()const;
        bool getState()const;
        int getExecuteGrade()const;
        void beSigned(Bureaucrat &signer);
        virtual void execute(Bureaucrat const &executor)const =0;

           class FormNotSignedException  : public std::exception {
        public:
            const char* what() const throw();
    };
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

std::ostream &operator<<(std::ostream &o, AForm const &i);

#endif
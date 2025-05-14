#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP


#include <iostream>

class Bureaucrat
{
    private:
        const std::string name;
        int grade;
        
    public:
        Bureaucrat();
        Bureaucrat(std::string name, int gradee);
        Bureaucrat(const Bureaucrat &src);
        Bureaucrat &operator=(const Bureaucrat &rhs);
        ~Bureaucrat();
    
        std::string getName() const;
        int getGrade() const;
        void incrementGrade();
        void decrementGrade();
        void signForm();
    
        
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
std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
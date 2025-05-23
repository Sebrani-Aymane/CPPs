#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>



class Intern{
    public :

    Intern();
    ~Intern();
    Intern(const Intern &src);
    Intern& operator=(const Intern &rhs);

    AForm* makeForm(std::string formName,std::string target);
class NoSuchFormException : public std::exception{
    public:
    virtual const char *what()const throw();
};

};


#endif
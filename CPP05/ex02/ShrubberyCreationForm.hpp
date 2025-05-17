#ifndef SHRUBBERYCREATIONFRM_HPP
#define SHRUBBERYCREATIONFRM_HPP

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm{

private:
    std::string target;
public:
    ShrubberyCreationForm();
    ShrubberyCreationForm(std::string target);
    ShrubberyCreationForm(const ShrubberyCreationForm &other);
    ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);
    ~ShrubberyCreationForm();

    void execute(Bureaucrat const &executor) const;
    std::string getTarget() const;
    class FileOpenException : public std::exception {
        public:
            const char* what() const throw();    
    };

};

#endif
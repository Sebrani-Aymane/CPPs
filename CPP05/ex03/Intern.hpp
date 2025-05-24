#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <string>
#include <iostream>

class Intern {
public:
    Intern();
    ~Intern();
    Intern(const Intern &src);
    Intern& operator=(const Intern &rhs);

    AForm* makeForm(std::string formName, std::string target);

    class NoSuchFormException : public std::exception {
    public:
        const char* what() const throw();
    };

    struct FormCreator {
        std::string name;
        AForm* (*create)(const std::string&);
    };

private:
    static AForm* createShrubbery(const std::string& target);
    static AForm* createRobotomy(const std::string& target);
    static AForm* createPresidential(const std::string& target);
};

#endif
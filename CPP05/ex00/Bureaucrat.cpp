/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:23:48 by asebrani          #+#    #+#             */
/*   Updated: 2025/05/05 00:40:36 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(): name("Default")
{
    //std::cout << "Default constructor called" << std::endl;
    grade = 150;
}
Bureaucrat::Bureaucrat(std::string name, int gradee): name(name)
{
    //std::cout << "Parameterized constructor called" << std::endl;
    if (gradee < 1)
        throw Bureaucrat::GradeTooHighException();
    else if (gradee > 150)
        throw Bureaucrat::GradeTooLowException();
    grade = gradee;
}
Bureaucrat::Bureaucrat(const Bureaucrat &src): name(src.name)
{
    
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}
Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->grade = rhs.grade;
    }
    return *this;
}
Bureaucrat::~Bureaucrat()
{
    //std::cout << "Destructor called" << std::endl;
}
std::string Bureaucrat::getName() const
{
    return this->name;
}
int Bureaucrat::getGrade() const
{
    return this->grade;
}
void Bureaucrat::incrementGrade()
{
    if (this->grade <= 1)
        throw Bureaucrat::GradeTooHighException();
    this->grade--;
}
void Bureaucrat::decrementGrade()
{
    if (this->grade >= 150)
        throw Bureaucrat::GradeTooLowException();
    this->grade++;
}

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}
    

const char *Bureaucrat::GradeTooLowException::what() const  throw()
{
    return "Grade is too low";
}
std::ostream &operator<<(std::ostream &o, Bureaucrat const &i) 
{
    o << i.getName() << ", bureaucrat grade " << i.getGrade();
    return o;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:30:40 by asebrani          #+#    #+#             */
/*   Updated: 2025/05/16 01:54:04 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm():target("Bureaucrat")
{
    //std::cout << "Default constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(Bureaucrat &target):target(target.getName())
{
    //std::cout << "Params constructor called" << std::endl;
}
PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src)
{
    
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        return *this;
        this->target = rhs.target;
    }
}

bool PresidentialPardonForm::getState() const
{
    return this->state;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    //std::cout << "Destructor called" << std::endl;
}
const char *PresidentialPardonForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *PresidentialPardonForm::GradeTooLowException::what() const  throw()
{
    return "Grade is too low";
}
void Presidential
std::ostream &operator<<(std::ostream &o, PresidentialPardonForm const &PresidentialPardonForm) 
{
    o << ", PresidentialPardonForm SignGrade is 25 and ExecutionGrade is 5 and it s state is " << PresidentialPardonForm.getState();
    return o;
}
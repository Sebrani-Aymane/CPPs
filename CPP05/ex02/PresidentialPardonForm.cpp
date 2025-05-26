/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:30:40 by asebrani          #+#    #+#             */
/*   Updated: 2025/05/16 22:51:44 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(): AForm("PresidentialPardonForm",25,5),target("Bureaucrat")
{
    //std::cout << "Default constructor called" << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) :AForm(src),target(src.target)
{
    
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
        this->target = rhs.target;
    return *this;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
    //std::cout << "Destructor called" << std::endl;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const{
    if (this->getState() == false)
        throw PresidentialPardonForm::FormNotSignedException();
   if (executor.getGrade() > this->getExecuteGrade())
        throw AForm::GradeTooLowException();
    std::cout << executor << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

const char *PresidentialPardonForm::FormNotSignedException::what() const throw()
{
    return "This form is not signed";
}
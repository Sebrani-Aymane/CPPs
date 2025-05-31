/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 23:30:40 by asebrani          #+#    #+#             */
/*   Updated: 2025/05/15 23:35:59 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(): name("theAForm") ,sign_grade(100),execute_grade(149)
{
    //std::cout << "Default constructor called" << std::endl;
    state = false; 
}
AForm::AForm(std::string name,int const si_grade,int const exec_grade): name(name) ,sign_grade(si_grade),execute_grade(exec_grade)
{
    //std::cout << "Parameterized constructor called" << std::endl;
    state = false;
}
AForm::AForm(const AForm &src): name(src.name),sign_grade(src.sign_grade),execute_grade(src.execute_grade)
{
    
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

AForm &AForm::operator=(const AForm &rhs)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->state = rhs.state;
    }
    return *this;
}
AForm::~AForm()
{
    
}
void AForm::execute(Bureaucrat const &executor)const{
    if (this->getState()==false)
        throw AForm::FormNotSignedException();
     if (executor.getGrade() >this->getExecuteGrade())
        throw AForm::GradeTooLowException();
}
std::string AForm::getName() const
{
    return this->name;
}
int AForm::getSignGrade()const{
    return this->sign_grade;
}
int AForm::getExecuteGrade()const{
    return this->execute_grade;
}
bool AForm::getState() const{
    return this->state;
}
const char *AForm::FormNotSignedException::what() const throw()
{
    return "This form is not signed";
}
void AForm::beSigned(Bureaucrat &signer)
{
    if (this->state ==true)
            std::cout << "Aform is already signed"<<std::endl;
    if (signer.getGrade() <= this->getSignGrade())
    {
        this->state = true;
        std::cout<< this->getName() << " is signed succesfully " <<std::endl;
    }

    else
        throw AForm::GradeTooLowException();

}
const char *AForm::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *AForm::GradeTooLowException::what() const  throw()
{
    return "Grade is too low";
}
std::ostream &operator<<(std::ostream &o, AForm const &Aform) 
{
    o << Aform.getName() << ",SignGrade " << Aform.getSignGrade()<<" and ExecutionGrade "<<Aform.getExecuteGrade()<<" and it s state is "<<Aform.getState();
    return o;
}
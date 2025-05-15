/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 02:20:06 by asebrani          #+#    #+#             */
/*   Updated: 2025/05/15 09:04:12 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(): name("theForm") ,sign_grade(100),execute_grade(149)
{
    //std::cout << "Default constructor called" << std::endl;
    state = false; 
}
Form::Form(std::string name,int const si_grade,int const exec_grade): name(name) ,sign_grade(si_grade),execute_grade(exec_grade)
{
    //std::cout << "Parameterized constructor called" << std::endl;
    state = false;
}
Form::Form(const Form &src): name(src.name),sign_grade(src.sign_grade),execute_grade(src.execute_grade)
{
    
    //std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Form &Form::operator=(const Form &rhs)
{
    //std::cout << "Copy assignment operator called" << std::endl;
    if (this != &rhs)
    {
        this->state = rhs.state;
    }
    return *this;
}
Form::~Form()
{
    //std::cout << "Destructor called" << std::endl;
}
std::string Form::getName() const
{
    return this->name;
}
int Form::getSignGrade()const{
    return this->sign_grade;
}
int Form::getExecuteGrade()const{
    return this->execute_grade;
}
bool Form::getState() const{
    return this->state;
}

void Form::beSigned(Bureaucrat &signer)
{
    if (this->state ==true)
            std::cout << "form is already signed"<<std::endl;
    if (signer.getGrade() >= this->getSignGrade())
        this->state = true;
    else
        throw Form::GradeTooLowException();

}
const char *Form::GradeTooHighException::what() const throw()
{
    return "Grade is too high";
}

const char *Form::GradeTooLowException::what() const  throw()
{
    return "Grade is too low";
}
std::ostream &operator<<(std::ostream &o, Form const &form) 
{
    o << form.getName() << ", Form SignGrade " << form.getSignGrade()<<" and ExecutionGrade "<<form.getExecuteGrade()<<" and it s state is "<<form.getState();
    return o;
}
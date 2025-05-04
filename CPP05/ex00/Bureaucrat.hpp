/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:23:52 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/30 05:21:44 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
    
        
        class GradeTooHighException : public std::exception
        {
        public:
            GradeTooHighException();
            GradeTooHighException(const GradeTooHighException &src);
            GradeTooHighException &operator=(const GradeTooHighException &rhs);
            virtual ~GradeTooHighException() ;
           virtual const char *what() const ;
        };
    
        class GradeTooLowException : public std::exception
        {
        public:
            GradeTooLowException();
            GradeTooLowException(const GradeTooLowException &src);
            GradeTooLowException &operator=(const GradeTooLowException &rhs);
           virtual  ~GradeTooLowException() ;
           virtual const char *what()const throw() ;
    };
};
std::ostream &operator<<(std::ostream &o, Bureaucrat const &i);

#endif
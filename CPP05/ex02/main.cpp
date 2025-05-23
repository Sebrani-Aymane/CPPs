/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 03:02:49 by asebrani          #+#    #+#             */
/*   Updated: 2025/05/15 08:50:30 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"


int main ()
{
    Bureaucrat b1("Bureaucrat", 1);
    Bureaucrat b2("Bureaucrat", 2);
    Bureaucrat b3("Bureaucrat", 3);
    
    Bureaucrat b4("Bureaucrat b4", 1);

    ShrubberyCreationForm shrubberyForm;
    RobotomyRequestForm robotomyForm;
    PresidentialPardonForm presidentialForm;

    std::cout << shrubberyForm << std::endl;
    std::cout << robotomyForm << std::endl;
    std::cout << presidentialForm << std::endl;

    try {
        shrubberyForm.beSigned(b1);
        robotomyForm.beSigned(b2);
        presidentialForm.beSigned(b3);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        presidentialForm.execute(b1);
        robotomyForm.execute(b2);
        shrubberyForm.execute(b4);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
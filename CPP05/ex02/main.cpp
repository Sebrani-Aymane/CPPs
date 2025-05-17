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

#include "Form.hpp"
#include "Bureaucrat.hpp"

int main ()
{
    Bureaucrat b1("Bureaucrat", 1);
    Bureaucrat b2("Bureaucrat", 150);
    Bureaucrat b3("Bureaucrat", 100);
    Bureaucrat b4("Bureaucrat", 50);
    Bureaucrat b5("Bureaucrat", 25);
    Bureaucrat b6("Bureaucrat", 5);

    ShrubberyCreationForm shrubberyForm;
    RobotomyRequestForm robotomyForm;
    PresidentialPardonForm presidentialForm;

    std::cout << "Initial state of forms:" << std::endl;
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
        shrubberyForm.execute(b4);
        robotomyForm.execute(b5);
        presidentialForm.execute(b6);
    } catch (std::exception &e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
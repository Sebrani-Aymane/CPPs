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
#include "Intern.hpp"

int main() {
    Intern Intern;
    Bureaucrat boss("Boss", 1);
    AForm* form;

    // Test creating each valid form
    try {
        form = Intern.makeForm("shrubbery creation", "home");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;

        form = Intern.makeForm("robotomy request", "Bender");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;

        form = Intern.makeForm("presidential pardon", "Zaphod");
        boss.signForm(*form);
        boss.executeForm(*form);
        delete form;

        form = Intern.makeForm("invalid form", "target");
        delete form;
    } 
    catch (const std::exception& e) {
        std::cout << e.what() << std::endl;
        if (form)
            delete form;
    }

    return 0;
}
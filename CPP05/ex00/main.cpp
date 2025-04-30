/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/28 02:23:55 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/28 08:21:14 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
    try
    {
        Bureaucrat a("A", 1);
        std::cout << a << std::endl;
        a.decrementGrade();
        std::cout << a.getGrade() <<std::endl;
        a.incrementGrade();
        std::cout << a.getGrade() <<std::endl;
        a.incrementGrade();
        std::cout << a.getGrade()<<std::endl;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << std::endl;
    }
    try
    {

        Bureaucrat b("B", 151);
        std::cout << b << std::endl;
        b.incrementGrade();
        std::cout << b.getGrade() <<std::endl;
        b.decrementGrade();
        std::cout << b.getGrade() <<std::endl;
        b.decrementGrade();
        std::cout << b.getGrade()<<std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return 0;
}

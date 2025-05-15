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
    try{
        Bureaucrat a("A",99);
        std::cout<< a<<std::endl;
        std::cout <<a.getGrade()<<std::endl;
        Form form;
        std::cout<< form<<std::endl;
        a.signForm(form);
    }
    catch(std::exception &e){
    std::cout <<e.what()<<std::endl;
    }
}
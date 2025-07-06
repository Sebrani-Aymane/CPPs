/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:38:14 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/06 09:35:42 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include "helpers.hpp"

int main(int ac,char **av)
{
    if (ac !=2 )
        return(std::cout << "Usage <./CST> <value> " << std::endl,1);
    std::string input(av[1]);
    ScalarConverter::convert(input);
}

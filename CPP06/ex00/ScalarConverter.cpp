/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:38:08 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/07 16:22:41 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::convert(const std::string& input) {
    if (Helpers::isPseudoLiterals(input)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input<< std::endl;
        std::cout << "double: " << input << std::endl;
        return;
    }
    if (Helpers::getType(input)==true){
        std::cout << "garbage input" << std::endl;
        return;
    }
    double value = strtod(input.c_str(),NULL);
    Helpers::printChar(value);
    Helpers::printInt(value);
    Helpers::printFloat(value);
    Helpers::printDouble(value);
}
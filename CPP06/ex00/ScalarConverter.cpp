/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:38:08 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/06 11:57:15 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

void ScalarConverter::printChar(double value) {
    if (!std::isprint(static_cast<char>(value)))
        std::cout <<"char: non displayable"<< std::endl;
    else if (value < -128|| value > 128 )
        std::cout << "char: impossible" << std::endl;
    else {
        std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
    }
}
void ScalarConverter::printInt(double value) {  
    if (value < -2147483648|| value > 2147483647) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << static_cast<int>(value) << std::endl;
    }
}
void ScalarConverter::printFloat(double value) {
    if (value < std::numeric_limits<float>::min() || value > std::numeric_limits<float>::max()) {
        std::cout << "float: impossible" << std::endl;
    } else {
        std::cout << "float: " << static_cast<float>(value) << "f" << std::endl;
    }
}
void ScalarConverter::printDouble(double value) {
    if (value < std::numeric_limits<double>::min() || value > std::numeric_limits<double>::max()) {
        std::cout << "double: impossible" << std::endl;
    } else {
        std::cout << "double: " << value << std::endl;
    }
}

void ScalarConverter::convert(const std::string& input) {
    if (Helpers::isPseudoLiterals(input)) {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << input << "f" << std::endl;
        std::cout << "double: " << input << std::endl;
        return;
    }
    if (Helpers::getType(input)==true){
        std::cout << "garbage input" << std::endl;
        return;
    }
    double value = strtod(input.c_str(),NULL);
    printChar(value);
    printInt(value);
    printFloat(value);
    printDouble(value);
}
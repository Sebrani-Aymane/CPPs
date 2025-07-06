/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:38:19 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/06 09:33:26 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include "helpers.hpp"
 #include <cstdlib>

class ScalarConverter {
    private :
        ScalarConverter();
    public:
        static void convert(const std::string& input);
        static void printChar(double value);
        static void printInt(double value);
        static void printFloat(double value);
        static void printDouble(double value);
};


#endif
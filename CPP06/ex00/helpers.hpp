/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:40:56 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/07 16:24:20 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <cfloat>
#include <sstream>
#include <iomanip>
#include <cmath>

class Helpers {
public:
   static  bool isPseudoLiterals(const std::string &str);
    static bool isChar(const std::string& input);
    static bool isInt(const std::string& input);
    static bool isFloat(const std::string& input);
    static bool isDouble(const std::string& input);
     static bool isFloatingPoint(const std::string& input);
     static bool getType(const std::string& input);
             static void printChar(double value);
        static void printInt(double value);
        static void printFloat(double value);
        static void printDouble(double value);
};

#endif
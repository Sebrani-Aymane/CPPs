/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:40:56 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/06 11:53:32 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HELPERS_HPP
#define HELPERS_HPP

#include <iostream>
#include <limits>
#include <cmath>
#include <limits>
#include <iomanip>
class Helpers {
public:
   static  bool isPseudoLiterals(const std::string &str);
    static bool isChar(const std::string& input);
    static bool isInt(const std::string& input);
    static bool isFloat(const std::string& input);
    static bool isDouble(const std::string& input);
     static bool isFloatingPoint(const std::string& input);
     static bool getType(const std::string& input);
};

#endif
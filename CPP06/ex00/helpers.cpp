/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:44:34 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/06 11:54:15 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "helpers.hpp"

bool Helpers::isPseudoLiterals(const std::string &str)
{
    if (str == "+inff" || str == "-inff" || str == "nanf" || str == "nan" || str == "+inf" || str == "-inf")
        return true;
    return false;
}

bool Helpers::isChar(const std::string& input) {
    return input.length() == 1 && std::isprint(input[0]);
}

bool Helpers::isInt(const std::string& input) {
    if (input.empty()) {
        return false;
    }
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-') {
        if (input.length() == 1) {
            return false; 
        }
        start = 1;
    }
    for (size_t i = start; i < input.length(); i++) {
        if (!std::isdigit(input[i])) {
            return false;
        }
    }
    return true;
}

bool Helpers::isFloat(const std::string& input) {
    if (input.empty() || input.length() < 2) {
        return false;
    }
    if (input[input.length() - 1] != 'f') {
        return false;
    }
    std::string numbers = input.substr(0, input.length() - 1);
    return isFloatingPoint(numbers);
}

bool Helpers::isDouble(const std::string& input) {
    if (input.empty()) {
        return false;
    }
    if (input[input.length() - 1] == 'f') {
        return false;
    }
    return isFloatingPoint(input);
}

bool Helpers::isFloatingPoint(const std::string& input) {
    if (input.empty()) {
        return false;
    }
    size_t start = 0;
    if (input[0] == '+' || input[0] == '-') {
        if (input.length() == 1) {
            return false;
        }
        start = 1;
    }
    if (start >= input.length()) {
        return false;
    }
    size_t dots = 0;
    bool hasDigits = false;
    for (size_t i = start; i < input.length(); ++i) {
        if (input[i] == '.')
        {
            dots++;
            if (dots > 1)
                return false; 
        } 
        else if (std::isdigit(input[i]))
        {
            hasDigits = true;
        } 
        else {
            return false;
        }
    }
    return hasDigits;
}

bool Helpers::getType(const std::string& input) {
    if (isPseudoLiterals(input)) {
        return false ;
    } else if (isChar(input)) {
        return false;
    } else if (isInt(input)) {
        return false;
    } else if (isFloat(input)) {
        return false;
    } else if (isDouble(input)) {
        return false;
    }
    return true;
}
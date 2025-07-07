/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/06 08:38:19 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/07 16:14:51 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "helpers.hpp"

class ScalarConverter {
    private :
        ScalarConverter();
    public:
        static void convert(const std::string& input);

};


#endif
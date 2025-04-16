/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:27:15 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/15 04:46:13 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal{
    protected:
    std::string type;
    public:

    Animal();
    Animal(const Animal &other);
    Animal &operator=(const Animal &other);
   virtual ~Animal();
    std::string getType() const;
   virtual void makeSound() const;

};

#endif
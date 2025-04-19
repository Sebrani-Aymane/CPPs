/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:17:05 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/19 22:19:09 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Ice.hpp"

Ice::Ice()  {
    name = "ice";
    //std::cout << "Ice materia created." << std::endl;
}

Ice::~Ice() {
    //std::cout << "Ice materia destroyed." << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {
    *this = other;
    //std::cout << "Ice materia copied." << std::endl;
}


Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        this->name=other.name;
    }
    //std::cout << "Ice materia assigned." << std::endl;
    return *this;
}


std::string const& Ice::getType() const {
    return name;  
}


Ice* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "shoots an ice bolt at " << target.getName()<< std::endl;

}

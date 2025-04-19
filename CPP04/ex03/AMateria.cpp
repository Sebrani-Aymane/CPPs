/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:16:45 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/19 22:16:46 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "AMateria.hpp"

AMateria::AMateria(){

    //std::cout << "AMateria Default constructor"<<std::endl; 
}
AMateria::AMateria(const AMateria &other){
    //std::cout << "AMateria Copy constructor called"<<std::endl;
    *this = other;
}
AMateria::~AMateria(){
    //std::cout << "AMateria Destructor called"<<std::endl;
}
AMateria &AMateria::operator=(const AMateria &other)
{
    //std::cout<< "AMateria assignement operator overload"<< std:: endl;
    if (this != &other)
       name = other.name;
    return *this;
}

std::string const& AMateria::getType()const{
    return(this->name);
}

void AMateria::use(ICharacter &target)
{
    std::cout << "shoots at "<< &target << std::endl;
}



/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 17:27:09 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/14 20:13:02 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Animal.hpp"

Animal::Animal(){
    this->type = "Unkown";
    std::cout << "Animal Default constructor"<<std::endl; 
}
Animal::Animal(const Animal &other){
    std::cout << "Animal Copy constructor called"<<std::endl;
    *this = other;
}
Animal::~Animal(){
    std::cout << "Animal Destructor called"<<std::endl;
}
Animal &Animal::operator=(const Animal &other)
{
    std::cout<< "Animal assignement operator overload"<< std:: endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void Animal::setType(std::string type)
{
    type = "Animal";
}
std::string Animal::getType() const
{
    return(this->type);
}
void Animal::makeSound()const
{
    std::cout <<"Animal goes Bla BLa!"<<std::endl;
}

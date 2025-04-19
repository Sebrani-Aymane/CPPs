/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:16:04 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/19 22:16:05 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Brain.hpp"

Brain::Brain(){    
    std::cout << "Brain Default constructor"<<std::endl; 
    for(int i = 0;i < 100;i++)
    {
        ideas[i] = "no idea";
    }
}

Brain::Brain(const Brain &other){
    std::cout << "Brain Copy constructor called"<<std::endl;
    *this = other;
}

Brain::~Brain(){
    std::cout << "Brain Destructor called"<<std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout<< "Brain assignement operator overload"<< std:: endl;
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i]; 
        }
    }
    return *this;
}

void Brain::setNewIdea(const std::string new_idea)
{
    static int i;
    ideas[i++ % 100] = new_idea;
}
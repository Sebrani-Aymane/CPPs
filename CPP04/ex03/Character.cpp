/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:16:39 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/19 22:16:40 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Character.hpp"
#include <iostream>

Character::Character():name("person")
{for (int i=0;i<4;i++)
    {
        tools[i]=NULL;
    }
}
Character::Character(std::string name) : name(name){
    for (int i=0;i<4;i++)
    {
        tools[i]=NULL;
    }
    
}

Character::~Character() {
	for (int i=0;i<4;i++)
		delete tools[i];
}


Character::Character(const Character& other){
	name=other.name;
    for (int i = 0; i < 4; i++) {

        if (other.tools[i]) {
            tools[i] = other.tools[i]->clone(); 
        }
		else
			tools[i]=NULL;
    }
}


Character& Character::operator=(const Character& other) {
    if (this != &other) {  
        name = other.name;
        for (int i = 0; i < 4; i++) {
			delete tools[i];
            if (other.tools[i]) {
                tools[i] = other.tools[i]->clone(); 
            } else {
                tools[i] = NULL;
            }
        }
    }
    return *this;
}


std::string const& Character::getName() const {
    return name;
}

void Character::equip(AMateria* m) {
    if (!m) return; 
    for(int i = 0; i < 4 ; i++)
    {
        if(tools[i] == m)
            return;
    }
    for (int i = 0; i < 4; i++) {
        if (tools[i] == NULL) {
            tools[i] = m;

            break;
        }
    }
}

void Character::unequip(int idx) {
    if (idx >= 0 && idx < 4 && tools[idx]) {
        tools[idx] = NULL;  
    }
}


void Character::use(int idx, ICharacter& target) {
    if (idx >= 0 && idx < 4 && tools[idx]) {
        tools[idx]->use(target); 
    }
}

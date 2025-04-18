#include "Character.hpp"
#include <iostream>


Character::Character(std::string name) : name(name){
    for (int i=0;i<4;i++)
    {
        tools[i]=NULL;
    }
}

Character::~Character() {
    for (AMateria* m : tools) {
        if (m) {
            delete m;
        }
    }
}


Character::Character(const Character& other) : name(other.name), tools({nullptr, nullptr, nullptr, nullptr}) {
    for (int i = 0; i < 4; ++i) {
        if (other.tools[i]) {
            tools[i] = other.tools[i]->clone(); 
        }
    }
}


Character& Character::operator=(const Character& other) {
    if (this != &other) {  
        for (AMateria* m : tools) {
            if (m) {
                delete m;
            }
        }
        name = other.name;
        for (int i = 0; i < 4; ++i) {
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
    for (int i = 0; i < 4; ++i) {
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


void Character::use(int idx, Character& target) {
    if (idx >= 0 && idx < 4 && tools[idx]) {
        tools[idx]->use(target); 
    }
}

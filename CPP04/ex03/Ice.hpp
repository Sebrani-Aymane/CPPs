#ifndef ICE_HPP
#define ICE_HPP

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria{

    private : 
        std::string type;
    public:
    Ice();
    ~Ice();
    Ice&operator=(const Ice &other);
    Ice(const Ice &other);

    std::string const &getType() const; //Returns the materia type
    Ice* clone() const;
    void use(ICharacter& target);

};

#endif
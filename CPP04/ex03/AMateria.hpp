#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include "Character.hpp"

class AMateria
{
protected:
std::string name;

public:
AMateria();
AMateria(const AMateria &other);
AMateria &operator=(const AMateria &other);
virtual ~AMateria();

std::string const & getType() const; //Returns the materia type
virtual AMateria* clone() const = 0;
virtual void use(ICharacter& target);
};


#endif
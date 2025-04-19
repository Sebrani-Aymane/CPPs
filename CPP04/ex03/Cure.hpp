#ifndef CURE_HPP
#define CURE_HPP

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria{

    public:
    Cure();
    ~Cure();
    Cure&operator=(const Cure &other);
    Cure(const Cure &other);

    std::string const & getType() const; //Returns the materia type
    Cure* clone() const;
    void use(ICharacter& target);

};

#endif
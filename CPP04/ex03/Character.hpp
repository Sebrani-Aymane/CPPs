#ifndef CHARACTER_HPP
#define CHARACTER_HPP


#include <iostream>
#include "AMateria.hpp"

class ICharacter
{
    private:
    std::string name;
public:
ICharacter(std::string name);
ICharacter();
ICharacter(const ICharacter &other);
ICharacter &operator=(const ICharacter &other);
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
};

#endif


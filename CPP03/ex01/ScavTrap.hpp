#ifndef SCAVTRAP.HPP
#define SCAVTRAP.HPP


#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        ScavTrap(std::string name);
        ~ScavTrap();
        ScavTrap(const ScavTrap &other);
        ScavTrap &()

};

#endif
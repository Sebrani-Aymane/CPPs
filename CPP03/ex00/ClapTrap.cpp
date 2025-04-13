#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name)
{
    this->name = name;
    this->hit_points = 10;
    this->energy_points = 10;
    this->attack_damage = 0;
    std::cout<<"default construcor called " << std::endl;
}

ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << this->name << " destroyed" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
    std::cout <<"copy constructor called"<<std::endl;
    *this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    this->name = other.name;
    this->hit_points = other.hit_points;
    this->energy_points = other.energy_points;
    this->attack_damage = other.attack_damage;
    std::cout <<"copy assignements overload "<<std::endl;

    return *this;
}

void ClapTrap::attack(const std::string& target)
{
    if (this->hit_points <= 0)
    {
        std::cout << "ClapTrap " << this->name << " has died " << std::endl;
        return;
    }
    if (this->energy_points > 0)
    {
        this->energy_points--;
        std::cout << "ClapTrap " << this->name << " attacks " << target << std::endl;
    }
    else
        std::cout << this->name << " has no energy points" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
    if (this->hit_points > 0)
    {
        this->hit_points -= amount;
        std::cout<<"ClapTrap " << this->name << " takes " << amount << " points of damage" << std::endl;
    }
    else
        std::cout << this->name << " has died" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount)
{
    if (this->hit_points <= 0)
    {
        std::cout << this->name << " has died" << std::endl;
        return;
    }
    if (this->energy_points > 0)
    {
        this->energy_points -= amount;
        std::cout << "ClapTrap " << this->name << " is repaired for " << amount << " points" << std::endl;
    }
    else
        std::cout << this->name << " has no energy points" << std::endl;
}


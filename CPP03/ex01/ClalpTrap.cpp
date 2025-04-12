#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) : name(name), hit_points(10), energy_points(10), attack_damage(0)
{
    std::cout << "ClapTrap " << name << " created" << std::endl;
}
ClapTrap::~ClapTrap()
{
    std::cout << "ClapTrap " << name << " destroyed" << std::endl;
}
ClapTrap::ClapTrap(const ClapTrap &other) : name(other.name), hit_points(other.hit_points), energy_points(other.energy_points), attack_damage(other.attack_damage)
{
    std::cout << "ClapTrap " << name << " copied" << std::endl;
}
ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
    if (this != &other)
    {
        name = other.name;
        hit_points = other.hit_points;
        energy_points = other.energy_points;
        attack_damage = other.attack_damage;
    }
    return *this;
}
void ClapTrap::attack(const std::string &target)
{
    if (hit_points > 0 && energy_points > 0)
    {
        std::cout << "ClapTrap " << name << " attacks " << target << ", causing " << attack_damage << " points of damage!" << std::endl;
        energy_points--;
    }
}


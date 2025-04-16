#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"

class IMateriaSource
{
public:
IMateriaSource();
IMateriaSource(const IMateriaSource &other);
IMateriaSource &operator=(const IMateriaSource &other);
IMateriaSource(std::string const & type);

virtual ~IMateriaSource();
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif
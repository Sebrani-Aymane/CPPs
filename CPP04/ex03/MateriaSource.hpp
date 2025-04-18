#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"


class MateriaSource : public IMateriaSource
{
public:
MateriaSource();
MateriaSource(const MateriaSource &other);
MateriaSource &operator=(const MateriaSource &other);
MateriaSource(std::string const & type);
learnMateria(AMateria*);
createMateria(std::string const &)
};

#endif
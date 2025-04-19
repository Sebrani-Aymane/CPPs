#include "MateriaSource.hpp"

IMateriaSource::IMateriaSource()
{
    for (int i=0;i<4;i++)
        tools[i]=NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i=0;i<4;i++)
        tools[i]=NULL;
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i=0;i<4;i++)
        tools[i]=other.tools[i];
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    for (int i=0;i<4;i++)
        tools[i]=other.tools[i];
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for (int i=0;i<4;i++)
    {
        if (tools[i]==NULL)
        {
            tools[i]=m;
            break;
        }
    }
}

AMateria* MateriaSource::createMateria(std::string const & type)
{
    for (int i=0;i<4;i++)
    {
        if (tools[i]->getType()==type)
            return tools[i]->clone();
    }
    return NULL;
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:19:23 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/19 22:19:24 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i=0;i<4;i++)
        tools[i]=NULL;
}

MateriaSource::~MateriaSource()
{
    for (int i=0;i<4;i++)
        delete tools[i];
}

MateriaSource::MateriaSource(const MateriaSource &other)
{
    for (int i=0;i<4;i++)
    {
        if(other.tools[i])
            tools[i]=other.tools[i]->clone();
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource &other)
{
    for (int i=0;i<4;i++)
    {
        delete tools[i];
        if(other.tools[i])
            tools[i]=other.tools[i]->clone();
        else
            tools[i] = NULL;
    }
    return *this;
}

void MateriaSource::learnMateria(AMateria* m)
{
    for(int i = 0; i < 4 ; i++)
    {
        if(tools[i] == m)
            return;
    }
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
        if (tools[i] && tools[i]->getType()==type)
            return tools[i]->clone();

    }
    return NULL;
}
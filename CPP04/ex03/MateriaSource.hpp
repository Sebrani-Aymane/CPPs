/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:19:26 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/19 22:19:27 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "AMateria.hpp"
#include "IMateriaSource.hpp"
#include "Character.hpp"



class MateriaSource : public IMateriaSource
{
    private:
        AMateria* tools[4];
    public:
        MateriaSource(const MateriaSource &other);
        MateriaSource();
        ~MateriaSource();
        MateriaSource &operator=(const MateriaSource &other);

        MateriaSource(std::string const &type);
        void learnMateria(AMateria*);
        AMateria* createMateria(std::string const &);
};

#endif
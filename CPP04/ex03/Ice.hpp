/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:19:11 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/19 22:19:12 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_HPP
#define ICE_HPP

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

class Ice : public AMateria{

    private : 
        std::string type;
    public:
    Ice();
    ~Ice();
    Ice&operator=(const Ice &other);
    Ice(const Ice &other);

    std::string const &getType() const; //Returns the materia type
    Ice* clone() const;
    void use(ICharacter& target);

};

#endif
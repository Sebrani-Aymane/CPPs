/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:19:04 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/19 22:19:05 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_HPP
#define CURE_HPP

#include "Character.hpp"
#include "AMateria.hpp"
#include <iostream>

class Cure : public AMateria{

    public:
    Cure();
    ~Cure();
    Cure&operator=(const Cure &other);
    Cure(const Cure &other);

    std::string const & getType() const; //Returns the materia type
    Cure* clone() const;
    void use(ICharacter& target);

};

#endif
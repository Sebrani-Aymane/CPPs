/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 04:32:48 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/15 05:35:01 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <string>
#include <iostream>

class Brain{
    private :
    std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &other);
        ~Brain();
        Brain& operator=(const Brain &other);
        void setNewIdea(const std::string new_idea);
};

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 22:18:27 by asebrani          #+#    #+#             */
/*   Updated: 2025/04/19 22:18:28 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef WrongCAT_HPP
#define WrongCAT_HPP
#include "WrongAnimal.hpp"
#include "iostream"


class WrongCat: public WrongAnimal{
    public:

    WrongCat();
    WrongCat(std::string type);
    WrongCat(const WrongCat &other);
    WrongCat &operator=(const WrongCat &other);
    ~WrongCat();
    void setType(std::string type);
    std::string getType() const;
    void makeSound() const;
};


#endif
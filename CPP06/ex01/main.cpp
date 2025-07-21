/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:20:45 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/20 17:33:14 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"
#include "Serializer.hpp"

int main() {
    Data data;
    data.a = 42;
    data.b = 'c';
    data.c = 3.14f;

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "Data before: " << raw << std::endl;
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "a: " << deserializedData->a  << std::endl;
  std::cout << "b: " << deserializedData->b << std::endl;
  std::cout << "c: " << deserializedData->c << std::endl;

    return 0;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:20:45 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/07 16:30:01 by asebrani         ###   ########.fr       */
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
    std::cout << "Serialized data: " << raw << std::endl;
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "Deserialized Data: " << deserializedData->a << ", "
              << deserializedData->b << ", "
              << deserializedData->c << std::endl;

    return 0;
}


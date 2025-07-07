/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asebrani <asebrani@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 16:35:00 by asebrani          #+#    #+#             */
/*   Updated: 2025/07/07 16:32:58 by asebrani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.hpp"
#include <iostream>

int main() {
    std::cout << "=== Testing type identification ===" << std::endl;
    
    // Test multiple random generations
    for (int i = 0; i < 10; i++) {
        Base* base = generate();
        
        std::cout << "Generated object " << i + 1 << ":" << std::endl;
        std::cout << "  identify(Base*): ";
        identify(base);
        std::cout << "  identify(Base&): ";
        identify(*base);
        std::cout << std::endl;
        
        delete base;
    }
    
    std::cout << "=== Testing specific types ===" << std::endl;
    
    // Test each type specifically
    A* a = new A();
    B* b = new B();
    C* c = new C();
    
    std::cout << "Testing A:" << std::endl;
    std::cout << "  identify(Base*): ";
    identify(a);
    std::cout << "  identify(Base&): ";
    identify(*a);
    
    std::cout << "Testing B:" << std::endl;
    std::cout << "  identify(Base*): ";
    identify(b);
    std::cout << "  identify(Base&): ";
    identify(*b);
    
    std::cout << "Testing C:" << std::endl;
    std::cout << "  identify(Base*): ";
    identify(c);
    std::cout << "  identify(Base&): ";
    identify(*c);
    
    delete a;
    delete b;
    delete c;
    
    return 0;
}

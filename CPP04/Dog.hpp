#ifndef DOG_HPP
#define DOG_HPP
#include "Animal.hpp"
#include "iostream"


class Dog:public Animal{
    public:

    Dog();
    Dog(std::string type);
    Dog(const Dog &other);
    Dog &operator=(const Dog &other);
    ~Dog();
    void setType(std::string type);
    std::string getType() const;
    void makeSound()const;
};
#endif
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
#include "WrongCat.hpp"

WrongCat::WrongCat(){
    this->type = "WrongCat";
    std::cout << "WrongCat Default constructor"<<std::endl; 
}
WrongCat::WrongCat(const WrongCat &other):WrongAnimal(other){
    std::cout << "WrongCat Copy constructor called"<<std::endl;
    *this = other;
}
WrongCat::~WrongCat(){
    std::cout << "WrongCat Destructor called"<<std::endl;
}
WrongCat &WrongCat::operator=(const WrongCat &other)
{
    std::cout<< "WrongCat assignement operator overload"<< std:: endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void WrongCat::setType(std::string type)
{
    type = "WrongCat";
}
std::string WrongCat::getType() const
{
    return(type);
}
void WrongCat::makeSound()const
{
    std::cout <<"WrongCat goes Meow Meow!"<<std::endl;
}

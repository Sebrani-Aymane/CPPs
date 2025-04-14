#include "Dog.hpp"

Dog::Dog(){
    this->type = "Dog";
    std::cout << "Dog Default constructor"<<std::endl; 
}
Dog::Dog(const Dog &other):Animal(other){
    std::cout << "Dog Copy constructor called"<<std::endl;
    *this = other;
}
Dog::~Dog(){
    std::cout << "Dog Destructor called"<<std::endl;
}
Dog &Dog::operator=(const Dog &other)
{
    std::cout<< "Dog assignement operator overload"<< std:: endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void Dog::setType(std::string type)
{
    type = "Dog";
}
std::string Dog::getType() const
{
    return(type);
}
void Dog::makeSound() const
{
    std::cout <<"Dog goes Woof Woof!"<<std::endl;
}

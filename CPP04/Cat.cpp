#include "Cat.hpp"

Cat::Cat(){
    this->type = "Cat";
    std::cout << "Cat Default constructor"<<std::endl; 
}
Cat::Cat(const Cat &other):Animal(other){
    std::cout << "Cat Copy constructor called"<<std::endl;
    *this = other;
}
Cat::~Cat(){
    std::cout << "Cat Destructor called"<<std::endl;
}
Cat &Cat::operator=(const Cat &other)
{
    std::cout<< "Cat assignement operator overload"<< std:: endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void Cat::setType(std::string type)
{
    type = "Cat";
}
std::string Cat::getType() const
{
    return(type);
}
void Cat::makeSound()const
{
    std::cout <<"Cat goes Meow Meow!"<<std::endl;
}

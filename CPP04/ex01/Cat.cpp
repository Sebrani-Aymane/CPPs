#include "Cat.hpp"

Cat::Cat(){

    brain = new Brain();
    for(int i = 0; i < 100;i++)
    {
        brain->setNewIdea("mew mew im god");
    }
    this->type = "Cat";
    std::cout << "Cat Default constructor"<<std::endl; 
}

Cat::Cat(const Cat &other):Animal(other){
    std::cout << "Cat Copy constructor called"<<std::endl;
    *this = other;
}

Cat::~Cat(){
    std::cout << "Cat Destructor called"<<std::endl;
    delete brain;
}

Cat &Cat::operator=(const Cat &other)
{
    std::cout<< "Cat copy assignement operator overload"<< std:: endl;
    if (this != &other)
    {
        *this->brain = *other.brain;
        type = other.type;
    }
    return *this;
}

void Cat::makeSound()const
{
    std::cout <<"Cat goes Meow Meow!"<<std::endl;
}

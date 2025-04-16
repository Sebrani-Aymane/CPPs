#include "Dog.hpp"

Dog::Dog(){

    brain = new Brain();
    for(int i = 0; i < 100 ; i++)
    {
        brain->setNewIdea("help owner");
    }
    this->type = "Dog";
    std::cout << "Dog Default constructor"<<std::endl; 
}

Dog::Dog(const Dog &other):Animal(other){
    std::cout << "Dog Copy constructor called"<<std::endl;
    *this = other;
}

Dog::~Dog(){
    delete brain;
    std::cout << "Dog Destructor called"<<std::endl;
}

Dog &Dog::operator=(const Dog &other)
{
    std::cout<< "Dog assignement operator overload"<< std:: endl;
    if (this != &other)
        {
            delete brain;
            brain = new Brain(*other.brain);
            type = other.type;
        }

    return *this;
}
void Dog::makeSound() const
{
    std::cout <<"Dog goes Woof Woof!"<<std::endl;
}

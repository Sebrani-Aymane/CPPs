#include "Brain.hpp"

Brain::Brain(){    
    std::cout << "Brain Default constructor"<<std::endl; 
    for(int i = 0;i < 100;i++)
    {
        ideas[i] = "no idea";
    }
}

Brain::Brain(const Brain &other){
    std::cout << "Brain Copy constructor called"<<std::endl;
    *this = other;
}

Brain::~Brain(){
    std::cout << "Brain Destructor called"<<std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout<< "Brain assignement operator overload"<< std:: endl;
    if (this != &other)
    {
        for(int i = 0; i < 100; i++)
        {
            this->ideas[i] = other.ideas[i]; 
        }
    }
    return *this;
}

void Brain::setNewIdea(const std::string new_idea)
{
    static int i;
    ideas[i++ % 100] = new_idea;
}
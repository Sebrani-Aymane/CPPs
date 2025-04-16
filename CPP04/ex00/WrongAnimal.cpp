#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(){
    this->type = "Unkown";
    std::cout << "WrongAnimal Default constructor"<<std::endl; 
}
WrongAnimal::WrongAnimal(const WrongAnimal &other){
    std::cout << "WrongAnimal Copy constructor called"<<std::endl;
    *this = other;
}
WrongAnimal::~WrongAnimal(){
    std::cout << "WrongAnimal Destructor called"<<std::endl;
}
WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
    std::cout<< "WrongAnimal assignement operator overload"<< std:: endl;
    if (this != &other)
        type = other.type;
    return *this;
}

void WrongAnimal::setType(std::string type)
{
    type = "WrongAnimal";
}
std::string WrongAnimal::getType() const
{
    return(this->type);
}
void WrongAnimal::makeSound()const
{
    std::cout <<"WrongAnimal goes Bla BLa!"<<std::endl;
}

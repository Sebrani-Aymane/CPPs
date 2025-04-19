#include "Cure.hpp"



Cure::Cure(){
    name = "cure";
    //std::cout << "Cure materia created." << std::endl;
}

Cure::~Cure() {
    //std::cout << "Cure materia destroyed." << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other) {
    *this = other;
    //std::cout << "Cure materia copied." << std::endl;
}


Cure& Cure::operator=(const Cure& other) {
    if (this != &other) {
       this->name = other.name;  
    }
    //std::cout << "Cure materia assigned." << std::endl;
    return *this;
}


std::string const& Cure::getType() const {
    return name;  
}


Cure* Cure::clone() const {
    return new Cure(*this);
}

void Cure::use(ICharacter& target) {
    std::cout << "Healing " << target.getName() << "'s wounds" << std::endl;

}

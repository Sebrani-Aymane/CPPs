#include "Ice.hpp"



Ice::Ice() : type("Ice") {
    
    std::cout << "Ice materia created." << std::endl;
}

Ice::~Ice() {
    std::cout << "Ice materia destroyed." << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other) {

    std::cout << "Ice materia copied." << std::endl;
}


Ice& Ice::operator=(const Ice& other) {
    if (this != &other) {
        AMateria::operator=(other);  
    }
    std::cout << "Ice materia assigned." << std::endl;
    return *this;
}


std::string const& Ice::getType() const {
    return type;  
}


Ice* Ice::clone() const {
    return new Ice(*this);
}

void Ice::use(ICharacter& target) {
    std::cout << "shoots an ice bolt at " << target.getName()<< std::endl;

}

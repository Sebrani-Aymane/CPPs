#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

const Animal* j = new Dog();
const Animal* i = new Cat();
std::cout << j->getType() << " " << std::endl;
std::cout << i->getType() << " " << std::endl;
i->makeSound(); //will output the cat sound!
j->makeSound();

delete i;
delete j;

const WrongAnimal* metaa = new WrongAnimal();
const WrongAnimal* ii = new WrongCat();
std::cout << ii->getType() << " " << std::endl;
ii->makeSound(); //will not output the cat sound!
metaa->makeSound();
delete metaa;
delete ii;
return 0;
} 
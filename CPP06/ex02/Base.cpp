#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

#include <exception>

Base::~Base() {
}

Base* generate(void)
{
    srand(time(NULL));
    int class_num = rand() % 3;

    switch (class_num)
    {
        case 0:
            return new A();
        case 1:
            return new B();
        case 2:
            return new C();
    }
    return NULL;
}

void identify(Base *p){

    if(dynamic_cast<A*>(p))
    {
        std::cout << "class A" << std::endl;
        return ;
    }
    if(dynamic_cast<B*>(p))
    {
        std::cout << "class B" << std::endl;
        return ;
    }
    if(dynamic_cast<C*>(p))
    {
        std::cout << "class C" << std::endl;
        return ;
    }
    std::cout <<"Base" << std::endl;
}

void identify(Base &p)
{
    try{
        A &a = dynamic_cast<A&>(p);
        std::cout << "Class A" <<std::endl;
    }
    catch(std::exception &e)
    {
        try
        {
            B &b = dynamic_cast<B&>(p);
            std::cout << "Class B" <<std::endl;
        }
        catch(std::exception &e)
        {
            try
            {
                C &c = dynamic_cast<C&>(p);
                std::cout << "Class C" <<std::endl;
            }
            catch(std::exception &e)
            {
                std::cout << "Base" << std::endl;
            }
        }
    }
}

#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


int main()
{
    Base cls;
    identify(cls);
    A a;
    B b;
    C c;

    identify(a);
    identify(b);
    identify(c);

    identify(&b);

}

#ifndef ITER_HPP
#define ITER_HPP
#include <iostream>


template <typename T,typename F>
void iter(T *array, int lenght,void f1(F element))
{
    for (int i =0; i < lenght ; i++)
    {
        f1(array[i]);
    }
}


#endif
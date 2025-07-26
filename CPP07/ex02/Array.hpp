#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template <typename T>
class Array{
private:
    T* array;
    unsigned int size;
public: 
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();
    Array& operator=(const Array& other);
    Array& operator[](unsigned int index);


};

#endif
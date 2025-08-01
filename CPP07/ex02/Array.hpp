#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
template <typename T>
class Array{
private:
    T* array;
    unsigned int sizee;
public: 
    Array();
    Array(unsigned int n);
    Array(const Array& other);
    ~Array();
    Array& operator=(const Array& other);
    T& operator[](unsigned int index) const;
    unsigned int size();

};

#endif
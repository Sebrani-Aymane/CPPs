
#include "Array.hpp"
#include <exception>

template <typename T>
Array<T>::Array()
{
    array = new T[0];
    sizee = 0;
    std::cout << "default constrc called"<< std::endl;
}
template <typename T>
Array<T>::Array(unsigned int n)
{
    if (n <4294967295){
        array = new T[n];
        sizee = n;
    }
    else {
        std::cout << "out of limits" << '\n';
        array = NULL;
        exit(1);
       }   std::cout << "params constrc called"<<std::endl;
    
}


template <typename T>
Array<T>::~Array()
{
    std::cout << "destructor"<<std::endl;
    delete[] array;
}
template <typename T>
Array<T>::Array(const Array<T>& other) : array (new T[other.sizee]),sizee(other.sizee)
{
    for(unsigned int i=0;i< sizee ;i++){
        array[i] = other.array[i];
    }
}
template <typename T>
 Array<T>& Array<T>::operator=(const Array<T>& other){
    if (this != &other)
        {
            delete []array;
            sizee= other.sizee;
            if (sizee >0)
            {
                array = new T[sizee];
                for (unsigned int i=0;i<sizee ;i++)
                {
                    array[i] = other.array[i];
                }
            }
        }
        return(*this);
}
template <typename T>
T& Array<T>::operator[](unsigned int index) const
{
    if (index >= sizee)
    {
        throw std::out_of_range("Index out of bounds");
    }
    return array[index];
}


template<typename T>
unsigned int Array<T> :: size(){
   
    return(sizee);
}
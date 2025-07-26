
#include "Array.hpp"
#include <exception>

template <typename T>
Array<T>::Array(unsigned int n)
{
    try
    {
        array = new T[n];
        size = n;
    }
    catch(const std::exception& e)
    {
        std::cout << e.what() << '\n';
        array = NULL;
        exit(1);
    }
    
}

template <typename T>
Array<T>::Array()
{
    array = new T[0];
    size = 0;
}

template <typename T>
Array<T>::~Array()
{
    delete[] array;
}
template <typename T>
Array<T>::Array(const Array<T>& other)
{
    this = other;
}
template <typename T>
 Array<T>& Array<T>::operator=(const Array<T>& other)
{
    if (this != &other) {            
            int* temp = array;
            array  = new int[other.size];
            
     
            if (array == nullptr) {
                array = temp;
            }
            else {
                
        
                delete [] temp;
                
        
                size = other.size;
                memmove(array, c.array, size * sizeof(T));
            }
        }
     return *this;
}





#include "Array.tpp"

// int main()
// {
//     Array<char> a(100);
//     Array <int> b(20);

//     std::cout <<a.size()<< std::endl;
//     std::cout <<b.size()<< std::endl;
//     std::cout <<sizeof(a)<< std::endl;
//     std::cout <<sizeof(b)<< std::endl;
//     return 0;
// }
#include "Array.hpp"
#include <iostream>

int main() {
    try {

        Array<int> emptyArray;
        std::cout << "Empty array size: " << emptyArray.size() << std::endl;
        Array<int> intArray(4);
        std::cout << "Int array size: " << intArray.size() << std::endl;
        for (unsigned int i = 0; i < intArray.size(); i++) {
            intArray[i] = i * 10;
        }

        for (unsigned int i = 0; i < intArray.size(); i++) {
            std::cout << "intArray[" << i << "] = " << intArray[i] << std::endl;
        }

        Array<int> copiarray(intArray);
        std::cout << "Copied array[2]: " << copiarray[2] << std::endl;

        Array<int> assignarray;
        assignarray = intArray;
        std::cout << "Assigned array[3]: " << assignarray[3] << std::endl;

  
        std::cout << "Testing out of bounds" << std::endl;
        std::cout << intArray[6] << std::endl;
    }
    catch (const std::exception& e) {
        std::cerr << "Exception caught: " << e.what() << std::endl;
    }
    return 0;
}
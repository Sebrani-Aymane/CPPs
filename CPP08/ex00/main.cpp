#include <iostream>
#include <vector>
#include <list>
#include <iterator>

#include "easyfind.hpp"

int main() {
 
    std::cout << "-- Testing vector --" << std::endl;
    std::vector<int> numbers;
    for (int i = 0; i < 5; ++i) {
        numbers.push_back(i * 10);
    }

    try {
        std::vector<int>::iterator it = easyfind(numbers, 30);
        std::cout << *it
               << " is in the vector at index " << it - numbers.begin() << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    try {
        (void)easyfind(numbers, 99);
        std::cout << "Unexpectedly found 99 in vector" << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Vector (not found): " << e.what() << std::endl;
    }

    // List test
    std::cout << "-- Testing list --" << std::endl;
    std::list<int> numberList;
    for (int i = 1; i <= 5; ++i) {
        numberList.push_back(i);
    }

    try {
        std::list<int>::iterator it = easyfind(numberList,1);
        std::cout << *it << " is in the list at index "  << std::distance(numberList.begin(), it) << std::endl;
    } catch (const std::exception &e) {
        std::cout << "List: " << e.what() << std::endl;
    }

    return 0;
} 
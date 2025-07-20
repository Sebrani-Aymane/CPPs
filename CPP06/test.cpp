#include <limits>
#include <iostream>
#include <iomanip>
#include <ostream>
int main()
{
    srand(time(NULL));
    std::cout << rand() % 3 << std::endl;
}
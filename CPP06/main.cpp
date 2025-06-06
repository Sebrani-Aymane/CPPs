#include <string>
#include <iostream>
#include  "ScalarConverter.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Usage: ./ScalarConverter <string>" << std::endl;
        return 1;
    }
    std::string input = argv[1]; ScalarConverter::convert(argv[1]);
    return 0;
}
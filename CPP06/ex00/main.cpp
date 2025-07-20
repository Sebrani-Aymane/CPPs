#include "ScalarConverter.hpp"

int main(int ac,char **av)
{
    if (ac !=2 )
        return(std::cout << "Usage <./CST> <value> " << std::endl,1);
    std::string input(av[1]);
    ScalarConverter::convert(input);
}
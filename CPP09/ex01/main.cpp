#include "RPN.hpp"

int main(int ac,char **av)
{
    if (ac != 2)
    {
        std::cout <<"Usage <./RPN <operands,operations> >"<<std::endl;
        return 1;
    }
    RPN rpn;
    std::string args = av[1];
    rpn.handle_data(args);
    return 0;
}
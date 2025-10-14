#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include <sstream>
class RPN{
    private :
        std::stack<std::string> tokens;
    public :
    RPN();
    RPN(const RPN &other);
    RPN &operator=(const RPN &other);
    ~RPN();
    void handle_data(const std::string args);
};
#endif
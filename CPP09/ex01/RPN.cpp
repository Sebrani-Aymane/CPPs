#include "RPN.hpp"

RPN::RPN(){
    // tokens.push("");
}
RPN::RPN(const RPN &other){
    *this= other;
}

RPN &RPN::operator=(const RPN &other){
    if (this!= &other)
        this->tokens = other.tokens;
    return *this;
}
RPN::~RPN(){}
void handle_tokens(std::stack<std::string>& tokens)
{

    if (tokens.size() < 3)
        return;
    
    std::string operation = tokens.top();
    tokens.pop();
    double operand2 = std::strtod(tokens.top().c_str(), NULL);
    tokens.pop();
    double operand1 = std::strtod(tokens.top().c_str(), NULL);
    tokens.pop();
    double result = 0.0;
    if (operation == "+")
        result = operand1 + operand2;
    else if (operation == "-")
        result = operand1 - operand2;
    else if (operation == "*")
        result = operand1 * operand2;
    else if (operation == "/")
        result = operand1 / operand2;
    
    std::stringstream ss;
    ss << result;
    tokens.push(ss.str());
}
void RPN::handle_data(const std::string args)
{
    std::istringstream iss(args);
    std::string token;
    
    while (iss >> token)
    {

        if (token == "+" || token == "-" || token == "*" || token == "/")
        {
            if (tokens.size() < 2)
            {
                std::cout << "Error: insufficient operands" << std::endl;
                return;
            }
            tokens.push(token);
            handle_tokens(tokens);
        }
        else
        {
            char* endptr;
            double digit = std::strtod(token.c_str(), &endptr);
            if (*endptr != '\0' || digit>9)
            {
                std::cout << "Error: bad input" << std::endl;
                return;
            }
            tokens.push(token);
        }
    }
    if (tokens.size() != 1)
    {
        std::cout << "Error: invalid expression" << std::endl;
        return;
    }
    std::cout << tokens.top() << std::endl;
}
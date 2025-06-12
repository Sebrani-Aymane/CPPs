#include "helpers.hpp"
#include <cstdlib>
#include <sstream>

int checkFloat(const  std::string &input) {
    if (input == "-inff" || input == "+inff" || input == "nanf")
    {
        return 1;
    }
    int f = static_cast<int>(input.length());
    if (input[f-1] != 'f')
    {
        return 0;
    }
    for (int i = 0; i < f; i++)
    {
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-' && input[i] != '+')
        {
            return 0;
        }
    }
    if (input.find('.') == std::string::npos || input.find('.') == 0 || static_cast<int>(input.find('.')) == f - 1)
    {
        return 0;
    }
    return 1;
}

int checkDouble(const  std::string &input) {
    if (input == "-inf" || input == "+inf" || input == "nan")
    {
        return 1;
    }
    for (int i = 0; i < static_cast<int>(input.length()); i++)
    {
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != '-' && input[i] != '+')
        {
            return 0;
        }
    }
    if (input.find('.') == std::string::npos || input.find('.') == 0 
       || input.find('.') == input.length() - 1)
    {
        return 0;
    }
    return 1;
}
int checkInt(const std::string &input) {
    if (input.empty() || (input.length() == 1 && !isdigit(input[0]) && input[0] != '-' && input[0] != '+'))
    {
        return 0;
    }
    for (size_t i = 0; i < input.length(); i++)
    {
        if (!isdigit(input[i]) && (i != 0 || (input[i] != '-' && input[i] != '+')))
        {
            return 0;
        }
    }
    try
    {
        std::atoi(input.c_str());
    }
    catch (const std::out_of_range &)
    {
        return 0;
    }
    return 1;
}
void convertChar(const std::string &input) {
    if (input.length() == 1 && isprint(input[0]))
    {
        char c = input[0];
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << std::endl;
    }
    else
    {
        std::cout << "char: Non displayable" << std::endl;
        std::cout << "int: " << static_cast<int>(input[0]) << std::endl;
        std::cout << "float: " << static_cast<float>(input[0]) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(input[0]) << std::endl;
    }
}

void convertFloat(const std::string &input) {
    float f = static_cast<float>(atof(input.c_str()));
    std::cout << "char: " << static_cast<char>(f) << std::endl;
    std::cout << "int: " << static_cast<int>(f) << std::endl;
    std::cout << "float: " << f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void convertDouble(const std::string &input) {
    double d = atof(input.c_str());
    std::cout << "char: " << static_cast<char>(d) << std::endl;
    std::cout << "int: " << static_cast<int>(d) << std::endl;
    std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
    std::cout << "double: " << d << std::endl;
}

void convertInt(const std::string &input) {
    int i = atoi(input.c_str());
    std::cout << "char: " << static_cast<char>(i) << std::endl;
    std::cout << "int: " << i << std::endl;
    std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(i) << std::endl;
}
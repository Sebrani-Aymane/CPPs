#include "ScalarConvert,.hpp"

int ScalarConvert::getType(const sts::string &input)
{
 
}

void ScalarConverter::convert(const std::string &input)
{
    int type = getType(input);
    switch (type)
    {
        case 0:
            // Convert to char
            break;
        case 1: // int
            // Convert to int
            break;
        case 2: // float
            // Convert to float
            break;
        case 3: // double
            // Convert to double
            break;
        default:
            std::cout << "Invalid input type." << std::endl;
            break;
    }
}
void ScalarConverter::convertChar(const std::string &input)
{
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
    }
}
void ScalarConverter::convertInt(const std::string &input)
{
    try
    {
        int i = std::stoi(input);
        std::cout << "char: '" << static_cast<char>(i) << "'" << std::endl;
        std::cout << "int: " << i << std::endl;
        std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(i) << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "int: out of range" << std::endl;
    }
}
void ScalarConverter::convertFloat(const std::string &input)
{
    try
    {
        float f = std::stof(input);
        std::cout << "char: '" << static_cast<char>(f) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(f) << std::endl;
        std::cout << "float: " << f << "f" << std::endl;
        std::cout << "double: " << static_cast<double>(f) << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "float: out of range" << std::endl;
    }
}
void ScalarConverter::convertDouble(const std::string &input)
{
    try
    {
        double d = std::stod(input);
        std::cout << "char: '" << static_cast<char>(d) << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(d) << std::endl;
        std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
        std::cout << "double: " << d << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cout << "double: out of range" << std::endl;
    }
}
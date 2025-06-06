#include "ScalarConverter.hpp"

int ScalarConverter::getType(const std::string &input)
{
    if (input.length()==1 && isprint(input[0]))
    {
        return 0;
    }
else  if (checkFloat(input))
    {
        return 1; 
    }
    else if (checkDouble(input))
    {
        return 2;
    }
    else if (checkInt(input))
    {
        return 3;
    }
return-1;
}

void ScalarConverter::convert(const std::string &input)
{
    int type = getType(input);
    switch (type)
    {
        case 0:
            convertChar(input);
            break;
        case 1:
            convertFloat(input);
            break;
        case 2:
            convertDouble(input);
            break;
        case 3:
            convertInt(input);
            break;
        default:
            std::cout << "Invalid input type." << std::endl;
            break;
    }
}

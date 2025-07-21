#include "ScalarConverter.hpp"
#include "helpers.hpp"
#include <iomanip>
#include <cmath>
#include <limits>

ScalarConverter::ScalarConverter() {}
ScalarConverter::~ScalarConverter() {}
ScalarConverter::ScalarConverter(const ScalarConverter &) {}
ScalarConverter &ScalarConverter::operator=(const ScalarConverter &) {
    return *this;
}

void ScalarConverter::convertChar(const std::string &str) {
    char c = str[0];
    std::cout << "char: '" << c << "'" << std::endl;
    std::cout << "int: " << static_cast<int>(c) << std::endl;
    
    float f_val = static_cast<float>(c);
    std::cout << "float: ";
    Helpers::printFloat(f_val);
    std::cout << std::endl;
    
    double d_val = static_cast<double>(c);
    std::cout << "double: ";
    Helpers::printDouble(d_val);
    std::cout << std::endl;
}

void ScalarConverter::convertInt(const std::string &str) {
    int value = std::stoi(str);
    std::cout << "char: ";
    if (value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
    } else {
        char c = static_cast<char>(value);
        if (std::isprint(c)) {
            std::cout << "'" << c << "'" << std::endl;
        } else {
            std::cout << "Non displayable" << std::endl;
        }
    }
    std::cout << "int: " << value << std::endl;
    
    float f_val = static_cast<float>(value);
    std::cout << "float: ";
    Helpers::printFloat(f_val);
    std::cout << std::endl;
    
    double d_val = static_cast<double>(value);
    std::cout << "double: ";
    Helpers::printDouble(d_val);
    std::cout << std::endl;
}

void ScalarConverter::convertFloat(const std::string &str) {
        std::string numPart = str.substr(0, str.length() - 1);

        double value = std::strtof(numPart.c_str(),NULL);
        if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        std::cout << "char: ";
        if (value < 0 || value > 127 ) {
            std::cout << "impossible" << std::endl;
        } else {
            char c = static_cast<char>(value);
            if (std::isprint(c)) {
                std::cout << "'" << c << "'" << std::endl;
            } else {
                std::cout << "Non displayable" << std::endl;
            }
        }
        std::cout << "int: ";
        if (value < INT_MIN || value > INT_MAX) {
            std::cout << "impossible" << std::endl;
        } else {
            int iValue = static_cast<int>(value);
            std::cout << iValue << std::endl;
        }
        
        std::cout << "float: ";
        Helpers::printFloat(value);
        std::cout << std::endl;
        
        double d_val = static_cast<double>(value);
        std::cout << "double: ";
        Helpers::printDouble(d_val);
        std::cout << std::endl;
        return;
}

void ScalarConverter::convertDouble(const std::string &str) {

        double value = std::strtod(str.c_str(), NULL);
        if (value > std::numeric_limits<float>::max() || value < -std::numeric_limits<float>::max()) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        std::cout << "char: ";
        if (value < 0 || value > 127) {
            std::cout << "impossible" << std::endl;
        } else {
            char c = static_cast<char>(value);
            if (std::isprint(c)) {
                std::cout << "'" << c << "'" << std::endl;
            } else {
                std::cout << "Non displayable" << std::endl;
            }
        }
        std::cout << "int: ";
        if (value < INT_MIN || value > INT_MAX) {
            std::cout << "impossible" << std::endl;
        } else {
            int iValue = static_cast<int>(value);
            std::cout << iValue << std::endl;
        }
        float f_val = static_cast<float>(value);
        std::cout << "float: ";
        Helpers::printFloat(f_val);
        std::cout << std::endl;
        
        std::cout << "double: ";
        Helpers::printDouble(value);
        std::cout << std::endl;
    } 

void ScalarConverter::convert(const std::string &str) {
    int type = Helpers::getType(str); 
    switch (type) {
        case 0:
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
      if (str == "nan" || str == "inf" || str == "-inf" || str == "+inf") {
    std::cout << "float: " << str << "f" << std::endl;
    std::cout << "double: " << str << std::endl;
} else if (str.back() == 'f') {

    std::cout << "float: " << str << std::endl;
    std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
} else {

    std::cout << "float: " << str << "f" << std::endl;
    std::cout << "double: " << str << std::endl;
}
            break;
        case 1: 
            convertFloat(str);
            break;
        case 2: 
            convertDouble(str);
            break;
        case 3: 
            convertInt(str);
            break;
        case 4: 
            convertChar(str);
            break;
        default:
           std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
    }
}
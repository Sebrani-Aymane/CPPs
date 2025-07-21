#include "helpers.hpp"
#include <sstream> 
#include <cmath>
#include <cfloat>

int Helpers::getType(const std::string &str) {
     if (isLiteral(str))
        return 0;
    else if (isFloat(str))
        return 1; 
    else if (isDouble(str))
        return 2;
  else  if (isInt(str))
        return 3;
   else if (isChar(str))
        return 4; 
    return -1;
}

bool Helpers::isChar(const std::string &str) {
    if (str.length() == 1 && std::isprint(str[0]) && !std::isdigit(str[0]))
        return true;
 return false;
}

bool Helpers::isInt(const std::string &str) {
    if (str.empty() || (str[0] != '-' && str[0] != '+' && !isdigit(str[0])))
        return false;
    for (size_t i = 1; i < str.length(); ++i) {
        if (!isdigit(str[i]))
            return false;
    }
    try {
        long value = std::stol(str);
        if (value < std::numeric_limits<int>::min() || value > std::numeric_limits<int>::max())
            return false;
    } catch (const std::out_of_range &) {
        return false;
    }
    return true;
}

bool Helpers::isFloat(const std::string &str) {
    if (str.empty() || str.back() != 'f')
        return false;
    std::string numPart = str.substr(0, str.length() - 1);
    if (numPart.empty() || (numPart[0] != '-' && numPart[0] != '+' && !isdigit(numPart[0])))
        return false;
    int dot =0;
    for (size_t i = 1; i < numPart.length(); ++i) {
        if (!isdigit(numPart[i]) && numPart[i] != '.')
            return false;
        if (numPart[i] == '.') {
            dot++;
            if (dot > 1)
                return false;
        }
    }
    size_t pos = numPart.find('.');
    if(pos != std::string::npos && (!isdigit(str[pos+1]) || !str[pos+1]))
        return false;

        float value = std::strtof(numPart.c_str(),NULL);
        if (std::isinf(value) || std::isnan(value))
            return false;
    return true;
}

bool Helpers::isDouble(const std::string &str) {
    if (str.empty() || str.back() == 'f' || (str[0] != '-' && str[0] != '+' && !isdigit(str[0])))
        return false;
    int dotCount = 0;
    for (size_t i = 1; i < str.length(); ++i) {
        if (!isdigit(str[i]) && str[i] != '.')
            return false;
        if (str[i] == '.') {
            dotCount++;
            if (dotCount > 1)
                return false;
        }
    }

    size_t pos = str.find('.');
    if (pos != std::string::npos && (pos + 1 >= str.length() || !isdigit(str[pos + 1])))
        return false;

    double value = std::strtod(str.c_str(), NULL);
    if (std::isinf(value) || std::isnan(value))
        return false;

    return true;
}

void Helpers::printFloat(float value) {
    if (std::isinf(value) || std::isnan(value)) {
        std::cout << "impossible";
        return;
    }
    std::cout << std::fixed;
    std::ostringstream temp;
    temp << value;
    size_t pos = temp.str().find('.');
    if (pos == std::string::npos) {
        std::cout << std::setprecision(1)<< value << "f";
        return;
    }
    int dot = temp.str().length() - pos - 1;

        std::cout << std::setprecision(dot) << value << "f";
    }

void Helpers::printDouble(double value) {
    if(std::isinf(value) || std::isnan(value)) {
    std::cout << "double: impossible" << std::endl;
    return;
}
    if (std::isinf(value) || std::isnan(value)) {
        std::cout << "impossible";
        return;}
    
    std::cout << std::fixed;
    std::ostringstream temp;
    temp << value;
    size_t pos = temp.str().find('.');
    if (pos == std::string::npos) {
        std::cout << std::setprecision(1) << value;
        return;
    }
    int dot = temp.str().length() - pos - 1;
        std::cout << std::setprecision(dot) << value;
    }

bool Helpers::isLiteral(const std::string &str) {
    return str == "nan" || str == "nanf"
        || str == "+inf" || str == "-inf" 
        || str == "+inff" || str == "-inff"
        || str == "inf" || str == "inff";
}


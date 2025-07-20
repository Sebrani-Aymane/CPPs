#include "helpers.hpp"
#include <cmath>
#include <limits>

int Helpers::getType(const std::string &str) {
     if (isLiteral(str))
        return 0;
    else if (isFloat(str))
        return 1; 
    else if (isDouble(str))
        return 2;
  else  if (isInt(str))
        return 3;
   else  if (isChar(str))
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
    try {
        std::stof(numPart);
        return true;
    } catch (...) {
        return false;
    }
}

bool Helpers::isDouble(const std::string &str) {
    if (str.empty())
        return false;
    try {
        std::stod(str);
        return true;
    } catch (...) {
        return false;
    }
}

void Helpers::printFloat(float value) {
    if (std::isinf(value) || std::isnan(value)) {
        std::cout << "impossible";
        return;
    }
    
    std::cout << std::fixed;
    if (value == static_cast<long long>(value) && value >= -1e10 && value <= 1e10) {
        std::cout << std::setprecision(1) << value << "f";
    } else {
        std::cout << std::setprecision(6) << value << "f";
    }
}

void Helpers::printDouble(double value) {
    const double MAX_DISPLAYABLE = 1e15;
    const double MIN_DISPLAYABLE = -1e15;
    
    if (std::isinf(value) || std::isnan(value) || 
        value > MAX_DISPLAYABLE || value < MIN_DISPLAYABLE) {
        std::cout << "impossible";
        return;
    }
    
    std::cout << std::fixed;
    if (value == static_cast<long long>(value) && value >= -1e10 && value <= 1e10) {
        std::cout << std::setprecision(1) << value;
    } else {
        std::cout << std::setprecision(6) << value;
    }
}

bool Helpers::isLiteral(const std::string &str) {
    return str == "nan" || str == "nanf"
        || str == "+inf" || str == "-inf" 
        || str == "+inff" || str == "-inff"
        || str == "inf" || str == "inff";
}

